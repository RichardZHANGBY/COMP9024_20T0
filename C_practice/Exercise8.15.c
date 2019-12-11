#include <stdio.h>

double median(double x, double y, double z);

int main(int argc, char *argv[]) {
	printf("%f", median(1.2, 3.6, 2.4));
}

double median(double x, double y, double z){
	double median = x;
	
	if ((y - x) * (y - z) <= 0){
		median = y;
	}
	if ((z - x) * (z - y) <= 0){
		median = z;
	}
	
	return median;
	
}
