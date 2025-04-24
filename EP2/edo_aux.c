#include <stdio.h>
#include "utils.h"
#include "edo.h"
#include "edo_aux.h"

void fatLUTridiag(Tridiag *A) {
    real_t m;

    for(int i = 0; i < A->n-1; ++i) {
        m = A->Di[i] / A->D[i];
        A->Di[i] = m;
        A->D[i+1] -= m * A->Ds[i];
    }
}
