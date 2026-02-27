#include"library.h"
account* GetAccounts()
{
	FILE* file = fopen("D:\\代码\\我的期末作业\\图书馆管理系统\\accounts.txt", "r");
	account* head = NULL;
	char password[80];
	char line[256];
	fgets(line, sizeof(line), file);
	while (fgets(line, sizeof(line), file))
	{
		account* newnode = (account*)malloc(sizeof(account));
		newnode->next = NULL;
		memset(newnode, 0, sizeof(account));
		if (sscanf(line, "%d %s %s %d %d %d %d %d %d %lld",
			&newnode->id, newnode->name, password,
			&newnode->maxbook,
			&newnode->getbook,
			&newnode->pay,
			&newnode->punish,
			&newnode->privilege,
			&newnode->day,&newnode->phone) != 10)
		{
			free(newnode);
			break;
		}
		newnode->phone -= 886114514;
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
	fclose(file);
	return head;
}
void ShowAccount(account* head)
{
	while (head!=NULL)
	{
		printf("账户ID:%d 用户名:%s 密码:%s 最大借书:%d 已借书:%d罚款标准:%d 违规次数:%d 特权:%d 可借天数:%d 电话号码:%lld\n",
			head->id, head->name, head->password,
			head->maxbook, head->getbook, head->pay,
			head->punish, head->privilege, head->day,head->phone);
		printf("\n");
		head = head->next;
	}
}
account* FindAccount(int power,account* acc)
{
	int IdDown;
	int IdUp;
	account* result = NULL;
	if (power==2)
	{
		printf("你将输入用户id范围来查询一些用户的信息，如果你仅想查询其中一位，输入相同的下界和上界即可\n");
		printf("请输入你要查找的id下界:\n");
		scanf("%d", &IdDown);
		printf("请输入你要查找的id上界:\n");
		scanf("%d", &IdUp);
		account* head = AccountHead;
		while (head != NULL)
		{
			if (IdDown <= head->id && head->id <= IdUp)
			{
				account* newnode = (account*)malloc(sizeof(account));
				memcpy(newnode, head, sizeof(account));
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
			head = head->next;
		}
	}
	else
	{
		printf("现在展示您的用户信息:\n");
		printf("账户ID:%d 用户名:%s 密码:%s 最大借书:%d 已借书:%d 赔付标准:%d 违规次数:%d 特权等级:%d 可借天数:%d 电话号码:%lld\n",
			acc->id, acc->name, acc->password, acc->maxbook, acc->getbook, 
			acc->pay, acc->punish, acc->privilege, acc->day ,acc->phone);
	}
	
	return result;
}