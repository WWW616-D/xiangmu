#include<stdio.h>
#include<stdlib.h>
typedef struct stacknode
{
	int value;
	struct stacknode* next;
}stacknode;

typedef struct stack
{
	struct stacknode* top;
}astack;

astack* creatstack()
{
	astack* stack = (astack*)malloc(sizeof(astack));
	stack->top = NULL;
	return stack;
}

void putstack(astack* stack, int value)
{
	stacknode* newstacknode = (stacknode*)malloc(sizeof(stacknode));
	newstacknode->value = value;
	newstacknode->next = stack->top;
	stack->top = newstacknode;
}

int getstack(astack* stack)
{
	int value = stack->top->value;
	stacknode* temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	return value;
}
                           //队列
typedef struct teamnode
{
	int value;
	struct teamnode* next;
}teamnode;

typedef struct teams
{
	teamnode* head;
	teamnode* tail;
}teams;

teams* creatteam()
{
	teams* team = (teams*)malloc(sizeof(teams));
	team->head = NULL;
	team->tail = NULL;
	return team;
}

void getin(teams* team,int value)
{
	teamnode* newteamnode = (teamnode*)malloc(sizeof(teamnode));
	newteamnode->value = value;
	newteamnode->next = NULL;
	if (team->head==NULL)
	{
		team->head = newteamnode;
		team->tail = newteamnode;
	}
	else
	{
		team->tail->next = newteamnode;
		team->tail = newteamnode;
	}
}

int getoff(teams* team)
{
	if (team->head==NULL)
	{
		printf("当前队列为空！！！");
		return 0;
	}
	int value = team->head->value;
	teamnode* temp = team->head;
	team->head = team->head->next;
	free(temp);
	return value;
}
