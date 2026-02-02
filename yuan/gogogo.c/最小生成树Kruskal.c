#include <stdio.h>
#include <stdlib.h>

#define V 5  // 顶点数
#define E 7  // 边数

// 边结构体
typedef struct {
    int src, dest, weight;
} Edge;

// qsort比较函数（按权重升序）
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// 并查集
int parent[V];

int find(int x) {
    return parent[x] == x ? x : (parent[x] = find(parent[x]));
}

// Kruskal算法
void kruskalMST(Edge edges[]) {
    Edge result[V - 1];
    int e = 0;  // result索引
    int total = 0;

    // 1. 排序边（直接用qsort）
    qsort(edges, E, sizeof(Edge), compareEdges);

    // 2. 初始化并查集
    for (int i = 0; i < V; i++) parent[i] = i;

    // 3. 选择边
    printf("最小生成树的边：\n");
    for (int i = 0; i < E && e < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            result[e++] = edges[i];
            parent[find(u)] = find(v);
            total += edges[i].weight;
            printf("%d - %d \t权重: %d\n", u, v, edges[i].weight);
        }
    }

    printf("总权重: %d\n", total);
}

int main() {
    Edge edges[E] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(edges);
    return 0;
}