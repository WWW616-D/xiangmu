#include<stdio.h>
#include<time.h>
#include<math.h>
#include<stdlib.h>
void change(int* p1, int* p2);
void changeda(int* p1, int* p2);
double lossshu(double x)
{
	double loss = x * x - 5.0;
	return loss * loss;
}
double tt(double x)
{
	double t = 4 * x * (x * x - 5);
	return t;
}
void sqrt_(double shu, double buchang, double wucha, int max)
{
	int n = 0;
	float x = shu / 2;
	printf("迭代过程：\n");
	printf("迭代次数\t  x值\t\t  损失值\t\t  梯度值\n");
	for (n; n <= max; n++)
	{
		double x1 = x;
		double t = tt(x);
		double loss = lossshu(x);
		printf("%d\t  %.6f\t\t  %.6f\t\t  %.6f\t\t\n", n, x, loss, t);
		x = x - buchang * t;
		if (fabs(buchang * t) < wucha || n == max)
		{
			printf("迭代了%d次，最终数值为%.6f,损失值为%.6f\n", n, x, loss);
			break;
		}
	}
}
void prinw(int a[], int len);



//void exe1()
//{
//	printf("**********************\n");
//	printf("\n");
//	printf("Very GOOD!\n");
//	printf("\n");
//	printf("****************\n");
//}
//void exe2() 
//{
//	int a;
//	int b;
//	int c;
//	int d;
//    int sum;
//	a = 10;
//	b = 20;
//	c = 30;
//	sum = a + b + c;
//	a = c; d = a + c;
//	printf("sum=%d,d=%d", sum, d);
//}
//void exe3()
//{
//	int a;
//	int b;
//	int c;
//	printf("请输入三个整数：\n");
//	scanf("%d %d %d", &a, &b, &c);
//	printf("这三个整数的平均数为%d,乘积为%d\n", (a + b + c) / 3, a * b * c);
//}
//void exe4()
//{
//	int a = 70;
//	int b = 89;
//	int c = 65;
//	int d = 100;
//	int e = 78;
//	printf("平均分为%d\n", (a + b + c + d + e)/5);
//}
//void exe6() 
//{
//	int a = 5;
//	int b = 10;
//	int c = 6;
//	printf("a=%d,b=%d,c=%d,s=%d\n", a, b, c, (a + b) * c / 2);
//}
//void exe7()
//{
//	int a, b, c;
//	float d, x1, x2;
//	printf("请输入a,b,c\n");
//	scanf("%d %d %d", &a, &b, &c);
//	d = sqrt(b * b - 4 * a * c);
//	x1 = (b * -1 + d) / 2 / a;
//	x2 = (b * -1 - d) / 2 / a;
//	printf("%f %f\n", x1, x2);
//}
//void exe8()
//{
//	int a;
//	int b;
//	int c;
//	printf("请输入三个整数：\n");
//	scanf("%d %d %d", &a, &b, &c);
//	printf("%d\n", a * 100 + b * 10 + c * 1);
//}
//void exe9()
//{
//	float x;
//	printf("请输入一个浮点数");
//	scanf("%f", &x);
//	printf("%f", x * x * x * x * x);
//}
//void exe10()
//{
//
//}
//void exe11()
//{
//
//}
//void exe12()
//{
//
//}
//void exe13()
//{
//
//}
//void exe14()
//{
//
//}
//void exe15()
//{
//
//}
//void exe16()
//{
//	float a = 5;
//	float i = 2;
//	int n = 0;
//	for (i; i * i < 5; i += 0.0001)
//	{
//		n++;
//	}
//	/*while(i*i<5)
//	{
//		i += 0.0001;
//		n++;
//	}*/
//	printf("5的平方根为%f,迭代了%d次", i, n);
//}    
//int main_55()
//{
//	float x;
//	scanf("%f", &x);
//	printf("%f", x * x * x * x * x);
//}
//int main_136()
//{
//	int v = 20;
//	int a = 2;
//	int v1 = v + a * 20;
//	int v2 = (v + v1) / 2;
//	int m = (v1 + v2) * 20 / 2;
//	printf("末速度为%d 路程为%d 平均速度为%d", v1, v2, m);
//}
//int main_23165()
//{
//	float a;
//	scanf("%f", &a);
//	double b;
//	b = a * 950 / 3;
//	printf("%lf ", b * 10e22);
//}
//int main()
//{
//	float a, b, c, s;
//	scanf("%f %f %f", &a, &b, &c);
//	if (a + b > c && b + c > a && a + c > b)
//	{
//		s = (a + b + c) / 2;
//		printf("%f", sqrt(s * (s - a) * (s - b) * (s - c)));
//	}
//
//
//	else
//		printf("这不是三角形");
//}


//int main()
//{
//	float pai = 3.14;
//	float r = 1.5;
//	float h = 3.0;
//	float c = 2 * pai * r;
//	float s = pai * r * r * 2 + c * h;
//	float v = pai * r * r * h;
//	printf("周长为%f 表面积为%f 体积为%f", c, s, v);
//}
//int main()
//{
//	float u = 220;
//	float r2 = 10e4;
//	float r1 = 10e4;
//	float r3 = 200e4;
//	float r4 = 200e4;
//	printf("电流分别为%f %f %f %f", u / r1, u / r2, u / r3, u / r3);
//	float r_ = 1 / r1 + 1 / r2 + 1 / r3 + 1 / r4;
//	float r = 1 / r_;
//	printf("总电阻为%f", r);
//}
//int main()
//{
//	int day;
//	scanf("%d", &day);
//	int zhou = day / 7;
//	int day1 = day % 7;
//	printf("%d周%d天", zhou, day1);
//}
//int main()
//{
//	char str[6];
//	char a = 'a';
//	scanf("%s", str);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%c", str[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%c", a + ((str[i] - a + 4) % 26));
//	}
//}
//int main()
//{
//	char ch1;
//	while (scanf_s("%c", &ch1) != EOF)
//	{
//		if (ch1 > 86 && ch1 <= 90)
//		{
//			printf("%c", ch1 - 22);
//		}
//		else if (ch1 > 118 && ch1 <= 122)
//		{
//			printf("%c", ch1 - 22);
//		}
//		else
//		{
//			printf("%c", ch1 + 4);
//		}
//	}
//}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int aa = a * a;
//	int b = aa % 10;
//	aa /= 10;
//	int c = aa % 10;
//	printf("转化后十位是%d,个位是%d", c, b);
//}
int change_(char* string)
{
	int sign = 1;
	char* p = string;
	int shu = 0;
	printf("这个函数执行了\n");
	while (*p != '\0')
	{
		if (*p == '-')
		{
			sign = -1;
		}
		else if (*p >= '0' && *p <= '9')
		{
			shu = ((int)*p - 48) + shu * 10;
		}
		else
		{
			break;
			printf("请重新输入\n");
		}
		p++;
	}
	printf("转化后的数字为%d\n", shu);
	return shu;
}
void paixu(char(*stuno)[20], int n)
{
	int a[5];
	for (int i = 0; i <= 4; i++)
	{
		a[i] = change_(stuno);
		stuno++;
	}
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			changeda(&a[j], &a[j + 1]);
		}
	}
	printf("到这里的代码执行了2\n");
	prinw(a, n);
}
char* strin(char* s1, char* s2)
{
	int i1 = 0;
	int i2 = 0;
	int flag = 1;
	char* p1 = NULL;
	while (s1[i1] != '\0')
	{
		i1++;
	}
	while (s2[i2] != '\0')
	{
		i2++;
	}
	printf("长度1为%d\n长度2为%d\n", i1, i2);
	int i = 0;
	if (i1 >= i2)
	{
		char* p = s2;
		while (*s2 != '\0')
		{
			printf("这个循环在执行第%d遍\n", i + 1);
			i++;
			if (*s1 == '\0')
			{
				printf("并没有包含\n");
				return NULL;
			}
			if (*s2 == *s1 && flag)
			{
				p1 = s1;
				flag = 0;
			}
			if (*s2 == *s1)
			{
				s2++;
				s1++;
			}

			else
			{
				s1++;
				s2 = p;
				flag = 1;
				p1 = NULL;
			}
		}
		printf("自己看看结果吧bro\n");
		return p1;
	}
	else
	{
		printf("s1还没s2长呢\n");
		return NULL;
	}
}
void change__(int(*m)[5])
{
	int maax = 0;
	int maxi;
	int maxj;
	int a[4] = { 26, 26, 26, 26 };
	int pa[4][2] = { 0,0,0,0,0,0,0,0};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int num = *(*(m + i) + j);
			if (num > maax)
			{
				maax = *(*(m + i) + j);
				maxi = i;
				maxj = j;
			}
			if (num < a[3])
			{
				a[3] = num;
				pa[3][0] = i;
				pa[3][1] = j;
				int i1 = 3;
				while (i1 > 0 && a[i1] < a[i1 - 1])
				{
					change(&a[i1], &a[i1 - 1]);
					change(&pa[i1][0], &pa[i1 - 1][0]);
					change(&pa[i1][1], &pa[i1 - 1][1]);
					i1 = i1 - 1;
				}
			}
		}
	}
	printf("最小的数值依次为:\n");
	prinw(a,4);
	printf("对应的坐标为:\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d\t", pa[i][j]);
		}
		printf("\n");
	}
	change(*(m + 2) + 2, *(m + maxi) + maxj);
	for (int i = 0; i < 4; i++)
	{
		if (pa[i][0] == 2 && pa[i][1] == 2)
		{
			pa[i][0] = maxi;
			pa[i][1] = maxj;
		}

	}
	change(*(m), *(m + pa[0][0]) + pa[0][1]);
	for (int i = 1; i < 4; i++)
	{
		if (pa[i][0] == 0 && pa[i][1] == 0)
		{
			pa[i][0] = pa[0][0];
			pa[i][1] = pa[0][1];
		}

	}
	change(*(m)+4, *(m + pa[1][0]) + pa[1][1]);
	for (int i = 2; i < 4; i++)
	{
		if (pa[i][0] == 0 && pa[i][1] == 4)
		{
			pa[i][0] = pa[1][0];
			pa[i][1] = pa[1][1];
		}

	}
	change(*(m+4), *(m + pa[2][0]) + pa[2][1]);
	for (int i = 3; i < 4; i++)
	{
		if (pa[i][0] == 4 && pa[i][1] == 0)
		{
			pa[i][0] = pa[2][0];
			pa[i][1] = pa[2][1];
		}
	}
	change(*(m+4)+4, *(m + pa[3][0]) + pa[3][1]);
	
	
	printf("转换完成后的结果为:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", *(*(m + i) + j));
		}
		printf("\n");
	}
}
void print(char zimu)
{
	int num = zimu - 'A' + 1;
	num = 150;
	int count = 1;
	char a = 'A';
	for (int i=0;i<num-1;i++)
	{
		printf(" ");
	}
	printf(" ");
	printf("%c", a);
	for (int i = 1; i < num; i++)
	{
		printf("\n");
		for (int l=num-i-1;l>0;l--)
		{
			printf(" ");
		}
		printf(" ");
		count += 2;
		for (int j=0;j<=count/2;j++)
		{
			printf("%c", a + j);
		}
		for (int k=count/2+1;k<count;k++)
		{
			printf("%c", a + count / 2 - (k - count / 2));
		}
	}
}
int main_asdawd()
{
	/*int a[5][5];
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = rand() % 25 + 1;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	int(*p)[5] = a;
	change__(p);*/
	/*float b = 128.1010;
	printf("%f\n", b);
	int n = 100;
	int count1 = 0;
	int count2 = 0;
	while(n>2)
	{
		n -= 5;
		count1++;
		if (n<=2)
		{
			break;
		}
		n += 2;
		count2++;
	}
	printf("%d\n%d", count1, count2);
	*/
	char a;
	printf("请输入要多少行");
	scanf("%c", &a);
	print(a);
	
	
	//printf("hello world\n");
	//printf("我不要上早八\n");
	///*main_2();*/
	//int n1;
	//int n2;
	//printf("请输入两个整数：");
	//scanf("%d %d", &n1, &n2);
	//printf("这两个整数中的较大值为：%d", max(n1, n2));
	//printf("请输入三个整数：");
	//int a;
	//int b;
	//int c;
	//int d;
	//scanf("%d%d%d%d\n", &a, &b, &c, &d);
	///*swap(&a, &b);
	//swap(&b, &c);
	//swap(&a, &b);*/
	//printf("%d%d%d%d", a, b, c, d);
	/*char c = 'TB';
	printf("%d\n", c);
	int e = 16;
	char f = (char)e;
	printf("%c\n", f);*/
	/*exe1();
	exe2();
	exe3();
	exe4();
	exe6();
	exe7();
	exe8();
	exe9();*/
	//exe16();
	/*double target;
	double buchang;
	double wucha;
	int max;
	printf("请依次输入要求的数，步长，允许误差，最大迭代次数:");
	scanf("%lf %lf %lf %d",&target, &buchang, &wucha, &max);
	sqrt_(target, buchang, wucha, max);*/
	/*char string[100];
	scanf("%s", &string);
	change_(string);*/
	/*int chang = 5;
	char students[5][20] =
	{
		"123546112",
		"123541521",
		"231645833",
		"111",
		"654892244"
	};
	char (*stuno)[20] = students;
	paixu(stuno, chang);
	printf("结束");*/
	//char str1[100];
	//char str2[100];
	//scanf("%s %s", &str1, &str2);
	///*printf("%p", str1);
	//printf("%p", strin(str1, str2));*/
	//char* p = strin(str1, str2);
	//printf("%d\n", p - str1);
	//printf("%p\n %p\n", p, str1);
	/*char a = 68;
	char b = 127;
	printf("%d", a+b);*/
	int a[40];
	srand(time[NULL]);
	float f;
	int h;
	for (int i=0;i<40;i++)
	{
		a[i] = rand() % 100 + 1;
		h += a[i];
	}
	f = float(h) / 40;
	for (int i=0;i<40;i++)
	{
		printf("第%d个学生成绩与平均分%f的差距为%f分\n", i, f, a[i] - f);
	}
	return 0;
	
}