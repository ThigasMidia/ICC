#include <stdio.h>
#include "utils.h"
#include "SL_aux.h"

int main() {
    
    real_t tempo;
    int_t it;
    SL sistema = constroiSistema();
    SL copia = copiaSistema(sistema);
    real_t *xEG, *xGS, *rEG, *rGS;
    xEG = malloc(sizeof(real_t) * sistema.ordem);
    xGS = malloc(sizeof(real_t) * sistema.ordem);
    rEG = malloc(sizeof(real_t) * sistema.ordem);
    rGS = malloc(sizeof(real_t) * sistema.ordem);
    for(int i = 0; i < sistema.ordem; i++)
        xGS[i] = 0.0;
    /*for(int i = 0; i < copia.ordem; i++) {
        for(int j = 0; j < copia.ordem; j++) 
            fprintf(stderr,"%f ", copia.A[i][j]);
        printf("%f\n", copia.b[i]);
    }
    printf("\n\n");*/
    
    tempo = timestamp();
    eliminacaoGauss(sistema);
    retrossubs(sistema, xEG);
    calculaResiduo(sistema, xEG, rEG);
    tempo = timestamp() - tempo;
    /*for(int i = 0; i < sistema.ordem; i++) {
        for(int j = 0; j < sistema.ordem; j++) 
            fprintf(stderr,"%f ",sistema.A[i][j]);
        printf("%f\n", sistema.b[i]);
    }
    printf("\n\n");*/

    printf("EG:\n%.8e ms\n", tempo);
    for(int i = 0; i < sistema.ordem; i++)
        printf("%.12e ", xEG[i]);
    printf("\n");
    for(int i = 0; i < sistema.ordem; i++)
        printf("%.12e ", rEG[i]);
    printf("\n");
    
    tempo = timestamp();
    gaussSeidel(copia, xGS, &it);
    calculaResiduo(copia, xGS, rGS);
    tempo = timestamp() - tempo;
    printf("GS: %ld\n%.8e ms\n", it, tempo);
    for(int i = 0; i < sistema.ordem; i++)
        printf("%.12e ", xGS[i]);
    printf("\n");
    for(int i = 0; i < sistema.ordem; i++)
        printf("%.12e ", rGS[i]);
    printf("\n");

    destroiSistema(sistema);
    destroiSistema(copia);
    return 0;
}
