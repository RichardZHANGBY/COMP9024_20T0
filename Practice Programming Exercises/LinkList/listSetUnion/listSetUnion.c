
#include "list.h"

List listSetUnion(List s1, List s2) {
	List s3 = newList();
	
	if (s1->head == NULL){
		s3->head = s2->head;
		return s3;	
	}
	if (s2->head == NULL){
		s3->head = s1->head;
		return s3;	
	}
	
	List ordereds1 = listSortedCopy(s1);
	List ordereds2 = listSortedCopy(s2);
		
	if (ordereds1->head->value < ordereds2->head->value){
		s3->head = newNode(ordereds1->head->value);
	}
	else{
		s3->head = newNode(ordereds2->head->value);
	}

	Node curr1 = ordereds1->head;
	Node curr2 = ordereds2->head;
	Node curr3 = s3->head;

	while(curr1 != NULL || curr2 != NULL){

		if(curr1 == NULL || curr1->value >= curr2->value ) {
			if(curr3->value < curr2->value){
				curr3->next = newNode(curr2->value);
				curr3 = curr3->next;
			}
			curr2 = curr2->next;
			continue;
		}

		if(curr2 == NULL || curr2->value > curr1->value ) {
			if(curr3->value < curr1->value){
				curr3->next = newNode(curr1->value);
				curr3 = curr3->next;
			}
			curr1 = curr1->next;
			continue;
		}

		
	}

	freeList(ordereds1);
	freeList(ordereds2);
	return s3;


}
