#include<stdio.h>
#include<stdlib.h>
#define NUM 10
void swap(int* p1, int* p2);
typedef struct
{
	int size;
	int maxsize;
	int* data;
}maxheap;
maxheap* createheap(int maxsize)
{
	maxheap* heap = (maxheap*)malloc(sizeof(maxheap));
	heap->data = (int*)calloc(maxsize, sizeof(int));
	heap->maxsize = maxsize;
	heap->size = 0;
	return heap;
}
int dad(int i)
{
	return (i - 1) / 2;
}
int Lchild(int i)
{
	return i * 2 + 1;
}
int Rchild(int i)
{
	return i * 2 + 2;
}
void up(maxheap * heap, int i)
{
	while (i > 0 && heap->data[i] > heap->data[dad(i)])
	{
		swap(&heap->data[i], &heap->data[dad(i)]);
		i = dad(i);
	}
}
void uphole(maxheap * heap, int i)
{
	int hole = i;
	int key = heap->data[i];
	while (hole > 0 && key > heap->data[dad(hole)])
	{
		heap->data[hole] = heap->data[dad(hole)];
		hole = dad(hole);
	}
	heap->data[hole] = key;
}
void down(maxheap * heap, int i)
{
	int largest = i;
	int left = Lchild(i);
	int right = Rchild(i);
	if (heap->size > left && heap->data[largest] < heap->data[left])
	{
		largest = left;
	}
	if (heap->size > right && heap->data[largest] < heap->data[right])
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(&heap->data[i], &heap->data[largest]);
		down(heap, largest);
	}
}
void downhole(maxheap * heap, int i)
{
	int hole = i;
	int key = heap->data[i];
	int left = 2 * hole + 1;
	int right = 2 * hole + 2;
	int largest = left;
	while (left < heap->size)
	{
		if (right < heap->size && heap->data[right] > heap->data[left])
		{
			largest = right;
		}
		if (heap->data[largest] > key)
		{
			heap->data[hole] = heap->data[largest];
			hole = largest;
		}
		else
		{
			break;
		}
	}
heap->data[hole] = key;
}
void putheap(maxheap * heap, int key)
{
	if (heap->size == heap->maxsize)
	{
		printf("这个栈满了\n");
		return;
	}
	heap->data[heap->size] = key;
	heap->size++;
	up(heap, heap->size - 1);
}
void deleteheap(maxheap * heap)
{
	int a = 0;
	if (heap->size == 0)
	{
		printf("这个堆是空的！\n");
		return;
	}
	printf("你删除的元素是:%d", heap->data[0]);
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;
	down(heap, a);

}
int getheap(maxheap * heap)
{
	return heap->data[0];
}
void freeheap(maxheap * heap)
{
	free(heap->data);
	free(heap);
}
int main_askjhaw()
{
	maxheap* heap = createheap(10);
	putheap(heap, 3);
	putheap(heap, 1);
	putheap(heap, 5);
	putheap(heap, 8);
	putheap(heap, 4);
	printf("堆顶: %d\n", getheap(heap));  // 应该输出5
	deleteheap(heap);  // 删除5
	printf("删除后堆顶: %d\n", getheap(heap));  // 应该输出4
	freeheap(heap);
}