#include <stdio.h>
#include <math.h>
#include <float.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main () {
    real_t a, b;
    Polinomio pol;
    
    scanf("%d", &pol.grau);
    
    pol.p = malloc(sizeof(real_t) * (pol.grau+1));
    for (int i=pol.grau; i >=0; --i)
        scanf("%lf", &pol.p[i]);

    scanf("%lf %lf", &a, &b); // intervalo onde está uma das raizes.
    
    int it = 0;
    real_t raiz = 0;
    real_t erro;
    real_t tempo;

    printf("RAPIDO\n\n");
    
    //bisseccao rapida
    tempo = timestamp();
    erro = bisseccao(pol, a, b, 0, &it, &raiz, 1);
    tempo = timestamp() - tempo;
    printf("bissec %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = bisseccao(pol, a, b, 1, &it, &raiz, 1);
    tempo = timestamp() - tempo;
    printf("bissec %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = bisseccao(pol, a, b, 2, &it, &raiz, 1);
    tempo = timestamp() - tempo;
    printf("bissec %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);

    //newton-raphson rapido
    tempo = timestamp();
    erro = newtonRaphson(pol, 1, 0, &it, &raiz, 1);
    tempo = timestamp() - tempo;
    printf("newton %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = newtonRaphson(pol, 1, 1, &it, &raiz, 1);
    tempo = timestamp() - tempo;
    printf("newton %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = newtonRaphson(pol, 1, 2, &it, &raiz, 1);
    tempo = timestamp() - tempo;
    printf("newton %.15e %.15e %3d %.8e\n\n", raiz, erro, it, tempo);


    printf("LENTO\n\n");

    //bissecao lenta
    tempo = timestamp();
    erro = bisseccao(pol, a, b, 0, &it, &raiz, 0);
    tempo = timestamp() - tempo;
    printf("bissec %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = bisseccao(pol, a, b, 1, &it, &raiz, 0);
    tempo = timestamp() - tempo;
    printf("bissec %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = bisseccao(pol, a, b, 2, &it, &raiz, 0);
    tempo = timestamp() - tempo;
    printf("bissec %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);

    //newton-raphson lento
    tempo = timestamp();
    erro = newtonRaphson(pol, 1, 0, &it, &raiz, 0);
    tempo = timestamp() - tempo;
    printf("newton %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = newtonRaphson(pol, 1, 1, &it, &raiz, 0);
    tempo = timestamp() - tempo;
    printf("newton %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);
    tempo = timestamp();
    erro = newtonRaphson(pol, 1, 2, &it, &raiz, 0);
    tempo = timestamp() - tempo;
    printf("newton %.15e %.15e %3d %.8e\n", raiz, erro, it, tempo);

    free(pol.p);
    
    return 0;
}

