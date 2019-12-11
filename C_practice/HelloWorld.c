#include <stdio.h>
int main(void)
{

	int heigh, length, width, volume;

	heigh = 8;
	length = 12;
	width = 10;
	volume = heigh * length * width;

	printf("Dimension: %dx%dx%d\n", length, width, heigh);
	printf("volume: %d\n", volume);
}