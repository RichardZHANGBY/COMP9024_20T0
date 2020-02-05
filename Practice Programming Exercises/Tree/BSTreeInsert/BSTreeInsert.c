
#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

BSTree BSTreeInsert(BSTree t, int val) {
	BSTree new = malloc(sizeof(struct BSTNode));
	new->value = val;
	new->left = NULL;
	new->right = NULL;

	if (t == NULL){
		return new;
	}


	BSTree curr = t;
	while (true){
		if (val < curr->value){
			if (curr->left == NULL){
				curr->left = new;
				return t;
			}
			else {
				curr = curr->left;
				continue;
			}		
		}
		else if (val > curr->value){
			if (curr->right == NULL){
				curr->right = new;
				return t;
			}
			else {
				curr = curr->right;
				continue;
			}		
		}
		else {
			return t;
		}
	}
}

