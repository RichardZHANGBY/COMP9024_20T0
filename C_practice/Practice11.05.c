#include <stdio.h>

void split_time(long total_sec, int *hr, int *min, int *sec);

int main(int argc, char *argv[]) {
	int hr, min, sec;
	
	split_time(43300, &hr, &min, &sec);
	
	printf("%d,%d,%d", hr, min, sec);
}

void split_time(long total_sec, int *hr, int *min, int *sec){
	*hr = total_sec / 3600;
	*min = (total_sec - 3600 * *hr) / 60;
	*sec = total_sec - 3600 * *hr - 60 * *min;
}