#include"library.h"
record* GetRecord()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\借书记录.txt", "r");
	if (file==NULL)
	{
		printf("文件打开失败\n");
	}
	record* head = NULL;
	record* tail = NULL;
	char line[512];
	while (fgets(line, sizeof(line), file))
	{
		record* records = (record*)malloc(sizeof(record));
		records->next = NULL;
		if (sscanf(line, "%d|%d|%31[^|]|%d|%31[^|]|%31[^|]|%31[^|]|%d",
			&records->recordid,
			&records->bookid,
			records->name,
			&records->accountid,
			records->time,
			records->ShouldBackTime,
			records->TrueBackTime,
			&records->flag)!=8)
		{
			free(records);
			break;
		}
		if (head == NULL)
		{
			printf("创建头节点\n");
			head = records;
			tail = records;
		}
		else
		{
			tail->next = records;
			tail = records;
		}
	}
	printf("你好");
	return head;
}
void ShowRecord(record* head)
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
void StorageRecord()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\借书记录.txt", "w");
	while (RecordHead!=NULL)
	{
		fprintf(file, "%d|%d|%s|%d|%s|%s|%s|%d\n",
			RecordHead->recordid,
			RecordHead->bookid,
			RecordHead->name,
			RecordHead->accountid,
			RecordHead->time,
			RecordHead->ShouldBackTime,
			RecordHead->TrueBackTime, 
			RecordHead->flag);
		RecordHead = RecordHead->next;
	}
	fclose(file);
}