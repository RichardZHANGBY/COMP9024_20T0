// Linked Flist interface ... COMP9024 19T3

//Modified by Mushan in 2020X0
//Linked list for float&&string type

#include <stdbool.h>
#include <stdio.h>

typedef struct FNode *Flist;

//Insert a url and pagerank
Flist finsertFNode(Flist L, char *str, float pagerank);
//Search a url and return the it's pointer
Flist finLL(Flist L, char *url);
void ffreeLL(Flist);
//If a url include a word, the pagerank of the url +1
void faddSelf(Flist L, char *str);
//Print the result of the search
void fshowUrl(Flist L, int n);

