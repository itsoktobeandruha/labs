#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
#include "strsort.h"
#include <time.h>

//BEFORE YOU START! IF YOU WANT TO SEE SORTED TEXT, PLEASE VISIT SORT.C -> char** AddAndSortAndPrint -> AND TURN ON PRINT!

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int caseChoose;
	if (argc > 1)
		caseChoose = 2;
	else
	{
		printf("get text from file --type 1\n get text from files inside the file --type 3");
		scanf_s("%d", &caseChoose);
	}
	system("cls");
	if ((caseChoose > 3) || (caseChoose < 1))
	{
		printf("Wrong number");
		return 0;
	}
	switch (caseChoose)
	{
	case 1: //this case opens input.txt
	{
		FILE* A;
		fopen_s(&A, "input.txt", "r");
		char** fulltext = NULL;
		time_t t2 = time(NULL);
		fulltext = AddAndSortAndPrint(fulltext, A, 1, 0);
		time_t t3 = time(NULL);
		double time_in_seconds = difftime(t2, t3);
		printf("prog required %f seconds\n", time_in_seconds);
		fclose(A);
		break;
	}
	case 2: //in case 2 we get file name from console
	{
		printf("Opening file -> %s\n", argv[1]);
		FILE* B;
		fopen_s(&B, argv[1], "r");
		char** fulltext = NULL;
		time_t t4 = time(NULL);
		fulltext = AddAndSortAndPrint(fulltext, B, 2, 0);
		time_t t5 = time(NULL);
		double time_in_seconds = difftime(t4, t5);
		printf("prog required %f seconds\n", time_in_seconds);
		fclose(B);
		break;
	}
	case 3: //in this case we get file names from different file
	{
		printf("Opening file -> files.txt\n");
		char** fulltext = NULL;
		time_t t0 = time(NULL);
		detectTXTfiles(fulltext);
		time_t t1 = time(NULL);
		double time_in_seconds = difftime(t1, t0);
		printf("prog required %f seconds\n", time_in_seconds);
		free(fulltext);
		break;
	}
	}
	system("PAUSE");
	return 0;
}