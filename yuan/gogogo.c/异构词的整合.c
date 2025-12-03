//#define hashsize 1007
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void quicksortstr(char* key, int left, int right)
//{
//	if (left >= right)
//		return;
//	int q = left;
//	int p = right;
//	char mid = key[(left + right) / 2];
//	while (q <= p)
//	{
//		while (key[q] < mid) q++;
//		while (key[p] > mid) p--;
//		if (q <= p)
//		{
//			char temp = key[q];
//			key[q] = key[p];
//			key[p] = temp;
//			q++;
//			p--;
//		}
//	}
//	quicksortstr(key, left, p);
//	quicksortstr(key, q, right);
//}
//typedef struct hashnode
//{
//	char* sortkey;
//	char** key;
//	int count;
//	int capacity;
//	struct hashnode* next;
//}node;
//typedef struct hashmap
//{
//	node** buckets;
//}hashmap;
//hashmap* creathashmap()
//{
//	hashmap* map = (hashmap*)malloc(sizeof(hashmap));
//	map->buckets = (node**)calloc(hashsize, sizeof(node*));
//	return map;
//}
//unsigned int hash(char* key)
//{
//	unsigned int value = 0;
//	quicksortstr(key, 0, strlen(key) - 1);
//	while (*key != '\0')
//	{
//		value = (*key * 61 + value) % hashsize;
//		key++;
//	}
//	return value;
//}
//void puthashmap(hashmap* map, char* key)
//{
//	char* beforekey = (char*)malloc(strlen(key) + 1);
//	strcpy(beforekey, key);
//	unsigned int value = hash(beforekey);
//	node* p = map->buckets[value];
//	while (p != NULL)
//	{
//		if (strcmp(beforekey, p->sortkey) == 0)
//		{
//			p->key[p->count] = key;
//			p->count++;
//			if (p->capacity <= p->count)
//			{
//				char** temp = (char**)realloc(p->key, p->capacity * 2 * sizeof(char*));
//				if (temp != NULL)
//				{
//					p->key = temp;
//					p->capacity *= 2;
//				}
//			}
//			free(beforekey);
//			return;
//		}
//		p = p->next;
//	}
//	node* newnode = (node*)malloc(sizeof(node));
//	newnode->sortkey = beforekey;
//	newnode->count = 0;
//	newnode->capacity = 4;
//	newnode->key = (char**)malloc(newnode->capacity * sizeof(char*));
//	newnode->key[newnode->count] = key;
//	newnode->count++;
//	newnode->next = map->buckets[value];
//	map->buckets[value] = newnode;
//}
//char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
//{
//	hashmap* map = creathashmap();
//	for (int i = 0; i < strsSize; i++)
//	{
//		puthashmap(map, strs[i]);
//	}
//	int nums = 0;
//	for (int i = 0; i < hashsize; i++)
//	{
//		node* p = map->buckets[i];
//		while (p != NULL)
//		{
//			nums++;
//			p = p->next;
//		}
//	}
//	*returnSize = nums;
//	char*** result = (char***)malloc(nums * sizeof(char**));
//	*returnColumnSizes = (int*)calloc(nums, sizeof(int));
//	int count = 0;
//	for (int i = 0; i < hashsize; i++)
//	{
//		node* p = map->buckets[i];
//		while (p != NULL)
//		{
//			int size = 0;
//			result[count] = p->key;
//			(*returnColumnSizes)[count] = p->count;
//			count++;
//			p = p->next;
//		}
//	}
//	return result;
//}