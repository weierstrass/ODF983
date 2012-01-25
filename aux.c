/*
 * Auxillary functions, mainly conversion of starage schemes for
 * matrices.
 *
 * Andreas Bülling, 2012
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "Gotoblas2/common.h"
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
