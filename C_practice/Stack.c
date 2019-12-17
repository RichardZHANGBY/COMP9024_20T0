#include <assert.h>
#include "Stack.h"


typedef struct {
	int item[MAX_ITEM];
	int top;
} Intstack;

static Intstack stack;

void initstack(){
	stack.top = 0;
}

int isEmpty(){
	return stack.top == 0;
}

void push(int num){
	assert(stack.top < MAX_ITEM - 1);
	stack.item[stack.top++] = num;
}

int pop(){
	assert(stack.top > 0);
	return stack.item[--stack.top];
}