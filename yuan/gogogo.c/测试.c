#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int** createnums(int* len,int** col)
{
    printf("请输入二维数组的长度:\n");
    scanf("%d", len);
    *col = (int*)calloc(*len, sizeof(int));
    printf("你将输入一系列数来决定这个数组内部数组的长度:\n");
    for (int i=0;i<*len;i++)
    {
        scanf("%d", *col + i);
    }
    int** nums = (int**)malloc(*len*sizeof(int*));
    for (int i=0;i<*len;i++)
    {
        nums[i] = (int*)calloc(*(*col + i), sizeof(int));
    }
    printf("你将对这个二维数组赋值:\n");
    for (int i=0;i<*len;i++)
    {
        for (int j=0;j<*(*col+i);j++)
        {
            scanf("%d", &nums[i][j]);
        }
    }
    return nums;
}
