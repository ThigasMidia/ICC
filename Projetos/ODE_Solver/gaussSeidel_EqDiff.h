Tridiag *genTridiag (EDo *edoeq);
void gaussSeidel_3Diag (Tridiag *sl, real_t *Y, unsigned int maxiter, rtime_t *tTotal);
real_t normaL2_3Diag (Tridiag *sl, real_t *Y);

void gaussSeidel_EDO (EDo *edoeq, real_t *Y, unsigned int maxiter, rtime_t  *tTotal);
real_t normaL2_EDO (EDo *edoeq, real_t *Y);

void prnVetor (real_t *v, unsigned int n);
void prnTriDiagonal(Tridiag *sl);
void prnEDOsl (EDo *edoeq, int diagOnly);

