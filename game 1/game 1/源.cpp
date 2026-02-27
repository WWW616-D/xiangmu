#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"raylib.h"
void kill (int** nums,int i,int j)
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
	InitWindow(1000, 800, "棋盘");
	SetTargetFPS(60);
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
	printf("%d", count);
}	
int main()
{
	Eight_Queens();
	return 0;
}