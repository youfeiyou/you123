#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#define up 1
#define down 2
#define left 3
#define right 4
typedef struct SNACK
{
	int x;
	int y;
	struct SNACK *next;
}snack;
int add = 10, score, i, j, n = 0;

int direction = 2;


int end;
snack *head, *food, *q;
void gotoxy(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void map()
{
	for (i = 0; i < 62; i = i + 2)
	{

		gotoxy(i, 0);
		printf("■");
		gotoxy(i, 26);
		printf("■");

	}
	for (j = 0; j < 26; j = j + 1)
	{

		gotoxy(0, j);
		printf("■");

		gotoxy(60, j);
		printf("■");

	}
}
void snackbody()
{
	snack *tail;
	tail = (snack *)malloc(sizeof(struct SNACK));
	tail->x = 24, tail->y = 5;
	tail->next = NULL;
	for (i = 1; i < 4; i++)
	{
		head = (snack *)malloc(sizeof(struct SNACK));
		head->next = tail;
		head->x = 2 * i + 24;
		head->y = 5;
		tail = head;
	}

	while (tail != NULL)
	{
		gotoxy(tail->x, tail->y);

		printf("■");

		tail = tail->next;


	}
}







void createfood()
{
	srand((unsigned)time(NULL));
	food = (snack *)malloc(sizeof(struct SNACK));

	food->x = 25, food->y = 10;

	while ((food->x % 2) != 0)
	{
		food->x = rand() % 58 + 2;
	}
	food->y = rand() % 24 + 1;
	q = head;
	while (q != NULL)
	{
		if (q->x == food->x&&q->y == food->y)
		{

			free(food);
			createfood();
		}
		if (q->next == NULL)break;
		q = q->next;
	}

	gotoxy(food->x, food->y);

	printf("■");
}



void endgame()
{
	if (end == 1)
	{
		system("cls");
		system("cls");
		gotoxy(30, 10);
		printf("咬到自己");
		gotoxy(30, 11);
		printf("你的分数为:%d", score);
		gotoxy(30, 15);
	}
	if (end == 2)
	{
		system("cls");
		gotoxy(30, 10);
		printf("你撞墙了");
		gotoxy(30, 11);
		printf("你的分数为:%d", score);
		gotoxy(30, 15);
	}


}
int cantcrosswall()
{
	if (head->x == 0 || head->x == 60 || head->y == 0 || head->y == 25)

	{

		return 1;
	}
	return 0;
}
int biteself()
{
	snack *nexthead;
	nexthead = (snack *)malloc(sizeof(struct SNACK));
	nexthead = head->next;
	while (nexthead != NULL)
	{
		if (head->x == nexthead->x&&head->y == nexthead->y)
		{
			end = 1;
			return 1;
		}
		else

			nexthead = nexthead->next;
	}
	return 0;
}


void welcome()
{
	system("cls");
	for (i = 30; i < 60; i = i + 1)
	{

		gotoxy(i, 4);
		printf("*");
		gotoxy(i, 15);
		printf("*");

	}


	gotoxy(38, 6);
	printf("贪吃蛇游戏");
	gotoxy(35, 8);
	printf("请用↑↓→←操作游戏\n");
	gotoxy(35, 10);
	printf("请按空格键终止游戏\n");
	gotoxy(35, 12);
	printf("请按回车键开始游戏\n");
	gotoxy(70, 20);
	printf("by\n");
	gotoxy(70, 22);


	system("pause");

	system("cls");

}
void stop()
{
	if ((GetAsyncKeyState(VK_SPACE)))
	{
		while (1)
		{
			Sleep(1000);

			if ((GetAsyncKeyState(VK_SPACE)))
			{
				break;
			}
		}
	}
}
void snackmove()
{
	snack * nexthead;

	nexthead = (snack*)malloc(sizeof(snack));
	if (direction == 1)
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;
		if (nexthead->x == food->x && nexthead->y == food->y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createfood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (direction == 2)
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		if (nexthead->x == food->x && nexthead->y == food->y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createfood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}

	if (direction == 3)
	{
		nexthead->x = head->x - 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");;
				q = q->next;
			}
			score = score + add;
			createfood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (direction == 4)
	{
		nexthead->x = head->x + 2;
		nexthead->y = head->y;
		if (nexthead->x == food->x && nexthead->y == food->y)
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			score = score + add;
			createfood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			q = head;
			while (q->next->next != NULL)
			{
				gotoxy(q->x, q->y);
				printf("■");
				q = q->next;
			}
			gotoxy(q->next->x, q->next->y);
			printf(" ");
			free(q->next);
			q->next = NULL;
		}
	}
	if (biteself() == 1)
	{
		end = 1;
		endgame();
	}
	if (cantcrosswall() == 1)
	{
		end = 2;
		endgame();

	}

}

int speed()
{
	int time = 500;
	if (score > 30)
	{
		time = 250;
		n = 1;

	}
	if (score > 60)
	{
		time = 200;
		n = 2;
	}
	if (score > 100)
	{
		time = 150;
		n = 3;
	}
	if (score > 150)
	{
		time = 100;
		n = 4;
	}
	if (score > 220)
	{
		time = 50;
		n = 5;

	}
	return time;



}


void gameoprate()
{

	while (1)
	{
		gotoxy(65, 4);
		printf("你的等级：%d", n);
		gotoxy(65, 6);
		printf("每一次得分:%d", add);
		gotoxy(65, 8);
		printf("你的分数为:%d", score);
		gotoxy(65, 10);
		printf("请按↑↓←→操作游戏");
		gotoxy(65, 12);
		printf("请按空格建暂停游戏");


		if (GetAsyncKeyState(VK_UP) && direction != 2)



		{
			direction = 1;
		}
		else if (GetAsyncKeyState(VK_DOWN) && direction != 1)
		{
			direction = 2;
		}

		else if (GetAsyncKeyState(VK_LEFT) && direction != 4)
		{
			direction = 3;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && direction != 3)
		{
			direction = 4;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			stop();
		}
		Sleep(speed());
		snackmove();
		if (biteself() == 1 || cantcrosswall() == 1)
			break;
	}
}










int main()
{
	system("mode con cols=100 lines=30");
	welcome();
	map();
	snackbody();
	createfood();
	gameoprate();

	return 0;
}