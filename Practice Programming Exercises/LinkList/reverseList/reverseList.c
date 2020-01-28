
#include "list.h"

void listReverse(List l) {
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

