#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;

    // 用于sort的比较函数
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

class DSU {
    vector<int> parent;

public:
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

int kruskalMST(int V, vector<Edge>& edges) {
    // 1. 排序边
    sort(edges.begin(), edges.end());

    // 2. 初始化并查集
    DSU dsu(V);

    // 3. 构建MST
    int total = 0, edgesUsed = 0;

    for (const Edge& e : edges) {
        if (!dsu.same(e.u, e.v)) {
            total += e.w;
            dsu.unite(e.u, e.v);
            if (++edgesUsed == V - 1) break;
        }
    }

    return total;
}

int main_154() {
    vector<Edge> edges = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3},
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7},
        {3, 4, 9}
    };

    int weight = kruskalMST(5, edges);
    cout << "最小生成树总权重: " << weight << endl;

    return 0;
}