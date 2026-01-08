#include"library.h"
book* BookHead = NULL;
record* RecordHead = NULL;
account* AccountHead = NULL;
int main()
{
	printf("\t\t\t\t\t\t文件读取中\n");
	BookHead = GetBookInformation();
	RecordHead = GetRecord();
	printf("\t\t\t\t\t\t文件读取成功!\n");
	//登录注册板块

START:

	printf("\t\t\t\t\t\thello world\n");
	printf("请输入数字对应您要进行的操作:\n1:登录\n2:注册新的账户\n");
	int choice;
	int power;
	scanf("%d", &choice);
	account* sir = NULL;
	MainAccount* leader;
	if (choice==1)
	{
		power=login(&sir,&leader);
		if (sir==NULL)
		{
			printf("鬼啊，叉出去!\n");
			return;
		}
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
		goto START;
	}
	//管理员操作板块




	//读者操作模块

CONTROL:

	printf("请选择您需要的操作:\n1:查询图书\n2:借阅图书\n3:归还图书\n4:查看个人信息\n");
	scanf("%d", &choice);
	if (choice==1)
	{

	FIND:

		book* find=FindBook();
		ShowBook(find,power);
		printf("按1继续查询，按2回到选择操作界面，按3回到登录注册界面，按4退出系统\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			goto FIND;
		}
		else if (choice == 2)
		{
			goto CONTROL;
		}
		else if (choice == 3)
		{
			goto START;
		}
	}
	else if (choice==2)
	{

	BORROW:

		BorrowBook(sir);
		printf("按1继续借书，按2回到选择操作界面，按3回到登录注册界面，按其他数字退出系统\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			goto BORROW;
		}
		else if (choice == 2)
		{
			goto CONTROL;
		}
		else if (choice == 3)
		{
			goto START;
		}
	}
	else if (choice==3)
	{

	BACK:

		BackBook(sir);
		printf("按1继续还书，按2回到选择操作界面，按3回到登录注册界面，按4退出系统\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			goto BACK;
		}
		else if (choice == 2)
		{
			goto CONTROL;
		}
		else if (choice == 3)
		{
			goto START;
		}
	}
	printf("\t\t\t\t\t\t开始存盘\n");
	StorageBookInformation();
	StorageRecord();
	StorageAccount();
	ShowRecord(RecordHead);
	printf("存盘完成");
}