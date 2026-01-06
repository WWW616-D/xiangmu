#include"library.h"
int main()
{
	a:
	printf("\t\t\t\t\t\thello world\n");
	printf("请输入数字对应您要进行的操作:\n1:登录\n2:注册新的账户\n");
	int choice;
	scanf("%d", &choice);
	if (choice==1)
	{
		login();
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
		goto a;
	}
}