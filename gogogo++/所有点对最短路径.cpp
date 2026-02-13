#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX / 2;

/**
 * 标准二维优化 - 原地更新
 * 空间: O(V²)
 * 时间: O(V³)
 */
vector<vector<int>> floyd_warshall(int V, vector<vector<pair<int, int>>>& graph) {
    // 初始化距离矩阵
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // 对角线为0
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
    }

    // 初始化直接边
    for (int i = 0; i < V; i++) {
        for (auto& edge : graph[i]) {
            int j = edge.first;
            int w = edge.second;
            dist[i][j] = min(dist[i][j], w);  // 处理平行边
        }
    }

    // 核心三重循环 - k在最外层
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (dist[i][k] == INF) continue;  // 剪枝
            for (int j = 0; j < V; j++) {
                if (dist[k][j] == INF) continue;  // 剪枝
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist;
}