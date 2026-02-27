///**
// * Dijkstra最短路径算法（堆优化版）
// * 时间复杂度：O((V+E)log V)
// * 适用：无负权边的图
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//#define INF INT_MAX  // 无穷大
//
// // ============ 数据结构 ============
//
// // 邻接表节点
//typedef struct AdjNode {
//    int vertex;      // 邻居顶点
//    int weight;      // 边权值
//    struct AdjNode* next;
//} AdjNode;
//
//// 堆节点（优先队列）
//typedef struct HeapNode {
//    int dist;        // 到起点的距离
//    int vertex;      // 顶点编号
//} HeapNode;
//
//// 最小堆
//typedef struct MinHeap {
//    HeapNode* arr;   // 堆数组
//    int size;        // 当前大小
//    int capacity;    // 容量
//} MinHeap;
//
//// ============ 堆操作 ============
//
//// 创建堆
//MinHeap* createHeap(int cap) {
//    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
//    heap->arr = (HeapNode*)malloc(cap * sizeof(HeapNode));
//    heap->size = 0;
//    heap->capacity = cap;
//    return heap;
//}
//
//// 交换节点
//void swapnode(HeapNode* a, HeapNode* b) {
//    HeapNode temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//// 向下调整堆
//void heapify(MinHeap* heap, int i) {
//    int smallest = i;
//    int left = 2 * i + 1;
//    int right = 2 * i + 2;
//
//    if (left < heap->size && heap->arr[left].dist < heap->arr[smallest].dist)
//        smallest = left;
//    if (right < heap->size && heap->arr[right].dist < heap->arr[smallest].dist)
//        smallest = right;
//
//    if (smallest != i) {
//        swap(&heap->arr[i], &heap->arr[smallest]);
//        heapify(heap, smallest);
//    }
//}
//
//// 插入堆
//void insertHeap(MinHeap* heap, int dist, int vertex) {
//    if (heap->size == heap->capacity) return;
//
//    int i = heap->size++;
//    heap->arr[i].dist = dist;
//    heap->arr[i].vertex = vertex;
//
//    // 上浮调整
//    while (i > 0 && heap->arr[(i - 1) / 2].dist > heap->arr[i].dist) {
//        swapnode(&heap->arr[i], &heap->arr[(i - 1) / 2]);
//        i = (i - 1) / 2;
//    }
//}
//
//// 弹出堆顶（最小值）
//HeapNode extractMin(MinHeap* heap) {
//    if (heap->size <= 0) {
//        HeapNode empty = { INF, -1 };
//        return empty;
//    }
//
//    HeapNode root = heap->arr[0];
//    heap->arr[0] = heap->arr[--heap->size];
//    heapify(heap, 0);
//
//    return root;
//}
//
//// 堆空判断
//int isEmpty(MinHeap* heap) {
//    return heap->size == 0;
//}
//
//// 释放堆
//void freeHeap(MinHeap* heap) {
//    free(heap->arr);
//    free(heap);
//}
//
//// ============ 图操作 ============
//
//// 添加边
//void addEdge(AdjNode* graph[], int u, int v, int w) {
//    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
//    node->vertex = v;
//    node->weight = w;
//    node->next = graph[u];
//    graph[u] = node;
//}
//
//// 打印图
//void printGraph(AdjNode* graph[], int V) {
//    for (int i = 0; i < V; i++) {
//        printf("顶点%d: ", i);
//        AdjNode* cur = graph[i];
//        while (cur) {
//            printf("->%d(w:%d) ", cur->vertex, cur->weight);
//            cur = cur->next;
//        }
//        printf("\n");
//    }
//}
//
//// ============ Dijkstra算法 ============
//
///**
// * Dijkstra堆优化版
// * @param graph 邻接表
// * @param src   起点
// * @param V     顶点数
// */
//void dijkstra(AdjNode* graph[], int src, int V) {
//    int* dist = (int*)malloc(V * sizeof(int));
//    for (int i = 0; i < V; i++) dist[i] = INF;
//    dist[src] = 0;
//
//    // 创建堆，放入起点
//    MinHeap* heap = createHeap(V * V);
//    insertHeap(heap, 0, src);
//
//    printf("从顶点 %d 出发的最短路径:\n", src);
//
//    while (!isEmpty(heap)) {
//        // 弹出当前距离最小的顶点
//        HeapNode node = extractMin(heap);
//        int u = node.vertex;
//        int d_u = node.dist;
//
//        // 关键：如果弹出的是过时信息，跳过
//        if (d_u > dist[u]) {
//            // printf("跳过过时信息: 顶点%d 距离%d > 当前%d\n", u, d_u, dist[u]);
//            continue;
//        }
//
//        // 更新u的所有邻居
//        AdjNode* cur = graph[u];
//        while (cur != NULL) {
//            int v = cur->vertex;
//            int w = cur->weight;
//            int new_dist = d_u + w;
//
//            // 如果找到更短路径
//            if (new_dist < dist[v]) {
//                dist[v] = new_dist;
//                // 不删除旧记录，直接插入新的
//                insertHeap(heap, new_dist, v);
//            }
//            cur = cur->next;
//        }
//    }
//
//    // 打印结果
//    printf("顶点\t最短距离\n");
//    for (int i = 0; i < V; i++) {
//        if (dist[i] == INF)
//            printf("%d\t不可达\n", i);
//        else
//            printf("%d\t%d\n", i, dist[i]);
//    }
//
//    free(dist);
//    freeHeap(heap);
//}
//
//// ============ 测试 ============
//
//int main() {
//    int V = 6;  // 顶点数
//
//    // 创建邻接表
//    AdjNode* graph[6];
//    for (int i = 0; i < V; i++) graph[i] = NULL;
//
//    // 添加边（示例图）
//    addEdge(graph, 0, 1, 4);
//    addEdge(graph, 1, 0, 4);
//    addEdge(graph, 1, 2, 8);
//    addEdge(graph, 2, 1, 8);
//    addEdge(graph, 2, 3, 7);
//    addEdge(graph, 3, 2, 7);
//    addEdge(graph, 2, 4, 4);
//    addEdge(graph, 4, 2, 4);
//    addEdge(graph, 2, 5, 2);
//    addEdge(graph, 5, 2, 2);
//    addEdge(graph, 3, 4, 9);
//    addEdge(graph, 4, 3, 9);
//    addEdge(graph, 3, 5, 14);
//    addEdge(graph, 5, 3, 14);
//    addEdge(graph, 4, 5, 10);
//    addEdge(graph, 5, 4, 10);
//
//    // 打印图结构
//    printGraph(graph, V);
//    printf("\n");
//
//    // 运行Dijkstra
//    dijkstra(graph, 0, V);
//
//    // 清理内存
//    for (int i = 0; i < V; i++) {
//        AdjNode* cur = graph[i];
//        while (cur) {
//            AdjNode* temp = cur;
//            cur = cur->next;
//            free(temp);
//        }
//    }
//
//    return 0;
//}
//
///*
//输出示例：
//顶点0: ->1(w:4)
//顶点1: ->2(w:8) ->0(w:4)
//顶点2: ->5(w:2) ->4(w:4) ->3(w:7) ->1(w:8)
//顶点3: ->5(w:14) ->4(w:9) ->2(w:7)
//顶点4: ->5(w:10) ->3(w:9) ->2(w:4)
//顶点5: ->4(w:10) ->3(w:14) ->2(w:2)
//
//从顶点 0 出发的最短路径:
//顶点    最短距离
//0       0
//1       4
//2       12
//3       19
//4       16
//5       14
//*/
///**
// * SPFA算法 - Bellman-Ford的队列优化
// * 平均复杂度：O(kE)，k≈2
// * 最坏复杂度：O(VE) (但实际很少达到)
// */
// /**
//  * Bellman-Ford算法 - 处理负权边的最短路径
//  * 复杂度：O(VE)
//  * 特性：能处理负权边，能检测负权环
//  */
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <limits.h>
//
//#define INF INT_MAX
//
//  // 边结构
//typedef struct Edge {
//    int u, v, w;  // 起点，终点，权值
//} Edge;
//
///**
// * Bellman-Ford核心算法
// * @param edges 边数组
// * @param E     边数
// * @param V     顶点数
// * @param src   起点
// * @return 1=成功, 0=有负权环
// */
//int bellmanFord(Edge edges[], int E, int V, int src) {
//    // 1. 初始化距离数组
//    int* dist = (int*)malloc(V * sizeof(int));
//    for (int i = 0; i < V; i++) dist[i] = INF;
//    dist[src] = 0;
//
//    // 2. 进行V-1轮松弛
//    for (int i = 1; i <= V - 1; i++) {
//        int updated = 0;
//
//        // 遍历所有边
//        for (int j = 0; j < E; j++) {
//            int u = edges[j].u;
//            int v = edges[j].v;
//            int w = edges[j].w;
//
//            // 松弛操作
//            if (dist[u] != INF && dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//                updated = 1;
//            }
//        }
//
//        // 如果一轮中没有更新，提前结束
//        if (!updated) break;
//    }
//
//    // 3. 检测负权环
//    for (int j = 0; j < E; j++) {
//        int u = edges[j].u;
//        int v = edges[j].v;
//        int w = edges[j].w;
//
//        if (dist[u] != INF && dist[u] + w < dist[v]) {
//            free(dist);
//            return 0;  // 有负权环
//        }
//    }
//
//    // 4. 输出结果
//    printf("顶点\t距离\n");
//    for (int i = 0; i < V; i++) {
//        if (dist[i] == INF)
//            printf("%d\t不可达\n", i);
//        else
//            printf("%d\t%d\n", i, dist[i]);
//    }
//
//    free(dist);
//    return 1;  // 成功
//}
//
///**
// * 重建路径
// * @param edges 边数组
// * @param E     边数
// * @param V     顶点数
// * @param src   起点
// * @param dest  终点
// */
//void printPath(Edge edges[], int E, int V, int src, int dest) {
//    int* dist = (int*)malloc(V * sizeof(int));
//    int* parent = (int*)malloc(V * sizeof(int));
//
//    for (int i = 0; i < V; i++) {
//        dist[i] = INF;
//        parent[i] = -1;
//    }
//    dist[src] = 0;
//
//    // V-1轮松弛
//    for (int i = 1; i <= V - 1; i++) {
//        for (int j = 0; j < E; j++) {
//            int u = edges[j].u;
//            int v = edges[j].v;
//            int w = edges[j].w;
//
//            if (dist[u] != INF && dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//                parent[v] = u;  // 记录前驱
//            }
//        }
//    }
//
//    // 检查负权环
//    for (int j = 0; j < E; j++) {
//        int u = edges[j].u;
//        int v = edges[j].v;
//        int w = edges[j].w;
//
//        if (dist[u] != INF && dist[u] + w < dist[v]) {
//            printf("存在负权环，无法找到路径\n");
//            free(dist);
//            free(parent);
//            return;
//        }
//    }
//
//    // 输出路径
//    if (dist[dest] == INF) {
//        printf("顶点 %d 到 %d 不可达\n", src, dest);
//    }
//    else {
//        printf("最短距离: %d\n路径: ", dist[dest]);
//
//        // 反向追踪路径
//        int path[V], index = 0;
//        for (int v = dest; v != -1; v = parent[v]) {
//            path[index++] = v;
//        }
//
//        // 反向输出
//        for (int i = index - 1; i >= 0; i--) {
//            printf("%d", path[i]);
//            if (i > 0) printf(" -> ");
//        }
//        printf("\n");
//    }
//
//    free(dist);
//    free(parent);
//}
//
//// ============ 测试代码 ============
//
//int main() {
//    // 示例1：无负权环
//    printf("=== 测试1：无负权环 ===\n");
//    int V1 = 5, E1 = 8;
//    Edge edges1[] = {
//        {0, 1, -1}, {0, 2, 4},
//        {1, 2, 3}, {1, 3, 2},
//        {1, 4, 2}, {3, 2, 5},
//        {3, 1, 1}, {4, 3, -3}
//    };
//
//    bellmanFord(edges1, E1, V1, 0);
//    printPath(edges1, E1, V1, 0, 3);
//    printf("\n");
//
//    // 示例2：有负权环
//    printf("=== 测试2：有负权环 ===\n");
//    int V2 = 4, E2 = 5;
//    Edge edges2[] = {
//        {0, 1, 1}, {1, 2, -1},
//        {2, 3, -1}, {3, 0, -1},
//        {1, 3, 4}
//    };
//
//    if (!bellmanFord(edges2, E2, V2, 0)) {
//        printf("检测到负权环！\n");
//    }
//
//    return 0;
//}
//
///*
//输出示例：
//=== 测试1：无负权环 ===
//顶点  距离
//0       0
//1       -1
//2       2
//3       -2
//4       1
//最短距离: -2
//路径: 0 -> 1 -> 4 -> 3
//
//=== 测试2：有负权环 ===
//检测到负权环！
//*/
//#define INF INT_MAX
//#define MAXV 1000
//
// // 邻接表节点
//typedef struct Node {
//    int v, w;
//    struct Node* next;
//} Node;
//
//// 队列
//typedef struct Queue {
//    int items[MAXV];
//    int front, rear;
//} Queue;
//
//// ============ 队列操作 ============
//Queue* createQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue));
//    q->front = -1;
//    q->rear = -1;
//    return q;
//}
//
//int isEmpty(Queue* q) {
//    return q->front == -1;
//}
//
//void enqueue(Queue* q, int value) {
//    if (q->rear == MAXV - 1) return;
//    if (q->front == -1) q->front = 0;
//    q->items[++(q->rear)] = value;
//}
//
//int dequeue(Queue* q) {
//    if (isEmpty(q)) return -1;
//    int item = q->items[q->front];
//    q->front++;
//    if (q->front > q->rear) q->front = q->rear = -1;
//    return item;
//}
//
//// ============ SPFA算法 ============
///**
// * SPFA最短路径算法
// * @param graph 邻接表
// * @param V     顶点数
// * @param src   起点
// * @return 1=成功, 0=有负环
// */
//int spfa(Node* graph[], int V, int src) {
//    int* dist = (int*)malloc(V * sizeof(int));
//    int* inQueue = (int*)calloc(V, sizeof(int));  // 是否在队列中
//    int* count = (int*)calloc(V, sizeof(int));    // 入队次数
//    Queue* q = createQueue();
//
//    // 初始化
//    for (int i = 0; i < V; i++) dist[i] = INF;
//    dist[src] = 0;
//
//    // 起点入队
//    enqueue(q, src);
//    inQueue[src] = 1;
//    count[src]++;
//
//    while (!isEmpty(q)) {
//        int u = dequeue(q);
//        inQueue[u] = 0;  // 出队标记
//
//        // 遍历u的所有邻居
//        Node* cur = graph[u];
//        while (cur != NULL) {
//            int v = cur->v;
//            int w = cur->w;
//
//            // 松弛操作
//            if (dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//
//                // 如果v不在队列中，入队
//                if (!inQueue[v]) {
//                    enqueue(q, v);
//                    inQueue[v] = 1;
//                    count[v]++;
//
//                    // 检测负环：顶点入队超过V次
//                    if (count[v] > V) {
//                        free(dist);
//                        free(inQueue);
//                        free(count);
//                        free(q);
//                        return 0;  // 有负环
//                    }
//                }
//            }
//            cur = cur->next;
//        }
//    }
//
//    // 输出结果
//    printf("SPFA结果：\n顶点\t距离\n");
//    for (int i = 0; i < V; i++) {
//        if (dist[i] == INF)
//            printf("%d\t不可达\n", i);
//        else
//            printf("%d\t%d\n", i, dist[i]);
//    }
//
//    free(dist);
//    free(inQueue);
//    free(count);
//    free(q);
//    return 1;
//}
//
//// ============ 辅助函数 ============
//void addEdge(Node* graph[], int u, int v, int w) {
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->v = v;
//    node->w = w;
//    node->next = graph[u];
//    graph[u] = node;
//}
//
//// ============ 测试 ============
//int main() {
//    int V = 5;
//    Node* graph[V];
//    for (int i = 0; i < V; i++) graph[i] = NULL;
//
//    // 添加边（与Bellman-Ford测试相同）
//    addEdge(graph, 0, 1, -1);
//    addEdge(graph, 0, 2, 4);
//    addEdge(graph, 1, 2, 3);
//    addEdge(graph, 1, 3, 2);
//    addEdge(graph, 1, 4, 2);
//    addEdge(graph, 3, 2, 5);
//    addEdge(graph, 3, 1, 1);
//    addEdge(graph, 4, 3, -3);
//
//    printf("=== SPFA算法测试 ===\n");
//    if (spfa(graph, V, 0)) {
//        printf("计算成功！\n");
//    }
//    else {
//        printf("检测到负权环！\n");
//    }
//
//    // 清理内存
//    for (int i = 0; i < V; i++) {
//        Node* cur = graph[i];
//        while (cur) {
//            Node* temp = cur;
//            cur = cur->next;
//            free(temp);
//        }
//    }
//
//    return 0;
//}
// 这是最核心的部分（去掉了打印和路径重建）：
//void dagShortestPathSimple(Node* graph[], int V, int src, int order[], int size) {
//    int dist[V];
//    for (int i = 0; i < V; i++) dist[i] = INF;
//    dist[src] = 0;
//
//    // 按拓扑序处理
//    for (int i = 0; i < size; i++) {
//        int u = order[i];
//        if (dist[u] == INF) continue;  // 不可达的跳过
//
//        Node* cur = graph[u];
//        while (cur != NULL) {
//            int v = cur->v;
//            int w = cur->w;
//
//            // 关键：松弛操作
//            if (dist[u] + w < dist[v]) {
//                dist[v] = dist[u] + w;
//            }
//            cur = cur->next;
//        }
//    }

    // dist[]现在包含最短距离
//}