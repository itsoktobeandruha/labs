#include "snake.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main()
{
	FILE* f;
	Snake* snake = (Snake*)malloc(sizeof(Snake));
	Snake* snakeMove;
	Snake* tmp;
	Apple* apple = (Apple*)malloc(sizeof(Apple));
	int score = 0;
	snake->next = NULL;
	snake->previous = NULL;
	snake->x = 20;
	snake->y = 10;
	char char1='Y', char2='Y';
	int gameOver=0;
	int time;
	char nick[20];
	char buffer[50];
	char bestPlayer[20];
	int bestScore;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	printf("You are welcome to my snake game! If you eat an apple -> delay = delay -10(game will be faster); Please, write your nickname (20 symbols) : \n");
	gets_s(nick, 20);
	printf("Also don't forget: PRESS 'W' 'A' 'S' 'D' TO PLAY THE GAME!\ninput start delay(10-1000ms):\n");
	scanf_s("%d", &time);
	system("cls");
	fieldCreator();
	addApple(apple);
	printApple(apple);
		while (gameOver == 0)
		{
			if (_kbhit())
				char1 = _getch();
			if (char1 == 'w' || char1 == 'a' || char1 == 's' || char1 == 'd')
				char2 = char1;

			switch (char2)
			{
			case 'w':
			{
				tailRemover(snake);
				snakeGo(snake);
				snake->y--;
				printSnake(snake);
				Sleep(time);
				break;
			}
			case 'a':
			{
				tailRemover(snake);
				snakeGo(snake);
				snake->x--;
				printSnake(snake);
				Sleep(time);
				break;
			}
			case 's':
			{
				tailRemover(snake);
				snakeGo(snake);
				snake->y++;
				printSnake(snake);
				Sleep(time);
				break;
			}
			case 'd':
			{
				tailRemover(snake);
				snakeGo(snake);
				snake->x++;
				printSnake(snake);
				Sleep(time);
				break;
			}
			}
			if (snake->x > 39 || snake->x < 1 || snake->y < 1 || snake->y > 19)
			{
				system("cls");
				printf("Game Over, your score is: %d\n", score);
				gameOver = 1;
				break;
			}
			if (snake->x == apple->x && snake->y == apple->y)
			{
				snakeUpgrade(snake, char1);
				addApple(apple);
				appleEaten(apple, snake);
				printApple(apple);
				score++;
				if (time >= 50)
					time -= 10;
			}
			snakeMove = snake;
			while (snakeMove->next != NULL)
			{
				snakeMove = snakeMove->next;
				if (snake->x == snakeMove->x && snake->y == snakeMove->y)
				{
					system("cls");
					printf("GG, your score: %d\n", score);
					gameOver = 1;
					break;
				}
			}
		}
	if (gameOver != 0)
	{
		fopen_s(&f, "A.txt", "r+");
		int flag = 0;
		while (!feof(f))
		{
			long g = ftell(f);
			fgets(buffer, 50, f);
			int i = strlen(buffer);
			while (!((int)buffer[i] >= 65 && (int)buffer[i] <= 90) && !((int)buffer[i] >= 97 && (int)buffer[i] <= 122))
			{
				i--;
			}
			buffer[i + 1] = '\0';
			if (strcmp(buffer, nick) == 0)
			{
				fseek(f, g, SEEK_SET);
				fprintf(f, "%s - %d\n", nick, score);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			fseek(f, 0, SEEK_END);
			fprintf("%s - %d\n", nick, score);
		}
		fclose(f);
		free_snake(snake);
		free(apple);
		system("pause");
	}
	return 0;
}