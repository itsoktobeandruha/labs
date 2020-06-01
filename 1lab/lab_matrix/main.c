#include <stdio.h>
#include "matrix.h"
#include <time.h>
#include <stdbool.h>


int main()
{
    bool xd = false;
    double det = 1;
    double finalDet;
    FILE* A;
    matrix a;
    int size;
    errno_t err;
    int caseChoose;
    printf("If you want to print matrix --type 1\nCreate random matrix --type 2\nGet matrix from txt file --type 3\n");
    scanf_s("%d", &caseChoose);
    system("cls");
    if ((caseChoose > 3) && (caseChoose < 1))
    {
        printf("Wrong number");
        return 0;
    }
    switch (caseChoose)
    {
    case 1: // HERE I FIND DET FROM CONSOLE'S MATRIX!
    {
        printf("Type the str ammount ::  ");
        scanf_s("%d\n", &size);
        a.col = size;
        a.str = size;
        a.mass = creatematrix(a.col, a.str);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                i++;
                j++;
                printf("Type element [  %d  ][  %d  ] === ", i, j);
                i--;
                j--;
                scanf_s("%lf", &a.mass[i][j]);
            }
        }
        time_t start1, end1;
        start1 = time(NULL);
        det = treugMatrixDet(a, size, i, j);
        finalDet = det;
        end1 = time(NULL);
        printf("The det is --> %.0lf\n", finalDet);
        printf("Time elapsed --> %f\n", difftime(end1, start1));
        system("pause");
        printf("\n");
        break;
    }
    /*ñase 2: // HERE I FIND DET FROM RANDOM MATRIX!
    {
        time_t start2, end2;
        start2 = time(NULL);
        srand(time(NULL));
        size = 1 + rand() % 10;
        a.mass = creatematrix(size, size);
        a = getRandomMatrix(a, size);
        for (int i = 0, j = 1; i < (size - 1); i++, j++)
        {
            treugMatrixDet(a, size, i, j);
        }
        for (int i = 0; i < size; i++)
        {
            det *= a.mass[i][i];
        }
        finalDet = det;
        end2 = time(NULL);
        printf("The det is --> %.0lf\n", finalDet);
        printf("Time elapsed --> %f\n", difftime(end2, start2));
        system("PAUSE");
        break;
    }
    case 3: // HERE I FIND DET FROM FILE!
    {
        time_t start3, end3;
        start3 = time(NULL);
        err = fopen_s(&A, "A.txt", "r");
        if (err)
        {
            printf_s("The file A was not opened\n");
            system("pause");
            return 1;
        }
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
        for (int i = 0, j = 1; i < (size - 1); i++, j++)
        {
            treugMatrixDet(a, size, i, j);
        }
        for (int i = 0; i < size; i++)
        {
            det *= a.mass[i][i];
        }
        finalDet = det;
        end3 = time(NULL);
        printf("The det is --> %.0lf\n", finalDet);
        printf("Time elapsed --> %f\n", difftime(end3, start3));
        fclose(A);
        system("pause");
        return 0;
    }
    }
    */
    }
}
    
