#include <stdio.h>
#include <ctype.h>

void remove_filename(char *url);

int main(int argc, char *argv[]) {
	char str[] = "http://www.knking.com/index.html";
	remove_filename(str);
	printf("%s", str);
	
}

void remove_filename(char *url){
	char *p;
	while (*url++ != '\0'){
		if (*url == '/'){
			p = url;
		}
	}
	*p = '\0';
}