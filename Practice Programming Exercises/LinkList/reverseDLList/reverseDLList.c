
#include "list.h"

void reverseDLList(List l) {
	Node curr = l->first;
	Node temp;
	l->last = l->first;

	while(curr->next != NULL){
		temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;
		curr = temp;
	}
	curr->next = curr->prev;
	curr->prev = NULL;
	l->first = curr;
}

