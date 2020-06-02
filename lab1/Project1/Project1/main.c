#include <stdio.h>
#include "matrix.h"
#include <time.h>
#include "matrix.h"

int main()
{
    int det1 = 0;
    FILE* A;
    matrix a;
    a.size = 0;
    errno_t err;
    int caseChoose;
    printf("If you want to fined det from file --type 1\nCreate random matrix --type 2\nGet matrix from console --type 3\n");
    scanf_s("%d", &caseChoose);
    system("cls");
    if ((caseChoose > 3) && (caseChoose < 1))
    {
        printf("Wrong number");
        return 0;
    }
    switch (caseChoose)
    {
 
    case 1: // HERE I FIND DET FROM FILE!
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
        det1 = matrixDet(a.mass, a.size);
        printf("The det is --> %d\n", det1);
        fclose(A);
        system("pause");
        return 0;
    }

    case 2: // HERE I FIND DET FROM RANDOM MATRIX!
    {
        time_t start2, end2;
        start2 = time(NULL);
        srand(time(NULL));
        a.mass = creatematrix(a.size);
        a = getRandomMatrix(a, a.size);
        det1 = matrixDet(a.mass, a.size);
        printf("The det is --> %d\n", det1);
        system("PAUSE");
        break;
    }
    
    case 3: // HERE I FIND DET FROM CONSOLE'S MATRIX!
    {
        int size;
        printf("Type the str ammount ::  ");
        scanf_s("%d", &size);
        printf("\n");
        a.size = size;
        a.mass = creatematrix(a.size);
        for (int i = 0; i < a.size; i++)
        {
            for (int j = 0; j < a.size; j++)
            {
                i++;
                j++;
                printf("Type element [  %d  ][  %d  ] === ", i, j);
                i--;
                j--;
                scanf_s("%d", &a.mass[i][j]);
            }
        }
        det1 = matrixDet(a.mass, a.size);
        printf("The det is --> %.0lf\n", det1);
        system("pause");
        printf("\n");
        break;
    }
    }
}