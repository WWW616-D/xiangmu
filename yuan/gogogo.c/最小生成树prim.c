#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // 顶点数
#define MAX_HEAP 100  // 堆最大容量

// ============ 简单优先队列（数组实现）============
typedef struct {
    int vertex;
    int key;
} PQNode;

PQNode pq[MAX_HEAP];  // 简单数组作为堆
int pqSize = 0;

// 上浮调整
void swim(int k) {
    while (k > 0 && pq[k].key < pq[(k - 1) / 2].key) {
        // 交换
        PQNode temp = pq[k];
        pq[k] = pq[(k - 1) / 2];
        pq[(k - 1) / 2] = temp;
        k = (k - 1) / 2;
    }
}
// 下沉调整
void sink(int k) {
    while (2 * k + 1 < pqSize) {
        int j = 2 * k + 1;
        // 选择较小的子节点
        if (j + 1 < pqSize && pq[j + 1].key < pq[j].key) j++;
        if (pq[k].key <= pq[j].key) break;

        // 交换
        PQNode temp = pq[k];
        pq[k] = pq[j];
        pq[j] = temp;
        k = j;
    }
}

// 插入元素
void pqInsert(int vertex, int key) {
    pq[pqSize].vertex = vertex;
    pq[pqSize].key = key;
    swim(pqSize);
    pqSize++;
}

// 弹出最小元素
PQNode pqPopMin() {
    if (pqSize == 0) {
        PQNode empty = { -1, INT_MAX };
        return empty;
    }

    PQNode min = pq[0];
    pq[0] = pq[--pqSize];
    sink(0);
    return min;
}

// 判断堆是否为空
bool pqEmpty() {
    return pqSize == 0;
}

// ============ Prim算法主函数 ============
void primMST(int graph[V][V]) {
    int parent[V];      // 存储MST
    int key[V];         // key值
    bool inMST[V];      // 是否在MST中

    // 初始化
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    // 从顶点0开始
    key[0] = 0;
    parent[0] = -1;
    pqInsert(0, 0);

    while (!pqEmpty()) {
        // 取出key值最小的顶点
        PQNode node = pqPopMin();
        int u = node.vertex;

        // 如果已经在MST中，跳过
        if (inMST[u]) continue;
        inMST[u] = true;

        // 遍历所有邻居
        for (int v = 0; v < V; v++) {
            // 如果有边，且v不在MST中，且找到更小的边
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                pqInsert(v, key[v]);  // 插入或更新堆
            }
        }
    }

    // 打印结果
    printf("边 \t权重\n");
    int totalWeight = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("最小生成树总权重: %d\n", totalWeight);
}

int main() {
    /* 示例图
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}