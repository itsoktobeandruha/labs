#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "matrix.h"

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
	int col_summ=1, prev_col=-1;
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


int** creatematrix(int str, int col)
{
	double** mass = (double**)malloc(str*sizeof(double*));
	for (int i = 0; i < str; i++)
		mass[i] = (double*)malloc(col * sizeof(double));
	for (int k = 0; k < str; k++)
		for (int j = 0; j < col; j++)
			mass[k][j] = 0;
	return mass;
}


matrix getmatrix(FILE*F)
{
	matrix M;
	char c;
	int ammount;
	M.str = 1;
	M.col = 1;
	while ((c = fgetc(F)) != EOF)
	{
		if (c == '\n')
			M.str++;
		if ((c == ' ') && M.str<2) 
			M.col++;
	}
	fseek(F, 0, SEEK_SET);
	M.mass = creatematrix(M.str, M.col);
	for (int count1 = 0; count1 < M.str; count1++)
		for (int count2 = 0; count2 < M.col; count2++)
			fscanf_s(F, "%lf", &M.mass[count1][count2]);
	return M;
}

void printmatrix(matrix printedmatrix) 
{
	for (int i = 0; i < printedmatrix.str; i++)
	{
		for (int k = 0; k < printedmatrix.col; k++)              // for checks
			printf("%.1lf ", printedmatrix.mass[i][k]);
		printf("\n");
	}
}


int treugMatrixDet(matrix M, int n, int temp1, int temp2)
{
	double koef;
	double det = 1;
	for (int j = temp2; j < n; j++)
	{
		koef = M.mass[j][temp1] / M.mass[temp1][temp1];
		for (int i = temp1; i < n; i++)
		{
			M.mass[j][i] -= M.mass[temp1][i] * koef;
		}
	}
} 



matrix getRandomMatrix(matrix A, int n)
{
	matrix M;
	char c;
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
			M.mass[count1][count2]=rand() %10;
	return M;
}



