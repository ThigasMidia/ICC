#ifndef __EDO_AUX_H__
#define __EDO_AUX_H__

void transformaLUT(Tridiag *A);

void lowerRetrossubs(Tridiag *L, real_t *Y);
void upperRetrossubs(Tridiag *U, real_t *X);
void fatoracaoLUT(Tridiag *A, real_t *X);

#endif
