// By Mushan, 20T0
//https://github.com/mushanshanshan
#include "list.h"

void reverseDLList(List l) {
	if (l != NULL && l->first != NULL) {
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

}

