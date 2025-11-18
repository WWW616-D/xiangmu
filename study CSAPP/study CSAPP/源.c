#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef unsigned char* byte_pointer;
int tmult_ok(int x, int y) {
	long long llp = (long long)x * y;
	return llp == (int)llp;
}
int tadd_ok(int a, int b)
{
	if (b >= 0)
	{
		return a > INT_MAX - b;
	}
	if (b < 0)
	{
		return a < INT_MIN - b;
	}
}
void show_bytes(byte_pointer start,size_t len)
{
	size_t i;
	for (i = 0; i < len; i++)
	{
		printf("%.2x ", start[i]);
	}
	printf("\n");
}
void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}
void show_pointer(void* x)
{
	show_bytes((byte_pointer)&x, sizeof(void*));
}
void project1()
{
	int ival = 0x87654321;
	byte_pointer valp = (byte_pointer)&ival;
	show_bytes(valp, 1);
	show_bytes(valp, 2);
	show_bytes(valp, 3);
	show_bytes(valp, 4); 
		a:
	printf("请输入你要的数字:\n");
	if (scanf("%d", &ival) == 1)
	{
		float fval = (float)ival;
		int* pval = &ival;
		show_int(ival);
		show_float(fval);
		show_pointer(pval);
	}
	else
	{
		printf("请重新输入:\n");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		goto a;
	}
}
void project2()
{
	int x = 0x87654321;
	x = x ^ ~0xFF;
	int y = x | 0xFF;
	printf("%x %x", x, y);
}
int fun1(unsigned word)
{
	return (int)((word << 24) >> 24);
}
int fun2(unsigned word)
{
	return ((int)word << 24) >> 24;
}
int main()
{
	short x = -12345;
	unsigned short usx = x;
	int sx = x;
	unsigned ux = usx;
	show_bytes((byte_pointer)&x, sizeof(short));
	show_bytes((byte_pointer)&usx, sizeof(unsigned short));
	show_bytes((byte_pointer)&sx, sizeof(int));
	show_bytes((byte_pointer)&ux, sizeof(unsigned));
	unsigned a = 0x000000C9;
	printf("%d\n%d", fun1(a), fun2(a));
}
//无符号数的减法结果永远不会是负数;
//大整数转float再转回整数可能会变化数值.