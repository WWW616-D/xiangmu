#include"library.h"
const char Xtable[] = "0123456789ABCDEF";
account* getAccounts(FILE* file)
{
	account* head = NULL;
	char name[80];
	char password[80];
	char line[256];
	while (fgets(line,sizeof(line),file))
	{
		account* newnode = (account*)malloc(sizeof(account));
		newnode->next = NULL;
		if (sscanf(line,"%79[^,],%s\n",name,password) != 2)
		{
			free(newnode);
			break;
		}
		back(name, newnode->name);
		back(password, newnode->password);
		printf("解析后的字符串是%s\n%s\n", newnode->name, newnode->password);
		if (head==NULL)
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
void login()
{
	int count = 0;
	printf("你的身份是:\n1:读者\n2:管理员\n"); 
	int choice;
	scanf("%d", &choice);
	FILE* file;
	if (choice == 1)
	{
		file = fopen("D:\\代码\\图书馆管理系统\\accounts.txt", "r");
	}
	else
	{
		file = fopen("D:\\代码\\图书馆管理系统\\adAccounts.txt", "r");
	}
	account* p = getAccounts(file);
	account* head = p;
	char name[40];
	char password[40];
	a:
	printf("请输入你的用户名;\n");
	scanf_s("%s", name, 40);
	printf("请输入你的密码;\n");
	scanf_s("%s", password, 40);
	while(p!=NULL)
	{
		if(strcmp(p->name,name)==0)
		{
			break;
		}
		p = p->next;
	}
	if (p==NULL||strcmp(p->password,password)!=0)
	{
		printf("用户名或密码错误!请重新输入!\n");
		count++;
		if (count==5)
		{
			return;
		}
		printf("你还有%d次输入机会\n", 5 - count);
		goto a;
	}
	printf("\t\t\t\thello! %s\n", name);
	while (head != NULL)
	{
		account* temp = head;
		head = head->next;
		free(temp);
	}
	fclose(file);
}
void password(char* pwd, int len)
{
	int i = 0;
	char ch;
	while (i<len-1)
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
void CreateNewAccount()
{
	printf("请选择你要创建的账户类型:\n1:读者账户\n2:管理员账户(需要激活码)\n");
	int choice;
	scanf("%d", &choice);
	account* new_account = (account*)malloc(sizeof(account));
	if (new_account == NULL)
	{
		printf("新账户创建失败,请重试\n");
		return;
	}
	FILE* file = NULL;
	FILE* getfile = NULL;
	char rightcode[16];
	if (choice == 1)
	{
		file = fopen("D:\\代码\\图书馆管理系统\\accounts.txt", "r");
	}
	else
	{
		getfile = fopen("D:\\代码\\图书馆管理系统\\激活码.txt","r");
		file = fopen("D:\\代码\\图书馆管理系统\\adAccounts.txt", "r");
		fscanf(getfile, "%15s\n",rightcode);
		rightcode[15] = '\0';
		for (int i = 0;i<15;i++)
		{
			rightcode[i] = 'A' + (rightcode[i]-'A'+i+1) % 26;
			printf("%c\n", rightcode[i]);
		}
		char code[16];
		b:
		printf("请输入激活码:\n");
		scanf_s("%s", code, 15);
		if (strcmp(code, rightcode)==0)
		{
			printf("激活码正确:");
		}
		else
		{
			goto b;
		}
	}
	a:
	printf("请输入你的用户名;(8到16个字符)\n");
	scanf_s("%s", new_account->name,sizeof(new_account->name));
	printf("请输入你的密码;(8到16个字符)\n");
	password(new_account->password, sizeof(new_account->password));
	account* p = getAccounts(file);
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
	printf("%s", new_account->name);
	char name[80];
	char password[80];
	change(new_account->name,name);
	change(new_account->password,password);
	fclose(file);
	if (getfile!=NULL)
	{
		fclose(getfile);
	}
	FILE* write_file;
	if (choice == 1) {
		write_file = fopen("D:\\代码\\图书馆管理系统\\accounts.txt", "a");
	}
	else 
	{
		getfile = fopen("D:\\代码\\图书馆管理系统\\激活码.txt","w");
		write_file = fopen("D:\\代码\\图书馆管理系统\\adAccounts.txt", "a");
		fprintf(getfile,"%s",rightcode);
	}
	fprintf(write_file,"%s,%s\n",name,password);
	fclose(write_file);
	fclose(getfile);
}