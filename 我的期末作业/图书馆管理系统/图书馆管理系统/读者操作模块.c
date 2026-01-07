#include"library.h"
void GetTime(long long int times, char* buffer, int buffer_size) 
{
	time_t timestamp = (time_t)times;
	struct tm* timeinfo = localtime(&timestamp);

	snprintf(buffer, buffer_size, "%d.%d.%d %d:%02d:%02d",
		timeinfo->tm_year + 1900,  
		timeinfo->tm_mon + 1,      
		timeinfo->tm_mday,         
		timeinfo->tm_hour,         
		timeinfo->tm_min,          
		timeinfo->tm_sec);         
}
void BorrowBook(account* sir)
{
	if (sir->getbook>=sir->maxbook)
	{
		printf("借阅额度抵达上限,已无法继续借阅\n");
		return;
	}
	int flag = 1;
	book* head = GetBookInformation();
	book* temp;
	while (flag)
	{
		flag = 1;
		temp = head;
		printf("请选择借书形式:\n1:查询id\n2:书名和作者名结合查询\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("请输入书的id:\n");
			int id;
			scanf("%d", &id);
			while (temp != NULL)
			{
				//printf("%d\n",temp->id);
				if (id == temp->id)
				{
					printf("查询到书:\n");
					printf("编号:%d|书名:%s|作者名:%s|出版社:%s|出版时间:%s|是否在库:%d\n",
						temp->id,
						temp->name,
						temp->writer,
						temp->birthname,
						temp->birthtime,
						temp->flag);
					if (!temp->flag)
					{
						printf("该书已被借出,无法借入\n");
						temp = temp->next;
						continue;
					}
					printf("输入0确认借入,输入2退出借书界面:\n");
					scanf("%d", &flag);
					if (flag == 2)
					{
						return;
					}
					break;
				}
				temp = temp->next;
				if (temp == NULL)
				{
					printf("你要找的书不存在\n");
					printf("输入2退出借书界面:除0外任意键继续\n");
					scanf("%d", &flag);
					if (flag == 2)
					{
						return;
					}
					if (flag == 0)
					{
						flag = 1;
					}
				}
			}
		}
		if (choice == 2)
		{
			printf("请输入书的名字和作者名:\n");
			char name[32];
			char writer[50];
			scanf("%s %s", name, writer);
			while (temp != NULL)
			{
				if (!strcmp(name, temp->name) && !strcmp(writer, temp->writer))
				{
					printf("查询到书:\n");
					printf("编号:%d|书名:%s|作者名:%s|出版社:%s|出版时间:%s|是否在库:%d\n",
						temp->id,
						temp->name,
						temp->writer,
						temp->birthname,
						temp->birthtime,
						temp->flag);
					if (!temp->flag)
					{
						printf("该书已被借出,无法借入\n");
						temp = temp->next;
						continue;
					}
					printf("输入0确认借入,输入2退出借书界面:\n");
					scanf("%d", &flag);
					if (flag == 2)
					{
						return;
					}
					break;
				}
				temp = temp->next;
				if (temp == NULL)
				{
					printf("你要找的书不存在\n");
					printf("输入2退出借书界面:除0外任意数字键继续\n");
					scanf("%d", &flag);
					if (flag == 2)
					{
						return;
					}
					if (flag == 0)
					{
						flag = 1;
					}
				}
			}
		}
	}

	temp->flag = 0;
	(sir->getbook)++;


	long long int currenttime = time(NULL);
	temp->outtime = currenttime;
	char localtime[32];
	GetTime(currenttime, localtime, sizeof(localtime));
	long long int backtime = currenttime + 24 * 60 * 60 * sir->day;
	char ShouldBackTime[32];
	GetTime(backtime, ShouldBackTime, sizeof(ShouldBackTime));
	BorrowRecord* p = GetBorrowRecord();
	int recordid;
	int bookid = temp->id;
	if (p == NULL)
	{
		recordid = 10001;
	}
	else
		recordid = p->recordid + 1;
	char TrueBackTime[32];
	TrueBackTime[0] = '\0';
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\借书记录.txt", "a");
	fprintf(file, "%d|%d|%s|%d|%s|%s|%s|%d\n",
		recordid,
		bookid,
		temp->name,
		sir->id,
		localtime,
		ShouldBackTime,
		TrueBackTime,0);
	StorageBookInformation(head); 
	StorageAccount();
	fclose(file);
}