#include <string.h>
#include <Windows.h>
#include <locale.h>
#include "strsort.h"
#include <time.h>

//next three functions we use to get sizes!
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
	free(a);
	fclose(anotherstart);
	return size;
}
int getSizeFordetectedTXT(FILE* anotherstarttxt)
{
	fopen_s(&anotherstarttxt, "files.txt", "r");
	char* a;
	int size1 = 0;
	a = (char*)malloc(255 * sizeof(char));
	while (!feof(anotherstarttxt))
	{
		fgets(a, 255, anotherstarttxt);
		size1++;
	}
	free(a);
	fclose(anotherstarttxt);
	return size1;
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
	free(a);
	return size;
}
//this function we use for quick sort!
/*int cmp(const void* a, const void* b) 
{
	return *(int*)a - *(int*)b; 
}*/
//in next funcion we sort and print sorted text

void myquicksort(char** a, int first, int last)
{
	char* string;
	string = (char*)malloc(255 * sizeof(char));
	int i = first, j = last;
	double x = strlen(a[(first + last) / 2]);
	do {
		while (strlen(a[i]) < x)
			i++;
		while (strlen(a[j]) > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				string = a[i];
				a[i] = a[j];
				a[j] = string;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		myquicksort(a, i, last);
	if (first < j)
		myquicksort(a, first, j);
}
char** AddAndSortAndPrint(char** fulltext, FILE* in, int caseChoose, int sizeifneeded)
{
	char comp(const char*, const char*);
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
	//get text
	for (int i = 0; i < size1; i++)
	{
		fulltext[i] = (char*)malloc(255 * sizeof(char));
		fgets(fulltext[i], 255, in);
	}
	fseek(in, 0, SEEK_SET);
	// THIS ONE IS A BUBBLE METHOD
	/*int* strsize;
	strsize = (int*)malloc(size1 * sizeof(int));
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
	}*/
	/// THIS ONE IS QUICK SORT (1 sec)!
	/*qsort(fulltext, size1, sizeof(char*), cmp);*/
	myquicksort(fulltext, 0,(size1-1)); //my own qsort works!!!!
	for (int i = 0; i < size1; i++)
	{
		printf("%s", fulltext[i]);                        ////PRINT
	}
	printf("\n");
	return fulltext;
}
//this function we use for case 3
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
		fulltextForTXT[i] = (char*)malloc(100 * sizeof(char));
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
	free(fulltext);
	free(filename);
	free(fulltextForTXT);
}
