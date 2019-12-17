#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int length, seed = 0;

    sscanf(argv[1], "%d", &length);
    sscanf(argv[2], "%d", &seed);

    //scanf("%d %d",&length, &seed);
    /*for (int i = 0; i < 26; i++) {
        printf("%c", i + 'a');
    }*/
    srand(seed);
    for (int i = 0; i < length; i++) {
        int newChar = rand() % 26;
        printf("%C", newChar + 'a');
    }
    return 0;
}