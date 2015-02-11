#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;

struct node {
	struct node* left;
	struct node* right;
	int data;
};

struct tree {
	struct node* root;
};

/* Using Node instead of struct node, makes the code more readable*/
typedef struct node Node;
typedef struct tree BinaryTree;

/* Returns a new node-> makes the left and right child as NULL, and assigns the value to the Node */
Node* newNode(int value) {
	Node* root = new Node;
	root->left = root->right = NULL;
	root->data = value;
	return root;
}

/* 
 * Inserts the Node into the tree
 * Find the first NULL position and using the newNode function adds the node there
*/
Node* insert(Node* root, int value) {
	if(root == NULL) {
		return(newNode(value));
	}

	/* If the root exists, then find out the next null position ( the node with an empty position) and insert there a new node */	
	queue<Node*> q;
	q.push(root);
	Node* temp;
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		
		if(temp->left != NULL) {
			q.push(temp->left);
		}
		else {
			Node* node = newNode(value);
			temp->left = node;
			return root;
		}
		
		if(temp->right != NULL) {
			q.push(temp->right);
		}
		else {
			Node* node = newNode(value);
			temp->right = node;
			return root;
		}
	}		
}

/* preOrder- prints the root, then goes to process the left subtree and then the right subtree */
void preOrder(Node* root) {
	if(root) {
		cout << root->data << "--->" ;
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Print the pre order of a binary tree without using recursion(iterative)*/
void preOrderWithoutRecur(Node* root) {
	
	stack<Node*> s;
	
	while(1) {
		while(root) {
			cout << root->data << "--->";
			s.push(root);
			root = root->left;		
		}
		
		if(s.empty()) { 
			break;
		}
		
		root = s.top();
		s.pop();
		root = root->right;
	}
}

/* inOrder - prints the left subtree, then the root and then the right sub tree */
void inOrder(Node* root) {
	if(root) {
		inOrder(root->left);
		cout << root->data << "--->";
		inOrder(root->right);
	}
}
/* Prints the in order of a tree without using recursion(iterative) */
void inOrderWithoutRecur(Node* root) {
	stack<Node*> s;
	
	while(1) {
		while(root) {
			s.push(root);
			root = root->left;
		}
		
		if(s.empty()) break;
		
		root = s.top();
		s.pop();
		
		cout << root->data << "--->";
		
		root = root->right;
	}
}

void postOrder(Node* root) {
	if(root) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << "--->";
	}
}

/* uses two stacks to do the task */
void postOrderWithoutRecur(Node* root) { // 
	stack<Node*> s1, s2;
	if(root) s1.push(root);
	
	while(s1.empty() == false) {
		Node* temp = s1.top();
		s2.push(temp);
		s1.pop();

		if(temp->left) s1.push(temp->left);
		if(temp->right) s1.push(temp->right);		
	}

	while(!s2.empty()) {
		cout << s2.top()->data << "--->";
		s2.pop();
	}
}

/*Go level by level and print the nodes, uses a queue to keep track of the child nodes */
void levelOrderTraversal(Node* root) {
	queue<Node*> q;
	if(root) q.push(root);
	else {
		cout << "No Tree";
		return;
	}

	while(!q.empty()) {
		root = q.front();
		q.pop();

		cout << root->data << "--->";

		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right); 
	}
}

/* Maximum value in the Tree */
int maxElementInTree(Node* root) {
	int root_value, left_value, right_value, max_value = INT_MIN;
	if(root != NULL) {
		root_value = root->data;
		left_value = maxElementInTree(root->left);
		right_value = maxElementInTree(root->right);
		max_value = max(left_value, right_value);
		max_value = max(max_value, root_value);	
	}
	return max_value;
}
/* Maximum value in the Tree without recursion( Iterative ) */
int maxElementWithoutRecur(Node* root) {
	int max_value = INT_MIN;
	queue<Node*> q;

	if(!root) return max_value;
	q.push(root);

	while(!q.empty()) {
		root = q.front();
		q.pop();

		max_value = max(max_value, root->data);

		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right);
	}

	return max_value;
}

/* Search for a value in the given Tree */
bool search(Node* root, int value) {
	if(root) {
		if(root->data == value) {
			return true;
		}
		return (search(root->left, value) || search(root->right, value));
	}
}

/* Iterative implementation of search */
bool searchWithoutRecur(Node* root, int value) {
	queue<Node*> q;
	if(root) q.push(root);
	else return false;

	while(!q.empty()) {
		root = q.front();
		q.pop();

		if(root->data == value) return true;
		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right);
	}
	return false;
}

/* Returns the number of nodes in the tree */
int sizeOfTree(Node* root) {
	if(!root) {
		return 0;
	}
	return sizeOfTree(root->left) + 1 + sizeOfTree(root->right);
}

/* Returns the number of nodes in the tree (Iterative) */
int sizeOfTreeWithoutRecur(Node* root) {
	if(!root) return 0;
	
	int size = 0;

	queue<Node*> q;
	if(root) q.push(root);

	while(!q.empty()) {
		root = q.front();
		q.pop();
		size++;

		if(root->left) q.push(root->left);
		if(root->right) q.push(root->right);
	}
	return size;
}

/* Prints in the reverse order, from level n -> level (n-1) -> level (n-2) -> ... */
void printInReverseOrder(Node* root) {
	if(!root) return;

	queue<Node*> q;
	stack<Node*> s;
	if(root) q.push(root);

	while(!q.empty()) {
		root = q.front();
		s.push(root);
		q.pop();

		if(root->right) q.push(root->right);
		if(root->left) q.push(root->left);		
	}

	while(!s.empty()) {
		cout << s.top()->data << "--->";
		s.pop(); 
	}
}

/* Delete the given tree */
void deleteTree(Node* root) {
	if(!root) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete(root);
}

/* returns the height of the Tree */
int height(Node* root) {
	if(!root) return 0;
	return max(height(root->left) + 1, height(root->right) + 1); 
}

/* Iterative implementation of the calculating the height of the tree */
int heightWithoutRecursion(Node* root) {
	int level = 1;
	if(!root) return 0;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		root = q.front();
		q.pop();

		if(root == NULL) {
			if(!q.empty())
				q.push(NULL);
			level++;
		} else {
			if(root->left) q.push(root->left);
			if(root->right) q.push(root->right);
		}
	}

	return level;
}

int main() {
	BinaryTree* tree = new BinaryTree; /* Creating a Tree*/
	
	/* Insert values to the tree*/
	tree->root = insert(tree->root, 1);
	tree->root = insert(tree->root, 2);	
	tree->root = insert(tree->root, 3);
	tree->root = insert(tree->root, 4);
	tree->root = insert(tree->root, 512);
	tree->root = insert(tree->root, 6123);
	tree->root = insert(tree->root, 7);
	tree->root = insert(tree->root, 7123);

	/* preorder of the tree */
	preOrder(tree->root);
	cout << endl;
	preOrderWithoutRecur(tree->root);
	cout << endl;
	
	/* Inorder of the tree */
	inOrder(tree->root);
	cout << endl;
	inOrderWithoutRecur(tree->root);
	cout << endl;

	/* postorder of the Binary Tree */
	postOrder(tree->root);
	cout << endl;
	postOrderWithoutRecur(tree->root);
	cout << endl;

	/* Level Order Traversal of the tree */
	levelOrderTraversal(tree->root);
	cout << endl;

	/* Max Element in the Tree */
	cout << "Max Value:- " << maxElementInTree(tree->root) << endl;
	cout << "Max Value without recursion:- " << maxElementWithoutRecur(tree->root) << endl;

	/*Search in the Tree */
	cout << search(tree->root, 7123) << endl;
	cout << searchWithoutRecur(tree->root, 7) << endl;

	/*Number of nodes in the tree */
	cout << "Size of the tree is:- " << sizeOfTree(tree->root) << endl;
	cout << "Size of the Tree without recursion:- " << sizeOfTreeWithoutRecur(tree->root) << endl;

	/*Print the tree in the reverse order*/
	printInReverseOrder(tree->root);
	cout <<endl;

	/*delete the Tree*/
	/*deleteTree(tree->root);*/
}
