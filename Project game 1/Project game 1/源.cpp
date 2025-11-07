#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	initgraph(640, 480);
	settextcolor(YELLOW);
	settextstyle(36, 0, "宋体");
	outtextxy(200, 200, "我的第一个游戏");
	getch();
	closegraph();
	printf("hello world");
}