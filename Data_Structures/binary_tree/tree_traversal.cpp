#include "tree_utils.cpp"
#include <stack>

void inOrder(Node* root) {
	if(root) {
		inOrder(root->left);
		cout << root->data << "--->";
		inOrder(root->right);
	}
}

void inOrderWithoutRecur(Node* root) {
	stack<Node*> s;

	while(1) {
		while(root != NULL) {
			s.push(root);
			root = root->left;
		}

		if(s.empty()) break;
		root = s.top();
		cout << root->data << "--->";
		s.pop();
		root = root->right; 
	}
}
 
void preOrder(Node* root) {
	if(root) {
		cout << root->data << "--->";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void preOrderWithoutRecur(Node* root) {
	stack<Node*> s;

	while(1) {
		while (root != NULL) {
			cout << root->data << "--->";
			s.push(root);
			root = root->left;
		}

		if(s.empty()) break;

		root = s.top(); s.pop();

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

void postOrderWithoutRecur(Node* root) {
	stack<Node*> s1, s2;
	if(!root) return;
	s1.push(root);

	while(!s1.empty()){
		root = s1.top(); s1.pop();
		s2.push(root);

		if(root->left) s1.push(root->left);
		if(root->right) s1.push(root->right);
	}

	while(!s2.empty()){
		cout << s2.top()->data << "--->";
		s2.pop();
	}
}

int main(void) {
	Tree* tree = new Tree;

	tree->root = insert(tree->root, 1);
	tree->root = insert(tree->root, 2);
	tree->root = insert(tree->root, 3);
	tree->root = insert(tree->root, 4);
	tree->root = insert(tree->root, 5);
	tree->root = insert(tree->root, 6);
	tree->root = insert(tree->root, 7);

	inOrder(tree->root);
	cout << endl;

	inOrderWithoutRecur(tree->root);
	cout << endl;

	preOrder(tree->root);
	cout << endl;

	preOrderWithoutRecur(tree->root);
	cout << endl;

	postOrder(tree->root);
	cout << endl;

	postOrderWithoutRecur(tree->root);
	cout << endl;
	return 0;
}