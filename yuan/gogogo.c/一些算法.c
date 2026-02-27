#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int read()
{
	int f = 1;
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') 
			f = -1;  
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0'); 
		ch = getchar();
	}
	return x * f;  
}
void write(int x)
{
	if (x == 0) 
	{
		putchar('0');
		return;
	}

	if (x < 0) 
	{
		putchar('-');
		x = -x;
	}
	char buffer[20];
	int len = 0;
	while (x > 0)
	{
		buffer[len++] = x % 10 + '0';
		x /= 10;
	}
	for (int i = len - 1; i >= 0; i--) 
	{
		putchar(buffer[i]);
	}
}
void threesort(int* a,int left,int right)
{
	if (left >= right)
		return;
	int q = left;
	int p = right;
	int mid = a[(left + right) / 2];
	printf("我们取的基准值为%d\n", mid);
	int i = left;
	while(i<=p)
	{
		if (a[i] < mid)
		{
			printf("我们交换了%d %d\n", a[i], a[q]);
			int temp = a[i];
			a[i] = a[q];
			a[q] = temp;
			q++;
			i++;
		}
		else if (a[i] > mid)
		{
			printf("我们交换了%d %d\n", a[i], a[p]);
			int temp = a[i];
			a[i] = a[p];
			a[p] = temp;
			p--;
		}
		else
			i++;
	}
	threesort(a, left, q - 1);
	threesort(a, p + 1, right);
}
void quicksort(int* a,int left, int right)
{
	if (left>=right)
	{
		return;
	}
	int q = left;
	int p = right;
	int mid = a[(q + p) / 2];
	printf("以下交换的基准值为%d\n", mid);
	while (q<=p)
	{
		while (a[q]<mid)
		{
			q++;
		}
		while (a[p]>mid)
		{
			p--;
		}
		if (q <= p)
		{
			printf("%d 和 %d发生了交换\n", a[q], a[p]);
			int temp = a[p];
			a[p] = a[q];
			a[q] = temp;
			q++;
			p--;
		}
	}
	quicksort(a, left, p);
	quicksort(a, q, right);
}
int quickselect(int* a,int left,int right,int k)
{
	int q = left;
	int value = a[right];
	for(int i=left;i<right;i++)
	{
		if(a[i]<value)
		{
			int temp = a[i];
			a[i] = a[q];
			a[q] = temp;
			q++;
		}
	}
	a[right] = a[q];
	a[q] = value;
	int rank = q - left + 1;
	if (rank==k)
	{
		return value;
	}
	if (rank>k)
	{
		return quickselect(a, left, q - 1, k);
	}
	if (rank < k)
	{
		return quickselect(a, q+1, right, k-rank);
	}
	return -1;
}
int main_564488()
{
	/*int a = read();
	write(a);
	write(5654);*/
	srand(time(NULL));
	int a[10];
	for (int i=0;i<10;i++)
	{
		a[i] = rand() % 50 + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	threesort(a,0,9);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

}