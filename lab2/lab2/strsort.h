#include <stdio.h>

#ifndef _STRSORT_H
#define _STRSORT_H

int getSize(FILE*);
int getSizeFordetectedTXT(FILE*);
int getSizeforFinalTXT(FILE*, char*);
char** AddAndSortAndPrint(char**, FILE*, int, int);
void detectTXTfiles(char**);

#endif
