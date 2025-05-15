#include "edo.h"
#include "edo_aux.h"
#include "utils.h"
#include <stdio.h>
#include <likwid.h>

void main() {
    LIKWID_MARKER_INIT;
    
    EDo EDO;
    //Declara vetor X de resultados
    real_t *X;
    //Declara vetor de coeficientes R
    real_t *Rs;
    scanf("%d", &EDO.n);
    //Aloca os vetores zerados
    X = calloc(EDO.n, sizeof(real_t));
    Rs = calloc(400, sizeof(real_t));
    //Le EDO e retorna quantidade de coeficientes R
    int i = leEDO(X, Rs, &EDO);

    Tridiag *tri;
    tri = genTridiag(&EDO);
   
    //Transforma a tridiagonal em uma LU
    LIKWID_MARKER_START("LU");
    transformaLUT(tri);
    LIKWID_MARKER_STOP("LU");

    rtime_t tempo;
    char nome[5];
    //Loop de processo dos diferentes coeficientes R
    for(int j = 0; j < i; j = j+4) {
        //Troca o nome do rotulo do LIKWID usado para calcular a fatoracao LU
        sprintf(nome, "EDO%d", j/4);
        EDO.r1 = Rs[j];
        EDO.r2 = Rs[j+1];
        EDO.r3 = Rs[j+2];
        EDO.r4 = Rs[j+3];
        
        //Refaz B se necessario
        if(j != 0)
            refazB(tri, &EDO);
        
        //Printa Tridiag
        prnEDOsl(&EDO);
        
        //Calcula a fatoracao LU
        LIKWID_MARKER_START(nome);
        tempo = timestamp();
        fatoracaoLUT(tri, X);
        tempo = timestamp() - tempo;
        LIKWID_MARKER_STOP(nome);
        
        //Printa o vetor de resultados
        printf("\n");
        for(int a = 0; a < EDO.n; a++)
            printf(FORMAT, X[a]);
        printf("\n");
        //Printa tempo
        printf(FORMAT, tempo);
        printf("\n\n");
    }
    //Libera memoria
    free(X);
    free(Rs);
    liberaTridiag(tri);
    LIKWID_MARKER_CLOSE;
}
