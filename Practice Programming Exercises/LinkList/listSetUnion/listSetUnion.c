
#include "list.h"

List insertNode(List l, int value){
	if(l->head == NULL){
		l->head = newNode(value);
		return l;
	}

	Node curr = l->head;
	while (curr->next != NULL){
		if (curr->value == value){
			return l;
		}
		curr = curr->next;
	}
	if (curr->value == value){
		return l;
	}
	curr->next = newNode(value);	
	return l;

}

List listSetUnion(List s1, List s2) {
	List s3 = newList();
	Node curr1 = s1->head;
	Node curr2 = s2->head;

	while (curr1 != NULL){
		s3 = insertNode(s3, curr1->value);
		curr1 = curr1->next;
	}
	
	while (curr2 != NULL){
		s3 = insertNode(s3, curr2->value);
		curr2 = curr2->next;
	} 
	return s3;
}
