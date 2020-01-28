
#include "list.h"

int listDeleteLargest(List l) {
	int largest = 0;
	Node previous = NULL, curr, nextnode;
	
	curr = l->head;
	largest = curr->value;
	nextnode = curr->next;
	
	while (curr->next != NULL){
		if (curr->next->value > largest){
			previous = curr;
			nextnode = curr->next->next;
			largest = curr->next->value;
		}
		curr = curr->next;
	}
	
	if (previous == NULL){
		l->head = nextnode;
	}
	else if (nextnode == NULL){
		previous->next = NULL;
	}
	else{
		previous->next = nextnode;
	}
	
	return largest;
}

