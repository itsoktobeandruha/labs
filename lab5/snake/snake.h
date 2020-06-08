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

void addApple(Apple* apple);

void fieldCreator();

void printSnake(Snake* snake);

void tailRemover(Snake* snake);

void snakeUpgrade(Snake* snake);

void snakeGo(Snake* snake);

void free_snake(Snake* snake);

void appleEaten(Apple* apple, Snake* snake);

void printApple(Apple* apple);

#endif // !_SNAKE_H