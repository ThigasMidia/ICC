#include <stdio.h>
#include <fenv.h>
#include <likwid.h>
#include "utils.h"
#include "edo.h"
#include "edo_aux.h"

/*Thiago José Barzotto - GRR20235687*/

//Transforma uma matriz tridiagonal em uma matriz LU
void transformaLUT(Tridiag *A) {
    fesetround(FE_DOWNWARD);
    real_t m;
        
    //Loop de transformacao. Calcula M, armazena em Di e altera a diagonal principal
    for(int i = 0; i < A->n-1; ++i) {
        m = A->Di[i] / A->D[i];
        A->Di[i] = m;
        A->D[i+1] -= m * A->Ds[i];
    }
}

//Faz retrossubs de L com o vetor B, obtendo Y
void lowerRetrossubs(Tridiag *L, real_t *Y) {
    fesetround(FE_DOWNWARD);
    int n = L->n;
    //Primeiro elemento de Y
    Y[0] = L->B[0];
    
    //Loop de retrossubs.
    for(int i = 1; i < n; ++i)
        Y[i] = L->B[i] - (L->Di[i-1] * Y[i-1]); 
    
}

void upperRetrossubs(Tridiag *U, real_t *X) {
    fesetround(FE_DOWNWARD);
    int n = U->n;
    //Último elemento de X
    X[n-1] = X[n-1] / U->D[n-1];
    
    //Loop de retrossubs
    for(int i = n-2; i >= 0; --i) 
        X[i] = (X[i] - (U->Ds[i] * X[i+1])) / U->D[i];

}

//Junta lower e upper com um mesmo vetor X
void fatoracaoLUT(Tridiag *A, real_t *X) {
    lowerRetrossubs(A, X);
    upperRetrossubs(A, X);
}
