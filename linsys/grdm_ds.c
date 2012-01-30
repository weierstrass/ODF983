/*
 * grdm_ds.c
 * Andreas Bülling, 2012
 * Implementation of the conjugate gradient method
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "cblas.h"

void grdm_ds(double* A, double* b, double* x, int n, double tol){
  double alpha, *d;
  r = (double*) malloc(n * sizeof(double));
  p = (double*) malloc(n * sizeof(double));
  tmp = (double*) malloc(n * sizeof(double));
  
  //set initial vals on p and r
  cblas_dcopy(n, b, 1, r, 1); // b - Ax_0 -> r
  cblas_dsymv(CblasRowMajor, CblasUpper, n, -1.0, A, n, x, 1, 1.0, r, 1);
  cblas_dcopy(n, r, 1, p, 1); // b - Ax_0 -> p

  while(1){
    //alpha_k = dot(r_k, r_k) / dot(p_k, p_k)_A
    cblas_dsymv(CblasRowMajor, CblasUpper, n, 1, A, n, p, 1, 0, tmp, 1);
    alpha = cblas_ddot(n, r, 1, r, 1) / cblas_ddot(n, p, 1, tmp, 1);
    
    //x_k+1 = x_k + alpha_k*p_k 
    cblas_daxpy(n, alpha, p, 1, x, 1);
    
    r_old_dot = cblas_ddot(n, r, 1, r, 1);

    //r_k+1 = r_k - alpha_k*A*p_k
    cblas_daxpy(n, -alpha, tmp, 1, r, 1);

    //break if residual is small enough
    if(cblas_dnrm2(n, r, 1) < tol) break;

    //beta_k = dot(r_k+1, r_k+1) / dot(r_k, r_k)
    beta = cblas_ddot(n, r, 1, r, 1) / r_old_dot;

    //p_k+1 = r_k+1 + beta_k*p_k
    cblas_dscal(n, beta, p, 1);
    cblas_daxpy(n, 1, r, 1, p, 1);
  }

  free(r);
  free(p);
  free(tmp);

}
