#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//void sum(int num1,int num2)
//{ 
//	int sum = num1 + num2;
//	return sum;
//	/*printf("%d", num1 + num2);*/
//}
void swap(void* p1, void* p2, int len);
void prinm(int a[], int len);
void maxmin(int a[], int len, int* max, int* min);
void prinm(int a[], int len);
void prinw(int a[], int len);
void jia(int x, int y);
void jian(int x, int y);
void cheng(int x, int y);
void chu(int x, int y);
int searchch(int* data, int num,int len);                         
//最长无重复字母串
int lengthOfLongestSubstring(char* s)
{
	char* a = (char*)calloc(100, sizeof(char));
	int i = 0;
	int p = 0;
	int max = 0;
	while (s[i] != '\0')
	{
		a[s[i] - 32]++;
		if (a[s[i] - 32] > 1)
		{
			while (p <= i && s[p] != s[i])
			{
				a[s[p] - 32]--;
				p++;
			}
			a[s[p] - 32]--;
			p++;
		}
		if (i - p + 1 > max)
		{
			max = i - p + 1;
		}
		i++;
	}
	return max;
}
                           
 


//int* getSneakyNumbers(int* nums, int numsSize, int* returnSize)
//{
//	int* a = (int*)calloc(numsSize, sizeof(int));
//	int truesize = 0;
//	for (int i = numsSize - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int temp = 0;
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	int i = 0;
//	while (i < numsSize - 1)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			a[truesize] = nums[i];
//			truesize++;
//			i++;
//		}
//		i++;
//	}
//	int* new_a = (int*)realloc(a, truesize * sizeof(int));
//	*returnSize = truesize;
//	return new_a;
//}
 


//void founding(double* arr, int len, int num, int numdelete)
//{
//	int left = 0;
//	int right = len - 2;
//	int mid = (left + right) / 2;
//	int numi = -1;
//	int idelete;
//	int flag = 1;
//	while (left <= right)
//	{
//		if (numdelete > *(arr + mid))
//			left = mid + 1;
//		else if (numdelete == *(arr + mid))
//		{
//			idelete = mid;
//			flag = 0;
//			break;
//		}
//		else
//			right = mid - 1;
//		mid = (left + right) / 2;
//	}
//	for (int i = idelete; i < len - 1; i++)
//	{
//		*(arr + i) = *(arr + i + 1);
//	}
//	left = 0;
//	right = len - 3;
//	mid = (left + right) / 2;
//	while (left <= right)
//	{
//		if (num > *(arr + mid))
//			left = mid + 1;
//		else if (num == *(arr + mid))
//		{
//			numi = mid;
//			break;
//		}
//		else
//			right = mid - 1;
//		mid = (left + right) / 2;
//	}
//	if (left > right)
//		numi = left;
//	for (int i = len - 1; i > numi; i--)
//	{
//		*(arr + i) = *(arr + i - 1);
//	}
//	*(arr + numi) = num;
//}

//double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
//{
//	int flag = 0;
//	if (k % 2 == 0)
//		flag = 1;
//	*returnSize = numsSize - k + 1;
//	double* a = (double*)calloc(*returnSize, sizeof(double));
//	double* window = (double*)calloc(k + 1, sizeof(double));
//	for (int i = 0; i < k; i++)
//	{
//		window[i] = nums[i];
//	}
//	for (int i = 0; i < k; i++)
//	{
//		int count = 0;
//		for (int j = 0; j < k - i - 1; j++)
//		{
//			if (window[j] > window[j + 1])
//			{
//				double temp = window[j];
//				window[j] = window[j + 1];
//				window[j + 1] = temp;
//				count++;
//			}
//		}
//		if (count == 0)
//			break;
//	}
//	if (flag)
//		a[0] = (window[k / 2 - 1] + window[k / 2]) / 2.0;
//	else
//		a[0] = window[k / 2];
//	int count = 1;
//	for (int i = k; i < numsSize; i++)
//	{
//		founding(window, k + 1, nums[i], nums[i - k]);
//		if (flag)
//			a[count] = (window[k / 2 - 1] + window[k / 2]) / 2;
//		else
//			a[count] = window[k / 2];
//		count++;
//	}
//	return a;
//}


int main_6554()
{
	/*int nums[] = { 1,3,-1,-3,5,3,6,7 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int k = 3;
	int returnSize;

	printf("输入数组: ");
	for (int i = 0; i < numsSize; i++) {
		printf("%d ", nums[i]);
	}
	printf("\n");
	printf("窗口大小: %d\n\n", k);

	double* result = medianSlidingWindow(nums, numsSize, k, &returnSize);

	printf("\n最终结果: ");
	for (int i = 0; i < returnSize; i++) {
		printf("%.1f ", result[i]);
	}
	printf("\n");

	printf("期望结果: 1.0 -1.0 -1.0 3.0 5.0 6.0\n");

	free(result);*/
	//int a[100];
	printf("helloworld");
	/*typedef int (*zhizhen)(int, int);
	zhizhen biao[4];
	biao[0] = jia;
	biao[1] = jian;
	biao[2] = cheng;
	biao[3] = chu;
	int a;
	int b;
	int k;
	printf("请输入两个整数以及你要进行的操作编号：");
	scanf("%d%d%d", &a, &b, &k);
	switch (k)
	{
		case 0:
			biao[0](a, b);
			break;
		case 1:
			biao[1](a, b);
			break;
		case 2:
			biao[2](a, b);
			break;
		case 3:
			biao[3](a, b);
			break;

	}*/




	/*int* p1 = arr;
	int* p2 = &arr;
	printf("%p\n", p2 + 1);
	printf("%p", p1 + 2);*/

	//int a[1024];
	//srand(time(NULL));
	//for (int i = 0; i <= 1023; i++)
	//{
	//	a[i] = rand() % 1024 + 1;
	//	int num = a[i];
	//	if (contains(a, num, i))      //生成随机不重复数组
	//	{
	//		i--;
	//	}
	//}
	//int len = sizeof(a) / sizeof(int);
	//int nu;
	//printf("请输入一个整数\n");
	//scanf("%d", &nu);
	//int biao = searchch(a, nu,len);
	//printf("对应下标为%d", biao);
		//prinm(a, 10);
		//int max;
		//int min;
		//maxmin(a, 10, &max, &min);
		//printf("%d,%d",max, min);
		/*for (int i = 8; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
			{                             升序
				swap(&a[j], &a[j + 1]);
			}
		}*/
		/*int L = 0;
		int R = 9;
		int key;
		printf("请输入你要查找的数字：");
		scanf("%d", &key);
		int M;
		while (L <= R)
		{
			M = (L + R) / 2;
			if (a[M] == key)
			{
				printf("找到了！对应位置是%d", M + 1);
				break;
			}
			else if (a[M] > key)             //二分查找
			{
				R = M - 1;
			}
			else
			{
				L = M + 1;
			}
		}
		if (L > R)
		{
			printf("哎没有找到哦，给你看看数组吧！");
			printfw(a, 10);
		}*/

		//printfw(a, 10);
		/*int sum = 0;
		for (int k = 0; k <= 9; k++)
		{
			sum += a[k];
		}
		float jun = sum / 10;
		int c = 0;
		for (int j = 0; j <= 9; j++)
		{
			if (a[j] < jun)
				c = c + 1;
		}

		printf("这个随机数组的和为%d\n平均值为%f\n比平均值小的数有%d个", sum, jun, c);
		int j = 9;
		printf("这个数组反转前为:\n");
		for (int i = 0; i < 10; i++)
		{
			printf("%d\n", a[i]);
		}
		for (int i = 0; i < j; i++)
		{
			change(&a[i], &a[j]);
			j--;
		}
		printf("这个数组反转后为:\n");
		for (int i = 0; i < 10; i++)
		{
			printf("%d\n", a[i]);
		}*/
	/*作业一
	char namai[100] = "没有捏";   括号内为内存占用大小.
	printf("我亲亲女朋友的名字为：%s\n", namai);
	int suishu;
	printf("请输入你的年龄：");
	scanf("%d", &suishu);
	printf("我的年龄是：%d\n", suishu);*/

	/*作业二
	printf("请输入一个三位数：");
	int san;
	scanf("%d", &san);
	int bai = san / 100;
	san = san % 100;
	int shi = san / 10;
	san = san % 10;
	printf("这个三位数的百十个位数分别为%d %d %d", bai, shi, san);*/

	/*test
	float chang;
	float kuan;
	float gao;
	printf("请输入三个小数分别表示长宽高：");
	scanf("%f %f %f", &chang, &kuan, &gao);
	printf("该长方体的表面积为:%.2f",(chang*kuan+chang*gao+kuan*gao)*2);
	float tiji = chang * kuan * gao;
	printf("该长方体的体积为：%.2f", tiji);*/

	/*题目
	int num1;
	int num2;
	printf("请输入两个两位整数：\n" );
	scanf("%d\n%d", &num1, &num2);
	int num3 = num1 % 10;
	int num4 = num2 % 10;
	int num5 = num2 % 7;
	printf("num1为%d\nnum2为%d\n", num1, num2);
	num1 /= 10;
	num2 /= 10;
	printf("对于num1是否带7的判定结果为：%d\n", num3 != 7 && num1 != 7);
	printf("对于num2是否带7且非7的倍数的判定结果为：%d\n", num3 != 7 && num1 != 7 && num5 != 0);*/

	//题目
	/*int paia = 5;
	int paib = 5;
	int shua = 6;
	int shub = 8;
	if (paia = paib && (shua - shub == 1 || shua - shub == -1))
	printf("太棒了");
	else
	printf("那很坏了");*/

	//题目
	/*int fenshu;
	printf("请输入你本次考试的分数：\n");
	scanf("%d", &fenshu);
	if (fenshu >= 95 && fenshu <= 100)
	printf("666");
	else if (fenshu >= 90 && fenshu <= 94)
	{
	printf("可以啊兄弟");
	}
	else if (fenshu >= 85 && fenshu <= 89)
	{
	printf("还行吧");
	}
	else if (fenshu >= 0 && fenshu <= 84)
	{
	printf("还得练老弟");
	}
	else
	printf("不儿哥们别搞啊");*/

	/*switch练习
	int week;
	printf("请输入今天是周几：\n");
	scanf("%d", &week);
	switch (week)//字符或者整数
	//如果没有break case语句将穿透下去
	{
	case 1://字符或者整数，不能是变量
		printf("run\n");
		break;
	case 2:
		printf("swim\n");
		break;
	case 3:
		printf("slow walk\n");
		break;
	case 4:
		printf("I don't know");
		break;
	case 5:
		printf("fight");
		break;
	case 6:
		printf("panpa");
		break;
	case 7:
		printf("eat a big");
		break;
	default:
		printf("别搞哥们\n");
		break;
	}*/

	/*打印数字练习
	int i;
	int he = 0;
	for ( i = 1; i <= 50; i++)
	{
		printf("%d", i);
		he += i;
	}
	printf("%d", he);
	int ouhe = 0;
	for (int ou = 0; ou <= 100; ou += 2)
		ouhe += ou;
	printf("%d", ouhe);*/


	/*int zuo;
	int you;
	int jige = 0;
	printf("请输入一个范围：\n");
	scanf("%d %d", &zuo, &you);
	for (int liuba = zuo; liuba <= you; liuba++)
	{
		if (liuba % 6 == 0 && liuba % 8 == 0)
		{
			printf("%d\n", liuba);
			jige++;
		}
	}
	printf("这个范围内liuba有%d个\n", jige);*/

	/*循环算法题
	int i;
	int tong = 0;
	int c;
	printf("请输入一个整数");
	scanf("%d", &i);
	while (i > 2)
	{
		int c = i % 2;
		tong += c;
		i = i / 2;
	}
	if (tong == 0)
		printf("i是2的指数倍");
	else {
		printf("i不是2的指数倍");
	}*/
	/*int zhu = 1;
	int shu = 0;
	while (zhu <= 8844430)
	{
		zhu *= 2;
		shu += 1;
	}
	printf("折叠次数为%d", shu);*/


	/*printf("请输入一个正整数\n");
	int zhengshu;
	scanf("%d", &zhengshu);
	int i = 1;
	while (i * i <= zhengshu)
	{
		i++;
	}
	printf("这个整数的算数平方根为：%d", i - 1);

	int duibi = zhengshu;
	int jie = 0;
	while (zhengshu > 0)
	{
		int shu = zhengshu % 10;
		zhengshu /= 10;
		jie = jie * 10 + shu;
	}
	if (jie == duibi)
		printf("是回文数%d", jie);
	else
	{
		printf("不是回文数%d", jie);
	}*/

	/*for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (int k = 1; k <= 5; k++) 
	{
		for (int u = 1; u <= k; u++)
		{
			printf("*");
		}
		printf("\n");
	}*/
   /* for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t ", j, i, j * i);
		}
		printf("\n");
	}*/
	/*int n;
	int d = 0;
	printf("请输入一个整数：");
	scanf("%d", &n);
	int zong = n - 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j < i; j++)
		{
			int c = i % j;
			if (c == 0)
			{
				d = 1;
			}
		}
		zong -= d;
		d = 0;
	}
	printf("小于等于%d的质数有%d个", n, zong);*/

	//int a = 50;
	//int b = 60;
	//int c = sum(a, b);
	//printf("%d", c);
	//char* p1 = "Program";
	//printf("%p", p1);
	//scanf("%d%", a);
	//
	//srand(time(NULL));
	//int num = rand() % 100 + 1;
	//int i = 0;
	//while (i < 15)
	//{
	//	printf("开始猜");
	//	int a = 0;
	//	scanf("%d", &a);
	//	if (a == num)
	//		break;
	//	else
	//	{
	//		i++;
	//	}
	//}
	//if (i < 15)
	//{
	//	printf("猜对了！");
	//}
	//else
	//{
	//	printf("菜，正确的答案是%d", num);
	//}

	/*int n;
		int a;
		int c = 0;
		int he = 0;
		printf("输入n与a：");
		scanf("%d %d", &n, &a);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				c = c * 10 + a;
			}
			he = he + c;
			c = 0;
		}
		printf("结果为：%d", he);*/
	/*char a = 'a';
	char b = 's';
	swap(&a, &b, 1);
	printf("%c%c", a, b);*/

	return 0;
}	
