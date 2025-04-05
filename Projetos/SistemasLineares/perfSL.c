#include <stdio.h>
#include "utils.h"
#include "SL_aux.h"

int main() {
    
    SL sistema = constroiSistema();
    printf("%ld\n", sistema.ordem);
    for(int i = 0; i < sistema.ordem; i++) {
        for(int j = 0; j < sistema.ordem; j++) 
            fprintf(stderr,"%f ",sistema.A[i][j]);
        printf("%f\n", sistema.b[i]);
    }
    printf("\n\n");
    
    eliminacaoGauss(sistema);
    for(int i = 0; i < sistema.ordem; i++) {
        for(int j = 0; j < sistema.ordem; j++) 
            fprintf(stderr,"%f ",sistema.A[i][j]);
        printf("%f\n", sistema.b[i]);
    }

    printf("\n\n");

    real_t *x;
    x = malloc(sizeof(real_t) * sistema.ordem);
    retrossubs(sistema, x);
    for(int i = 0; i < sistema.ordem; i++)
        printf("%f ", x[i]);
    printf("\n");

    destroiSistema(sistema);
    return 0;
}
