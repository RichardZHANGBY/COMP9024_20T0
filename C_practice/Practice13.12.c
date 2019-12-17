#include <stdio.h>
#include <ctype.h>
#include <string.h>

void get_extension(const char *filename, char * extension);

int main(int argc, char *argv[]) {
	
	char filename[20] = "read_line.c", extension[20];
	get_extension(filename, extension);
	
	printf("filname:%s, extension:%s", filename, extension);
	
}

void get_extension(const char *filename, char *extension){
	while (*filename){
		if (*filename++ == '.'){
			strcpy(extension, filename);
			return;
		}
	}
	*extension = '\0';
}