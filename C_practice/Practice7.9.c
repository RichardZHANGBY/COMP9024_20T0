#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
	int hour, minute, offset;
	char apm;
	
	printf("Enter a 12-hour time:");
	scanf("%d:%d", &hour, &minute);
	scanf(" %c", &apm);
	
	offset = (toupper(apm) == 'P' ? 12 : 0);
	
	
	printf("24-hour time: %d:%d", hour + offset, minute);
}