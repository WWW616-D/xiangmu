#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#define maxkeys 5
#define minkeys 3
#define order 6
typedef struct Btreenode
{
	int keys[maxkeys];//
	void* values[maxkeys];
	struct Btreenode* children[order];
	struct Btreenode* next;
	struct Btreenode* dad;
	int num_keys;
	bool flag;
}Btreenode;
typedef struct
{
	Btreenode* root;
	Btreenode* firstleaf;
}Btree;
void split_leaf(Btree* tree, Btreenode* leaf, int key, void* value);
void insert_into_dad(Btree* tree, Btreenode* parent, int key, Btreenode* right_child);
void fix_parent_underflow(Btree* tree, Btreenode* node, Btreenode* parent, int index);
Btreenode* createnode(bool flag)
{
	Btreenode* node = (Btreenode*)malloc(sizeof(Btreenode));
	node->num_keys = 0;
	node->flag = flag;
	node->next = NULL;
	for (int i=0;i<maxkeys;i++)
	{
		node->keys[i] = 0;
		node->values[i] = NULL;
		node->children[i] = NULL;
	}
	node->children[maxkeys] = NULL;
	node->dad = NULL;
	return node;
}
Btree* createBtree()
{
	Btree* tree = (Btree*)malloc(sizeof(Btree));
	tree->root = NULL;
	tree->firstleaf = NULL;
	return tree;
}
Btreenode* findleaf(Btree* tree,int key)
{
	if (tree->root == NULL)
		return NULL;
	Btreenode* current = tree->root;
	while(!current->flag)
	{
		int i = 0;
		while (i < current->num_keys && key > current->keys[i])
			i++;
		current = current->children[i];
	}
	return current;
}
void* findinleaf(Btreenode* leaf,int key)
{
	if (leaf == NULL)
		return NULL;
	for (int i=0;i<leaf->num_keys;i++)
	{
		if(leaf->keys[i] == key)
		{
			return leaf->values[i];
		}
	}
	return NULL;
}
void searchB(Btree* tree,int key)
{
	Btreenode* leaf = findleaf(tree, key);
	if (!findinleaf(leaf, key))
	{
		printf("这个key找不到\n");
	}
	else
	{
		printf("找到了！key:%d对应的数值为%d\n", key, findinleaf(leaf,key));
	}
	return;
}
int find_insert_index(Btreenode* node,int key)
{
	int i = 0;
	while(i< node->num_keys&&key>node->keys[i])
	{
		i++;
	}
	return i;
}
void split_parent_node(Btree* tree,Btreenode* node,int new_key,Btreenode* new_child,int insert_index)
{
	printf("分裂: 原节点keys=[");
	for (int i = 0; i < node->num_keys; i++) printf("%d ", node->keys[i]);
	printf("], 插入key=%d\n", new_key);
	int temp_keys[maxkeys + 1];
	Btreenode* temp_children[order + 1];
	for (int i=0;i<node->num_keys;i++)
	{
		temp_keys[i] = node->keys[i];
		temp_children[i] = node->children[i];
	}
	temp_children[node->num_keys] = node->children[node->num_keys];
	for (int i=node->num_keys;i>insert_index;i--)
	{
		temp_keys[i] = temp_keys[i - 1];
		temp_children[i + 1] = temp_children[i];
	}
	temp_keys[insert_index] = new_key;
	temp_children[insert_index + 1] = new_child;
	int total_keys = node->num_keys + 1;
	int split_index;
	if (total_keys % 2 == 0) 
		split_index = total_keys / 2;  
	else 
		split_index = (total_keys + 1) / 2;  
	int promoted_key = temp_keys[split_index];
	node->num_keys = 0;
	for (int i=0;i<split_index;i++)
	{
		node->keys[i] = temp_keys[i];
		node->children[i] = temp_children[i];
		node->children[i]->dad = node;
		node->num_keys++;
	}
	node->children[split_index] = temp_children[split_index];
	node->children[split_index]->dad = node;
	Btreenode* new_node = createnode(false);
	new_node->num_keys = 0;
	for (int i=split_index+1,j=0;i<total_keys;i++,j++)
	{
		new_node->keys[j] = temp_keys[i];
		new_node->children[j] = temp_children[i];
		new_node->children[j]->dad = new_node;
		new_node->num_keys++;
	}
	new_node->children[new_node->num_keys] = temp_children[total_keys];
	new_node->children[new_node->num_keys]->dad = new_node;
	if (node->dad == NULL)
	{
		Btreenode* new_root = createnode(false);
		new_root->keys[0] = promoted_key;
		new_root->children[0] = node;
		new_root->children[1] = new_node;
		new_root->num_keys = 1;
		node->dad = new_root;
		new_node->dad = new_root;
		tree->root = new_root;
	}
	else
	{
		insert_into_dad(tree, node->dad, promoted_key, new_node);
	}
}
void insert_into_dad(Btree* tree, Btreenode* parent, int key, Btreenode* right_child)
{
	int index = 0;
	while (index<parent->num_keys && key >parent->keys[index])
	{
		index++;
	}
	if (parent->num_keys==maxkeys)
	{
		printf("父节点已满，即将分裂");
		split_parent_node(tree, parent, key, right_child,index);
	}
	else
	{
		for (int i = parent->num_keys; i > index; i--)
		{
			parent->keys[i] = parent->keys[i - 1];
			parent->children[i + 1] = parent->children[i];
		}
		parent->keys[index] = key;
		parent->children[index + 1] = right_child;
		parent->num_keys++;
		right_child->dad = parent;
	}
}
void insert_leaf(Btreenode* leaf, int key,void* value)
{
	int index = find_insert_index(leaf, key);
	for (int i = leaf->num_keys;i>index;i--)
	{
		leaf->keys[i] = leaf->keys[i - 1];
		leaf->values[i] = leaf->values[i - 1];
	}
	leaf->keys[index] = key;
	leaf->values[index] = value;
	leaf->num_keys++;
}
void insert_tree(Btree* tree,int key,void* value)
{
	printf("插入键%d\n", key);
	if (tree->root==NULL)
	{
		tree->root = createnode(true);
		tree->firstleaf = tree->root;
		tree->root->keys[0] = key;
		tree->root->values[0] = value;
		tree->root->num_keys = 1;
		printf("创建了根节点");
		return;
	}
	Btreenode* leaf = findleaf(tree, key);
	if (leaf->num_keys<maxkeys)
	{
		insert_leaf(leaf, key, value);
		printf("直接插入叶子");
	}
	else
	{
		printf("叶子满了,进行一次分裂\n");
		split_leaf(tree, leaf, key, value);
	}
}
void split_leaf(Btree* tree,Btreenode* leaf,int key,void* value)
{
	printf("分裂: 原节点keys=[");
	for (int i = 0; i < leaf->num_keys; i++) printf("%d ",leaf->keys[i]);
	printf("], 插入key=%d\n",key);
	int temp_keys[maxkeys + 1];
	void* temp_values[maxkeys + 1];
	int index = 0;
	while(index<leaf->num_keys&&key>leaf->keys[index])
	{
		index++;
	}
	for (int i = 0; i < leaf->num_keys; i++)
	{
		temp_keys[i] = leaf->keys[i];
		temp_values[i] = leaf->values[i];
	}
	for (int i = leaf->num_keys; i > index; i--) 
	{
		temp_keys[i] = temp_keys[i - 1];
		temp_values[i] = temp_values[i - 1];
	}
	temp_keys[index] = key;
	temp_values[index] = value;
	int nums = leaf->num_keys + 1;
	int splitindex;
	if (nums % 2 == 0)
		splitindex = nums / 2;
	else
		splitindex = (nums + 1) / 2;
	leaf->num_keys = 0;
	for (int i=0;i<splitindex;i++)
	{
		leaf->keys[leaf->num_keys] = temp_keys[i];
		leaf->values[leaf->num_keys] = temp_values[i];
		leaf->num_keys++;
	}
	Btreenode* newleaf = createnode(true);
	newleaf->num_keys = 0;
	for (int i = splitindex;i <nums;i++ )
	{
		newleaf->keys[newleaf->num_keys] = temp_keys[i];
		newleaf->values[newleaf->num_keys] = temp_values[i];
		newleaf->num_keys++;
	}
	newleaf->next = leaf->next;
	leaf->next = newleaf;
	int onkey = newleaf->keys[0];
	if (leaf->dad==NULL)
	{
		Btreenode* newroot = createnode(false);
		newroot->keys[0] = onkey;
		newroot->children[0] = leaf;
		newroot->children[1] = newleaf;
		newroot->num_keys = 1;
		leaf->dad = newroot;
		newleaf->dad = newroot;
		tree->root = newroot;
	}
	else
	{
		insert_into_dad(tree, leaf->dad, onkey, newleaf);
	}
}

void printnode(Btreenode* node)
{
	if (!node)
	{
		printf("空节点\n");
		return;
	}
	printf("[");
	for (int i =0;i<node->num_keys;i++)
	{
		printf("%d", node->keys[i]);
		if (i < node->num_keys - 1)
			printf(",");
	}
	printf("] %s", node->flag ? "叶子" : "内部");
}
void leafdelete(Btreenode* leaf,int key,int index)
{
	for (int i=index;i<leaf->num_keys-1;i++)
	{
		leaf->keys[i] = leaf->keys[i + 1];
		leaf->values[i] = leaf->values[i + 1];
	}
	leaf->num_keys--;
}
void fix_parent(Btreenode* leaf,int key,int trueway)
{
	char flag = 1;
	Btreenode* dad = leaf->dad;
	if (!dad || leaf->num_keys == 0)
		return;
	int child_index = -1;
	for (int i = 0; i <= dad->num_keys; i++) {
		if (dad->children[i] == leaf) {
			child_index = i;
			break;
		}
	}
	if (child_index > 0)
	{
		if (dad->keys[child_index-1]==key)
		{
			dad->keys[child_index - 1] = trueway;
			flag = 0;
		}
		if (flag)
		{
			fix_parent(dad, key, trueway);
		}
	}
	else
		return;
}
bool borrow(Btreenode* leaf,Btreenode* parent,int index)
{
	if (index < parent->num_keys)
	{
		Btreenode* right = parent->children[index + 1];
		if (right->num_keys > minkeys)
		{
			leaf->keys[leaf->num_keys] = right->keys[0];
			leaf->values[leaf->num_keys] = right->values[0];
			leaf->num_keys++;
			for (int i = 0; i < right->num_keys - 1; i++)
			{
				right->keys[i] = right->keys[i + 1];
				right->values[i] = right->values[i + 1];
			}
			right->num_keys--;
			parent->keys[index] = right->keys[0];
			return true;
		}
	}
	if (index >0)
	{
		Btreenode* left = parent->children[index - 1];
		if (left->num_keys > minkeys)
		{
			for (int i = leaf->num_keys;i>0;i--)
			{
				leaf->keys[i] = leaf->keys[i - 1];
			}
			leaf->keys[0] = left->keys[left->num_keys - 1];
			leaf->values[0] = left->values[left->num_keys - 1];
			leaf->num_keys++;
			left->num_keys--;
			parent->keys[index - 1] = leaf->keys[0];
			return true;
		}
	}
	return false;
}
bool borrow_left(Btreenode* node, Btreenode* left, Btreenode* parent, int index)
{
	if (left->num_keys > minkeys)
	{
		for (int i = node->num_keys; i > 0; i--)
		{
			node->keys[i] = node->keys[i - 1];
			node->children[i + 1] = node->children[i];
		}
		node->keys[0] = parent->keys[index - 1];
		node->children[1] = node->children[0];
		node->children[0] = left->children[left->num_keys];
		if (node->children[0]) 
			node->children[0]->dad = node;
		parent->keys[index - 1] = left->keys[left->num_keys - 1];
		left->num_keys--;
		node->num_keys++;
		return true;
	}
	else
		return false;
}
bool borrow_right(Btreenode* node, Btreenode* right, Btreenode* parent, int index)
{
	if (right->num_keys > minkeys)
	{
		node->keys[node->num_keys] = parent->keys[index];
		node->children[node->num_keys + 1] = right->children[0];
		if (node->children[node->num_keys + 1]) 
			node->children[node->num_keys + 1]->dad = node;
		node->num_keys++;
		parent->keys[index] = right->keys[0];

		for (int i = 0; i < right->num_keys - 1; i++) 
		{
			right->keys[i] = right->keys[i + 1];
			right->children[i] = right->children[i + 1];
		}
		right->children[right->num_keys - 1] = right->children[right->num_keys];
		right->num_keys--;
		return true;
	}
	else
		return false;
}
bool borrow_parent(Btreenode* node, Btreenode* parent, int index)
{
	if (index > 0) 
	{
		Btreenode* left = parent->children[index - 1];
		if (borrow_left(node, left, parent, index))
			return true;
	}
	if (index < parent->num_keys) 
	{
		Btreenode* right = parent->children[index + 1];
		if (borrow_right(node, right, parent, index))
			return true;
	}
	return false;
}
void merge_parent(Btree* tree, Btreenode* left, Btreenode* right, Btreenode* parent, int index)
{
	left->keys[left->num_keys] = parent->keys[index];
	left->num_keys++;
	for (int i = 0; i < right->num_keys; i++) 
	{
		left->keys[left->num_keys] = right->keys[i];
		left->children[left->num_keys] = right->children[i];
		if (left->children[left->num_keys]) 
		{
			left->children[left->num_keys]->dad = left;
		}
		left->num_keys++;
	}
	left->children[left->num_keys] = right->children[right->num_keys];
	if (left->children[left->num_keys]) 
	{
		left->children[left->num_keys]->dad = left;  
	}
	for (int i = index; i < parent->num_keys - 1; i++) 
	{
		parent->keys[i] = parent->keys[i + 1];
		parent->children[i + 1] = parent->children[i + 2];
	}
	parent->num_keys--;
	free(right);
	if (parent->dad==NULL)
	{
		if (parent->num_keys == 0) 
		{
			tree->root = left;  
			if (tree->root)
			{
				tree->root->dad = NULL;
			}
			free(parent);
		}
		return;
	}
	if (parent->dad)
	{
		if (parent->num_keys < minkeys)
		{
			int children_index = -1;
			Btreenode* dad = parent->dad;
			for (int i = 0; i <= dad->num_keys; i++)
			{
				if (parent == dad->children[i])
					children_index = i;
			}
			fix_parent_underflow(tree, parent, dad, children_index);
		}
	}
	
}
void fix_parent_underflow(Btree* tree,Btreenode* node,Btreenode* parent,int index)
{
	if (borrow_parent(node, parent, index)) 
	{
		return;
	}
	if (index < parent->num_keys) 
		merge_parent(tree, node, parent->children[index + 1], parent, index);
	else if (index > 0) 
		merge_parent(tree, parent->children[index - 1], node, parent, index - 1);
}
void merge(Btree* tree,Btreenode* node,Btreenode* partner,Btreenode* parent,int index)
{
	for (int i =0;i<partner->num_keys;i++)
	{
		node->keys[node->num_keys] = partner->keys[i];
		node->values[node->num_keys] = partner->values[i];
		node->num_keys++;
	}
	if (node->flag)
	{
		if (tree->firstleaf == partner) 
			tree->firstleaf = node; 
		node->next = partner->next;
	}
	int deletekey = parent->keys[index];
	for (int i = index;i<parent->num_keys-1;i++)
	{
		parent->keys[i] = parent->keys[i + 1];
		parent->children[i + 1] = parent->children[i + 2];
	}
	parent->num_keys--;
	if (parent->dad == NULL)
	{

		if (parent->num_keys == 0)
		{
			tree->root = node;
			node->dad = NULL;
			free(parent);
		}
	}
	else if (parent->num_keys < minkeys) 
	{
		Btreenode* grandpa = parent->dad;
		int parent_index = -1;
		for (int i=0;i<=grandpa->num_keys;i++)
		{
			if (grandpa->children[i] == parent)
				parent_index = i;
		}
		fix_parent_underflow(tree, parent, grandpa, parent_index);
	}
	if (node->dad)
	{
		fix_parent(node, deletekey, node->keys[0]);
	}
}
bool bdelete(Btree* tree,int key)
{
	if (!tree->root)
		return false;
	Btreenode* leaf = findleaf(tree, key);
	int key_index = -1;
	for (int i=0;i<leaf->num_keys;i++)
	{
		if (leaf->keys[i]==key)
		{
			printf("要删除的%d节点是存在的，现在开始删除\n", key);
			key_index = i;
			break;
		}
	}
	if (key_index==-1)
	{
		printf("要删除的%d节点不存在\n",key);
		return false;
	}
	int old_first_key = leaf->keys[0];
	leafdelete(leaf, key,key_index);
	if (leaf->num_keys>=minkeys)
	{
		if (key_index == 0 && leaf->dad)
		{
			int trueway = leaf->keys[0];
			fix_parent(leaf, old_first_key,trueway);
		}
		return true;
	}
	if (!leaf->dad)
	{
		if (leaf->num_keys == 0)
		{
			free(leaf);
			tree->root = NULL;
			tree->firstleaf = NULL;
		}
		return true;
	}
	Btreenode* dad = leaf->dad;
	int index = 0;
	while (index<=dad->num_keys&&dad->children[index]!=leaf)
	{
		index++;
	}
	if (borrow(leaf, dad, index))
		return true;
	if (index <dad->num_keys)
	{
		merge(tree,leaf, dad->children[index + 1], dad, index);
		return true;
	}
	else
	{
		merge(tree,dad->children[index - 1],leaf,dad,index-1);
		return true;
	}
}
void printtree(Btreenode* root,int level)
{
	if (!root)
		return;
	for (int i =0;i<level;i++)
	{
		printf("  ");
	}
	printnode(root);
	printf("\n");
	if (!root->flag)
	{
		for (int i=0;i<=root->num_keys;i++)
		{
			printtree(root->children[i],level+1);
		}
	}
}
void printtree_(Btreenode* root)
{
	Btreenode* team[50000];
	int head = 0;
	int tail = 0;
	team[0] = root;
	tail++;
	int level = 0;
	int count = 1;
	int nextcount = 0;
	printf("第%d层\n", level);
	while (head<tail)
	{
		Btreenode* node = team[head];
		head++;
		count--;
		printf("[");
		for (int i = 0; i < node->num_keys; i++) {
			printf("%d", node->keys[i]);
			if (i < node->num_keys - 1) printf(",");
		}
		printf("]%s ", node->flag ? "叶子" : "内部");
		if (!node->flag)
		{
			for (int i = 0; i < node->num_keys + 1; i++)
			{
				team[tail] = node->children[i];
				tail++;
				nextcount++;
			}
		}
		if (count==0)
		{
			if (nextcount!=0)
				printf("\n第%d层\n", level+1);
			level++;
			count = nextcount;
			nextcount = 0;
		}
	}
}
void printleafchain(Btreenode* firstleaf)
{
	printf("叶子链表\n");
	Btreenode* current = firstleaf;
	while (current)
	{
		printnode(current);
		printf("\n");
		printf("[");
		for (int i=0;i<current->num_keys;i++)
		{
			printf("%d", current->values[i]);
			if (i < current->num_keys - 1)
				printf(",");
		}
		printf("]");
		if (current->next)
		{
			printf("->\n");
		}
		current = current->next;
	}
}
int main_aaw()
{
	srand(time(NULL));
	Btree* tree = createBtree();
	printf("创建了一个空树\n");
	for (int i=0;i<2000;i++)
	{
		insert_tree(tree,rand()%20000+1, (void*)((rand()%200+1)));
	}
	printtree_(tree->root);
	for (int i = 0; i < 1000; i++)
	{
		bdelete(tree, rand() % 20000 + 1);
	}
	printtree_(tree->root);
	printleafchain(tree->firstleaf);
	//searchB(tree, 85);
	getchar();
	return 0;
}