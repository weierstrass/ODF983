/*
 * Test file.
 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(){
	//printf("nu borjar det...\n");
	double **A;
	double *x, *b;
	int n = SIZE, i;

	//allocate mem
	A = (double**) malloc(n * sizeof(double*));
	for(i = 0; i < n; i++){
		A[i] = (double*) malloc(n * sizeof(double));
	}
	x = (double*) malloc(n * sizeof(double));
	b = (double*) malloc(n * sizeof(double));

	//set dummy vals...

	for(i = 0; i < n - 1; i++){
		A[i][i+1] = -1;
		A[i+1][i] = -1;
	}
	for(i = 0; i < n; i++){
		A[i][i] = 2;
		b[i] = 1;
		x[i] = 0;
	}

	ssor(A, b, x, n, 1.99);

	printf("%lf", x[0]);

	return 0;
}
