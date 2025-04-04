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
