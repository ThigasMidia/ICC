/* Constantes */

#define DBL_FIELD "%12.7lg"
#define SEP_RES "\n\n\n"

#define DEF_SIZE 128
#define BASE 32


#define ABS(num)  ((num) < 0.0 ? -(num) : (num))

/* Implementações  para matrizes e vetores */

typedef double ** MatPtr;
typedef double * MatRow;
typedef double * Vetor;

/* ----------- FUNÇÕES ---------------- */

MatPtr geraMatPtr (int m, int n, int zerar);
MatPtr geraMatPtrRow (int m, int n, int zerar);
MatRow geraMat (int m, int n, int zerar);
Vetor geraVetor (int n, int zerar);

void liberaMatPtr (MatPtr mPtr, int n);
void liberaMatPtrRow (MatPtr mPtr, int n);
void liberaVetor (void *vet);

void multMatPtrVet (MatPtr mat, Vetor v, int m, int n, Vetor res);
void prnMatPtr (MatPtr mat, int m, int n);

void multMatVet (MatRow mat, Vetor v, int m, int n, Vetor res);
void prnMat (MatRow mat, int m, int n);

void multMatMatPtr (MatPtr A, MatPtr B, int n, MatPtr C);
void multMatMat (MatRow A, MatRow B, int n, MatRow C);

void prnVetor (Vetor vet, int n);

