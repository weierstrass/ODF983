/*
 * sor_ds.c
 * Andreas Bülling, 2012
 * Gauss-Seidel using over-relaxation for faster convergence.
 */

#include <stdio.h>
#include <math.h>

#include "common.h"
#include "cblas.h"

void sor_ds(double** A, double* b, double* x, int n, double w, double tol){
  int i;
  double err, x_old;

  while(1){
    err = 0;

    for(i = 0; i < n; i++){
      x_old = x[i];
      x[i] = x[i] + (b[i] - cblas_ddot(n, A[i], 1, x, 1)) * w / A[i][i];
      err += fabs(x_old - x[i]);
    }
    //convergence check
    if(err / n < tol) break;
  }

}

