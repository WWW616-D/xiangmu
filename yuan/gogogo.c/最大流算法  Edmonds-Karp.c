//#include <stdio.h>
//#include <limits.h>
//#include <stdbool.h>
//
//#define N 4
//#define SOURCE 0
//#define SINK 3
//
//// 广度优先搜索：在残量网络中找增广路径
//bool bfs(int residualGraph[N][N], int parent[]) {
//    bool visited[N] = { false };
//    int queue[N], front = 0, rear = 0;
//
//    queue[rear++] = SOURCE;
//    visited[SOURCE] = true;
//    parent[SOURCE] = -1;
//
//    while (front < rear) {
//        int u = queue[front++];
//
//        for (int v = 0; v < N; v++) {
//            // 如果有剩余容量且未访问
//            if (!visited[v] && residualGraph[u][v] > 0) {
//                queue[rear++] = v;
//                parent[v] = u;
//                visited[v] = true;
//
//                if (v == SINK) return true;
//            }
//        }
//    }
//    return false; // 找不到增广路径
//}
//
//// 最大流主函数
//int edmonds_karp(int graph[N][N]) {
//    int rGraph[N][N]; // 残量网络
//    int parent[N];    // 记录路径
//
//    // 初始化残量网络（拷贝原图）
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            rGraph[i][j] = graph[i][j];
//
//    int max_flow = 0;
//
//    // 每次循环：找到一条增广路径并更新流量
//    while (bfs(rGraph, parent)) {
//        // 1. 找到瓶颈容量
//        int bottleneck = INT_MAX;
//        for (int v = SINK; v != SOURCE; v = parent[v]) {
//            int u = parent[v];
//            if (rGraph[u][v] < bottleneck)
//                bottleneck = rGraph[u][v];
//        }
//
//        // 2. 更新残量网络（这里发生「退货调整」！）
//        for (int v = SINK; v != SOURCE; v = parent[v]) {
//            int u = parent[v];
//
//            printf("更新边 %d→%d: ", u, v);
//            printf("正向 %d → %d, ", rGraph[u][v], rGraph[u][v] - bottleneck);
//            printf("反向 %d → %d\n", rGraph[v][u], rGraph[v][u] + bottleneck);
//
//            // 关键的两行：减少正向，增加反向
//            rGraph[u][v] -= bottleneck; // 正向边剩余容量减少
//            rGraph[v][u] += bottleneck; // 反向边容量增加
//        }
//
//        max_flow += bottleneck;
//        printf("本轮增加流量: %d, 累计流量: %d\n\n", bottleneck, max_flow);
//    }
//
//    return max_flow;
//}
//
//int main() {
//    // 构造一个清晰的例子
//    int graph[N][N] = {
//        // s=0, A=1, B=2, t=3
//        {0, 3, 2, 0}, // s: s→A=3, s→B=2
//        {0, 0, 0, 2}, // A: A→t=2
//        {0, 1, 0, 1}, // B: B→A=1, B→t=1
//        {0, 0, 0, 0}  // t: 无出边
//    };
//
//    printf("初始图（容量矩阵）:\n");
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            printf("%d ", graph[i][j]);
//        printf("\n");
//    }
//    printf("\n");
//
//    int max_flow = edmonds_karp(graph);
//    printf("最大流 = %d\n", max_flow);
//
//    return 0;
//}