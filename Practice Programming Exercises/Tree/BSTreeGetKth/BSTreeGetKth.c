
#include <stdlib.h>

#include "BSTree.h"

void searchKth(BSTree t, int *k, int *small){
	if(t != NULL){
		searchKth(t->left, k, small);
		if (*k == 0){
			*small =  t->value;
		}
		(*k)--;
		searchKth(t->right, k, small);
	}
}


int BSTreeGetKth(BSTree t, int k) {
	int smallest = -1;
	searchKth(t, &k, &smallest);
	return smallest;
}

