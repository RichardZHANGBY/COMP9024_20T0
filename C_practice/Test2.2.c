#include <stdio.h>

int main(void)
{
	float radius, volume;
	printf("Please enter the radius:\n");
	scanf("%f", &radius);

	volume = (4.0f/3.0f) * 3.141596254 * radius * radius * radius;

	printf("The volume is %.2f.\n", volume);

	return 0;





}