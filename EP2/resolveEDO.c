#include "edo.h"
#include "edo_aux.h"
#include "utils.h"
#include <stdio.h>

void main() {

    EDo *hype;

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
    scanf("%f %f", &hype->a, &hype->b);
    scanf("%f %f", &hype->ya, &hype->yb);
    scanf("%f %f", &hype->p, &hype->q);
    scanf("%f %f %f %f", &hype->r1, &hype->r2, &hype->r3, &hype->r4);
    Tridiag *tri;
    tri = genTridiag(hype);
    prnEDOsl(hype);
    prnSL(*tri);
    printf("\n\n\n\n\n");
    fatLUTridiag(tri);
    prnSL(*tri);
}
