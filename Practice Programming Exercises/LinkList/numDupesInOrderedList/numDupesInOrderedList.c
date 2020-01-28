
#include "list.h"

int numDupesInOrderedList(List l) {
	Node curr = l->head;
	int num;

	while(curr->next != NULL){
		if ( curr->value == curr->next->value){
			num++;
		}
		curr = curr->next;
	}
	return num;
}

