#define _CRT_SECURE_NO_WARNINGS
#include"works.h"
#include<time.h>
#include<raylib.h>
int result[92][8];
void kill(int** nums, int i, int j)
{
	for (int a = 0; a < 8; a++)
	{
		if (a != i)
			nums[a][j]++;
		if (a != j)
			nums[i][a]++;
	}
	nums[i][j]++;
	int tempi = i - 1;
	int tempj = j - 1;
	while (tempi >= 0 && tempj >= 0)
	{
		nums[tempi][tempj]++;
		tempi--;
		tempj--;
	}
	tempi = i + 1;
	tempj = j + 1;
	while (tempi < 8 && tempj < 8)
	{
		nums[tempi][tempj]++;
		tempi++;
		tempj++;
	}
	tempi = i - 1;
	tempj = j + 1;
	while (tempi >= 0 && tempj < 8)
	{
		nums[tempi][tempj]++;
		tempi--;
		tempj++;
	}
	tempi = i + 1;
	tempj = j - 1;
	while (tempi < 8 && tempj >= 0)
	{
		nums[tempi][tempj]++;
		tempi++;
		tempj--;
	}
}
void killdown(int** nums, int i, int j)
{
	for (int a = 0; a < 8; a++)
	{
		if (a != i)
			nums[a][j]--;
		if (a != j)
			nums[i][a]--;
	}
	nums[i][j]--;
	int tempi = i - 1;
	int tempj = j - 1;
	while (tempi >= 0 && tempj >= 0)
	{
		nums[tempi][tempj]--;
		tempi--;
		tempj--;
	}
	tempi = i + 1;
	tempj = j + 1;
	while (tempi < 8 && tempj < 8)
	{
		nums[tempi][tempj]--;
		tempi++;
		tempj++;
	}
	tempi = i - 1;
	tempj = j + 1;
	while (tempi >= 0 && tempj < 8)
	{
		nums[tempi][tempj]--;
		tempi--;
		tempj++;
	}
	tempi = i + 1;
	tempj = j - 1;
	while (tempi < 8 && tempj >= 0)
	{
		nums[tempi][tempj]--;
		tempi++;
		tempj--;
	}
}
void start(int** plan, int** nums, int* num, int* count, int i, int j)
{
	if (i >= 8 || j >= 8)
		return;
	if (nums[i][j])
		return;
	plan[8 - *num][0] = i;
	plan[8 - *num][1] = j;
	(*num)--;
	kill(nums, i, j);
	if (*num > 0)
	{
		for (int currenti = i + 1; currenti < 8; currenti++)
		{
			for (int currentj = 0; currentj < 8; currentj++)
			{
				start(plan, nums, num, count, currenti, currentj);
			}
		}
		plan[8 - *num][0] = -1;
		plan[8 - *num][1] = -1;
	}
	else
	{
		for (int k = 0; k < 8; k++) 
		{
			result[*count][k] = plan[k][1];
		}
		(*count)++;
		/*printf("方案%d是:\n", *count);
		for (int k = 0; k < 8; k++)
		{
			printf("第%d个皇后,%d,%d\n", k + 1, plan[k][0], plan[k][1]);
		}*/
	}
	killdown(nums, i, j);
	(*num)++;
	return;
}
void Eight_Queens()
{
	/*InitWindow(1000, 800, "棋盘");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
	}*/
	int** nums = (int**)malloc(8 * sizeof(int*));
	for (int i = 0; i < 8; i++)
	{
		nums[i] = (int*)calloc(8, sizeof(int));
	}
	int count = 0;
	int num = 8;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int** plan = (int**)malloc(8 * sizeof(int*));
			for (int k = 0; k < 8; k++)
			{
				plan[k] = (int*)malloc(2 * sizeof(int));
				for (int l = 0; l < 2; l++)
				{
					plan[k][l] = -1;
				}
			}
			start(plan, nums, &num, &count, i, j);
			for (int k = 0; k < 8; k++)
			{
				free(plan[k]);
			}
			free(plan);
		}
	}
	
	
}
void EightQueensShow()
{
	printf("接下来将有画面展示八皇后的92种解法，点击任意键开始:\n演示过程种点击空格或左右箭头循环切换解法");
	system("pause");
	int len = 1400;
	int width = 1400;
	InitWindow(len, width, "八皇后棋盘");
	SetTargetFPS(60);
	Eight_Queens();
	const int boardSize = 8;
	const int cellSize = len / boardSize;
	Color lightColor = LIGHTGRAY;
	Color darkColor = DARKBROWN;
	Color borderColor = BLACK;
	int currentsolution = 0;
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int row = 0; row < boardSize; row++)
		{
			for (int col = 0; col < boardSize; col++)
			{
				int posX = col * cellSize;
				int posY = row * cellSize;
				Color currentColor = ((row + col) % 2 == 0) ? lightColor : darkColor;
				DrawRectangle(posX, posY, cellSize, cellSize, currentColor);
				DrawRectangleLines(posX, posY, cellSize, cellSize, borderColor);
			}
		}
		const char* titleText = "Eight Queens\nChessboard(8*8)";
		int textWidth = MeasureText(titleText, 30);
		DrawText(titleText, (len - textWidth) / 2 - 100, 10, 50, BLACK);
		for (int row = 0; row < boardSize; row++)
		{
			int queenCol = result[currentsolution][row];
			float centerX = queenCol * cellSize + cellSize / 2.0f;
			float centerY = row * cellSize + cellSize / 2.0f;
			float radius = cellSize * 0.35f;
			// 1. 红色主体
			DrawCircle(centerX, centerY, radius, RED);
			// 2. 深红色内圈
			DrawCircle(centerX, centerY, radius * 0.75f, MAROON);
			// 3. 白色皇冠符号 "Q"
			int textSize = radius * 1.2f;
			DrawText("Q", centerX - textSize / 4, centerY - textSize / 3, textSize, WHITE);
			// 4. 金色外框
			DrawCircleLines(centerX, centerY, radius, GOLD);
			DrawCircleLines(centerX, centerY, radius + 1, GOLD);
		}
		if (IsKeyPressed(KEY_SPACE))
		{
			currentsolution = (currentsolution + 1) % 92;
		}
		if (IsKeyPressed(KEY_RIGHT))
		{
			currentsolution = (currentsolution + 1) % 92;
		}
		if (IsKeyPressed(KEY_LEFT))
		{
			currentsolution = (currentsolution - 1) % 92;
			if (currentsolution < 0)
				currentsolution = 92 + currentsolution;
		}
		EndDrawing();
	}
	CloseWindow();
}
