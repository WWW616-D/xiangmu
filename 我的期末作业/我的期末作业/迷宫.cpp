#include"works.h"
#include<math.h>
#include<string.h>
#include"raylib.h"
#define CELL_SIZE 280
typedef struct ways
{
	char way[25][2];
	char length;
}ways;
ways* results[10000];
int count = 0;
char map[5][5];
char visited[5][5] = { 0 };
void mapdfs(char map[][5],int i,int j,ways* result)
{
	if (i < 0 || j < 0 || i>4 || j>4)
		return;
	if (map[i][j]||visited[i][j])
		return;
	result->way[result->length][0] = i;
	result->way[result->length++][1] = j;
	visited[i][j] = 1;
	if (i==4&&j==4)
	{
		ways* newPath = (ways*)malloc(sizeof(ways));
		memcpy(newPath, result, sizeof(ways));
		results[count++] = newPath;
		visited[i][j] = 0;   
		result->length--;
		return;
	}
	if (i - 1 >= 0)
	{
		mapdfs(map, i - 1, j, result);
	}
	if (i + 1 < 5)
	{
		mapdfs(map, i + 1, j, result);
	}
	if (j - 1 >= 0)
	{
		mapdfs(map, i, j-1, result);
	}
	if (j + 1 < 5)
	{
		mapdfs(map, i, j+1, result);
	}
	if (i - 1 >= 0 && j - 1 >= 0)
	{
		if (!(map[i-1][j]&&map[i][j-1]))
			mapdfs(map, i - 1, j - 1, result);
	}
	if (i + 1 < 5 && j - 1 >= 0)
	{
		if (!(map[i + 1][j] && map[i][j - 1]))
			mapdfs(map, i + 1, j - 1, result);
		
	}
	if (i - 1 >= 0 && j + 1 < 5)
	{
		if (!(map[i - 1][j] && map[i][j + 1]))
			mapdfs(map, i - 1, j + 1, result);
	}
	if (i + 1 < 5 && j + 1 < 5)
	{
		if (!(map[i + 1][j] && map[i][j + 1]))
			mapdfs(map, i + 1, j + 1, result);
	}
	visited[i][j] = 0;
	result->length--;
}
void Maze()
{
	printf("欢迎来到走迷宫游戏\n");
	FILE* file = fopen("D:\\代码\\我的期末作业\\迷宫.txt", "r");
	char c;
	int m = 0;
	int n = 0;
	while((c=fgetc(file))!=-1)
	{
		if (c == '\n')
			continue;
		map[m][n] = c - '0';
		n++;
		if (n==5)
		{
			n = 0;
			m++;
		}
		if (m == 5)
			break;
	}
	printf("现在展示迷宫图:\n");
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<5;j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("出口坐标为4,4\n");
	a:
	printf("请输入迷宫的起点:\n");
	int i;
	int j;
	scanf("%d %d",&i,&j);

	if (i<0||i>4||j<0||j>4||map[i][j] == 1)
	{
		printf("初始路径不可达,请重新选择\n");
		goto a;
	}
	ways* result=(ways*)malloc(sizeof(ways));
	result->length = 0;
	mapdfs(map, i, j,result);
}
void DrawPath(ways* path, Color color)
{
	if (path == NULL) return;
	Color semiColor = color;
	semiColor.a = 180; 
	for (int k = 0; k < path->length - 1; k++)
	{
		int i1 = path->way[k][0];
		int j1 = path->way[k][1];
		int i2 = path->way[k + 1][0];
		int j2 = path->way[k + 1][1];

		int x1 = j1 * CELL_SIZE + CELL_SIZE / 2;
		int y1 = i1 * CELL_SIZE + CELL_SIZE / 2;
		int x2 = j2 * CELL_SIZE + CELL_SIZE / 2;
		int y2 = i2 * CELL_SIZE + CELL_SIZE / 2;

		float dx = x2 - x1;
		float dy = y2 - y1;
		float length = sqrtf(dx * dx + dy * dy);

		int numPoints = (int)(length / 10) + 2;  

		for (int p = 0; p <= numPoints; p++)
		{
			float t = (float)p / numPoints;
			int x = x1 + (int)(dx * t);
			int y = y1 + (int)(dy * t);

			float radius = CELL_SIZE / 8;
			if (p == 0 || p == numPoints)
				radius = CELL_SIZE / 10; 

			DrawCircle(x, y, radius, color);

			DrawCircle(x + 2, y, radius / 2, color);
			DrawCircle(x - 2, y, radius / 2, color);
			DrawCircle(x, y + 2, radius / 2, color);
			DrawCircle(x, y - 2, radius / 2, color);
		}
	}
	for (int k = 0; k < path->length; k++)
	{
		int i = path->way[k][0];
		int j = path->way[k][1];
		int centerX = j * CELL_SIZE + CELL_SIZE / 2;
		int centerY = i * CELL_SIZE + CELL_SIZE / 2;
		DrawCircle(centerX, centerY, CELL_SIZE / 5, color);
	}
}
void DrawMaze()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int x = j * CELL_SIZE;
			int y = i * CELL_SIZE;
			if (map[i][j] == 1)
				DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, GRAY);  
			else
				DrawRectangle(x, y, CELL_SIZE, CELL_SIZE, LIGHTGRAY); 
			DrawRectangleLines(x, y, CELL_SIZE, CELL_SIZE, BLACK);
		}
	}
}
void MazeShow()
{
	Maze();
	if (count==0)
	{
		printf("没有可行路径\n");
		return;
	}
	printf("共有%d种路径\n", count);
	printf("输入任意字符开始生成该迷宫的所有路径\n用左右键来控制展示不同路径");
	system("pause");
	int length = 1400;
	int width = 1400;
	int currentPath = 0;
	InitWindow(length, width, "窗口标题");
	SetTargetFPS(60); 
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_RIGHT))
		{
			currentPath = (currentPath + 1) % count;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			currentPath = (currentPath - 1 + count) % count;
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawMaze();
		if (count > 0 && results[currentPath] != NULL)
		{			
			Color pathColor;
			if (currentPath % 3 == 0) pathColor = RED;
			else if (currentPath % 3 == 1) pathColor = BLUE;
			else if (currentPath % 3 == 2) pathColor = GREEN;

			DrawPath(results[currentPath], pathColor);

			if (results[currentPath]->length > 0)
			{
				int startI = results[currentPath]->way[0][0];
				int startJ = results[currentPath]->way[0][1];
				DrawText("start",
					startJ * CELL_SIZE + CELL_SIZE / 2 - 8,
					startI * CELL_SIZE + CELL_SIZE / 2 - 12,
					50, BLACK);
				int endI = results[currentPath]->way[results[currentPath]->length - 1][0];
				int endJ = results[currentPath]->way[results[currentPath]->length - 1][1];
				DrawText("end",
					endJ * CELL_SIZE + CELL_SIZE / 2 - 8,
					endI * CELL_SIZE + CELL_SIZE / 2 - 12,
					50, BLACK);
			}
		}
		EndDrawing();
	}
	CloseWindow();
}