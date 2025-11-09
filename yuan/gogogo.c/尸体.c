//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//	if (numsSize < 3) {
//		*returnColumnSizes = NULL;
//		return NULL;
//	}
//	int truesize = 0;
//	*returnSize = 100;
//	int count = 0;
//	int** threesum = (int**)calloc(100, sizeof(int*));
//	int* data = (int*)malloc(100 * 3 * sizeof(int));
//	for (int i = 0; i < *returnSize; i++)
//	{
//		threesum[i] = data + i * 3;
//	}
//	for (int i = numsSize - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int temp = 0;
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < numsSize - 2; i++)
//	{
//		int nuu = nums[i];
//		int num = nums[i] * -1;
//		int* left = nums + i + 1;
//		int* right = nums + numsSize - 1;
//		while (left < right)
//		{
//			if (*(left + 1) == *left)
//			{
//				left++;
//				continue;
//			}
//			if (*(right - 1) == *right)
//			{
//				right--;
//				continue;
//			}
//			if (*left + *right == num)
//			{
//				threesum[truesize][0] = nuu;
//				threesum[truesize][1] = *left;
//				threesum[truesize][2] = *right;
//				truesize += 1;
//				left++;
//				right--;
//			}
//			if (*left + *right < num)
//			{
//				left++;
//			}
//			if (*left + *right > num)
//			{
//				right--;
//			}
//		}
//	}
//	int a;
//	int b;
//	int c;
//	int d = 0;
//	for (int i = 0; i < truesize-1-d; i++)
//	{
//		a = threesum[i][0];
//		b = threesum[i][1];
//		c = threesum[i][2];
//		for (int j = i+1; j < truesize-d; j++)
//		{
//			if (a == threesum[j][0] && b == threesum[j][1] && c == threesum[j][2])
//			{
//				for (int k = j; k < truesize - 1; k++)
//				{
//					threesum[k][0] = threesum[k + 1][0];
//					threesum[k][1] = threesum[k + 1][1];
//					threesum[k][2] = threesum[k + 1][2];
//					
//				}
//				j--;
//				d += 1;
//				break;
//			}
//		}
//	}
//	*returnSize = truesize-d;
//	*returnColumnSizes = (int*)malloc(truesize * sizeof(int));
//	for (int i = 0; i < truesize; i++)
//	{
//		(*returnColumnSizes)[i] = 3;
//	}
//	return threesum;
//}
 

//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//	int truesize = 0;
//	*returnSize = 100;
//	int count = 0;
//	int** threesum = (int**)calloc(100, sizeof(int*));
//	int* data = (int*)malloc(100 * 3 * sizeof(int));
//	for (int i = 0; i < *returnSize; i++)
//	{
//		threesum[i] = data + i * 3;
//	}
//	for (int i = numsSize - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int temp = 0;
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < numsSize - 2; i++)
//	{
//		int nuu = nums[i];
//		int num = nums[i] * -1;
//		int* left = nums + i + 1;
//		int* right = nums + numsSize - 1;
//		while (left < right)
//		{
//			if (*left + *right == num)
//			{	
//				threesum[truesize][0] = nuu;
//				threesum[truesize][1] = *left;
//				threesum[truesize][2] = *right;
//				for (int k = 2; k > 0; k--) 
//				{
//					for (int l = 0; l < k; l++)
//					{
//						int temp = 0;
//						temp = threesum[truesize][l];
//						threesum[truesize][l] = threesum[truesize][l+1];
//						threesum[truesize][l+1] = temp;
//					}
//				}
//				truesize += 1;
//				
//			}
//			if (*left + *right < num)
//			{
//				left++;
//			}
//			if (*left + *right > num)
//			{
//				right--;
//			}
//		}
//	}
//int a;
//int b;
//int c;
//int d = 0;
//for (int i = 0; i < truesize; i++)
//{
//	a = threesum[i][0];
//	b = threesum[i][1];
//	c = threesum[i][2];
//	for (int j = 0; j < truesize; j++)
//	{
//		if (a == threesum[j][0] && b == threesum[j][1] && c == threesum[j][2])
//		{
//			for (int k = j; k < truesize - 1; k++)
//			{
//				threesum[k][0] = threesum[k + 1][0];
//				threesum[k][1] = threesum[k + 1][1];
//				threesum[k][2] = threesum[k + 1][2];
//				d += 1;
//			}
//			break;
//		}
//	}
//}
//	*returnSize = truesize;
//	*returnColumnSizes = (int*)malloc(truesize * sizeof(int));
//	for (int i = 0; i < truesize; i++)
//	{
//		*returnColumnSizes[i] = 3;
//	}
//	return threesum;
//}
 

//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
//{
//	int truesize = 0;
//	*returnSize = 100;
//	int count = 0;
//	int flag = 1;
//	int** threesum = (int**)calloc(100, sizeof(int*));
//	int* data = (int*)malloc(100 * 3 * sizeof(int));
//	for (int i = 0; i < *returnSize; i++)
//	{
//		threesum[i] = data + i * 3;
//	}
//	for (int i = numsSize - 1; i > 0; i--)
//	{
//		for (int j = 0; j < i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int temp = 0;
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < numsSize - 2; i++)
//	{
//		int nuu = nums[i];
//		int num = nums[i] * -1;
//		int* left = nums + i + 1;
//		int* right = nums + numsSize - 1;
//		while (left < right)
//		{
//			if (*left + *right == num)
//			{
//				flag = 1;
//				for (int j = 0; j < truesize; j++)
//				{
//					count = 0;
//					if (threesum[j][0] == nuu || threesum[j][1] == nuu || threesum[j][2] == nuu)
//					{
//						count += 1;
//					}
//					if (threesum[j][0] == nuu || threesum[j][1] == nuu || threesum[j][2] == nuu)
//					{
//						count += 1;
//					}
//					if (threesum[j][0] == nuu || threesum[j][1] == nuu || threesum[j][2] == nuu)
//					{
//						count += 1;
//					}
//					if (count == 3)
//					{
//						flag = 0;
//						break;
//					}
//				}
//				if (flag)
//				{
//					threesum[truesize][0] = nuu;
//					threesum[truesize][1] = *left;
//					threesum[truesize][2] = *right;
//					truesize += 1;
//				}
//			}
//			if (*left + *right < num)
//			{
//				left++;
//			}
//			if (*left + *right > num)
//			{
//				right--;
//			}
//		}
//	}
//	*returnSize = truesize;
//	*returnColumnSizes = (int*)malloc(truesize * sizeof(int));
//	for (int i = 0; i < truesize; i++)
//	{
//		(*returnColumnSizes)[i] = 3;
//	}
//	return threesum;
//}