/*
 * ssor.c
 * Andreas Bülling, 2012
 * Gauss-Seidel using over-relaxation for faster convergence
 */

#include <stdio.h>
#include <math.h>

#include "Gotoblas2/common.h"
#include "cblas.h"

#include "odf983.h"

void ssor_dummy(double** A, double* b, double* x, int n, double w, double tol){
  int i, j, k;
  double s, err, x_old;

  for(k = 0; ; k++){
    err = 0;
    //printf("%lf\n", x[0]);
    for(i = 0; i < n; i++){
      s = 0;
      for(j = 0; j < i; j++){
	s += A[i][j] * x[j];
      }
      for(j = i + 1; j < n; j++){
	s += A[i][j] * x[j];
      }
      x_old = x[i];
      x[i] = (1 - w) * x[i] + w / A[i][i] * (b[i] - s);
      err += fabs(x_old - x[i]);
    }
    if(err / n < tol) break;
    //conv check...
  }
}

void ssor(double** A, double* b, double* x, int n, double w, double tol){
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
