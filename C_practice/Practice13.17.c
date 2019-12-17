#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool test_extension(const char *file_name, const char *extension);

int main(int argc, char *argv[]) {
	char file_name[20] = "book.txt", extension[10] = "TXT";
	printf("%d", test_extension(file_name, extension));
	
}

bool test_extension(const char *file_name, const char *extension){
	while (*file_name++ != '.')
	;
	while (*file_name++ != '\0' && *extension++ != '\0'){
		if (toupper(*file_name) != toupper(*extension)){
			return false;
		}
	}
	return true;
}

