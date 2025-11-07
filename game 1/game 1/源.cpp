#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	srand(time(NULL));
	initgraph(1280, 800);
	settextcolor(YELLOW);
	settextstyle(100, 0, L"宋体");
	setorigin(0, 800);
	outtextxy(300, -400, L"我的第一个游戏");
	setaspectratio(1, -1);
	for (int i=0;i<10000;i++)
	{
		int x = rand() % 1280 + 1;
		int y = rand() % 800 + 1;
		putpixel(x, y, CYAN);
	}
	for (int i = 0; i < 150; i++)
	{
		circle(i * 13, i * 8, 10);
		circle(1280 - i * 13, i * 8, 10);
		
	}
	_getch();
	closegraph();
	printf("hello world");
	return 0;
}