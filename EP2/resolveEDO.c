#include "edo.h"
#include "edo_aux.h"
#include "utils.h"
#include <stdio.h>

void main() {

    EDo hype;
    real_t *X;
    scanf("%d", &hype.n);
    X = calloc(hype.n, sizeof(real_t));
    scanf("%lf %lf", &hype.a, &hype.b);
    scanf("%lf %lf", &hype.ya, &hype.yb);
    scanf("%lf %lf", &hype.p, &hype.q);
    int i = 0;
    real_t Rs[400];
    while(scanf("%lf %lf %lf %lf", &Rs[i], &Rs[i+1], &Rs[i+2], &Rs[i+3]) == 4) {
        i += 4;
    }

    Tridiag *tri;
    tri = genTridiag(&hype);

    //LIKWID PARA FATORACAO LU
    transformaLUT(tri);

    rtime_t tempo;

    for(int j = 0; j < i; j = j+4) {
        hype.r1 = Rs[j];
        hype.r2 = Rs[j+1];
        hype.r3 = Rs[j+2];
        hype.r4 = Rs[j+3];
        if(j != 0)
            refazB(tri, &hype);
        prnEDOsl(&hype);
        tempo = timestamp();
        //LIKWID PARA RETROSSUBS
        fatoracaoLUT(tri, X);
        tempo = timestamp() - tempo;
        printf("\n\n");
        for(int i = 0; i < hype.n; i++)
            printf(FORMAT, X[i]);
        printf("\n");
        printf(FORMAT, tempo);
        printf("\n\n");
    }
}
