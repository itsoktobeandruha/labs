#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <locale.h>
#include "strsort.h"

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
	case 1:
	{
		FILE* A;
		fopen_s(&A, "input.txt", "r");
		char** fulltext = NULL;
		fulltext = AddAndSortAndPrint(fulltext, A, 1, 0);
		fclose(A);
		system("PAUSE");
		return 0;
	}
	case 2:
	{
		printf("Opening file -> %s\n", argv[1]);
		FILE* B;
		fopen_s(&B, argv[1], "r");
		char** fulltext = NULL;
		fulltext = AddAndSortAndPrint(fulltext, B, 2, 0);
		fclose(B);
		system("PAUSE");
		return 1;
	}
	case 3:
	{
		printf("Opening file -> files.txt\n");
		char** fulltext = NULL;
		detectTXTfiles(fulltext);
		system("PAUSE");
	}
	}
}