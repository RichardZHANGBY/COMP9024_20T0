#include <stdio.h>

int main(void)
{
	int i, k, j;
	i = 7;
	j = 8;
	k = 9;
	printf("%d\n", (i + 10) % k / j);
}