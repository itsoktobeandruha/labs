#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct
{
	double** mass;
	int str, col;
}matrix;
errno_t checkmatrix(FILE*);
int** creatematrix(int, int);
matrix getmatrix(FILE*);
int diagonalView(matrix M, int n, int temp1, int temp2);
double treugMatrixDet(matrix a, int size, int temp1, int temp2);
void printmatrix(matrix ok);
matrix getRandomMatrix(matrix A, int n);


#endif // ! _MATRIX_H
