#include <stdio.h>
#include <ctype.h>

void capitalize(char str[], int l);
int read_line_c(char str[], int n);
void print_line(char str[]);

int main(int argc, char *argv[]) {
	char msg[20];
	printf("Enter a message: ");
	read_line_c(msg, 20);
	capitalize(msg, 20);
	print_line(msg);
	return 0;
}

int read_line_c(char str[], int n){
	int length = 0;
	
	for (;(str[length] = getchar()) != '\n'; length++)
	;
	str[++length] = '\0';
	return length;
}

void capitalize(char str[], int l){
	for (int i = 0; i < l; i++){
		if (str[i] <= 'z' && str[i] >= 'a'){
			str[i] = toupper(str[i]);
		}
	}
}

void print_line(char str[])
{
	char *p;

	for (p = str; *p != '\0'; p++)
		printf("%c", *p);
}