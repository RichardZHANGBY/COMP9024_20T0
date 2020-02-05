
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
	if (t == NULL){
		return -1;
	}
    
	if (t->left == NULL && t->right == NULL){
		return 0;
	}

	if (TreeHeight(t->left) > TreeHeight(t->right)){
		return TreeHeight(t->left) + 1;
	}
	else {
		return TreeHeight(t->right) + 1;
	}
}

