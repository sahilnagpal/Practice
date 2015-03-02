#include "linked_list_utils.c"

void reverse(List* list) {
	Node* prev = NULL, *curr = list->head, *next = NULL;
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	list->head = prev;
}

Node* reverseGivenK(Node* head, int k) {
	Node* prev = NULL, *curr = head, *next = NULL;
	int count = 0;
	while(curr != NULL && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;	
	}
	if(next != NULL) {
		head->next = reverseGivenK(next, k); 
	}
	return prev;
}

int main(void) {
	int i;
	List* list = (List*)malloc(sizeof(List));
	for(i = 0; i < 10; i++)
		insert(list, 10 - i);
	printList(list);
	list->head = reverseGivenK(list->head, 4);
	printList(list);
}