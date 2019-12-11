#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[]) {
	double x, y = 1, avg, oldy;
	
	printf("x：");
	scanf("%lf", &x);
	
	do{
		avg = (y + x/y) / 2;
		oldy = y;
		y = avg;
	} while (fabs(oldy - y) > (.00001f * y));
	
	printf("fabs: %lf; y:%lf", oldy, y);
	
}