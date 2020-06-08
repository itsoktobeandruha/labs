#include "snake.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void addApple(Apple* apple)
{
	apple->x = (rand() % 39) + 1;
	apple->y = (rand() % 19) + 1;
}

void fieldCreator()
{
	for (int i = 1; i < 40; i++)
	{
		gotoxy(i, 0);
		printf("_");
		gotoxy(i, 20);
		printf("_");
	}

	for (int i = 1; i < 20; i++)
	{
		gotoxy(0, i);
		printf("|");
		gotoxy(40, i);
		printf("|");
	}

}

void printSnake(Snake* snake)
{
	while (snake != NULL)
	{
		gotoxy(snake->x, snake->y);
		printf("x");
		snake = snake->next;
	}
}

void tailRemover(Snake* snake)
{
	while (snake->next != NULL)
		snake = snake->next;
	gotoxy(snake->x, snake->y);
	printf(" ");
}

void snakeUpgrade(Snake* snake)
{
	Snake* tmp;
	while (snake->next != NULL)
		snake = snake->next;
	tmp = snake;
	snake->next = (Snake*)malloc(sizeof(Snake));
	snake = snake->next;
	snake->next = NULL;
	snake->previous = tmp;
}

void snakeGo(Snake* snake)
{
	Snake* snake_goes, * tmp;
	snake_goes = snake;

	while (snake_goes->next != NULL)
		snake_goes = snake_goes->next;

	while (snake_goes->previous != NULL)
	{
		tmp = snake_goes->previous;
		snake_goes->y = tmp->y;
		snake_goes->x = tmp->x;
		snake_goes = snake_goes->previous;
	}
}

void free_snake(Snake* snake)
{
	while (snake->next != NULL)
		snake = snake->next;

	while (snake->previous != NULL)
	{
		snake = snake->previous;
		free(snake->next);
	}
	free(snake);
}

void appleEaten(Apple* apple, Snake* snake)
{
	Snake* temp = snake;
	while (temp != NULL)
	{
		if (temp->x == apple->x && temp->y == apple->y)
		{
			addApple(apple);
			temp = snake;
		}
		temp = temp->next;
	}
}

void printApple(Apple* apple)
{
	gotoxy(apple->x, apple->y);
	printf("O");
}