#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct treenode
{
	int num;
	struct treenode* left;
	struct treenode* right;
	int count;
	int flag;
	int height;
}treenode;
treenode* creattreenode(int num)
{
	treenode* newnode = (treenode*)malloc(sizeof(treenode));
	newnode->num = num;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->count = 1;
	newnode->flag = 1;
	return newnode;
}
void beforeorder(treenode* p)
{
	if (p == NULL)
		return;
	printf("%d\n", p->num);
	beforeorder(p->left);
	beforeorder(p->right);
}
void midorder(treenode* p)
{
	if (p == NULL)
		return;
	midorder(p->left);
	printf("%d\n", p->num);
	midorder(p->right);
}
void lastorder(treenode* p)
{
	if (p == NULL)
		return;
	lastorder(p->left);
	lastorder(p->right);
	printf("%d\n", p->num);
}
void insert(treenode* root,int num)
{
	treenode* newnode=creattreenode(num);
	treenode* p = root;
	treenode* q = NULL;
	int flag=0;
	while (p!=NULL)
	{
		if (p == NULL)
			break;
		q = p;
		if (num < p->num)
		{
			p = p->left;
			flag = 1;
		}
		else if (num > p->num)
		{
			p = p->right;
			flag = 2;
		}
		else
		{
			p->count++;
			break;
		}
	} 
	if (flag)
	{
		if (flag==1)
		{
			q->left = newnode;
		}
		if (flag==2)
		{
			q->right = newnode;
		}
	}
	else
	{
		return;
	}
}
void find(treenode* root, int num)
{
	while (root!=NULL)
	{
		if (num > root->num)
			root = root->right;
		else if (num < root->num)
			root = root->left;
		else
		{
			printf("找到了!%d这个数字在二叉树中是存在的！\n",num);
			return;
		}
	}
	printf("%d这个数字找不到\n",num);
}
int treeheight(treenode* root)
{
	if (root == NULL)
		return 0;
	int leftheight = treeheight(root->left);
	int rightheight = treeheight(root->right);
	return(leftheight > rightheight ? leftheight : rightheight) + 1; 
}
int getheight(treenode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		return root->height;
	}
}
treenode* findmin(treenode* root)
{
	while(root->left!=NULL)
	{
		root = root->left;
	}
	return root;
}
treenode* delete(treenode* root,int num)
{
	if (root==NULL)
	{
		printf("这个数字并不存在");
		return root;
	}
	else
	{
		if(num<root->num)
		{
			root->left = delete(root->left, num);
		}
		else if(num>root->num)
		{
			root->right = delete(root->right, num);
		}
		else
		{
			if(root->left==NULL)
			{
				treenode* temp = root->right;
				free(root);
				return temp;
			}
			else if(root->right==NULL)
			{
				treenode* temp = root->left;
				free(root);
				return temp;
			}
			else
			{
				treenode* min = findmin(root->right);
				root->num = min->num;
				root->right = delete(root->right, min->num);
			}
		}
	}
	return root;
}
void freetree(treenode* root)
{
	if (root!=NULL)
	{
		freetree(root->left);
		freetree(root->right);
		free(root);
	}
	return;
}
int main()
{
	treenode* root = creattreenode(5);
	srand(time(NULL));
	for (int i=0;i<100;i++)
	{
		insert(root,rand() % 200 + 1);
	}
	/*beforeorder(root);
	midorder(root);
	lastorder(root);*/
	find(root,57);
	printf("这棵树的高度是%d\n", treeheight(root));
}