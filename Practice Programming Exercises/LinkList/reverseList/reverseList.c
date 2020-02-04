// By Mushan, 20T0
//https://github.com/mushanshanshan
#include "list.h"

void listReverse(List l) {
	if (l->head != NULL && l->head->next != NULL){
		Node curr = l->head;
		Node previous = NULL, nextnode = curr->next;
		while(nextnode !=NULL){
			nextnode = curr->next;
			curr->next = previous;
			previous = curr;
			curr = nextnode;
				
		}
		l->head = previous;
	}
}

