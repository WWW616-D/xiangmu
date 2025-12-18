#include<stdio.h>
#include<math.h>
#include <stdlib.h>
void prinm(int a[], int len);
void prinw(int a[], int len);
typedef struct str
{
	char c;
	int count;
}str;
void kill (int** nums,int i,int j)
{
	for (int a = 0; a < 8; a++)
	{
		if (a != i)
			nums[a][j]++;
		if (a != j)
			nums[i][a]++;
	}
	nums[i][j]++;
	int tempi = i-1;
	int tempj = j-1;
	while (tempi >=0 && tempj>=0)
	{
		nums[tempi][tempj]++;
		tempi--;
		tempj--;
	}
	tempi = i+1;
	tempj = j+1;
	while (tempi < 8 && tempj < 8 )
	{
		nums[tempi][tempj]++;
		tempi++;
		tempj++;
	}
	tempi = i - 1;
	tempj = j + 1;
	while (tempi >= 0 && tempj < 8)
	{
		nums[tempi][tempj]++;
		tempi--;
		tempj++;
	}
	tempi = i + 1;
	tempj = j - 1;
	while (tempi < 8 && tempj >= 0)
	{
		nums[tempi][tempj]++;
		tempi++;
		tempj--;
	}
}
void killdown(int** nums, int i, int j)
{
	for (int a = 0; a < 8; a++)
	{
		if (a != i)
			nums[a][j]--;
		if (a != j)
			nums[i][a]--;
	}
	nums[i][j]--;
	int tempi = i-1;
	int tempj = j-1;
	while (tempi >= 0 && tempj >= 0)
	{
		nums[tempi][tempj]--;
		tempi--;
		tempj--;
	}
	tempi = i+1;
	tempj = j+1;
	while (tempi < 8 && tempj < 8)
	{
		nums[tempi][tempj]--;
		tempi++;
		tempj++;
	}
	tempi = i - 1;
	tempj = j + 1;
	while (tempi >= 0 && tempj < 8)
	{
		nums[tempi][tempj]--;
		tempi--;
		tempj++;
	}
	tempi = i + 1;
	tempj = j - 1;
	while (tempi < 8 && tempj >=0)
	{
		nums[tempi][tempj]--;
		tempi++;
		tempj--;
	}
}
void start(int** plan,int** nums,int* num,int* count,int i,int j)
{
	if (i >= 8 || j >= 8)
		return;
	if (nums[i][j])
		return;
	plan[8 - *num][0] = i;
	plan[8 - *num][1] = j;
	(*num)--;
	kill(nums, i, j);
	if (*num>0)
	{
		for (int currenti=i+1;currenti<8;currenti++)
		{
			for (int currentj=0;currentj<8;currentj++)
			{
				start(plan,nums,num, count, currenti, currentj);
			}
		}
		plan[8 - *num][0] = -1;
		plan[8 - *num][1] = -1;
	}
	else
	{
		(*count)++;
		printf("方案%d是:\n", *count);
		for (int k=0;k<8;k++)
		{
			printf("第%d个皇后,%d,%d\n", k + 1, plan[k][0], plan[k][1]);
		}
	}
	killdown(nums, i, j);
	
	(*num)++;
	return;
}
void Eight_Queens()
{
	int** nums = (int**)malloc(8*sizeof(int*));
	for (int i=0;i<8;i++)
	{
		nums[i] = (int*)calloc(8, sizeof(int));
	}
	int count = 0;
	int num = 8;
	for (int i=0;i<8;i++)
	{
		for (int j=0;j<8;j++)
		{
			int** plan = (int**)malloc(8 * sizeof(int*));
			for (int k=0;k<8;k++)
			{
				plan[k] = (int*)malloc(2*sizeof(int));
				for (int l=0;l<2;l++)
				{
					plan[k][l] = -1;
				}
			}
			start(plan,nums,&num,&count,i,j);
			for (int k=0;k<8;k++)
			{
				free(plan[k]);
			}
			free(plan);
		}
	}
	printf("%d", count);
}
int main()
{
	Eight_Queens();
	/*str strs[26];
	for (int i =0;i<26;i++)
	{
		strs[i].count = 0;
		strs[i].c = 'a' + i;
	}
	char s[1024];
	scanf("%s", s);
	int i = 0;
	while (s[i]!='\0')
	{
		if ('a'<=s[i]&&'z' >=s[i])
		{
			strs[s[i] - 'a'].count++;
		}
		i++;
	}
	for (i=26;i>0;i--)
	{
		int flag = 0;
		for (int j=0;j<i;j++)
		{
			if (strs[j].count < strs[j + 1].count || (strs[j].c > strs[j + 1].c && strs[j].count == strs[j + 1].count))
			{
				str temp = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = temp;
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
	for (i=0;i<26;i++)
	{
		if (strs[i].count == 0)
			break;
		printf("%c    %d\n", strs[i].c, strs[i].count);
	}*/
}
//void exe1()
//{
//	int x;
//	int y;
//	float z;
//	printf("请输入x和y\n");
//	scanf("%d %d", &x, &y);
//	if (x > 0 && y > 0)
//	{
//		z = log(x) + log(y);
//	}
//	if (x > 0 && y < 0)
//	{
//		z = sin(x) + sin(y);
//	}
//	if (x < 0 && y > 0)
//	{
//		z = exp(2*x) + exp(3*x);
//	}
//	if (x < 0 && y < 0)
//	{
//		z = tan(x + y);
//	}
//	printf("%f", z);
//}
//void exe2()
//{
//	int x;
//	int y;
//	printf("请输入两个整数\n");
//	scanf("%d %d", &x, &y);
//	int count;
//	printf("1 做加法\n2 做减法\n3 做乘法\n4 做除法");
//	scanf("%d", &count);
//	switch (count)
//	{
//		case 1:printf("%d", x + y);
//			break;
//		case 2:printf("%d", x - y);
//			break;
//		case 3:printf("%d", x * y);
//			break;
//		case 4: 
//			if (y == 0)
//			{
//				printf("除数为0");
//			}
//			else
//				printf("%d", x / y);
//			break;
//	}
//}
//void exe3()
//{
//	for (int i=1;i<9;i++)
//	{
//		for (int k=1;k<i;k++)
//		{
//			printf("\t");
//		}
//		for (int j=i;j<9;j++)
//		{
//			printf("%d * %d = %d\t", i, j, i * j);
//		}
//		printf("\n");
//	}
//}
//int getnum(int num)
//{
//	int sum = 1;
//	for (int i=2;i*i<=num;i++)
//	{
//		if (num%i==0)
//		{
//			if (i * i != num)
//				sum += i + num / i;
//			else
//				sum += i;
//		}		
//	}
//	return sum;
//}
//void exe()
//{
//	for (int i =2;i<1000;i++)
//	{
//		int sum = getnum(i);
//		if (2<sum&&sum<1000&&sum!=i)
//		{
//			int sum1 = getnum(sum);
//			if (sum1==i)
//			{
//				printf("我们找到了一个亲密数对%d,%d\n", i, sum);
//			}
//		}
//	}
//}
//void exe()
//{
//	int a = 0;
//	int b = 1;
//	printf("%d %d ", a, b);
//	for (int i=3;i<=100;i++)
//	{
//		if (i&1)
//		{
//			int temp = a + b;
//			printf("%d ", temp);
//			a = b;
//			b = temp;
//		}
//		else
//		{
//			int temp = a - b;
//			printf("%d ", temp);
//			a = b;
//			b = temp;
//		}
//	}
//}
int main_32145()
{
	/*int a;
	int b;
	int c;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	printf("这三个整数的平均数为%d,乘积为%d", (a + b + c) / 3, a * b * c);*/
	/*int a = 70;
	int b = 89;
	int c = 65;
	int d = 100;
	int e = 78;
	printf("平均分为%d", (a + b + c + d + e)/5);*/
	/*int a;
	printf("请输入一个整数：");
	scanf("%d", &a);
	int b = a - 10;
	printf("%d", b * b * b);*/
	/*int a;
	printf("请输入一个四位数：");
	scanf("%d", &a);
	int c = 0;
	while (a > 0)
	{
		int b = a % 10;
		a = a / 10;
		c = c * 10 + b;
	}
	printf("这个数倒过来的数字是%d", c);*/
	/*int a;
	int b;
	int c;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	printf("这三个整数的平均数为%d,和为%d", (a + b + c) / 3, a + b + c);*/
	/*int a;
	printf("请输入一个ascll码：");
	scanf("%d", &a);
	char b = (char)a;
	printf("这个ascll码的对应字符为%c", b);*/
	/*int a;
	int b;
	int c;
	printf("请输入三个个位数：");
	scanf("%d %d %d", &a, &b, &c);
	int d = a * 100 + b * 10 + c;
	printf("由他们三个整数组成的一个三位数为%d", d);
	char a = 0;
	printf("请输入一个大写字母");
	scanf("%c", &a);
	int b = (int)a + 32;
	char c = (char)b;
	printf("对应小写字母为%c", c);*/
	/*float a;
	float b;
	printf("请输入两个浮点数：");
	scanf("%f %f", &a,&b);
	float c = a;
	a = b;
	b = c;
	printf("交换后的数字为%f,%f", a, b);*/
	/*int a;
	int b;
	int c;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	printf("用这三个数表示的年份为：%d年%d月%d日", a, b, c);
	int a;
	printf("请输入华氏温度：")
	scanf("%d", &a);
	printf("对应的摄氏温度是%d", a / 5 * 9 + 32);

	float a;
	float b;
	printf("请输入两个直角边：");
	scanf("%f %f", &a, &b);
	printf("斜边长为%f", sqrt(a * a + b * b));*/
	/*float n = 5;
	float i = 2;
	float j = 3;
	while (j * j > n)
	{
		j = j - 0.001;
	}
	while (i * i < n)
	{
		i = i + 0.001;
	}
	printf("5的算术平方根是%f\n", i);
	printf("5的算术平方根是%f\n", j);*/
	/*double a;
	int zheng[100];
	int xiao[100];
	printf("请输入一个十进制数字");
	scanf("%lf", &a);
	int e = (int)a;
	int i1 = 0;
	double m = a - e;
	double d = 0.5;
	int n = 0;
	while (m>0)
	{
		double f = m / d;
		xiao[i1] = (int)f;
		if (m >= d)
			m = m - d;
		i1++;
		d = d / 2.0;
		if (i1 >= 99)
			break;
	}*/
	
	/*while (1)
	{
		m = m * 2.0;
		int f = (int)m;
		xiao[i1] = f;      //法二
		i1++;
		if (m == 1.0)
			break;
		m = m - f;
		n++;
		if (n >= 100)
			break;
	}
	*/
	/*int i2 = 0;
	while(e>0)
	{
		zheng[i2] = e % 2;
		e = e / 2;
		i2++;
	}
	prinm(zheng, i2);
	printf(".");
	prinw(xiao, i1);*/
	



	return 0;
}

