/*
 * Auxillary functions, mainly conversion of starage schemes for
 * matrices.
 *
 * Andreas Bülling, 2012
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "cblas.h"

void amv(int n, double* A, double* v, double* Av);

void amv(int n, double* A, double* v, double* Av){
  int i, j;
  double s ;

  for(i = 0; i < n; i++){
    s = 0;
    for(j = 0; j < n; j++){
      s += *(A + i +(n)*j) * v[j];
    }
    Av[i] = s;
  }
  
}

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
