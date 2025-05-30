#ifndef __EQDIFF_H__
#define __EQDIFF_H__

typedef double real_t;

#define FORMAT "%23.15e"

/*Thiago José Barzotto - GRR20235687*/

// Sistema linear Tri-diagonal
typedef struct {
  real_t *D, *Di, *Ds, *B;
  int n;
} Tridiag;

// Equação Diferencial Ordinária
typedef struct {
  int n; // número de pontos internos na malha
  real_t a, b; // intervalo
  real_t ya, yb; // condições contorno
  real_t p, q, r1, r2, r3, r4; // coeficientes EDO genérica
} EDo;

// Funções auxiliares

Tridiag *genTridiag (EDo *edoeq);
void liberaTridiag(Tridiag *sl);
void refazB(Tridiag *sl, EDo *edo);
int leEDO(real_t *X, real_t *R, EDo *EDO);
void prnEDOsl (EDo *edoeq);

#endif // __EQDIFF_H__

