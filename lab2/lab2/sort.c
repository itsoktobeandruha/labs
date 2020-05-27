#include <string.h>
#include <Windows.h>
#include <locale.h>
#include "strsort.h"

int getSize(FILE* anotherstart)
{
	fopen_s(&anotherstart, "input.txt", "r");
	char* a;
	int size = 0;
	a = (char*)malloc(255 * sizeof(char));
	while (!feof(anotherstart))
	{
		fgets(a, 255, anotherstart);
		size++;
	}
	fclose(anotherstart);
	return size;
}

int getSizeFordetectedTXT(FILE* anotherstarttxt)
{
	fopen_s(&anotherstarttxt, "files.txt", "r");
	char* a;
	int size = 0;
	a = (char*)malloc(255 * sizeof(char));
	while (!feof(anotherstarttxt))
	{
		fgets(a, 255, anotherstarttxt);
		size++;
	}
	fclose(anotherstarttxt);
	return size;
}

int getSizeforFinalTXT(FILE* anotherstart1, char* filename)
{
	fopen_s(&anotherstart1, filename, "r");
	char* a;
	int size = 0;
	a = (char*)malloc(255 * sizeof(char));
	while (!feof(anotherstart1))
	{
		fgets(a, 255, anotherstart1);
		size++;
	}
	return size;
}

char** AddAndSortAndPrint(char** fulltext, FILE* in, int caseChoose, int sizeifneeded)
{
	int temp1;
	char* string;
	int size1;
	if (caseChoose == 1 || caseChoose == 2)
		size1 = getSize(in);
	else
		size1 = sizeifneeded;
	string = (char*)malloc(255 * sizeof(char)); // string memory
	fulltext = (char**)malloc(size1 * sizeof(char*)); //fulltext memeory
	fseek(in, 0, SEEK_SET);
	for (int i = 0; i < size1; i++)
	{
		fulltext[i] = (char*)malloc(255 * sizeof(char));
		fgets(fulltext[i], 255, in);
	}
	fseek(in, 0, SEEK_SET);
	int* strsize;
	strsize = (int*)malloc(255 * sizeof(int));
	for (int i = 0; i < size1; i++)
	{
		strsize[i] = strlen(fulltext[i]);
		if (i != size1 - 1)
			strsize[i] = strsize[i] - 1;
	}
	for (int i = 0; i < size1 - 1; i++)            //bubble method! started from number sort, continued with strings
	{
		for (int j = (size1 - 1); j > i; j--)
		{
			if (strsize[j - 1] > strsize[j])
			{
				temp1 = strsize[j - 1];
				strsize[j - 1] = strsize[j];
				strsize[j] = temp1;
				string = fulltext[j - 1];
				fulltext[j - 1] = fulltext[j];
				fulltext[j] = string;
			}
		}
	}
	for (int i = 0; i < size1; i++)
	{
		//if (i == 1)
			//printf("\n");                 // sometimes it helps with \n problems, sometimes not
		printf("%s", fulltext[i]);
	}
	printf("\n");
	for (int i = 0; i < size1; i++)
	{
		printf("%d\n", strsize[i]);
	}
	return fulltext;
}

void detectTXTfiles(char** fulltext)
{
	FILE* start;
	fopen_s(&start, "files.txt", "r");
	char** fulltextForTXT;
	char* filename;
	int choosefile;
	int size1 = getSizeFordetectedTXT(start);
	char* string;
	string = (char*)malloc(255 * sizeof(char)); // string memory
	fulltextForTXT = (char**)malloc(size1 * sizeof(char*)); //fulltext memeory
	filename = (char*)malloc(size1 * sizeof(char));
	fseek(start, 0, SEEK_SET);
	for (int i = 0; i < size1; i++)
	{
		fulltextForTXT[i] = (char*)malloc(255 * sizeof(char));
		fgets(fulltextForTXT[i], 255, start);
	}
	fseek(start, 0, SEEK_SET);
	printf("We detected %d txt files with following names:\n", size1);
	for (int i = 0; i < size1; i++)
	{
		printf("%s  -> %d.\n", fulltextForTXT[i], i + 1);
	}
	printf("Choose which one you want to sort\n");
	scanf_s("%d", &choosefile);
	choosefile = choosefile - 1;
	fclose(start);
	FILE* finalone;
	if (choosefile != size1 - 1)
		fulltextForTXT[choosefile][strlen(fulltextForTXT[choosefile]) - 1] = 0;
	fopen_s(&finalone, fulltextForTXT[choosefile], "r");
	int anothersize = getSizeforFinalTXT(finalone, fulltextForTXT[choosefile]);
	fulltext = AddAndSortAndPrint(fulltext, finalone, 3, anothersize);
	fclose(finalone);
}
