
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t) {
	if (t == NULL){
		return 0;
	}
	else if (t->left == NULL && t->right == NULL){
		if (t->value % 2 != 0){
			return t->value;
		}
		else{
			return 0;
		}
	}
	else if (t->left == NULL){
		if (t->value % 2 != 0){
			return t->value + TreeSumOdds(t->right);
		}
		else{
			return TreeSumOdds(t->right);
		}
		
	}
	else if (t->right == NULL){
		if (t->value % 2 != 0){
			return t->value + TreeSumOdds(t->left);
		}
		else{
			return TreeSumOdds(t->left);
		}
	}
	else{
		if (t->value % 2 != 0){
			return t->value + TreeSumOdds(t->right) + TreeSumOdds(t->left);
		}
		else{
			return TreeSumOdds(t->right) + TreeSumOdds(t->left);
		}
	}
}

