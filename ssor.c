/*
 * s_sor.c
 *
 *  Created on: 13 jan 2012
 *      Author: andreas bulling
 */

#include <stdio.h>

#include "odf983.h"

void ssor(double** A, double* b, double* x, int n, double w){
	int i, j, k;
	double s;

	for(k = 0; k < 10000; k++){
	  //printf("%lf\n", x[0]);
		for(i = 0; i < n; i++){
			s = 0;
			for(j = 0; j < i; j++){
				s += A[i][j] * x[j];
			}
			for(j = i + 1; j < n; j++){
				s += A[i][j] * x[j];
			}
			x[i] = (1 - w) * x[i] + w / A[i][i] * (b[i] - s);
		}
		//conv check...
	}

}
