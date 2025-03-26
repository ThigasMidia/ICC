#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz, int Rapido) {
    *it = 1;
    real_t *px, *dpx, x1;
    px = malloc(sizeof(real_t));
    dpx = malloc(sizeof(real_t));

    if(Rapido) 
        calcPolinomio_rapido(p, x0, px, dpx);
    else 
        calcPolinomio_lento(p, x0, px, dpx);

    x1 = x0 - ((*px)/(*dpx));

    int zero = 1;
    while(((!criterioParada && zero)||(criterioParada == 1 && zero)||(criterioParada == 2 && zero)) && (*it < MAXIT)) {
        *it = *it + 1;
        if(Rapido) 
            calcPolinomio_rapido(p, x1, px, dpx);
        else 
            calcPolinomio_lento(p, x1, px, dpx);
        
        x1 -= (*px)/(*dpx);
    }
    *raiz = x1;
    free(px);
    free(dpx);
    return 0;
}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz, int Rapido) {
    *it = 1;
    real_t xM, xM_old;
    real_t *px1, *px2, *dpx;
    px1 = malloc(sizeof(real_t));
    px2 = malloc(sizeof(real_t));
    dpx = malloc(sizeof(real_t));
    *px1 = 0;
    *px2 = 0;
    xM_old = 0;
    xM = (a+b)/2;
    if(Rapido) {
        calcPolinomio_rapido(p, a, px1, dpx);
        calcPolinomio_rapido(p, xM, px2, dpx);
    }
    else {
        calcPolinomio_lento(p, a, px1, dpx);
        calcPolinomio_lento(p, xM, px2, dpx);
    }

    if((*px1)*(*px2) < 0)
        b = xM;
    else if((*px1)*(*px2) > 0)
        a = xM;
    else
        return xM;

    int zero = 1;
    while(((!criterioParada && (fabs(xM - xM_old) > EPS))||(criterioParada == 1 && (xM > DBL_EPSILON))||(criterioParada == 2 && zero)) && (*it < MAXIT)) {
        *it = *it + 1;
        xM = (a+b)/2;
        if(Rapido) {
            calcPolinomio_rapido(p, a, px1, dpx);
            calcPolinomio_rapido(p, xM, px2, dpx);
            }
        else {
            calcPolinomio_lento(p, a, px1, dpx);
            calcPolinomio_lento(p, xM, px2, dpx);
        }

        if((*px1)*(*px2) < 0)
            b = xM;
        else if((*px1)*(*px2) > 0)
            a = xM;
    }
    *raiz = xM;
    free(px1);
    free(px2);
    free(dpx);
    return 0;
}


void calcPolinomio_rapido(Polinomio p, real_t x, real_t *px, real_t *dpx) { 
    real_t b = p.p[p.grau], c = b;
    for(int i = p.grau-1; i > 0; i--) {
        b = p.p[i] + b*x;
        c = b + c*x;
    }
    b = p.p[0] + b*x;
    *px = b;
    *dpx = c;
}


void calcPolinomio_lento(Polinomio p, real_t x, real_t *px, real_t *dpx) {
    *px = 0;
    *dpx = 0;

    for(int i = p.grau; i > 0; i--) {
        *px += p.p[i]*pow(x,i);
        *dpx += i*p.p[i]*pow(x,i-1);
    }
    *px += p.p[0]*pow(x,0);

    return;
}

int main() {
    Polinomio *p = malloc(sizeof(Polinomio));
    scanf("%d", &p->grau);
    p->p = malloc(sizeof(real_t)*(p->grau+1));
    for(int i = 0; i <= p->grau;i++) 
        scanf("%lf", &p->p[i]);
    real_t *px, *dpx;
    px = malloc(sizeof(size_t));
    dpx = malloc(sizeof(size_t));
    *px = *dpx = 0;
    calcPolinomio_rapido(*p,0.89,px,dpx);
    printf("POLI: %f\n", *px);
    printf("DERI: %f\n", *dpx);
    int *px1;
    px1 = malloc(sizeof(int));
    bisseccao(*p,0,3,0,px1,dpx,1); 
    printf("IT: %d\n", *px1);
    printf("RAIZ: %f\n", *dpx);
    newtonRaphson(*p, 3, 0, px1, dpx, 1);
    printf("IT: %d\n", *px1);
    printf("RAIZ: %f\n", *dpx);
    free(px1);
    free(px);
    free(dpx);
    free(p->p);
    free(p);
}




















