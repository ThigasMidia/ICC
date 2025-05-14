#ifndef __EDO_AUX_H__
#define __EDO_AUX_H__

//Transforma uma matriz tridiagonal em uma matriz LU
void transformaLUT(Tridiag *A);

//Faz retrossubstituicao da matriz L com o vetor B, obtendo o resultado do vetor Y
void lowerRetrossubs(Tridiag *L, real_t *Y);
//Faz retrossubstituicao da matriz U com o resultado Y, obtendo o resultado do vetor X
void upperRetrossubs(Tridiag *U, real_t *X);
//junta lower e upper retrossubs em uma unica funcao
void fatoracaoLUT(Tridiag *A, real_t *X);

#endif
