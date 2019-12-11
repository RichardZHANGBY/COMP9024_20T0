#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = 0;



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
		exit(0);
	}
	else{
		stack[top++] = num;
	}
}

int pop(void){
	if (is_empty()){
		exit(0);
	}
	else{
		return stack[--top];
	}
}

int main(int argc, char *argv[]) {
	char ch;
	bool equal = true;
	
	printf("Enter an PRN expression:");
	do{
		ch = getchar();
		if (ch == ' '){
			continue;
		}
		switch (ch) {
			case '+':
				push(pop() + pop());
				break;
			case '-':
				push(-pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				push((int)((float)1 / pop() * pop()));
				break;
			case '=':
				printf("Value of expression: %d", pop());
				equal = false;
				break;
			default:
				push(ch - '1' + 1);
				break;
			
			
		}
		
	}while (equal);
}