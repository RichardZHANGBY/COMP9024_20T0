#include <stdio.h>

int main(void)
{

	int GS1, GI, PC, IN, CD;

	printf("Enter ISBN:");
	scanf("%d-%d-%d-%d-%d", &GS1, &GI, &PC, &IN, &CD);

	printf("GS1 prefix: %d\n", GS1);
    printf("Group identifier: %d\n", GI);
    printf("Publisher code: %d\n", PC);
    printf("Item number: %d\n", IN);
    printf("Check digit: %d\n", CD);

    return 0;

}