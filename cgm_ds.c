/*
 * cgm_ds.c
 * Andreas B�lling, 2012
 * Implementation of the conjugate gradient method
 *
 */

#include <stdio.h>
#include <math.h>

#include "common.h"
#include "cblas.h"

void cgm_ds(double* A, double* b, double* x, int n, double tol){
  int k;
  double alpha, beta, *r, r_old_dot, *p, *tmp;
  r = (double*) malloc(n * sizeof(double));
  p = (double*) malloc(n * sizeof(double));
  tmp = (double*) malloc(n * sizeof(double));
  
  cblas_dcopy(n, b, 1, r, 1); // b -> r TODO fixa, eg b - Ax0
  cblas_dcopy(n, b, 1, p, 1); // b -> p

  for(k = 0; ; k++){
    //printf("k: %d, x[0] = %.15f\n", k, x[0]);
    cblas_dgemv(CblasRowMajor, CblasNoTrans, n, n, 1, A, n, p, 1, 0, tmp, 1);
    //cblas_dsymv(CblasRowMajor, CblasUpper, n, 1, A, n, p, 1, 0, tmp, 1);
    alpha = cblas_ddot(n, r, 1, r, 1) / cblas_ddot(n, p, 1, tmp, 1);
    //printf("alpha = %.15f\n", alpha);
    cblas_daxpy(n, alpha, p, 1, x, 1);

    r_old_dot = cblas_ddot(n, r, 1, r, 1);
    cblas_daxpy(n, -alpha, tmp, 1, r, 1);

    if(cblas_dnrm2(n, r, 1) < tol) break;

    beta = cblas_ddot(n, r, 1, r, 1) / r_old_dot;
    cblas_dscal(n, beta, p, 1);
    cblas_daxpy(n, 1, r, 1, p, 1);
  }
}
