#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
//static:保存函数中变量到程序结束
void swap1(void* p1, void* p2, int len)
{
	char* pc1 = p1;
	char* pc2 = p2;
	char temp = 0;
	for (int i = 0; i < len; i++)
	{
		temp = *pc1;
		*pc1 = *pc2;
		*pc2 = temp;
		pc1++;
		pc2++;
	}
}
void swap(int* p1,int*p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void change(int* p1, int* p2)
{
	int temp = 0;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void changeda(int* p1, int* p2)
{
	if (*p1 > *p2)
	{
		int temp = 0;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
void changexiao(int* p1, int* p2)
{
	if (*p1 < *p2)
	{
		int temp = 0;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}
int mmax(int n1, int n2)
{
	return(n1 > n2 ? n1 : n2);
}
int sum(int num1, int num2)
{
	int sum = num1 + num2;
	printf("%d", sum);
	return sum;
}
int contains(int a[], int num, int len)
{
	for (int n = 0; n < len; n++)
	{
		if (a[n] == num)
			return 1;
	}
	return 0;
}
void maxmin(int a[], int len, int* max, int* min)
{
	*max = a[0];
	for (int i = 1; i < len; i++)
	{
		if (a[i] > *max)
		{
			*max = a[i];
		}
	}
	*min = a[0];
	for (int i = 1; i < len; i++)
	{
		if (a[i] < *min)
		{
			*min = a[i];
		}
	}
}
void prinm(int a[], int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		printf("%d\n", a[i]);
	}

}

void prinw(int a[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d\n", a[i]);
}
int searchch(int* data, int num, int len)
{
	
	for (int i = 0; i < len; i++)
	{
		if (num == data[i]) 
		{
			return i;
		}

	}
	return -1;
}
void array(int nums[],int numsSize)
{
	int count = 0;
	for (int i = numsSize - 1; i > 0; i--)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				int temp = 0;
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
				count++;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
void jia(int x, int y)
{
	printf("%d", x+y);
}
void jian(int x, int y)
{
	printf("%d", x-y);
}
void cheng(int x, int y)
{
	printf("%d", x*y);
}
void chu(int x, int y)
{
	printf("%d", x/y);
}
//一些陌生标准库函数
//strcmp(char char)    //判断两个单词是否相同   返回布尔
//free(arr)            //释放之前被malloc calloc realloc 分配的内存
//isalpha()            //检测输入内容是否为字符 返回布尔
// *p= malloc(size_t*size)   分配指定大小的内存块返回首地址
// calloc(size_t,size)//分配内存，初始化为0
//realloc(*p size_t*size)改变之前分配的内存返回新的地址
//strncpy(word start len)将start地址开始长度为len的字符串复制到word
//int compare(const void* a,const void* b)
//{
//	const int* inta = (const int*)a;
//	const int* intb = (const int*)b;
//	return *inta - *intb;
//}
//qsort(nums,len,sizeof,compare)
//字符串相关的库函数
//strlen(str)   求字符串长度(无休止符)
//strcat(str,str)拼接(第一个字符串要可以修改)
//strcpy(str,str)拷贝(后者覆盖前者同上)
//strcmp(str,str)比较(一样出0不一样出1)
//strlpr(str)改成大写strlwr(str)改成小写
//void* memset(void* ptr, int value, size_t num);初始化一个内存
typedef struct
{
	char name[100];
	int a;
	int b;
	int c;
	
}XT;
typedef struct yuanshen
{
	char name[100];
	XT tie;
}YS;

int main_aslkw()
{
	/*
	%d 整型
	%u 无符号整型
	%f 实数型
	%c 字符型
	%s 字符串
	%p 指针
	%x 16进制
	%o 8进制

	*/
	//变量需要统一定义在上方
	/*int b = 20;
	int a = 10;
	int money = 10;
	char d = 'a';*/

	//money = money + 2;
	//进制
	// 0b 二进制
	// 0  八进制
	// 0x 十六进制
	/*int e = 0b10000;*/
	  
	//const 使用const定义的变量无法更改
	/*short 短整型 (-32768~32767)2
	* int 整型4
	* long 长整型4
	* long long 长长整型8
	* signed int (有符号整数)
	* unsigned int (无符号整数）不能和double一起用
	*/
	/*
	* float  4
	* double 8
	*
	*/

	//double u = 1.011654654;
	/*转义字符
	//换行符 \n
	// 输出单斜杠\\
	//水平制表符\t:8格自填空对齐(大于8变16)
	*/
	//char m = 'A';
	//键盘录入：scanf
	/*int lj;
	printf("请输入你的力量：");
	scanf("%d", &lj);
	int num1;
	int num2;
	printf("请依次输入两个数字：\n");
	scanf(" %d %d", &num1, &num2);
	printf("您打出飞剑回旋镖＋的伤害为：%d\n", (lj + 3) * 4);
	printf("求和结果为%d\n", num1 + num2);*/

	//整数与整数运算结果为整数
	//小小=小
	//整小=小
	//short char 运算时会转变为int
	//计算时取值范围小的会往大的转变
	/*取值范围排名：
	* double
	* float
	* longlong
	* long
	* int
	* short
	* char
	*/

	//字符转数字会查询ascll码表
	// 97a 65A  
	//强制转换
	//int da = 1008;
	//short xiao = (short)da;
	//printf("%d\n", xiao);

	//++(变量自＋1)--(同)
	//前缀先于后缀，后缀优先级最低
	//int jia = 10;
	//jia++;
	//jia++;
	//jia--;
	//int jiajia = jia++;//若此处为++jia则结果为jia+2

	//+= -= *= /= 
	//a/=b:a=a/b
	//== != > >=(关系比较)(成立1不成立0)
	//printf("%d\n", a <= b);
	//&&:同and 左0右不执行
	//||:同or  左1右不执行
	//!:非
	//逻辑运算符中非0均为真（1）
	//三元运算符：关系表达式？表达式1:表达式2;(成立则出前，不成立则出后)
	//printf("a和b之间较大的那个数是：%d\n", a > b ? a : b);

	//运算符优先级：
	//小括号>一元>二元>三元
	//&&>||>赋值

	//if (a > 10)//括号中非0则成立，0则不成立
	//{
	//	printf("a真的大于10\n");
	//}
	//else if (a == 10)
	//{
	//	printf("a就是10！\n");
	//}
	//else
	//{
	//	printf("a小小的捏\n");
	//}

	//for循环  变量只在所属的大括号里面有用
	/*for (int i = 1; i <= 50; i++)
	{
		printf("666\n");
	}*/
	/*for (; ;)
	{
		printf("你好");
	}
    */

	//while while中的变量可以在外面用
	/*int w = 1;
	while (w <= 5) 
	{
		printf("wendiwendi\n");
		w++;
	}
	while (1)
	{

	}

	//do...while循环
	//先执行后判断
	int i = 1;
	do {
		printf("%d\n", i);
		i++;
	} while (i <= 5);
	do
	{
	
	}while (1);
	continue:结束本次循环
	break:结束循环
	goto:结合标号可让代码跳转
	     一般用于跳出循环
    */

//int a[10] = { 0,5,5,66,8,9,4,7,5,6 };
//a[5] = 156;
//printf("%X,%d", a, a[5]);//数组名字或第一个元素地址即首地址 
//数组参与运算会退化为首地址 除了sizeof
//数组在函数中使用时不是一个完整数组只是首地址 
//int len = sizeof(a) / sizeof(a[0]);
//printf("%d", len);

//指针和数组

//int x = 100;
//int* p = NULL;//(只指向int类型的变量)     void类型的指针可以接受任意指针的地址
//p = &x;      指针内存大小只与操作系统有关 但是无法获取数据或者加减
//printf("%d", *p);
//int x1, x2, temp;
//int* p1 = &x1, * p2 = &x2;
//printf("请输入两个数：");
//scanf("%d %d", &x1, &x2);
//if (x1 < x2)
//{
//	temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;//此处实际上指针未移动而是交换了变量值
//}
////若想移动指针，将temp初始赋值为悬空指针即可
////即用 temp=p1 p1=p2,p2=temp(*p是变量，p是指针)
//printf("%d,%d\n", x1, x2);
//printf("%d.%d\n", *p1, *p2);

//int a[10] = { 0,5,5,66,8,9,4,7,5,6 };
//a[5] = 156;
//int* p = a;
//int* p2 = &a[6];
//char* p1 = "Program";
//printf("%p\n,%p\n", p, (void*)p1);
//p = p + 1;
//printf("%d\n", *p);
//printf("%d", p2 - p);
//int data[10];
//int* p = data;
//for (int i = 1; i <= 10; i++) 
//{
//	scanf("%d", p++);
//}
//p = data;
//for (int i = 1; i <= 10; i++)
//{
//	printf("%d", *p);
//	p++;
//}
//char* string = "ni hao";
//printf("%s", string);
//char string[81];
//char* p = string;
//int i = 0;
//int counter = 0;                   
//fgets(p, 81, stdin);    字符串输出
//while (*p != '\0' && i <= 80)
//{
//	printf("%c", *p);
//	p++;
//	i++;
//}
//printf("%d", i);
//int* p = (int*)malloc(sizeof(int)*100);
//int* pyuan = p;
//for (int i = 1; i <= 100; i++) 
//{
//	*p = i;
//	printf("%d\n", *p);
//	p++;
//}
//int* pxin = realloc(pyuan,125 * sizeof(int));
//printf("%p\n%p\n", pyuan, pxin);
//for (int i = 1; i <= 125; i++)
//{
//	*pyuan = i;
//	printf("%d\n", *pyuan);
//	pyuan++;
//}

//for (int i = 1; i <= 125; i++)
//{
//	*pyuan = i;
//	printf("%d\n", *pyuan);
//	pyuan++;
//}
//free(pyuan);
//printf("%d\n", *(p-1));
//
//int a = 10;
//int b = 20;
//swap(&a, &b);
//printf("%d%d", a, b);
//long long res = time(NULL);
//
//printf("%lld\n", res);
//srand(time(NULL));
//for (int i = 1; i <= 100; i++)
//{
//	int num = rand() % 100 + 1;
//	printf("%d\n", num);
//}

//int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
//int(*p)[3] = a;//行指针
//printf("%d\n", *(*(p+1)+1));//列指针
//int* pa[3] = { a[0],a[1],a[2] };//指针数组
//printf("%d\n", *(pa[2]+1));//等价a[2][1]
//int (*pf)(int,int);//函数指针，返回int，形参为两个int
//typedef int (*zhizhen)(int, int);
//zhizhen pf;
//zhizhen pm[5];int (*pf[5])(int,int);//函数指针数组
//pf = sum;
//pf(a[0][1], a[0][2]);
//main_56();

               
						// 结构体
//XT xing = { "星",100,1000,10000 };
// YS zhongli;
// strcpy(zhongli.tie.name, "钟离");
// struct yuanshen wendi;
// struct yuanshen yinlang;
// struct yuanshen hutao;
// strcpy(wendi.name, "温迪");
// strcpy(yinlang.name, "银狼");
// strcpy(hutao.name, "胡桃");
// struct yuanshen arr[3] = { wendi,yinlang,hutao };//循环时采用下标来指代结构体
// 
// printf("wendi的名字是%s\n%s", wendi.name,zhongli.tie.name);

                        //文件读写
						//读
//  r:只读
//  w:只写             会清空原文件
//  a:追加写出         不会
//  rb:二进制只读 (视频，音频)
//  wb:二进制只写
//  ab：二进制追加写出
FILE* file = fopen("D:\\代码\\abc.txt", "r");
FILE* file1 = fopen("D:\\代码\\gogogo.c\\aaa\\a.txt","w");
char arr[1024];
int n;
while ((n = fread(arr,1,1024,file))!=0)
{
	fwrite(arr, 1, n, file1);
}
//char a[5] = {97,98,99,100,102};
//char c;
//while ((c = fgetc(file)) != -1)    //读不到返回-1
//{
//	printf("%c\n", c);
//}

//char* str1=fgets(arr, 1024, file);     //读不到返回null
//char* str2 = fgets(arr, 1024, file);
//char* str3 = fgets(arr, 1024, file);
//printf("%s\n %s\n %s\n", str1,str2,str3);

//int n;
//while ((n = fread(arr, 1, 2, file)) != 0)
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("%c", arr[i]);
//	}
//}
//int c = fputc(98, file);
//int d=fputs("你好你好你好", file);
//int f=fputs("你好你好你好", file);
//int e=fwrite(a, 1, 5, file);
fclose(file);
fclose(file1);
                           //
//FILE* file1 = fopen("aaa\\a.txt","r");
//fputc
//作为输出区
//printf("hello world\n");
//printf("%f\n", 1.83);
//printf("我推的名字是：%s\n", "温迪");
//printf("%d\t%d\n", b + a, money);
//printf("%c\n", d);
//printf("%zu\n", sizeof(a));
//printf("%d\n", e);
//printf("%.2f\n", u);//.2用于精确两位
//printf("%c\n", m);
//printf("%d\n", jia);
//printf("%d\n", jiajia);
	

    return 0;
}