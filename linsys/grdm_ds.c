/*
 * grdm_ds.c
 * Andreas Bülling, 2012
 * Implementation of the gradient method
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "cblas.h"

void grdm_ds(double* A, double* b, double* x, int n, double tol){
  double alpha, *d, *tmp;
  d = (double*) malloc(n * sizeof(double));
  tmp = (double*) malloc(n * sizeof(double));
  
  while(1){
    //printf("x[0] = %f\n", x[0]);
    //d_k = A*x_k - b
    cblas_dcopy(n, b, 1, d, 1);
    cblas_dsymv(CblasRowMajor, CblasUpper, n, 1, A, n, x, 1, -1.0, d, 1);

    //alpha_k = dot(d_k, d_k) / dot(d_k, d_k)_A
    cblas_dsymv(CblasRowMajor, CblasUpper, n, 1, A, n, d, 1, 0.0, tmp, 1);
    alpha = cblas_ddot(n, d, 1, d, 1) / cblas_ddot(n, d, 1, tmp, 1);

    cblas_dcopy(n, x, 1, tmp, 1);

    //x_k+1 = x_k + alpha_k * d_k
    cblas_daxpy(n, -alpha, d, 1, x, 1);
    cblas_daxpy(n, -1.0, x, 1, tmp, 1);

    //convergence check
    if(cblas_dnrm2(n, tmp, 1) < tol) break;
  }

  free(d);
  free(tmp);

}
