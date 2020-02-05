
#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t) {
	if (t == NULL){
		return NULL;
	}
	
	while (t->left != NULL){
		t = t->left;
	}
	return t;
}

