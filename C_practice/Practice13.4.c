#include <stdio.h>
#include <ctype.h>

int read_line_a(char str[], int n);
int read_line_b(char str[], int n);
int read_line_c(char str[], int n);
int read_line_d(char str[], int n);
void print_line(char str[]);

int main(int argc, char *argv[]) {
	char msg[20];
	printf("Enter a message: ");
	read_line_c(msg, 20);
	print_line(msg);
	return 0;
}

int read_line_a(char str[], int n){
	int ch, length = 0;
	
	while ((ch = getchar()) != '\n'){
		if (length == 0 && isspace(ch)){
			continue;
		}
		str[length++] = ch;
	}
	str[length] = '\0';
	return length;
}


int read_line_b(char str[], int n){
	int ch, length = 0;
	
	for (;!isspace(ch = getchar()) && length < n;length++){
		str[length] = ch;
	}
	str[++length] = '\0';
	return length;
}


int read_line_c(char str[], int n){
	int length = 0;
	
	for (;(str[length] = getchar()) != '\n'; length++)
	;
	str[++length] = '\0';
	return length;
}

int read_line_d(char str[], int n){
	int i, ch;

	for (i = 0; i < n - 1; i++) {
		ch = getchar();
		if (ch == '\n')
			break;
		str[i] = ch;
	}
	str[i] = '\0';
	return i;
}

void print_line(char str[])
{
	char *p;

	for (p = str; *p != '\0'; p++)
		printf("%c", *p);
}