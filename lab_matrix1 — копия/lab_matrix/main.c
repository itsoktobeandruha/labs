#include <stdio.h>
#include "matrix.h"


int main()
{
	double det=1;
	FILE* A;
	int size;
	errno_t err = fopen_s(&A, "A.txt", "r");
	if (err)
	{
		printf_s("The file A was not opened\n");
		system("pause");
		return 1;
	}
	matrix a;
	err = checkmatrix(A);
	if (err)
	{
		printf_s("type matrix only\n");
		system("pause");
		return 1;
	}
	a = getmatrix(A);
	size = a.str;
	double finalDet;
	for (int i=0, j=1; i < (size - 1); i++, j++)
	{
		treugMatrixDet(a, size, i,j);
	}
	for (int i = 0; i < size; i++)
	{
		det *= a.mass[i][i];
	}
	finalDet = det;
	printf("%.0lf\n", finalDet);
	fclose(A);
	system("pause");
	return 0;
}