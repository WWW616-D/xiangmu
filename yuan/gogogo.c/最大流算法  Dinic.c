#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXN 1000      // 最大顶点数
#define MAXE 20000     // 最大边数（注意：双向边要×2）

// ==================== 数据结构 ====================
typedef struct {
    int to;          // 目标顶点
    int cap;         // 剩余容量
    int rev;         // 反向边在edges数组中的索引
    int next;        // 下一条边在edges数组中的索引（-1表示结束）
} Edge;

Edge edges[2 * MAXE];  // 存储所有边的数组（双向边×2）
int head[MAXN];        // head[u]: 顶点u的第一条边在edges中的索引
int edge_cnt;          // 当前已使用的边数

int level[MAXN];       // BFS分层：level[u] = 从源点到u的距离
int iter[MAXN];        // 当前弧优化：iter[u] = 顶点u当前检查到哪条边
int n, s, t;           // 顶点数，源点，汇点

// ==================== 初始化 ====================
void init() {
    memset(head, -1, sizeof(head));  // -1表示没有边
    edge_cnt = 0;
}

// ==================== 添加边 ====================
void add_edge(int u, int v, int cap) {
    // 添加正向边 u→v
    edges[edge_cnt] = (Edge){ v, cap, edge_cnt + 1, head[u] };
    head[u] = edge_cnt;      // 头插法：新边成为链表头
    edge_cnt++;

    // 添加反向边 v→u（初始容量0）
    edges[edge_cnt] = (Edge){ u, 0, edge_cnt - 1, head[v] };
    head[v] = edge_cnt;
    edge_cnt++;
}

// ==================== BFS构建分层图 ====================
int bfs() {
    // 初始化所有顶点层级为-1（未访问）
    memset(level, -1, sizeof(level));

    // 简单队列实现
    int queue[MAXN];
    int front = 0, rear = 0;

    level[s] = 0;            // 源点层级为0
    queue[rear++] = s;       // 源点入队

    while (front < rear) {
        int u = queue[front++];  // 出队

        // 遍历u的所有出边
        for (int i = head[u]; i != -1; i = edges[i].next) {
            Edge* e = &edges[i];

            // 如果边还有容量且目标顶点未访问
            if (e->cap > 0 && level[e->to] < 0) {
                level[e->to] = level[u] + 1;  // 距离+1

                // 如果到达汇点，可以提前返回（优化）
                if (e->to == t) return 1;

                queue[rear++] = e->to;  // 入队
            }
        }
    }

    return level[t] >= 0;  // 返回是否可达汇点
}

// ==================== DFS找阻塞流 ====================
int dfs(int u, int f) 
{
    if (u == t) return f;  // 到达汇点，返回流量

    // 当前弧优化：从iter[u]开始，避免重复检查
    for (int i = iter[u]; i != -1; i = edges[i].next) {
        iter[u] = i;  // 更新当前弧位置（重要！）

        Edge* e = &edges[i];

        // 条件1: 边还有容量
        // 条件2: 符合分层图规则（只能往下一层走）
        if (e->cap > 0 && level[u] < level[e->to]) {
            // 递归尝试发送流量
            int d = dfs(e->to, (f < e->cap) ? f : e->cap);

            if (d > 0) {  // 成功发送了d单位流量
                e->cap -= d;                    // 减少正向边容量
                edges[e->rev].cap += d;         // 增加反向边容量
                return d;                       // 返回发送的流量
            }
        }
    }

    return 0;  // 无法发送任何流量
}

// ==================== Dinic主函数 ====================
int dinic() {
    int max_flow = 0;

    // 不断构建分层图并找阻塞流
    while (bfs()) {
        // 重置当前弧：每个顶点都从第一条边开始检查
        for (int i = 0; i < n; i++) {
            iter[i] = head[i];
        }

        // 在当前分层图上反复找增广路径
        int f;
        while ((f = dfs(s, INT_MAX)) > 0) {
            max_flow += f;
        }
    }

    return max_flow;
}

// ==================== 打印图的邻接表结构（调试用） ====================
void print_graph() {
    printf("\n=== 图的邻接表结构 ===\n");
    for (int u = 0; u < n; u++) {
        printf("顶点 %d 的边:", u);

        int count = 0;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            Edge* e = &edges[i];
            printf(" [%d→%d cap=%d rev=%d]", u, e->to, e->cap, e->rev);
            count++;
            if (count > 5) { printf("..."); break; }  // 防止输出太长
        }

        if (count == 0) printf(" 无出边");
        printf("\n");
    }
    printf("总边数: %d (双向边算2条)\n", edge_cnt);
}

// ==================== 打印流量分配（调试用） ====================
void print_flow() {
    printf("\n=== 流量分配 ===\n");
    for (int u = 0; u < n; u++) {
        for (int i = head[u]; i != -1; i = edges[i].next) {
            Edge* e = &edges[i];

            // 只打印正向边（初始容量>0的边）
            if (i % 2 == 0) {  // 我们约定：偶数索引是正向边
                // 计算实际流量 = 初始容量 - 剩余容量
                // 但这里不知道初始容量，所以只显示剩余容量
                printf("%d → %d: 剩余容量=%d", u, e->to, e->cap);

                // 如果反向边有容量，说明有流量
                if (edges[e->rev].cap > 0) {
                    printf(" (已发送流量=%d)", edges[e->rev].cap);
                }
                printf("\n");
            }
        }
    }
}

// ==================== 主函数：测试 ====================
int main() {
    // 初始化
    init();

    // 设置图参数（经典例子）
    n = 6;      // 顶点数：0,1,2,3,4,5
    s = 0;      // 源点
    t = 5;      // 汇点

    // 构建网络（经典网络流例子）
    printf("构建网络中...\n");

    add_edge(0, 1, 16);  // s→1
    add_edge(0, 2, 13);  // s→2
    add_edge(1, 2, 10);  // 1→2
    add_edge(1, 3, 12);  // 1→3
    add_edge(2, 1, 4);   // 2→1
    add_edge(2, 4, 14);  // 2→4
    add_edge(3, 2, 9);   // 3→2
    add_edge(3, 5, 20);  // 3→t
    add_edge(4, 3, 7);   // 4→3
    add_edge(4, 5, 4);   // 4→t

    // 打印图结构（调试）
    print_graph();

    printf("\n开始计算最大流...\n");
    printf("源点: %d, 汇点: %d\n", s, t);

    // 计算最大流
    int max_flow = dinic();

    printf("\n最大流值: %d\n", max_flow);

    // 打印流量分配
    print_flow();

    // ==================== 第二个测试例子 ====================
    printf("\n\n=== 第二个测试：简单网络 ===\n");

    init();  // 重新初始化
    n = 4; s = 0; t = 3;

    // 一个更简单的网络，方便理解
    add_edge(0, 1, 3);
    add_edge(0, 2, 2);
    add_edge(1, 3, 2);
    add_edge(2, 1, 1);
    add_edge(2, 3, 1);

    print_graph();

    max_flow = dinic();
    printf("\n最大流值: %d\n", max_flow);
    print_flow();

    return 0;
}