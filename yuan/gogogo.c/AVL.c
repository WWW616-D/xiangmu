#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
typedef struct avlnode
{
	int num;
	int height;
	int count;
	struct avlnode* left;
	struct avlnode* right;
}avlnode;
avlnode* createavlnode(int num)
{
	avlnode* newnode = (avlnode*)malloc(sizeof(avlnode));
	newnode->num = num;
	newnode->height = 0;
	newnode->count = 1;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
int getheight(avlnode* root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		return root->height;
	}
}
int getbalance(avlnode* root)
{
	if (root==NULL)
	{
		return 0;
	}
	else
	{
		return getheight(root->left) - getheight(root->right);
	}
}
int getnewheight(avlnode* root) 
{
	if (root == NULL) 
	{
		return 0;
	}
	return (getheight(root->left) > getheight(root->right) ? getheight(root->left) : getheight(root->right)) + 1;
}
void lazydelete(avlnode* root,int num)
{
	if (root==NULL)
	{
		printf("要删除的数字在本树中不存在\n");
		return;
	}
	if (num<root->num)
	{
		lazydelete(root->left, num);
	}
	else if (num>root->num)
	{
		lazydelete(root->right, num);
	}
	else
	{
		if (root->count > 0)
		{
			root->count--;
			return;
		}
		else
		{
			printf("要删除的数字在本树中不存在\n");
			return;
		}
	}
}
avlnode* leftrotate(avlnode* root)
{
	avlnode* right = root->right;
	avlnode* temp = right->left;
	root->right = temp;
	right->left = root;
	root->height = getnewheight(root);
	right->height = getnewheight(right);
	return right;
}
avlnode* rightrotate(avlnode* root)
{
	avlnode* left = root->left;
	avlnode* temp = left->right;
	root->left = temp;
	left->right = root;
	root->height = getnewheight(root);
	left->height = getnewheight(left);
	return left;
}
avlnode* avlinsert(avlnode* root, int num)
{
	if (root == NULL)
	{
		root = createavlnode(num);
	}
	else
	{
		if (num < root->num)
		{
			root->left = avlinsert(root->left, num);
		}
		else if (num > root->num)
		{
			root->right = avlinsert(root->right, num);
		}
		else
		{
			root->count++;
		}
	}
	root->height = getnewheight(root);
	int balance = getbalance(root);
	if (abs(balance)>1)
	{
		if (balance>1&&num<root->left->num)
		{
			root=rightrotate(root);
		}
		else if (balance<-1&&num>root->right->num)
		{
			root = leftrotate(root);
		}
		else if (balance>1&&num>root->left->num)
		{
			root->left = leftrotate(root->left);
			root = rightrotate(root);
		}
		else if (balance<-1&&num<root->right->num)
		{
			root->right = rightrotate(root->right);
			root = leftrotate(root);
		}
	}
	return root;
}