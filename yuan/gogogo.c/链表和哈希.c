#include<stdio.h>
#include<stdlib.h>
#define NUM 10
typedef struct node
{
	int len;
	int kuan;
	int height;
	struct node* next;
	struct node* before;
}num;
typedef struct HashList
{
	int num;
	int* data;
	char* current;
}hash;
hash* initlist()
{
	hash* list = (hash*)malloc(sizeof(hash));
	list->num = 0;
	list->data = (int*)calloc(NUM,sizeof(int));
	list->current = (char*)calloc(NUM, sizeof(char));
	return list;
}
int gethash(int data)
{
	return data % NUM;
}
void put(hash* list, int data)
{
	int index = gethash(data);
	int start = index;
	if (list->current[index] > 0)
	{
		int count = 1;//这是一个典型的开放寻址法，需要注意
                      //采用另一个哈希函数作为步长可能是更好的选择
					  //以及当碰撞次数过多的时候可以考虑再扩散为一个两倍的哈希表		
		while (list->current[index] > 0)
		{
			index = gethash(index + count);
			count++;
			if (index==start)
			{
				printf("这个哈希表满了\n");
				return;
			}

		}
	}
	list->data[index] = data;
	list->current[index] = 1;
}
int main_1124()
{
	
	/*hash* list = initlist();
	printf("你好");
	put(list, 10);
	put(list, 20);
	printf("你好%d\n%d\n", list->data[0],list->data[1]);*/
	/*num* head = NULL;
	num* tail = NULL;
	num* back = NULL;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		num* newnode = (num*)malloc(sizeof(num));
		newnode->len = rand() % 20 + 1;
		newnode->next = NULL;
		newnode->before = back;
		back = newnode;
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
	num* p = head;
	while (p != NULL)
	{
		printf("%d\n", p->len);
		p = p->next;
	}
	p = head;
	num* q = NULL;
	int num1 = rand() % 20 + 1;
	printf("你要删除的数字是%d\n", num1);
	while (p != NULL && ((p->len) != num1))
	{
		q = p;
		p = p->next;
	}
	if (p != NULL)
	{
		printf("你的链表中存在num1\n");
		if (p == head)
		{
			head = p->next;
		}
		else
		{
			q->next = p->next;
			if (p->next == NULL)
			{
				tail = q;
			}
		}
		free(p);
		p = head;
		while (p != NULL)
		{
			printf("%d\n", p->len);
			p = p->next;
		}
	}
	else
	{
		printf("没找到喵");
	}
	printf("代码到这里执行了\n");
	while (1)
	{
		int count = 1;
		p = head->next;
		q = head;
		printf("你好\n");
		while (p != NULL)
		{
			if ((p->len) < (q->len))
			{
				count = 0;
				if (q == head)
				{
					head = p;
					p->before = NULL;
					q->before = p;
					q->next = p->next;
					p->next = q;
					q = p;
					p = q->next;
				}
				else if (p == tail)
				{
					tail = q;
					q->before->next = p;
					q->next = p->next;
					p->before = q->before;
					p->next = q;
					q->before = p;
					break;
				}
				else
				{
					q->before->next = p;
					p->next->before = q;
					q->next = p->next;
					p->before = q->before;
					p->next = q;
					q->before = p;
					q = p;
					p = q->next;
				}
			}
			else
			{
				q = p;
				p = p->next;
			}
		}
		if (count)
		{
			break;
		}
	}
	printf("代码在这里执行了\n");
	p = head;
	while (p != NULL)
	{
		printf("%d\n", p->len);
		p = p->next;
	}
	num* newnode = (num*)malloc(sizeof(num));
	newnode->len = rand() % 100 + 1;*/
	return 0;
}