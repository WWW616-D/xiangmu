#include"library.h"
const char Xtable[] = "0123456789ABCDEF";

void ScanfPassword(char* pwd, int len)
{
	int i = 0;
	char ch;
	while (i < len - 1)
	{
		ch = _getch();
		if (ch == '\n' || ch == '\r')
		{
			pwd[i] = '\0';
			break;
		}
		else if (ch == '\b' && i > 0)
		{
			printf("\b \b");
			i--;
		}
		else if (i < len - 1)
		{
			pwd[i] = ch;
			i++;
			putchar('*');
		}
	}
}
int login(account** sir,MainAccount** leader)
{
	int flag = 0;
	int count = 0;

start:

	printf("你的身份是:\n1:读者\n2:管理员\n");
	int choice;
	
	scanf("%d", &choice);
	FILE* file;
	if (choice == 1)
	{
		file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\accounts.txt", "r");
	}
	else if (choice == 2)
	{
		file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\adAccounts.txt", "r");
	}
	else
	{
		printf("身份选择无效，请重新选择:\n");
		goto start;
	}
	if (choice == 1)
	{
		account* p = GetAccounts(file);
		if (p == NULL)
			printf("111");
		AccountHead = p;
		char name[40];
		char password[40];
	a:
		printf("请输入你的用户名;\n");
		scanf_s("%s", name, 40);
		printf("请输入你的密码;\n");
		ScanfPassword(password, sizeof(password));
		while (p != NULL)
		{
			if (strcmp(p->name, name) == 0)
			{
				break;
			}
			p = p->next;
		}
		if (p == NULL)
		if (p == NULL || strcmp(p->password, password) != 0)
		{
			printf("用户名或密码错误!请重新输入!\n");
			count++;
			if (count == 5)
			{
				return 3;
			}
			printf("你还有%d次输入机会\n", 5 - count);
			goto a;
		}
		printf("\t\t\t\thello! %s\n", name);
		fclose(file);
		*sir = p;
		return p->privilege;
	}
	else if (choice == 2)
	{
		MainAccount* p = GetMainAccounts(file);
		MainAccount* head = p;
		char name[40];
		char password[40];
	b:
		printf("请输入你的用户名;\n");
		scanf_s("%s", name, 40);
		printf("请输入你的密码;\n");
		ScanfPassword(password, sizeof(password));
		while (p != NULL)
		{
			if (strcmp(p->name, name) == 0)
			{
				break;
			}
			p = p->next;
		}
		if (p == NULL || strcmp(p->password, password) != 0)
		{
			printf("用户名或密码错误!请重新输入!\n");
			count++;
			if (count == 5)
			{
				return 3;
			}
			printf("你还有%d次输入机会\n", 5 - count);
			goto b;
		}
		printf("\t\t\t\thello! %s\n", name);
		fclose(file);
		*leader = p;
		return 2;
	}
}
void change(char* str, char* out)
{
	int length = strlen(str);
	for (int i = 0; i < length; i++)
	{
		char byte = str[i];
		out[i * 2] = Xtable[byte >> 4];
		out[i * 2 + 1] = Xtable[byte & 0x0F];
	}
	out[length * 2] = '\0';
}
void back(char* str,char* out)
{
	int len = strlen(str);
	for (int i=0;i<len;i+=2)
	{
		char high = str[i];
		char low = str[i + 1];
		char highvalue;
		char lowvalue;
		if (high <= '9' && high >= '0')
			highvalue = high - '0';
		else
			highvalue = high - 'A' + 10;
		if (low <= '9' && low >= '0')
			lowvalue = low - '0';
		else
			lowvalue = low - 'A' + 10;
		out[i / 2] = (highvalue) << 4 | lowvalue;
	}
	out[len / 2] = '\0';
}

MainAccount* GetMainAccounts(FILE* file)
{
	MainAccount* head = NULL;
	char name[80];
	char password[80];
	char line[256];
	while (fgets(line, sizeof(line), file))
	{
		MainAccount* newnode = (MainAccount*)malloc(sizeof(MainAccount));
		newnode->next = NULL;
		if (sscanf(line, "%79[^,],%s\n", newnode->name, password) != 2)
		{
			free(newnode);
			break;
		}
		back(password, newnode->password);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	return head;
}

void CreateNewMainAccount()
{
	MainAccount* new_mainaccount = (MainAccount*)malloc(sizeof(MainAccount));
	FILE* getfile = NULL;
	FILE* file = NULL;
	FILE* write_file;
	getfile = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\激活码.txt", "r");
	file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\adAccounts.txt", "r");

	//激活码模块

	char rightcode[16];
	fscanf(getfile, "%15s", rightcode);
	fclose(getfile);
	rightcode[15] = '\0';
	for (int i = 0; i < 15; i++)
	{
		rightcode[i] = 'A' + (rightcode[i] - 'A' + i + 1) % 26;
		printf("%c", rightcode[i]);
	}
	char code[16];
	b:
	printf("请输入激活码:\n"); 
	fflush(stdin);
	scanf_s("%s", code, 16);
	if (strcmp(code, rightcode) == 0)
	{
		printf("激活码正确:");
	}
	else
	{
		goto b;
	}
	getfile = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\激活码.txt", "w");
	write_file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\adAccounts.txt", "a");
	fprintf(getfile, "%s", rightcode);
	fclose(getfile);

	//账号密码输入模块

	a:
	printf("请输入你的用户名;(8到16个字符)\n");
	scanf_s("%s", new_mainaccount->name, sizeof(new_mainaccount->name));
	printf("请输入你的密码;(8到16个字符)\n");
	ScanfPassword(new_mainaccount->password, sizeof(new_mainaccount->password));
	MainAccount* p = GetMainAccounts(file);
	MainAccount* head = p;
	while (p != NULL)
	{
		if (strcmp(p->name, new_mainaccount->name) == 0)
		{
			printf("您的用户名与已存在用户名有冲突  请重新输入\n");
			goto a;
		}
		p = p->next;
	}
	while (head != NULL)
	{
		MainAccount* temp = head;
		head = head->next;
		free(temp);
	}
	if (strlen(new_mainaccount->password) > 16 || strlen(new_mainaccount->name) > 16 || strlen(new_mainaccount->password) < 8 || strlen(new_mainaccount->name) < 8)
	{
		printf("您的用户名或密码不符合限定长度  请重新输入\n");
		goto a;
	}

	//密码加密与数据写入模块

	char password[80];
	change(new_mainaccount->password, password);
	fprintf(write_file, "%s,%s\n", new_mainaccount->name, password);
}
account* GetAccounts(FILE* file)
{
	account* head = NULL;
	char password[80];
	char line[256];
	while (fgets(line, sizeof(line), file))
	{
		account* newnode = (account*)malloc(sizeof(account));
		newnode->next = NULL;
		if (sscanf(line, "%d %s %s %d %d %d %d %d %d",
			&newnode->id,newnode->name,password,
			&newnode->maxbook,
			&newnode->getbook,
			&newnode->pay,
			&newnode->punish,
			&newnode->privilege,
			&newnode->day) != 9)
		{
			free(newnode);
			break;
		}
		back(password, newnode->password);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	AccountHead = head;
	return head;
}
void CreateNewAccount()
{
	//账户初始化

	account* new_account = (account*)malloc(sizeof(account));
	if (new_account == NULL)
	{
		printf("新账户创建失败,请重试\n");
		return;
	}

	int choice;
	printf("是否有激活码?(激活特权用户)\n输入1开始进入输入激活码界面，输入其他继续正常注册\n");
	scanf("%d", &choice);
	int flag = 0;
	if (choice==1)
	{
		FILE* getfile= fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\account激活码.txt", "r");
		char rightcode[16];
		fscanf(getfile, "%15s", rightcode);
		fclose(getfile);
		rightcode[15] = '\0';
		for (int i = 0; i < 15; i++)
		{
			rightcode[i] = 'A' + (rightcode[i] - 'A' + i + 1) % 26;
			printf("%c", rightcode[i]);
		}
		char code[16];
	b:
		printf("请输入激活码:\n");
		fflush(stdin);
		scanf_s("%s", code, 16);
		if (strcmp(code, rightcode) == 0)
		{
			printf("激活码正确:");
		}
		else
		{
			goto b;
		}
		getfile = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\account激活码.txt", "w");
		flag = 1;
		fprintf(getfile, "%s", rightcode);
		fclose(getfile);
	}
	if (!flag)
	{
		new_account->maxbook = 10;
		new_account->getbook = 0;
		new_account->pay = 2;
		new_account->punish = 0;
		new_account->privilege = 0;
		new_account->day = 7;
	}
	else
	{
		new_account->maxbook = 20;
		new_account->getbook = 0;
		new_account->pay = 1;
		new_account->punish = 0;
		new_account->privilege = 1;
		new_account->day = 14;
	}
	FILE* file = NULL;
	file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\accounts.txt", "r");
	FILE* numfile = NULL;
	numfile = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\id.txt", "r");

	fscanf(numfile, "%d", &new_account->id);
	int nextid = new_account->id + 1;
	fclose(numfile);

	//账户注册

	a:
	printf("请输入你的用户名;(8到16个字符)\n");
	scanf_s("%s", new_account->name,sizeof(new_account->name));
	printf("请输入你的密码;(8到16个字符)\n");
	ScanfPassword(new_account->password, sizeof(new_account->password));
	account* p = GetAccounts(file);
	account* head = p;
	while (p!=NULL)
	{
		if (strcmp(p->name,new_account->name)==0)
		{
			printf("您的用户名与已存在用户名有冲突  请重新输入\n");
			goto a;
		}
		p = p->next;
	}
	while (head != NULL)
	{
		account* temp = head;
		head = head->next;
		free(temp);
	}
	if (strlen(new_account->password)>16||strlen(new_account->name) > 16||strlen(new_account->password) < 8 || strlen(new_account->name) < 8)
	{
		printf("您的用户名或密码不符合限定长度  请重新输入\n");
		goto a;
	}
	printf("欢迎你%s\n", new_account->name);

	//加密与写入

	char password[80];
	change(new_account->password,password);
	fclose(file);
	FILE* write_file;
	write_file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\accounts.txt", "a");
	fprintf(write_file,"%d %s %s ",new_account->id,new_account->name,password);
	fprintf(write_file, "%d %d ", new_account->maxbook, new_account->getbook);
	fprintf(write_file, "%d %d %d %d\n", new_account->pay, new_account->punish, new_account->privilege, new_account->day);
	fclose(write_file);
	numfile = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\id.txt", "w");
	fprintf(numfile, "%d", nextid);
	fclose(numfile);
}
void StorageAccount()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\accounts.txt", "w");
	char password[80];
	
	while (AccountHead!=NULL)
	{
		memset(password, 0, sizeof(password));
		change(AccountHead->password, password);
		fprintf(file, "%d %s %s ", AccountHead->id, AccountHead->name, password);
		fprintf(file, "%d %d ", AccountHead->maxbook, AccountHead->getbook);
		fprintf(file, "%d %d %d %d\n", AccountHead->pay, AccountHead->punish, AccountHead->privilege, AccountHead->day);
		AccountHead = AccountHead->next;
	}
	fclose(file);
}