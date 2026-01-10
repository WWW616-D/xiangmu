#include"library.h"
book* BookHead = NULL;
record* RecordHead = NULL;
account* AccountHead = NULL;
int main()
{
	printf("\t\t\t\t\t\t文件读取中\n");
	BookHead = GetBookInformation();
	RecordHead = GetRecord();
	AccountHead = GetAccounts();
	printf("\t\t\t\t\t\t文件读取成功!\n");
	//登录注册板块

START:

	printf("\t\t\t\t\t\thello world\n");
	printf("请输入数字对应您要进行的操作:\n1:登录\n2:注册新的账户\n");
	char choice[100];
	int power;
	scanf("%s", choice);
	account* sir = NULL;
	MainAccount* leader;
	if (!strcmp(choice,"1"))
	{
		power=login(&sir,&leader);
		if (sir==NULL&&leader==NULL)
		{
			printf("鬼啊，叉出去!\n");
			return;
		}
	}
	else
	{
		printf("请选择你要创建的账户类型:\n1:读者账户\n2:管理员账户(需要激活码)\n");
		scanf("%s", choice);
		if (!strcmp(choice, "1"))
			CreateNewAccount();
		else
			CreateNewMainAccount();
		system("cls");
		goto START;
	}

	//管理员操作板块

	if (power == 2)
	{

	ADACCOUNTCONTROL:

		printf("请选择您想执行的操作:\n1:书入库\n2:查询读者个人信息\n3:获取借书表信息\n4:处理逾期借书记录\n5:查询图书信息\n6:修改(删除)图书信息");
		scanf("%s", choice);
		if (!strcmp(choice,"1"))
		{

		ADD:

			AddBook();
			printf("按1继续添加，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto ADD;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ADACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice,"2"))
		{

		FINDACCOUNT:
			;
			account* AccountFind=FindAccount(power, sir);
			ShowAccount(AccountFind);
			printf("按1继续查询，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto FINDACCOUNT;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ADACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice,"3"))
		{

		FINDRECORD:
			;
			record* RecordFind=FindRecord(power,sir);
			ShowRecord(RecordFind);
			printf("按1继续查询，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto FINDRECORD;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ADACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice, "4"))
		{
			Punish();
			printf("按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "2"))
			{
				goto ADACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice, "5"))
		{
		ADFINDBOOK:
			;
			printf("按1浏览图书库，按其他则按照条件查询图书:\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				ShowBook(BookHead, power);
			}
			else
			{
				book* BookFind = FindBook();
				ShowBook(BookFind, power);
			}
			printf("按1继续查询，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto ADFINDBOOK;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ADACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice,"6"))
		{
			ChangeBook();
		}
	}
	//读者操作模块

	else
	{

	ACCOUNTCONTROL:

		printf("请选择您需要的操作:\n1:查询图书\n2:借阅图书\n3:归还图书\n4:查看个人信息\n");
		scanf("%s", choice);
		if (!strcmp(choice, "1"))
		{

		FINDBOOK:
			;
			printf("按1浏览图书库，按其他则按照条件查询图书:\n");
			scanf("%s", choice);
			if (!strcmp(choice,"1"))
			{
				ShowBook(BookHead, power);
			}
			else
			{
				book* BookFind = FindBook();
				ShowBook(BookFind, power);
			}
			printf("按1继续查询，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto FINDBOOK;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice, "2"))
		{

		BORROW:

			BorrowBook(sir);
			printf("按1继续借书，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto BORROW;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice, "3"))
		{

		BACK:

			BackBook(sir);
			printf("按1继续还书，按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "1"))
			{
				goto BACK;
			}
			else if (!strcmp(choice, "2"))
			{
				goto ACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
		else if (!strcmp(choice, "4"))
		{
			printf("按1查询个人账户信息,按其他查询个人相关借书记录:\n");
			scanf("%s", choice);
			if (!strcmp(choice,"1"))
				FindAccount(power,sir);
			else
			{
				record* RecordFind=FindRecord(power, sir);
				ShowRecord(RecordFind);
			}

			printf("按2回到选择操作界面，按3回到登录注册界面，按其他退出系统\n");
			scanf("%s", choice);
			if (!strcmp(choice, "2"))
			{
				goto ACCOUNTCONTROL;
			}
			else if (!strcmp(choice, "3"))
			{
				goto START;
			}
		}
	}
	printf("\t\t\t\t\t\t开始退出系统\n");
	printf("\t\t\t\t\t\t  开始存盘\n");
	StorageBookInformation();
	StorageRecord();
	StorageAccount();
	ShowRecord(RecordHead);
	printf("\t\t\t\t\t\t  存盘完成\n");
	system("pause");
}