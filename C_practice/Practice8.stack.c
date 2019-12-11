#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;

int main(int argc, char *argv[]) {
	
}

void make_empty(void){
	top = 0;
}

bool is_empty(void){
	return top == 0;
}

bool is_full(void){
	return top == STACK_SIZE;
}

void push(int num){
	if (is_full()){
		exit(0)
	}
	else{
		stack[top++] = num;
	}
}

int pop(void){
	if (is_empty()){
		exit(0)
	}
	else{
		return stack[--top];
	}
}