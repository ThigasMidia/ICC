#ifndef __SL_AUX_H__
#define __SL_AUX_H__

#define MAXIT 50
#include "utils.h"

typedef struct {
    real_t **A;
    real_t *b;
    int_t ordem;
} SL;

SL constroiSistema();
SL copiaSistema(SL copiado);
void destroiSistema(SL sistema);

void trocaLinha(SL sistema, int_t indice, int_t pivo);
int_t encontraMax(SL sistema, int_t comeco);
void pivotamento(SL sistema, int_t i);

void retrossubs(SL sistema, real_t *x);
void calculaResiduo(SL sistema, real_t *x, real_t *r);

void eliminacaoGauss(SL sistema);
void gaussSeidel(SL sistema, real_t *x, int_t *it);

#endif
