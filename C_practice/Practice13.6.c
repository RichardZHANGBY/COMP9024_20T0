#include <stdio.h>
#include <ctype.h>

void censor(char str[], int n);

int main(int argc, char *argv[]) {
	char str[30] = "food fool";
	censor(str, 30);
	printf("%s", str);
}

void censor(char str[], int n){
	for (char *p = str; *p ; p++){
		if (*p == 'f' && *(p+1) == 'o' && *(p+2) == 'o'){
			*p = *(p+1) = *(p+2) = 'x';
		}
	}
	
}