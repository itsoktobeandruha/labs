#ifndef _SNAKE_H
#define _SNAKE_H
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct
{
	int x;
	int y;
	struct Snake* next;
	struct Snake* previous;
} Snake;

typedef struct
{
	int x;
	int y;
} Apple;

void gotoxy(int, int);

void addApple(Apple*);

void fieldCreator();

void printSnake(Snake*);

void tailRemover(Snake*);

void snakeUpgrade(Snake*);

void snakeGo(Snake*);

void free_snake(Snake*);

void appleEaten(Apple*, Snake*) ;

void printApple(Apple*);

#endif // !_SNAKE_H