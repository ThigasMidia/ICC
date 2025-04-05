#include <stdio.h>

int main() {
    
    SL sistema = constroiSistema();
    printf("%d\n", sistema.ordem);
    for(int i = 0; i < sistema.ordem; i++) {
        for(int j = 0; j < sistema.ordem; i++) 
            printf("%.6e ", sistema.A[i][j]);
        printf("%.6e\n", sistema.b[i]);
    }
    printf("\n");

    destroiSistema(sistema);
    return 0;
}
