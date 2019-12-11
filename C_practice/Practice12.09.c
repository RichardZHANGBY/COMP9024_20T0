#include <stdio.h>

double inner_product(const double *a, const double *b, int n);

int main(int argc, char *argv[]) {
	double a[2] = {1.5, 2.0}, b[2] = {2.0, 4.0};
	printf("%lf", inner_product(a, b, 2));
	
}

double inner_product(const double *a, const double *b, int n){
	double sum = 0;
	for (int i = 0; i < n; i++){
		sum += *(a + i) * *(b + i);
	}
	return sum;
}