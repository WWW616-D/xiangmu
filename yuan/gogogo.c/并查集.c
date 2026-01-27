#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10001

//typedef struct Node {
//    int val;
//    struct Node* next;
//    struct Set* set;
//} Node;
//
//typedef struct Set {
//    Node* head;
//    Node* tail;
//    int size;
//} Set;
//
//Node* nodes[MAX_N];
//
//void init(int n) {
//    for (int i = 1; i <= n; i++) {
//        // 创建节点
//        Node* node = (Node*)malloc(sizeof(Node));
//        node->val = i;
//        node->next = NULL;
//
//        // 创建集合
//        Set* set = (Set*)malloc(sizeof(Set));
//        set->head = node;
//        set->tail = node;
//        set->size = 1;
//
//        // 节点指向集合
//        node->set = set;
//
//        // 保存
//        nodes[i] = node;
//    }
//}
//
//int find(int x) {
//    return nodes[x]->set->head->val;
//}
//
//void union_set(int x, int y) {
//    Node* node_x = nodes[x];
//    Node* node_y = nodes[y];
//    Set* set_x = node_x->set;
//    Set* set_y = node_y->set;
//
//    if (set_x == set_y) return;
//
//    // 让小集合并入大集合
//    if (set_x->size > set_y->size) {
//        Set* temp = set_x;
//        set_x = set_y;
//        set_y = temp;
//    }
//
//    // 修改小集合所有节点的set指针
//    Node* cur = set_x->head;
//    while (cur != NULL) {
//        cur->set = set_y;
//        cur = cur->next;
//    }
//
//    // 连接两个链表
//    set_y->tail->next = set_x->head;
//    set_y->tail = set_x->tail;
//    set_y->size += set_x->size;
//
//    // 不释放set_x！就这么放着
//}
//
//int main_55() {
//    int n = 5;
//    init(n);
//    printf("初始：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("%d在集合%d\n", i, find(i));
//    }
//    union_set(1, 2);
//    printf("\n合并1和2后：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("%d在集合%d\n", i, find(i));
//    }
//    union_set(3, 4);
//    union_set(1, 3);
//    printf("\n再合并后：\n");
//    for (int i = 1; i <= n; i++) {
//        printf("%d在集合%d\n", i, find(i));
//    }
//    printf("\n程序结束，内存不清理\n");
//    return 0;  // 操作系统会回收所有内存
//}
int parent[MAX_N];
int rank[MAX_N];
//可以考虑负数代表根，绝对值代表大小来节省一次内存开销。
void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 路径压缩
    }
    return parent[x];
}

void union_set(int x, int y) {
    int root_x = find(x);
    int root_y = find(y);

    if (root_x == root_y) return;

    // 按秩合并
    if (rank[root_x] < rank[root_y]) {
        parent[root_x] = root_y;
    }
    else if (rank[root_x] > rank[root_y]) {
        parent[root_y] = root_x;
    }
    else {
        parent[root_x] = root_y;
        rank[root_y]++;
    }
}

int main_564() {
    int n = 7;
    init(n);

    // 测试
    union_set(1, 2);
    union_set(2, 3);
    union_set(4, 5);
    union_set(6, 7);
    union_set(5, 6);
    union_set(3, 7);

    printf("优化版并查集测试：\n");
    for (int i = 1; i <= n; i++) {
        printf("元素%d的根是%d\n", i, find(i));
    }

    printf("\nparent数组：");
    for (int i = 1; i <= n; i++) printf("%d ", parent[i]);

    printf("\nrank数组：  ");
    for (int i = 1; i <= n; i++) printf("%d ", rank[i]);

    return 0;
}