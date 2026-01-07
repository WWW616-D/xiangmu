#include"library.h"
BorrowRecord* GetBorrowRecord()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\借书记录.txt", "r");
	BorrowRecord* head = NULL;
	char line[512];
	while (fgets(line, sizeof(line), file))
	{
		BorrowRecord* record = (BorrowRecord*)malloc(sizeof(BorrowRecord));
		record->next = NULL;
		if (sscanf(line, "%d|%d|%31[^|]|%d|%31[^|]|%31[^|]|%31[^|]|%d",
			&record->recordid,
			&record->bookid,
			record->name,
			&record->accountid,
			record->time,
			record->ShouldBackTime,
			record->TrueBackTime,
			&record->flag)!=8)
		{
			free(record);
			break;
		}
		if (head == NULL)
		{
			head = record;
		}
		else
		{
			record->next = head;
			head = record;
		}
	}
	return head;
}
void ShowBorrowRecord(BorrowRecord* head)
{
	while (head!=NULL)
	{
		printf("记录ID: %d | 图书ID: %d | 书名: %s\n",
			head->recordid, head->bookid, head->name);
		printf("账户ID: %d | 借出时间: %s\n",
			head->accountid, head->time);
		printf("应还时间: %s | 实还时间: %s | : %d\n",
			head->ShouldBackTime, head->TrueBackTime, head->flag);
		head = head->next;
	}
}