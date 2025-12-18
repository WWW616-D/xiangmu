#include<stdio.h>
#include<stdlib.h>

int main_6543()
{
	int map[100][100];
	for (int i=0;i<100;i++)
	{
		for (int j=0;j<100;j++)
		{
			map[i][j] = 0;
		}
	}
	//若存在边则设置对应位置为1
	//当边稀疏的时候，可以考虑制作一个链表数组，每个链表存储对应节点的所有邻居
}