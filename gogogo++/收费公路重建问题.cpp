#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class TurnpikeReconstructor {
private:
    int n;                          // 点的数量
    vector<int> points;            // 重建出的点坐标
    multiset<int, greater<int>> dists;  // 距离集合（降序）

    // 辅助函数：移除一个距离
    bool remove_distance(int d) {
        auto it = dists.find(d);
        if (it == dists.end()) return false;
        dists.erase(it);
        return true;
    }

    // 核心递归函数
    bool reconstruct(vector<int>& x, int left, int right) {
        // 递归终止：所有距离用完
        if (dists.empty()) return true;

        // 获取当前最大距离
        int d = *dists.begin();

        // 候选1：新点在右边
        int candidate1 = d;
        bool valid1 = true;
        vector<int> removed1;

        // 检查候选1是否合法：与所有已确定点的距离都存在
        for (int i = left; i <= right; i++) {
            int dist_needed = abs(x[i] - candidate1);
            auto it = dists.find(dist_needed);
            if (it == dists.end()) {
                valid1 = false;
                break;
            }
            removed1.push_back(dist_needed);
        }

        // 如果合法，尝试这个候选
        if (valid1) {
            // 移除所有涉及的距离
            for (int d : removed1) {
                remove_distance(d);
            }

            // 添加新点
            x[right + 1] = candidate1;

            // 递归
            if (reconstruct(x, left, right + 1)) {
                return true;
            }

            // 回溯：恢复距离，移除点
            for (int d : removed1) {
                dists.insert(d);
            }
        }

        // 候选2：新点在左边
        int candidate2 = x[right] - d;
        bool valid2 = true;
        vector<int> removed2;

        // 检查候选2是否合法
        for (int i = left; i <= right; i++) {
            int dist_needed = abs(x[i] - candidate2);
            auto it = dists.find(dist_needed);
            if (it == dists.end()) {
                valid2 = false;
                break;
            }
            removed2.push_back(dist_needed);
        }

        // 如果合法，尝试这个候选
        if (valid2 && candidate2 >= 0) {
            // 移除所有涉及的距离
            for (int d : removed2) {
                remove_distance(d);
            }

            // 添加新点（在左边插入）
            for (int i = right; i >= left; i--) {
                x[i + 1] = x[i];
            }
            x[left] = candidate2;

            // 递归
            if (reconstruct(x, left, right + 1)) {
                return true;
            }

            // 回溯：恢复距离和点
            for (int d : removed2) {
                dists.insert(d);
            }
            for (int i = left; i < right; i++) {
                x[i] = x[i + 1];
            }
        }

        return false;
    }

public:
    // 构造函数：输入距离集合
    TurnpikeReconstructor(vector<int>& distances) {
        for (int d : distances) {
            dists.insert(d);
        }

        // 计算点的数量 N(N-1)/2 = distances.size()
        n = (1 + sqrt(1 + 8 * distances.size())) / 2;
        points.resize(n);
    }

    // 重建主函数
    bool reconstruct() {
        // 设第一个点为0
        points[0] = 0;

        // 最大距离作为最后一个点
        int max_dist = *dists.begin();
        points[n - 1] = max_dist;

        // 移除最大距离
        remove_distance(max_dist);

        // 开始递归重建
        return reconstruct(points, 0, n - 1);
    }

    // 获取结果
    void print_points() {
        sort(points.begin(), points.end());
        cout << "重建的点坐标: ";
        for (int p : points) {
            cout << p << " ";
        }
        cout << "\n";
    }
};

// 测试代码
int main() {
    // 经典案例：6个点
    vector<int> distances = {
        1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 10
    };

    TurnpikeReconstructor tr(distances);
    if (tr.reconstruct()) {
        tr.print_points();
    }
    else {
        cout << "无法重建\n";
    }

    return 0;
}