#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long* byte_pointer;
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
int main()
{
	project2();
}