#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

struct node {
	int value;
	struct node* next;
};

struct list {
	struct node* head;
};

Node* newNode(int value) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->value = value;
	return node;
}

void insert(List* list, int value) {
	if(!list->head) {
		list->head = newNode(value);
		return;
	}
	Node* runner = list->head;

	while(runner->next != NULL) {
		runner = runner->next; 	
	}
	runner->next = newNode(value);
}

void printList(List* list) {
	Node* runner = list->head;
	while(runner != NULL) {
		printf("%d--->", runner->value);
		runner = runner->next;
	}
	printf("\n");
}