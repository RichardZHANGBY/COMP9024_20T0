
#include <stdlib.h>

#include "tree.h"

int countNode(Tree t){
	if(t == NULL){
		return 0;
	}
	return 1 + countNode(t->left) + countNode(t->right);
}

bool TreeIsPerfectlyBalanced(Tree t) {
	return t == NULL || (TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right) && countNode(t->left) - countNode(t->right) <=1 && countNode(t->left) - countNode(t->right) >=-1);
}

