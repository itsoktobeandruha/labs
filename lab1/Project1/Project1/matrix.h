#ifndef _MATRIX_H
#define _MATRIX_H

struct Matrix
{
	int** mass;
	int str, col;
	int size;
};
typedef struct Matrix matrix;
void printmatrix(matrix printedmatrix);
errno_t checkmatrix(FILE*);
matrix getRandomMatrix(matrix A, int n);
int** creatematrix(int);
matrix getmatrix(FILE*);
void deleteSTRINGSandCOL(int** matrix, int size, int row, int col, int** newMatrix);
int matrixDet(int** matrix, int size);

#endif