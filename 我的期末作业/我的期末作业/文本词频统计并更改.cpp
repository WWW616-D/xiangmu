#include"works.h"
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
	unsigned int result = 0;
	char* p = str;
	while (*p != '\0')
	{
		result += 33 * (int)*p;
		p++;
	}
	result = result % size;
	return result;
}
void putmap(hashmap* map, char* str, int* len)
{
	unsigned int key = hash(str);
	node* current = map->buckets[key];
	while (current != NULL)
	{
		if (!strcmp(current->word, str))
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
	for (int i = 0; i < size; i++)
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
void clean_word(char* word) {
	int i, j = 0;
	for (i = 0; word[i] != '\0'; i++)
	{
		if ((word[i] >= 'a' && word[i] <= 'z') ||
			(word[i] >= 'A' && word[i] <= 'Z') ||
			(word[i] >= '0' && word[i] <= '9') ||
			(word[i] == '-')||
			word[i] == '\'') {
			word[j++] = word[i];
		}
	}
	word[j] = '\0';
}
typedef struct words
{
	char word[50];
	int count;
}words;
int compare(const void* x, const void* y) 
{
	words* xx = (words*)x;
	words* yy = (words*)y;
	return yy->count - xx->count;
}
int strflag(char c) 
{
	if ('a' <= c && 'z' >= c)
		return 0;
	if ('A' <= c && 'Z' >= c)
		return 0;
	if (c == '_' || c == '\''||c == '-')
		return 0;
	return 1;
}
int findmaxnum(hashmap* map,char* word)
{
	unsigned int index = hash(word);
	node* current = map->buckets[index];
	while (current != NULL)
	{
		if (!strcmp(current->word, word))
		{
			return current->count;
		}
		current = current->next;
	}
}
void WordsCountAndChange()
{
	printf("现在显示该文章的词频统计结果:\n");
	FILE* file = fopen("D:\\代码\\我的期末作业\\文章.txt", "r");
	if (file == NULL)
		return;
	hashmap* map = createhashmap();
	int len = 0;
	char arr[1024];
	const char* bad = " ,.;!?\n\t:\"()[]{}<>@#$%^&*+=/\\|~`";
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
			if (strlen(word) > 0)
				putmap(map, word, &len);
			word = strtok(NULL, bad);
		}
	}
	words* all = (words*)malloc(len * sizeof(words));
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		node* p = map->buckets[i];
		while (p != NULL)
		{
			all[count].count = p->count;
			strcpy(all[count].word,p->word);
			p = p->next;
			count++;
		}
	}
	qsort(all, count,sizeof(words), compare);
	FILE* filecount = fopen("D:\\代码\\我的期末作业\\词汇计数.txt","w");
	for (int i = 0; i < count; i++)
	{
		printf("%s\t,%d\t\n", all[i].word, all[i].count);
		fprintf(filecount, "%s %d\n", all[i].word, all[i].count);
	}
	fclose(filecount);
	fclose(file);
	file= fopen("D:\\代码\\我的期末作业\\文章.txt", "r");
	FILE* fileout = fopen("D:\\代码\\我的期末作业\\新的文章.txt","w");
	char from[100];
	char to[100];

a:

	printf("请输入你要更改的单词:\n");
	scanf("%s", from);
	printf("请输入你要把这个单词改成什么:\n");
	scanf("%s", to);
	char temp[100];
	char before[100];
	char long_before[100];
	before[0] = '\0';
	long_before[0] = '\0';
	char c;
	int tempindex = 0;
	int beforeflag = 0;
	printf("请选择你要全部替换还是替换部分:\n1:替换全部\n2:替换部分\n");
	int choice;
	scanf("%d", &choice);
	if (choice == 1)
	{
		int maxnum = findmaxnum(map, from);
		if (!maxnum)
		{
			printf("你要替换的单词并不存在!\n");
			goto a;
		}
		while ((c = fgetc(file)) != EOF)
		{
			int flag = strflag(c);
			if (flag != beforeflag)
			{
				temp[tempindex] = '\0';
				if (!strcmp(temp, from))
				{
					fprintf(fileout, "%s", to);
				}
				else
				{
					fprintf(fileout, "%s", temp);
				}
				tempindex = 0;
			}
			temp[tempindex] = c;
			tempindex++;
			beforeflag = flag;
		}
	}
	else if (choice==2)
	{	
		int maxnum = findmaxnum(map, from);
		if (!maxnum)
		{
			printf("你要替换的单词并不存在!\n");
			goto a;
		}
		int currentcount = 0;
		while ((c = fgetc(file)) != EOF)
		{
			int flag = strflag(c);
			if (flag != beforeflag)
			{
				temp[tempindex] = '\0';
				
				if (!strcmp(temp, from))
				{
					int current;
					printf("现在遇到了一个%s,是第%d个单词,它的上两个单词是%s,%s\n输入1则替换,输入其他则不换\n", from, currentcount,long_before,before);
					scanf("%d", &current);
					if (current==1)
						fprintf(fileout, "%s", to);
					else
						fprintf(fileout, "%s", temp);
				}
				else
				{
					fprintf(fileout, "%s", temp);
				}
				tempindex = 0;
				if (flag == 1)
				{
					currentcount++;
					strcpy(long_before, before);
					strcpy(before,temp);
				}
			}
			temp[tempindex] = c;
			tempindex++;
			beforeflag = flag;
		}
	}
	fclose(fileout);
	fclose(file);
	freehashmap(map);
	printf("更换完成，已存入新的文档\n");
}