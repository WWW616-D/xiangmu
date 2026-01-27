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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student {
	int id;
	char name[10];
	int score;
	struct student* next;
}student;
student* creat()
{
	student* head = NULL;
	student* tail = NULL;
	int id;
	while (1)
	{
		printf("输入id\n");
		scanf("%d", &id);
		if (id == -1)
		{
			break;
		}
		student* new_node = (student*)malloc(sizeof(student));
		new_node->id = id;
		printf("输入名字\n");
		scanf("%s", new_node->name);
		printf("输入分数\n");
		scanf("%d", &new_node->score);
		new_node->next = NULL;
		if (head==NULL)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
	}
	return head;
}
int add(student* head, int pos, student* p)
{
	student* q = head;
	int count = 1;
	if (pos <= 0) return 0;
	while (q != NULL && count < pos - 1)
	{
		q = q->next;
		count++;
	}
	if (q)
	{
		p->next = q->next;
		q->next = p;
		return 1;
	}
	return 0;
}
int del(student* head, int pos)
{
	student* p = head, * q;
	int count = 1;
	while (p != NULL && count < pos - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL || p->next == NULL) return -1;
	q = p->next;
	p->next = q->next;
	free(q);
	return 1;
}
void prn(student* head)
{
	student* p;
	p = head;
	while (p != NULL)
	{
		printf("%d %s %d\n", p->id, p->name, p->score);
		p = p->next;
	}
}
void freelist(student* head)
{
	student* p, * temp;
	p = head;
	if (p != NULL)
	{
		temp = p;
		p = p->next;
		free(temp);
	}
}
int main()
{
	student* head;
	head = creat();
	prn(head);
	printf("new node");
	student* a = (student*)malloc(sizeof(student));
	scanf("%d %s %d", &a->id, a->name, &a->score);
	a->next = NULL;
	if (add(head, 2, a));
	{
		printf("添加成功");
	}
	del(head, 2);
	prn(head);
	freelist(head);
	return 0;
}