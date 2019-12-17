#include <stdio.h>
#include <stdbool.h>

int is_palindrom(const char *massage);

int main(int argc, char *argv[]) {
	char massage[50];
	printf("Enter the massage:");
	fgets(massage, 50, stdin);
	if (is_palindrom(massage)){
		printf("Palindrome.");
	}
	else{
		printf("NOT");
	}
}

int is_palindrom(const char *massage){
	const char *p1 = massage, *p2 = massage;
	while(*p2++)
	;
	for (p2 -= 3; p1 < p2; p1++, p2--){
		if (*p1 != *p2){
			return false;
		}
	}
	return true;
}