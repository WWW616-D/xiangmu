#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
typedef struct book
{
	int id;
	char writer[50];
	char name[32];
	char flag;
	int outtime;
}book;
typedef struct account
{
	int id;
	char name[40];
	char password[40];
	char book[5][6];
	char maxbook;
	char getbook;
	struct account* next;
}account;
typedef struct mainaccount
{
	char name[40];
	char password[40];
	struct mainaccount* next;
}mainaccount;
void CreateNewAccount();
void CreateNewMainAccount();
mainaccount* getMainAccounts(FILE* file);
account* getAccounts(FILE* file);
void login();
void change(char* str, int length, char* out);
void back(char* str, char* out);
