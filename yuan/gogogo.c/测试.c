#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* findAnagrams(char* s, char* p, int* returnSize)
{
    *returnSize = 0;
    short slong = strlen(s);
    int* result = (int*)calloc(slong, sizeof(int));
    short k = strlen(p);
    short a[26];
    for (int i = 0; i < k; i++)
    {
        a[s[i] - 97]++;
    }
    short b[26];
    for (int i = 0; i < k; i++)
    {
        b[s[i] - 97]++;
    }
    int i = k;
    int flag = 1;
    while (s[i] != '\0')
    {
        flag = 1;
        for (int j = 0; j < 26; j++)
        {
            if (a[j] != b[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            printf("这里做了一次加入\n");
            result[*returnSize] = i - k;
            (*returnSize)++;
        }
        a[s[i - k] - 97]--;
        a[s[i] - 97]++;
        i++;
    }
    printf("当前的i为%d\n", i);
    flag = 1;
    for (int j = 0; j < 26; j++)
    {
        if (a[j] != b[j])
        {
            printf("发现不相等了\n");
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        printf("这里做了一次加入\n");
        result[*returnSize] = i - k;
        (*returnSize)++;
    }
    return result;
}
int main_23155()
{
   /* char a[5];
    char b[3];
    int c;
    int* d = &c;
    scanf("%s %s", &a, &b);
    int* result=findAnagrams(a, b, d);
    for (int i=0;i<c;i++)
    {
        printf("%d", result[i]);
    }*/
    int count[4];
    char A = 'A';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a;
            printf("请问%c和%c有几座桥相连:\n", A + i, A + j);
            scanf("%d", &a);
            count[i] += a;
        }
    }
    int flag=0;
    for (int i = 0; i < 4; i++)
    {
        if (count[i] == 0)
        {
            printf("不能走完，有岛去不了.");
            break;
        }
        if (count[i] % 2 == 0)
            flag++;
    }
    if (flag == 4)
    {
        printf("能走完并回去.");
    }
    else if (flag == 2)
    {
        printf("能走完但回不去.");
    }
    else
        printf("走不完");
    return 0;
}