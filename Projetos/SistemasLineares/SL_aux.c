#include <stdio.h>

SL constroiSistema() {
    SL sistema;
    scanf("%d", &sistema.ordem);
    sistema.A = malloc(sizeof(real_t)*sistema.ordem);

    for(int i = 0;i < sistema.ordem;i++) 
        sistema.A[i] = malloc(sizeof(real_t)*sistema.ordem);
    sistema.b = malloc(sizeof(real_t)*sistema.ordem);
    
    for(int i = 0; i < sistema.ordem;i++) {
        for(int j = 0; j < sistema.ordem)
            scanf("%lf", &sistema.A[i][j]);
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
}

int_t encontraMax(SL sistema, int_t comeco) {
    int_t max = comeco;
    for(int i = comeco+1; i < sistema.ordem; i++) 
        if(sistema.A[i][comeco] > max)
            max = sistema.A[i][comeco];
    return max;
}

void pivotamento(SL sistema, int_t i) {
    int_t pivo = encontraMax(sistema, i);
    if(i != pivo)
        trocaLinha(sistema, i, pivo);
}
