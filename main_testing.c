/*
 * Test file.
 */
#include <stdio.h>
#include <stdlib.h>

#include "odf983.h"

#define SIZE 1000

int main(){
  double *A;
  double *x, *b;
  int n = SIZE, i, j;

  //allocate mem
  /* A = (double**) malloc(n * sizeof(double*)); */
/*   for(i = 0; i < n; i++){ */
/*     A[i] = (double*) malloc(n * sizeof(double)); */
  //}
  x = (double*) malloc(n * sizeof(double));
  b = (double*) malloc(n * sizeof(double));

  A = (double*) malloc(n * n * sizeof(double));

  //set dummy vals...
  for(i = 0; i < n-1; i++){
    *(A + i + (n)*(i+1)) = -1;
    *(A + i+1 + (n)*(i)) = -1;
  }

  for(i = 0; i < n; i++){
    *(A + i + n * i) = 3;
    b[i] = 1;
    x[i] = 0;
  }

  //ssor(A, b, x, n, 1.99, 1e-3);
  cgm_ds(A, b, x, n, 1e-3);
  printf("%.10f, %.10f\n", x[0], x[n-1]);

  return 0;
}
