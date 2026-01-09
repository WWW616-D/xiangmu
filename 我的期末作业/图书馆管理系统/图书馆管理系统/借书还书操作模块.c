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
	book* temp;
	while (flag)
	{
		flag = 1;
		temp = BookHead;
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
	printf("开始尝试借书\n");
	temp->flag = 0;
	(sir->getbook)++;


	long long int currenttime = time(NULL);
	temp->outtime = currenttime;
	char localtime[32];
	GetTime(currenttime, localtime, sizeof(localtime));
	long long int backtime = currenttime + 24 * 60 * 60 * sir->day;
	char ShouldBackTime[32];
	GetTime(backtime, ShouldBackTime, sizeof(ShouldBackTime));
	int recordid;
	int bookid = temp->id;
	record* TempRecord;
	if (RecordHead == NULL)
	{
		recordid = 10001;
	}
	else
	{
		TempRecord = RecordHead;
		while (TempRecord->next!=NULL)
		{
			TempRecord = TempRecord->next;
		}
		recordid = TempRecord->recordid + 1;
	}
	char TrueBackTime[32];
	TrueBackTime[0] = '0';
	TrueBackTime[1] = '\0';
	record* newrecord = (record*)malloc(sizeof(record));
	newrecord->recordid = recordid;
	newrecord->bookid = bookid;
	strcpy(newrecord->name, temp->name);
	newrecord->accountid = sir->id;
	strcpy(newrecord->time, localtime);
	strcpy(newrecord->ShouldBackTime,ShouldBackTime);
	strcpy(newrecord->TrueBackTime, TrueBackTime);
	newrecord->flag = 0;
	newrecord->next = NULL;
	if (RecordHead == NULL)
	{
		RecordHead = newrecord;
	}
	else
	{
		TempRecord = RecordHead;
		while (TempRecord->next != NULL)
		{
			TempRecord = TempRecord->next;
		}
		TempRecord->next = newrecord;
	}
	printf("记录添加完成\n");
}
void BackBook(account* sir)
{
	if (RecordHead==NULL)
	{
		printf("111\n");
	}
	if (sir->getbook == 0)
	{
		printf("你没有需要还的书\n");
		return;
	}
	int flag = 1;
	book* temp;
	int desition = 0;
	while (flag)
	{
		flag = 1;
		temp = BookHead;
		printf("请选择还书形式:\n1:提供id\n2:书名和作者名结合提供\n");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("请输入归还书的id:\n");
			int id;
			scanf("%d", &id);
			while (temp != NULL)
			{
				//printf("%d\n",temp->id);
				if (id == temp->id&&!temp->flag)
				{
					printf("查询到书:\n");
					printf("编号:%d|书名:%s|作者名:%s|出版社:%s|出版时间:%s|是否在库:%d\n",
						temp->id,
						temp->name,
						temp->writer,
						temp->birthname,
						temp->birthtime,
						temp->flag);
					printf("输入0确认归还,输入2退出还书界面:\n");
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
					printf("你要还的书不存在\n");
					printf("输入2退出还书界面:除0外任意键继续\n");
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
			printf("请输入归还书的名字和作者名:\n");
			char name[32];
			char writer[50];
			scanf("%s %s", name, writer);
			while (temp != NULL)
			{
				if (!strcmp(name, temp->name) && !strcmp(writer, temp->writer)&&!temp->flag)
				{
					
					record* q = RecordHead;
					while (q!=NULL)
					{
						if (q->bookid == temp->id&&q->accountid==sir->id)
						{
							desition = 1;
							if (q->flag==2)
							{
								desition = 2;
							}
						}
					}
					if (desition)
					{
						printf("查询到书:\n");
						printf("编号:%d|书名:%s|作者名:%s|出版社:%s|出版时间:%s|是否在库:%d\n",
							temp->id,
							temp->name,
							temp->writer,
							temp->birthname,
							temp->birthtime,
							temp->flag);
						printf("输入0确认归还,输入2退出借书界面:\n");
						scanf("%d", &flag);
						if (flag == 2)
						{
							return;
						}
						break;
					}
				}
				temp = temp->next;
				if (temp == NULL)
				{
					printf("你要还的书不存在\n");
					printf("输入2退出还书界面:除0外任意数字键继续\n");
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
	int dead = 1;
	record* TempRecord;
	temp->flag = 1;
	temp->outtime = 0;
	(sir->getbook)--;
	long long int currenttime = time(NULL);
	char localtime[32];
	GetTime(currenttime, localtime, sizeof(localtime));
	char outtime[32];
	GetTime(temp->outtime, outtime, sizeof(outtime));
	long long int OutTime = temp->outtime;
	if (((OutTime-currenttime)/24/60/60)>=sir->day)
	{
		dead = 2;
		printf("本次归还已逾期，请以后按时归还:\n");
		if (desition == 1)
		{
			printf("本次逾期尚未处罚，现在开始:\n");
			int day = (OutTime - currenttime) / 24 / 60 / 60 - sir->day + 1;
			printf("本次逾期%d天,你需要缴纳罚金%d元", day, day * sir->pay);
			sir->punish++;
			printf("正在记录您的更改数据:\n");
			if (sir->privilege)
			{
				sir->maxbook = 30 - sir->punish / 3;
				sir->day = 14 - sir->punish / 5;
				sir->pay = 1 + sir->punish / 5;
			}
			else
			{
				sir->maxbook = 10 - sir->punish / 3;
				sir->day = 7 - sir->punish / 5;
				sir->pay = 2 + sir->punish / 5;
			}
		}
		else if(desition==2)
		{
			printf("本次逾期已在先前由管理员登记处罚，请关注您的数据变动并确保已处理罚单\n");
		}
	}
	int bookid = temp->id;
	TempRecord = RecordHead;
	while (TempRecord!=NULL)
	{
		if (!strcmp(TempRecord->time,outtime)&&TempRecord->bookid==bookid)
		{
			strcpy(TempRecord->TrueBackTime, localtime);
			TempRecord->flag = dead;
			break;
		}
		TempRecord = TempRecord->next;
	}
	printf("记录更改完成\n");
}
void Punish()
{
	printf("开始查找逾期记录:\n");
	record* TempRecordHead = RecordHead;
	int flag = 1;
	while (TempRecordHead!=NULL)
	{
		if (TempRecordHead->flag==0)
		{
			int bookid = TempRecordHead->bookid;
			long long int currenttime = time(NULL);
			int accountid = TempRecordHead->accountid;
			int day;
			long long int outtime;
			book* TempBookHead = BookHead;
			while (TempBookHead!=NULL)
			{
				if (TempBookHead->id == bookid)
					break;
				TempBookHead = TempBookHead->next;
			}
			outtime = TempBookHead->outtime;
			int ThroughDay = (currenttime - outtime) / 24 / 60 / 60;
			if (ThroughDay>=7)
			{
				account* TempAccountHead = AccountHead;
				while (TempAccountHead != NULL)
				{
					if (TempAccountHead->id == accountid)
						break;
					TempAccountHead = TempAccountHead->next;
				}
				if (ThroughDay>=TempAccountHead->day)
				{
					printf("查询到逾期且未归还书本:\n");
					printf("流水编号: %d | 图书ID: %d | 书名: %s\n",
						TempRecordHead->recordid, TempRecordHead->bookid, TempRecordHead->name);
					printf("借书人账户ID: %d | 借出时间: %s\n",
						TempRecordHead->accountid, TempRecordHead->time);
					printf("应还时间: %s | 实还时间: %s | : %d\n",
						TempRecordHead->ShouldBackTime, TempRecordHead->TrueBackTime, TempRecordHead->flag);
					printf("现在开始处罚\n");
					TempAccountHead->punish++;
					if (TempAccountHead->privilege)
					{
						TempAccountHead->maxbook = 30 - TempAccountHead->punish / 3;
						TempAccountHead->day = 14 - TempAccountHead->punish / 5;
						TempAccountHead->pay = 1 + TempAccountHead->punish / 5;
					}
					else
					{
						TempAccountHead->maxbook = 10 - TempAccountHead->punish / 3;
						TempAccountHead->day = 7 - TempAccountHead->punish / 5;
						TempAccountHead->pay = 2 + TempAccountHead->punish / 5;
					}
					printf("账户数据已更改,且该用户需要缴纳%d罚金\n", ThroughDay * (TempAccountHead->pay));
					flag = 0;
				}
			}
		}
		TempRecordHead = TempRecordHead->next;
	}
	if (flag)
	{
		printf("未查询到逾期未还书记录\n");
	}
}