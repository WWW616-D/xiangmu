//哈希表的二数和应用
#include<stdio.h>
#include<stdlib.h>
typedef struct hashnode
{
	int key;
	int value;
	struct hashnode* next;
}hashnode;
typedef struct hashmap
{
	hashnode** buckets;
	int size;
}hashmap;
hashmap* creathashmap(int size)
{
	hashmap* map = (hashmap*)malloc(sizeof(hashmap));
	map->size = size;
	map->buckets = (hashnode**)calloc(size, sizeof(hashnode*));
	return map;
}
int hash(int key, int size)
{
	return abs(key) % size;
}
void puthash(hashmap* map, int key, int value)
{
	int index = hash(key, map->size);
	hashnode* newnode = (hashnode*)malloc(sizeof(hashnode));
	newnode->key = key;
	newnode->value = value;
	newnode->next = map->buckets[index];
	map->buckets[index] = newnode;
}
int get(hashmap* map, int key)
{
	int index = hash(key, map->size);
	hashnode* p = map->buckets[index];
	while (p != NULL)
	{
		if (p->key == key)
		{
			return p->value;
		}
		else
		{
			p = p->next;
		}
	}
	return -1;
}
void freehashmap(hashmap* map)
{
	for (int i = 0; i < map->size; i++)
	{
		hashnode* p = map->buckets[i];
		while (p != NULL)
		{
			hashnode* temp = p;
			p = p->next;
			free(temp);
		}
	}
	free(map->buckets);
	free(map);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize = 2;
	int* result = (int*)malloc(2 * sizeof(int));
	int size = 20;
	hashmap* map = creathashmap(numsSize);
	for (int i = 0; i < numsSize; i++)
	{
		int a = target - nums[i];
		int aindex = get(map, a);
		if (aindex != -1)
		{
			result[0] = i;
			result[1] = aindex;
			freehashmap(map);
			return result;
		}
		puthash(map, nums[i], i);
	}
	freehashmap(map);
	return NULL;
}
//三数和问题
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	if (numsSize < 3) {
		*returnColumnSizes = NULL;
		return NULL;
	}
	int truesize = 1;
	*returnSize = 100000;
	int count = 0;
	int** threesum = (int**)calloc(100000, sizeof(int*));
	int* data = (int*)malloc(100000 * 3 * sizeof(int));
	for (int i = 0; i < *returnSize; i++)
	{
		threesum[i] = data + i * 3;
	}
	for (int i = numsSize - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				int temp = 0;
				temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < numsSize - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
		{
			continue;
		}

		int nuu = nums[i];
		int num = nums[i] * -1;
		int* left = nums + i + 1;
		int* right = nums + numsSize - 1;
		while (left < right)
		{
			if (*left + *right == num)
			{
				threesum[truesize][0] = nuu;
				threesum[truesize][1] = *left;
				threesum[truesize][2] = *right;
				truesize += 1;
				while (left < right && *left == *(left + 1))
				{
					left++;
				}
				while (left < right && *right == *(right - 1))
				{
					right--;
				}
				left++;
				right--;


			}
			else if (*left + *right < num)
			{
				left++;
			}
			else if (*left + *right > num)
			{
				right--;
			}
		}
	}
	int d = 0;
	int a;
	int b;
	int c;
	for (int i = 0; i < truesize - 1 - d; i++) {
		for (int j = i + 1; j < truesize - d; j++) {
			if (threesum[i][0] == threesum[j][0] &&
				threesum[i][1] == threesum[j][1] &&
				threesum[i][2] == threesum[j][2]) {
				for (int k = j; k < truesize - 1 - d; k++) {
					threesum[k][0] = threesum[k + 1][0];
					threesum[k][1] = threesum[k + 1][1];
					threesum[k][2] = threesum[k + 1][2];
				}

				j--;
				d++;
			}
		}
	}
	*returnSize = truesize - d;
	*returnColumnSizes = (int*)malloc((truesize - d) * sizeof(int));
	for (int i = 0; i < (truesize - d); i++)
	{
		(*returnColumnSizes)[i] = 3;
	}
	return threesum;
}
//int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
// {
//	*returnSize = 2;
//	int count = 0;
//	int* a = (int*)calloc(2, sizeof(int));
//	int* b = (int*)calloc(2, sizeof(int));
//	int nums1[numsSize];
//	for (int i = 0; i < numsSize; i++)
//	{
//		nums1[i] = nums[i];
//	}
//
//	for (int i = numsSize - 1; i > 0; i--)
//	{
//		count == 0;
//		for (int j = 0; j < i; j++)
//		{
//			if (nums1[j] > nums1[j + 1])
//			{
//				int temp = 0;
//				temp = nums1[j];
//				nums1[j] = nums1[j + 1];
//				nums1[j + 1] = temp;
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			break;
//		}
//	}
//	int left = 0;
//	int right = numsSize - 1;
//	int flag = 1;
//	while (left < right)
//	{
//		if (nums1[left] + nums1[right] == target)
//		{
//			a[0] = nums1[left];
//			a[1] = nums1[right];
//			flag = 0;
//			break;
//		}
//		if (nums1[left] + nums1[right] < target)
//		{
//			left++;
//		}
//		if (nums1[left] + nums1[right] > target)
//		{
//			right--;
//		}
//	}
//	if (flag)
//	{
//		return NULL;
//	}
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == a[0])
//		{
//			b[0] = i;
//		}
//	}
//	for (int i = 0; i < numsSize; i++)
//	{
//		if (nums[i] == a[1] && b[0] != i)
//		{
//			b[1] = i;
//		}
//	}
//	return b;
//}
