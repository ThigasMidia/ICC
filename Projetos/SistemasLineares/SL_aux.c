#include <stdio.h>
#include "SL_aux.h"
#include "utils.h"

void eliminacaoGauss(SL sistema) {
    for(int i = 0; i < sistema.ordem; i++) {
       pivotamento(sistema, i);

       for(int k=i+1; k < sistema.ordem; k++) {
            real_t m = sistema.A[k][i] / sistema.A[i][i];
            sistema.A[k][i] = 0.0;
            for(int j = i+1; j < sistema.ordem; j++) 
                sistema.A[k][j] -= sistema.A[i][j] * m;
            sistema.b[k] -= sistema.b[i] * m;
       }
    }
}

void retrossubs(SL sistema, real_t *x) {
    for(int i = sistema.ordem-1; i >= 0; i--) {
        x[i] = sistema.b[i];
            for(int j = i+1; j < sistema.ordem; j++)
                x[i] -= sistema.A[i][j] * x[j];
        x[i] /= sistema.A[i][i];
    }
}

SL constroiSistema() {
    SL sistema;
    scanf("%ld", &sistema.ordem);
    sistema.A = malloc(sizeof(real_t)*sistema.ordem);

    for(int i = 0;i < sistema.ordem;i++) 
        sistema.A[i] = malloc(sizeof(real_t)*sistema.ordem);
    sistema.b = malloc(sizeof(real_t)*sistema.ordem);
    
    for(int i = 0; i < sistema.ordem;i++) {
        for(int j = 0; j < sistema.ordem;j++) {
            scanf("%lf", &sistema.A[i][j]);
        }
        scanf("%lf", &sistema.b[i]);
    }

    return sistema;
}

void destroiSistema(SL sistema) { 
    for(int i = 0;i < sistema.ordem;i++) 
        free(sistema.A[i]);
    free(sistema.A);
    free(sistema.b);
}

void trocaLinha(SL sistema, int_t indice, int_t pivo) {
    real_t *aux = sistema.A[indice];
    sistema.A[indice] = sistema.A[pivo];
    sistema.A[pivo] = aux;
    real_t aux2 = sistema.b[indice];
    sistema.b[indice] = sistema.b[pivo];
    sistema.b[pivo] = aux2;
}

int_t encontraMax(SL sistema, int_t comeco) {
    int_t max = comeco;
    for(int i = comeco+1; i < sistema.ordem; i++) 
        if(ABS(sistema.A[i][comeco]) > ABS(sistema.A[max][comeco]))
            max = i;
    return max;
}

void pivotamento(SL sistema, int_t i) {
    int_t pivo = encontraMax(sistema, i);
    if(i != pivo)
        trocaLinha(sistema, i, pivo);
}
