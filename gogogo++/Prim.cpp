#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 邻接表表示法的边
struct Edge {
    int to;      // 目标顶点
    int weight;  // 边权重

    Edge(int t, int w) : to(t), weight(w) {}

    // 用于优先队列的比较（最小堆）
    bool operator>(const Edge& other) const {   //避免拷贝
        return weight > other.weight;
    }
};

class PrimMST {
private:
    int V;  // 顶点数
    vector<vector<Edge>> adj;  // 邻接表

public:
    PrimMST(int vertices) : V(vertices), adj(vertices) {}

    // 添加边
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(Edge(v, weight));
        adj[v].push_back(Edge(u, weight));  // 无向图
    }

    // Prim算法实现（优先队列优化）
    void findMST() {
        vector<int> parent(V, -1);    // 存储MST
        vector<int> key(V, INT_MAX);  // key值
        vector<bool> inMST(V, false); // 是否在MST中

        // 优先队列（最小堆）
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // 从顶点0开始
        key[0] = 0;
        pq.push({ 0, 0 });  // {key值, 顶点}

        int totalWeight = 0;

        while (!pq.empty()) {
            // 取出key值最小的顶点
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;
            inMST[u] = true;

            // 遍历所有邻居
            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({ key[v], v });
                }
            }
        }

        // 打印结果
        cout << "边 \t权重" << endl;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " \t" << key[i] << endl;
            totalWeight += key[i];
        }
        cout << "最小生成树总权重: " << totalWeight << endl;
    }
};

int main_5444() {
    // 创建与C语言示例相同的图
    PrimMST graph(5);

    // 添加边
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    graph.findMST();

    return 0;
}