#include <stdio.h>
#include "utils.h"
#include "edo.h"
#include "edo_aux.h"

void transformaLUT(Tridiag *A) {
    real_t m;
    
    for(int i = 0; i < A->n-1; ++i) {
        m = A->Di[i] / A->D[i];
        A->Di[i] = m;
        A->D[i+1] -= m * A->Ds[i];
    }
}

void lowerRetrossubs(Tridiag *L, real_t *Y) {
    int n = L->n;
    Y[0] = L->B[0];

    for(int i = 1; i < n; ++i)
        Y[i] = L->B[i] - (L->Di[i-1] * Y[i-1]); 
    
}

void upperRetrossubs(Tridiag *U, real_t *X) {
    int n = U->n;
    X[n-1] = X[n-1] / U->D[n-1];

    for(int i = n-2; i >= 0; --i) 
        X[i] = (X[i] - (U->Ds[i] * X[i+1])) / U->D[i];

}

void fatoracaoLUT(Tridiag *A, real_t *X) {
    lowerRetrossubs(A, X);
    upperRetrossubs(A, X);
}
