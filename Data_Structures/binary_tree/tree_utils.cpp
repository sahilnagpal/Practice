#include <iostream>
#include <queue>

using namespace std;

struct tree {
	struct node* root;
};

struct node {
	struct node* left, *right;
	int data;
};

typedef struct node Node;
typedef struct tree Tree;

Node* newNode(int value) {
	Node* node = new Node;
	node->left = node->right = NULL;
	node->data = value;
	return node;
}

Node* insert(Node* root, int value) {
	if(!root) {
		root = newNode(value);
		return root;
	}
	
	queue<Node*> q;
	q.push(root);

	Node* temp;
	while(!q.empty()) {
		temp = q.front();
		q.pop();

		if(!temp->left) { // root->left == NULL
			temp->left = newNode(value);
			return root;
		} else {
			q.push(temp->left);
		}

		if(!temp->right) {
			temp->right = newNode(value);
			return root;
		} else {
			q.push(temp->right);
		}
	}

}

