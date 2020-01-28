
#include "list.h"

List listSetIntersection(List s1, List s2) {
	List ordereds1 = listSortedCopy(s1);
	List ordereds2 = listSortedCopy(s2);
	List s3 = newList();

	Node curr1 = ordereds1->head;
	Node curr2 = ordereds2->head;
	Node start = newNode(0);
	Node curr = start;

	while(curr1 != NULL && curr2 != NULL){

		printf("s1=%d,s2=%d\n", curr1->value, curr2->value);

		if(curr1->value == curr2->value ) {
			curr->next = newNode(curr2->value);
			curr = curr->next;
			curr2 = curr2->next;
			curr1 = curr1->next;
			continue;
		}

		if(curr2->value > curr1->value ) {
			curr1 = curr1->next;
			continue;
		}
		else{
			curr2 = curr2->next;
			continue;
		}

			
	}
	s3->head = start->next;
	return s3;
	
}
