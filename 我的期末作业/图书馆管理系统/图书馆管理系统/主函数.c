#include"library.h"
account* boss = NULL;
int main()
{
	//登录注册板块

on:

	printf("\t\t\t\t\t\thello world\n");
	printf("请输入数字对应您要进行的操作:\n1:登录\n2:注册新的账户\n");
	int choice;
	int power;
	scanf("%d", &choice);
	account* sir;
	MainAccount* leader;
	if (choice==1)
	{
		power=login(&sir,&leader);
	}
	else
	{
		printf("请选择你要创建的账户类型:\n1:读者账户\n2:管理员账户(需要激活码)\n");
		scanf("%d", &choice);
		if (choice == 1)
			CreateNewAccount();
		else
			CreateNewMainAccount();
		system("cls");
		goto on;
	}
	//管理员操作板块




	//读者操作模块

control:

	printf("请选择您需要的操作:\n1:查询图书\n2:借阅图书\n3:归还图书\n4:查看个人信息\n");
	scanf("%d", &choice);
	if (choice==1)
	{
	found:

		book* find=FindBook();
		ShowBook(find,power);
		printf("按1继续查询，按2回到选择操作界面，按3回到登录注册界面\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			goto found;
		}
		else if (choice == 2)
		{
			goto control;
		}
		else if (choice == 3)
		{
			goto on;
		}
	}
	if (choice==2)
	{
		BorrowBook(sir);
	}
}