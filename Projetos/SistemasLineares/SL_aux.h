#ifndef __SL_AUX_H__
#define __SL_AUX_H__

#define MAXIT 50

typedef struct {
    real_t **A
    real_t *b
    int_t ordem;
} SL;

SL constroiSistema();
void destroiSistema(SL sistema);

void trocaLinha(SL sistema, int_t indice, int_t pivo);
int_t encontraMax(SL sistema, int_t comeco);
void pivotamento(SL sistema, int_t i);

void eliminacaoGauss(SL sistema);
void gaussSeidel(SL sistema);

#endif
