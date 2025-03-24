#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t newtonRaphson (Polinomio p, real_t x0, int criterioParada, int *it, real_t *raiz)
{

}


// Retorna valor do erro quando método finalizou. Este valor depende de tipoErro
real_t bisseccao (Polinomio p, real_t a, real_t b, int criterioParada, int *it, real_t *raiz) {
    *it = 1;
    real_t xM;
    xM = (a+b)/2;
    if()

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
}




















