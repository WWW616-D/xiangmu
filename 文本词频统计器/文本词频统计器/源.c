#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 1007
typedef struct hashnode
{
	char* word;
	int count;
	struct hashnode* next;
}node;
typedef struct hashmap
{
	node** buckets;
}hashmap;
hashmap* createhashmap()
{
	hashmap* map = (hashmap*)malloc(sizeof(hashmap));
	map->buckets = (node**)calloc(size, sizeof(node*));
	return map;
}
unsigned int hash(char* str)
{
	unsigned int result=0;
	char* p = str;
	while(*p!='\0')
	{
		result += 33 * (int)*p;
		p++;
	}
	result = result % size;
	return result;
}
void putmap(hashmap* map,char* str,int* len)
{
	unsigned int key = hash(str);
	node* current = map->buckets[key];
	while(current!=NULL)
	{
		if (!strcmp(current->word,str))
		{
			current->count++;
			return;
		}
		current = current->next;
	}
	node* newnode = (node*)malloc(sizeof(node));
	newnode->count = 1;
	newnode->word = (char*)malloc((strlen(str) + 1) * sizeof(char));
	if (newnode->word == NULL) 
	{
		free(newnode);  
		return;
	}
	strcpy(newnode->word, str);
	newnode->next = map->buckets[key];
	map->buckets[key] = newnode;
	*len += 1;
}
void freehashmap(hashmap* map)
{
	for (int i= 0;i<size;i++)
	{
		node* p = map->buckets[i];
		while (p != NULL)
		{
			node* temp = p;
			p = p->next;
			free(temp->word);
			free(temp);
		}
	}
	free(map->buckets);
	free(map);
}
typedef struct heapnode
{
	int value;
	char* word;
}heapnode;
int dad(int num)
{
	return abs(num - 1) / 2;
}
int lchild(int num)
{
	return num * 2 + 1;
}
int rchild(int num)
{
	return num * 2 + 2;
}
void heapup(heapnode* heap, int num)
{
	while (num > 0 && heap[num].value > heap[dad(num)].value)
	{
			heapnode temp = heap[num];
			heap[num] = heap[dad(num)];
			heap[dad(num)] = temp;
			num = dad(num);
	}
}
void heapdown(heapnode* heap,int count)
{
	heapnode temp = heap[0];
	heap[0] = heap[count - 1];
	heap[count - 1] = temp;
	int p = 0;
	while (p*2+1<count-1)
	{
		int maxp = p;
		int max = heap[p].value;
		if (heap[lchild(p)].value > max)
		{
			maxp = lchild(p);
			max = heap[maxp].value;
		}
		if (rchild(p)<count-1 && heap[rchild(p)].value > max)
		{
			maxp = rchild(p);
			max = heap[maxp].value;
		}
		if (maxp == p)
			break;
		temp = heap[p];
		heap[p] = heap[maxp];
		heap[maxp] = temp;
		p = maxp;
	}
}
void clean_word(char* word) {
	int i, j = 0;
	for (i = 0; word[i] != '\0'; i++) 
	{
		if ((word[i] >= 'a' && word[i] <= 'z') ||
			(word[i] >= 'A' && word[i] <= 'Z') ||
			(word[i] >= '0' && word[i] <= '9') ||
			(word[i] == '-')) {
			word[j++] = word[i];
		}
	}
	word[j] = '\0';
}
int main()
{
	FILE* file = fopen("D:\\我的文档\\词组.txt", "r");
	if (file == NULL)
		return -1;
	hashmap* map = createhashmap();
	int len = 0;
	int* p = &len;
	char arr[1024];
	char* bad = ",.;!? \n\t:\"()[]-_'”“‘’—–•@#$%^&*+=/\\|<>{}~`;";
	while (1)
	{
		char* str = fgets(arr, 1024, file);
		if (str == NULL)
			break;
		char* word = strtok(arr, bad);
		while (word != NULL)
		{
			clean_word(word);
			_strlwr(word);
			if (strlen(word)>0)
				putmap(map, word,p);
			word = strtok(NULL, bad);
		}
	}
	heapnode* heap = (heapnode*)calloc(*p, sizeof(heapnode));
	int count = 0;
	for (int i=0;i<size;i++)
	{
		node* p = map->buckets[i];
		while(p!=NULL)
		{
			heap[count].value = p->count;
			heap[count].word = p->word;
			p = p->next;
			heapup(heap, count);
			count++;
		}
	}
	for (int i=0;i<50;i++)
	{
		printf("下面输出前10的高频词和对应次数：\n");
		printf("%s\t,%d\t\n", heap[0].word, heap[0].value);
		heapdown(heap,count);
		count--;
	}
	fclose(file);
	freehashmap(map);
}