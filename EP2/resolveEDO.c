#include "edo.h"
#include "edo_aux.h"
#include "utils.h"
#include <stdio.h>
#include <likwid.h>

void main() {
    LIKWID_MARKER_INIT;

    EDo EDO;
    real_t *X;
    real_t *Rs;
    scanf("%d", &EDO.n);
    X = calloc(EDO.n, sizeof(real_t));
    Rs = calloc(400, sizeof(real_t));
    int i = leEDO(X, Rs, &EDO);

    Tridiag *tri;
    tri = genTridiag(&EDO);

    LIKWID_MARKER_START("LU");
    transformaLUT(tri);
    LIKWID_MARKER_STOP("LU");

    rtime_t tempo;
    char nome[5];
    for(int j = 0; j < i; j = j+4) {
        sprintf(nome, "EDO%d", j/4);
        EDO.r1 = Rs[j];
        EDO.r2 = Rs[j+1];
        EDO.r3 = Rs[j+2];
        EDO.r4 = Rs[j+3];

        if(j != 0)
            refazB(tri, &EDO);

        prnEDOsl(&EDO);

        LIKWID_MARKER_START(nome);
        tempo = timestamp();
        fatoracaoLUT(tri, X);
        tempo = timestamp() - tempo;
        LIKWID_MARKER_STOP(nome);

        printf("\n\n");
        for(int a = 0; a < EDO.n; a++)
            printf(FORMAT, X[a]);
        printf("\n");
        printf(FORMAT, tempo);
        printf("\n\n");
    }
    free(X);
    free(Rs);
    liberaTridiag(tri);
    LIKWID_MARKER_CLOSE;
}
