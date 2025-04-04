#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fenv.h>

#include "utils.h"
#include "DoubleType.h"
#include "ZeroFuncao.h"

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz, int Rapido) {
    fesetround(FE_DOWNWARD);
    *it = 0;
    real_t px, dpx;
    Double_t xM, xOld;

    xM.f = x0;
     do {
        (*it)++;
        xOld.f = xM.f;
        if(Rapido)
            calcPolinomio_rapido(p, xM.f, &px, &dpx);
        else 
            calcPolinomio_lento(p, xM.f, &px, &dpx);
        
        xM.f -= px/dpx;
    } while(((!criterioParada && fabs(xM.f - xOld.f) > EPS)||(criterioParada == 1 && fabs(px) > ZERO)||(criterioParada == 2 && fabs(xM.i - xOld.i) > ULPS)) && (*it < MAXIT));
    *raiz = xM.f;

    switch(criterioParada) {
        case 0:
            return fabs(xM.f - xOld.f);
        case 1:
            return fabs(px/dpx);
        default:
            return fabs(xM.i - xOld.i);
    }
}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz, int Rapido) {
    fesetround(FE_DOWNWARD);
    *it = 0;
    Double_t xM, xM_old;
    real_t px1, px2, dpx;
    px1 = 0;
    px2 = 0;
    xM.f = 0;

    do {
        (*it)++;
        xM_old.f = xM.f;
        xM.f = (a+b)/2;
        if(Rapido) {
            calcPolinomio_rapido(p, a, &px1, &dpx);
            calcPolinomio_rapido(p, xM.f, &px2, &dpx);
            }
        else {
            calcPolinomio_lento(p, a, &px1, &dpx);
            calcPolinomio_lento(p, xM.f, &px2, &dpx);
        }

        if(px1*px2 < 0)
            b = xM.f;
        else if(px1*px2 > 0)
            a = xM.f;
    } while(((!criterioParada && (fabs(xM.f - xM_old.f) > EPS))||(criterioParada == 1 && (fabs(px2) > ZERO))||(criterioParada == 2 && (fabs(xM.i - xM_old.i) > ULPS))) && (*it < MAXIT)); 
    *raiz = xM.f;
    
    switch(criterioParada) {
        case 0:
            return fabs(xM.f - xM_old.f);
        case 1:
            return fabs(a-b);
        default:
            return fabs(xM.i - xM_old.i);
    }
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
    *px = p.p[0];
    *dpx = 0;

    for(int i = p.grau; i > 0; i--) {
        *px += p.p[i]*pow(x,i);
        *dpx += i*p.p[i]*pow(x,i-1);
    }

    return;
}
