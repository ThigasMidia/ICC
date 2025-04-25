#include "edo.h"
#include "edo_aux.h"
#include "utils.h"
#include <stdio.h>

void main() {

    EDo *hype;
    real_t *X;
    hype = malloc(sizeof(EDo));
    hype->n = 0;
    hype->a = 0;
    hype->b = 0;
    hype->ya = 0;
    hype->yb = 0;
    hype->p = 0;
    hype->q = 0;
    hype->r1 = 0;
    hype->r2 = 0;
    hype->r3 = 0;
    hype->r4 = 0;
    scanf("%d", &hype->n);
    X = calloc(hype->n, sizeof(real_t));
    scanf("%lf %lf", &hype->a, &hype->b);
    scanf("%lf %lf", &hype->ya, &hype->yb);
    scanf("%lf %lf", &hype->p, &hype->q);
    scanf("%lf %lf %lf %lf", &hype->r1, &hype->r2, &hype->r3, &hype->r4);
    Tridiag *tri;
    tri = genTridiag(hype);
    prnEDOsl(hype);
    prnSL(*tri);
    printf("\n\n\n\n\n");
    transformaLUT(tri);
    prnSL(*tri);
    fatoracaoLUT(tri, X);
    printf("\n\n");
    for(int i = 0; i < hype->n; i++)
        printf(FORMAT, X[i]);
    printf("\n\n");
}
