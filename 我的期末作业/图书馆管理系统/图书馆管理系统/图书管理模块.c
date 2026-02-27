#include"library.h"
book* GetBookInformation()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\books.txt","r");
	book* head = NULL;
	book* tail = NULL;
	char line[256];
	fgets(line, sizeof(line), file);
	while (fgets(line, sizeof(line), file))
	{
		book* newnode = (book*)malloc(sizeof(book));
		newnode->next = NULL;
		if (sscanf(line, "%d|%31[^|]|%49[^|]|%49[^|]|%9[^|]|%d|%lld",
			&newnode->id,                                                                                                                                                                               
			newnode->name,
			newnode->writer,
			newnode->birthname,
			newnode->birthtime,
			&(newnode->flag),
			&(newnode->outtime))!=7)
		{
			free(newnode);
			break;
		}
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
	fclose(file);
	return head;
}

void StorageBookInformation()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\books.txt", "w");
	fprintf(file, "书籍编号 | 书籍名称 | 作者名 | 出版社名 | 出版日期 | 是否在库 | 借出时间戳\n");
	while (BookHead!=NULL)
	{
		fprintf(file, "%d|%s|%s|%s|%s|%d|%lld\n",
				BookHead->id,
				BookHead->name,
				BookHead->writer,
				BookHead->birthname,
				BookHead->birthtime, 
				BookHead->flag,
				(long long)BookHead->outtime);
		BookHead = BookHead->next;
	}
	fclose(file);
}

void AddBook()
{
	book* newbook = (book*)malloc(sizeof(book));
	book* temp = BookHead;
	if (temp==NULL)
	{
		newbook->id = 10001;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		newbook->id = temp->id + 1;
	}
	printf("请依次输入这本书的书名，作者名，出版社名称，出版时间\n");
	scanf("%s %s %s %s", newbook->name, newbook->writer, newbook->birthname, newbook->birthtime);
	newbook->flag = 1;
	newbook->outtime = 0;
	newbook->next = NULL;
	if (BookHead==NULL)
	{
		BookHead == newbook;
	}
	else
	{
		temp = BookHead;
		while (temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = newbook;
		
	}
	printf("添加完成\n");
}

enum SearchType GetSearchType(char* input)
{
	if (strcmp(input, "1") == 0) return BY_ID;
	if (strcmp(input, "2") == 0) return BY_NAME;
	if (strcmp(input, "3") == 0) return BY_WRITER;
	if (strcmp(input, "4") == 0) return BY_BIRTHNAME;
	return 0; 
}

book* FindBook()
{
	char input[10];

startinput:

	printf("请输入查找方式:\n1:编号范围\n2:书名\n3:作者\n4:出版社\n");
	scanf("%s", input);
	enum SearchType type = GetSearchType(input);
	if (type==0)
	{
		printf("输入形式错误，请重新输入:\n");
		goto startinput;
	}

	book* head = BookHead;
	book* result = NULL;
	int IdDown;
	int IdUp;
	char name[32];
	char writer[50];
	char birthname[50];
	if (type == BY_ID)
	{
		printf("你将输入id范围来查询一些书，如果你仅想查询一本，输入相同的下界和上界即可\n");
		printf("请输入你要查找的id下界:\n");
		scanf("%d", &IdDown);
		printf("请输入你要查找的id上界:\n");
		scanf("%d", &IdUp);
	}
	else if (type == BY_NAME)
	{
		printf("请输入你要查找的书名:\n");
		scanf("%s", name);
	}
	else if (type == BY_WRITER)
	{
		printf("请输入你要查找的作者名:\n");
		scanf("%s", writer);
	}
	else
	{
		printf("请输入你要查找的出版社名:\n");
		scanf("%s", birthname);
	}
	while (head!=NULL)
	{
		if (type==BY_ID)
		{
			if (IdDown<=head->id&&head->id<=IdUp)
			{
				book* newnode = (book*)malloc(sizeof(book));
				memcpy(newnode, head, sizeof(book));
				newnode->next = NULL;
				if (result==NULL)
				{
					result = newnode;
				}
				else
				{
					newnode->next = result;
					result = newnode;
				}
			}
		}
		else if(type==BY_NAME)
		{
			if (!strcmp(name,head->name))
			{
				book* newnode = (book*)malloc(sizeof(book));
				memcpy(newnode, head, sizeof(book));
				newnode->next = NULL;
				if (result == NULL)
				{
					result = newnode;
				}
				else
				{
					newnode->next = result;
					result = newnode;
				}
			}
		}
		else if(type==BY_WRITER)
		{
			if (!strcmp(writer,head->writer))
			{
				book* newnode = (book*)malloc(sizeof(book));
				memcpy(newnode, head, sizeof(book));
				newnode->next = NULL;
				if (result == NULL)
				{
					result = newnode;
				}
				else
				{
					newnode->next = result;
					result = newnode;
				}
			}
		}
		else if(type==BY_BIRTHNAME)
		{
			if (!strcmp(birthname,head->birthname))
			{
				book* newnode = (book*)malloc(sizeof(book));
				memcpy(newnode, head, sizeof(book));
				newnode->next = NULL;
				if (result == NULL)
				{
					result = newnode;
				}
				else
				{
					newnode->next = result;
					result = newnode;
				}
			}
		}
		head = head->next;
	}
	if (result==NULL)
	{
		printf("你要找的书不存在\n");
	}
	return result;
}
void ShowBook(book* head,int power)
{
	while (head!=NULL)
	{
		if (power==2)
		{
			char time[32];
			if (head->outtime != 0)
			{
				GetTime(head->outtime, time, sizeof(time));
			}
			else
			{
				strcpy(time, "还没有出库");
			}
			printf("编号:%d|书名:%s|作者名:%s|出版社:%s|出版时间:%s|是否在库:%d|出库时间:%s\n", 
				head->id,
				head->name,
				head->writer,
				head->birthname,
				head->birthtime,
				head->flag,
				time);
		}
		else
		{
			printf("编号:%d|书名:%s|作者名:%s|出版社:%s|出版时间:%s|是否在库:%d\n",
				head->id,
				head->name,
				head->writer,
				head->birthname,
				head->birthtime,
				head->flag);
		}
		head = head->next;
	}
}
void ChangeBook()
{

START:
	int choice;
	printf("按1开始操作,按其他数字退出\n");
	scanf("%d", &choice);
	if (choice != 1)
		return;
	book* temp = BookHead;
	printf("你要查找你想修改(删除)的书,请选择查找书形式:\n1:查询id\n2:书名和作者名结合查询\n");
	scanf("%d", &choice);
	int flag = 0;
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
				printf("输入0确认开始更改,输入2退出界面:\n");
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
				printf("输入2退出界面:除0外任意数字键继续\n");
				scanf("%d", &flag);
				if (flag == 2)
				{
					return;
				}
			}
		}
	}
	else if (choice == 2)
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
				printf("输入0确认开始更改,输入2退出借书界面:\n");
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
				printf("输入2退出界面:除0外任意数字键继续\n");
				scanf("%d", &flag);
				if (flag == 2)
				{
					return;
				}
			}
		}
	}
	printf("请选择你要进行的操作\n1:修改书籍信息\n2:将其出库\n3:返回上一级");
	scanf("%d", &choice);
	if (choice == 1)
	{

	CHANGE:

		printf("请选择修改内容\n1:书籍名称\n2:作者名称\n3:出版社名称\n4:出版日期\n");
		char Get[50];
		scanf("%d", &choice);
		printf("请输入你要修改为什么:\n");
		scanf("%s", Get);
		printf("按1确认，其他数字返回上一级\n");
		int ok;
		scanf("%d", &ok);
		if (ok == 1)
		{
			if (choice == 1)
			{
				strcpy(temp->name, Get);
			}
			else if (choice == 2)
			{
				strcpy(temp->writer, Get);
			}
			else if (choice == 3)
			{
				strcpy(temp->birthname, Get);
			}
			else if (choice == 4)
			{
				strcpy(temp->birthtime, Get);
			}
			printf("更改成功!\n");
			printf("按1继续操作,其他数字返回\n");
			scanf("%d", &choice);
			if (choice == 1)
			{
				goto START;
			}
		}
		else
			goto CHANGE;
	}
	else if (choice == 2)
	{
		temp->flag = 0;
		printf("该书已出库!\n");
		printf("按1继续操作,其他数字返回\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			goto START;
		}
	}
	else
		goto START;
}