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
int treugMatrixDet(matrix M, int n);
void printmatrix(matrix ok);


#endif // ! _MATRIX_H
