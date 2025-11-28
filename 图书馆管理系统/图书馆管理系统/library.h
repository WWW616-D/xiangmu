#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
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
	char name[40];
	char password[40];
	struct account* next;
}account;
void CreateNewAccount();
account* getAccounts(FILE* file);
void login();
void change(char* str, int length, char* out);
void back(char* str, char* out);
