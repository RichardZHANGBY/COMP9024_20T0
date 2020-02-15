// Linked list interface ... COMP9024 19T3

//Modified by Mushan in 2020X0
//Linked list for string type

#include <stdbool.h>
#include <stdio.h>

typedef struct Node *List;

//Insert a word
List insertWord(List, char *str);
//Insert a url of a word
List insertUrl(List L, char *word, char *url);
//Search the position of a specific node and return the pointer
List inLL(List, char *str);
void freeLL(List);
//Print the linklist
void showLL(List);
//Print urls that contain a specific word
void showUrl(List);
//Write the linklist to a file
void writeLL(FILE*, List);
//Write the urls that contain a specific word to a file
void writeUrl(FILE*, List);