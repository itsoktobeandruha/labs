#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "matrix.h"

void printmatrix(matrix printedmatrix)
{
	for (int i = 0; i < printedmatrix.str; i++)
	{
		for (int k = 0; k < printedmatrix.col; k++)              // for checks
			printf("%d ", printedmatrix.mass[i][k]);
		printf("\n");
	}
}

errno_t checkmatrix(FILE* F)
{
	char c;
	char t = ' ';
	while ((c = fgetc(F)) != EOF)
	{
		if (!((c == '-') || ((c >= '0') && (c <= '9')) || (c == ' ') || (c == '\n')))
			return 1;
		if (c == ' ' && c == t)
			return 1;
		if (c == '-' && (t != ' ' || t != '\n'))
			return 1;
		t = c;
	}
	fseek(F, 0, SEEK_SET);
	if (t == -1)
		return 1;
	int col_summ = 1, prev_col = -1;
	while ((c = fgetc(F)) != EOF)
	{
		if (c == ' ')
			col_summ++;
		if (c == '\n')
			if (col_summ != prev_col)
				if (prev_col != -1)
					return 1;
				else
				{
					prev_col = col_summ;
					col_summ = 1;
				}
			else
				col_summ = 1;
	}
	if (col_summ != prev_col)
		if (prev_col != -1)
			return 1;
		else
		{
			prev_col = col_summ;
			col_summ = 1;
		}
	else
		col_summ = 1;
	fseek(F, 0, SEEK_SET);
}


int** creatematrix(int size)
{
	int** mass = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
		mass[i] = (int*)calloc(size, sizeof(int));
	return mass;
}


matrix getmatrix(FILE* F)
{
	matrix M;
	char buf[256];
	char c;
	int ammount;
	M.size = 0;
	/*while (c = fgetc(F) != EOF)
	{
		if (c == '\n')
		{
			M.str++;
		}
		if ((c == ' ') && M.str < 2)
		{
			M.col++;
		}
	}*/
	while(!feof(F))
	{
		fgets(buf, 256, F);
		M.size++;
	}
	fseek(F, 0, SEEK_SET);
	M.mass = creatematrix(M.size);
	for (int count1 = 0; count1 < M.size; count1++)
		for (int count2 = 0; count2 < M.size; count2++)
			fscanf_s(F, "%d", &M.mass[count1][count2]);
	fseek(F, 0, SEEK_SET);

	return M;
}

matrix getRandomMatrix(matrix A, int n)
{
	matrix M;
	M.str = 1;
	M.col = 1;
	for (int i = 0; i < n; i++)
	{
		M.str++;
		M.col++;
	}
	M.mass = creatematrix(M.str, M.col);
	for (int count1 = 0; count1 < M.str; count1++)
		for (int count2 = 0; count2 < M.col; count2++)
			M.mass[count1][count2] = rand() % 10;
	return M;
}

void deleteSTRINGSandCOL(int** M, int size, int row, int col, int** newMatrix) 
{
		int offsetRow = 0; //Смещение индекса строки в матрице
		int offsetCol = 0; //Смещение индекса столбца в матрице
		for (int i = 0; i < size - 1; i++) {
			//Пропустить row-ую строку
			if (i == row) {
				offsetRow = 1; //Как только встретили строку, которую надо пропустить, делаем смещение для исходной матрицы
			}

			offsetCol = 0; //Обнулить смещение столбца
			for (int j = 0; j < size - 1; j++) {
				//Пропустить col-ый столбец
				if (j == col) {
					offsetCol = 1; //Встретили нужный столбец, проускаем его смещением
				}
				newMatrix[i][j] = M[i + offsetRow][j + offsetCol];
			}
		}
}
int matrixDet(int** matrix, int size)
{
	int det = 0;
	int degree = 1; 
	if (size == 1) {
		return matrix[0][0];
	}
	else if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	else {
		int** newMatrix;
		newMatrix = (int**)malloc((size-1) * sizeof(int*));
		for (int i = 0; i < size - 1; i++) 
		{
			newMatrix[i] = (int*)malloc((size - 1) * sizeof(int));
		}
		for (int j = 0; j < size; j++) {
			deleteSTRINGSandCOL(matrix, size, 0, j, newMatrix);
			det = det + (degree * matrix[0][j] * matrixDet(newMatrix, size - 1));
			degree = -degree;
		}
		for (int i = 0; i < size - 1; i++) {
			free(newMatrix[i]);
		}
		free(newMatrix);
	}
	return det;
}