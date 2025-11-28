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
		CreateNewAccount();
		goto a;
	}
}