#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
typedef struct book
{
	int id;    //编号，如10001,10002
	char name[32]; //书名
	char writer[50]; //作者名
	char birthname[50];//出版社名
	char birthtime[10];//出版时间
	int flag;     //1表示未借出，0表示已经借出
	time_t outtime;  //借出时间
	struct book* next;
}book;
typedef struct account
{
	int id;
	char name[40];
	char password[40];
	char maxbook;
	char getbook;
	int pay;
	int punish;
	char privilege;
	int day;
	struct account* next;
}account;
typedef struct mainaccount
{
	char name[40];
	char password[40];
	struct mainaccount* next;
}MainAccount;
typedef struct BorrowRecord
{
	int recordid;
	int bookid;
	char name[32];
	int accountid;
	char time[32];
	char ShouldBackTime[32];
	char TrueBackTime[32];
	int flag;
	struct BorrowRecord* next;
}record;
enum SearchType {
	BY_ID = 1,
	BY_NAME,
	BY_WRITER,
	BY_BIRTHNAME
};
extern account* AccountHead;
extern book* BookHead;
extern record* RecordHead;
void CreateNewAccount();
void CreateNewMainAccount();
MainAccount* GetMainAccounts(FILE* file);
account* GetAccounts(FILE* file);
int login();
void change(char* str, int length, char* out);
void back(char* str, char* out);
book* GetBookInformation();
void StorageBookInformation();
void AddBook();
enum SearchType GetSearchType(char* input);
book* FindBook();
void ShowBook(book* head, int power);
void BorrowBook(account* sir);
record* GetRecord();
void ShowRecord(record* head);
void StorageAccount();
void StorageRecord();
void BackBook(account* sir);
void StorageAccount();
void CleanStdin();
void GetTime(long long int times, char* buffer, int buffer_size);

