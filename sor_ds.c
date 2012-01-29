/*
 * sor_ds.c
 * Andreas Bülling, 2012
 * Gauss-Seidel using over-relaxation for faster convergence.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "common.h"
#include "cblas.h"

void sor_ds(double* A, double* b, double* x, int n, double w, double tol){
  int i;
  double err, x_old, *wa;
  wa = (double*) malloc(n * sizeof(double));
  for(i = 0; i < n; i++) wa[i] = w / *(A + i + n * i);

  while(1){
    err = 0;

    for(i = 0; i < n; i++){
      x_old = x[i];
      x[i] = x[i] + (b[i] - cblas_ddot(n, (A + n * i), 1, x, 1)) * wa[i];
      
      x_old = fabs(x_old - x[i]); 
      err +=  x_old * x_old;
    }
    //convergence check
    if(sqrt(err) < tol) break;
  }
  
  free(wa);

}

