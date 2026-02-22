#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// 字典单词 + 概率 + 最优BST构建
class DictionaryOBST {
private:
    vector<string> words;      // 单词（已排序）
    vector<double> p;          // 成功概率 p[1..n]
    vector<double> q;          // 失败概率 q[0..n]
    int n;                     // 单词个数

    vector<vector<double>> e;  // e[i][j] 最小期望代价
    vector<vector<double>> w;  // w[i][j] 区间总概率
    vector<vector<int>> root;  // root[i][j] 最优根下标

public:
    // 构造函数：传入排序好的单词、成功概率、失败概率
    DictionaryOBST(const vector<string>& dict,
        const vector<double>& succProb,
        const vector<double>& failProb) {
        words = dict;
        n = words.size();

        // p[1..n]，索引对齐
        p.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            p[i] = succProb[i - 1];
        }

        // q[0..n]
        q = failProb;

        // 初始化DP表
        e.resize(n + 2, vector<double>(n + 1, 0.0));
        w.resize(n + 2, vector<double>(n + 1, 0.0));
        root.resize(n + 2, vector<int>(n + 1, 0));
    }

    // 构建最优BST（Knuth优化 O(n?)）
    double build() {
        // 初始化空树
        for (int i = 1; i <= n + 1; i++) {
            e[i][i - 1] = q[i - 1];
            w[i][i - 1] = q[i - 1];
        }

        // 按区间长度从小到大
        for (int len = 1; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1;

                // 计算区间总概率
                w[i][j] = w[i][j - 1] + p[j] + q[j];

                e[i][j] = numeric_limits<double>::max();

                // Knuth优化：根的范围
                int low = root[i][j - 1];
                int high = root[i + 1][j];
                if (len == 1) {
                    low = i;
                    high = j;
                }

                // 找最优根
                for (int r = low; r <= high; r++) {
                    double cost = e[i][r - 1] + e[r + 1][j] + w[i][j];
                    if (cost < e[i][j]) {
                        e[i][j] = cost;
                        root[i][j] = r;
                    }
                }
            }
        }

        return e[1][n];
    }

    // 打印树结构
    void printTree() {
        cout << "\n================ 最优二叉搜索树 ================\n";
        cout << "单词列表（已排序）：\n";
        for (int i = 1; i <= n; i++) {
            cout << "K" << i << " = \"" << words[i - 1] << "\" (p=" << p[i] << ")\n";
        }
        cout << "\n空隙概率：\n";
        for (int i = 0; i <= n; i++) {
            if (i == 0) cout << "d0: < " << words[0] << " (q=" << q[i] << ")\n";
            else if (i == n) cout << "d" << i << ": > " << words[n - 1] << " (q=" << q[i] << ")\n";
            else cout << "d" << i << ": " << words[i - 1] << " ~ " << words[i] << " (q=" << q[i] << ")\n";
        }

        cout << "\n=============== 树结构（括号内为概率） ===============\n";
        printSubtree(1, n, -1, ' ');
        cout << "\n最小期望查找代价 = " << e[1][n] << endl;
        cout << "================================================\n";
    }

private:
    void printSubtree(int i, int j, int parent, char dir) {
        if (i > j) {
            // 打印伪键（空隙）
            if (parent != -1) {
                if (dir == 'L') {
                    cout << "    [空隙] d" << i - 1 << " (q=" << q[i - 1]
                        << ") 是 \"" << words[parent - 1] << "\" 的左孩子\n";
                }
                else {
                    cout << "    [空隙] d" << j << " (q=" << q[j]
                        << ") 是 \"" << words[parent - 1] << "\" 的右孩子\n";
                }
            }
            return;
        }

        int r = root[i][j];

        // 打印当前节点
        if (parent == -1) {
            cout << "根节点：\"" << words[r - 1] << "\" (p=" << p[r] << ")\n";
        }
        else {
            cout << "节点：\"" << words[r - 1] << "\" (p=" << p[r]
                << ") 是 \"" << words[parent - 1] << "\" 的 "
                << (dir == 'L' ? "左" : "右") << "孩子\n";
        }

        // 递归打印左右子树
        printSubtree(i, r - 1, r, 'L');
        printSubtree(r + 1, j, r, 'R');
    }
};

int main_456() {
    // ========== 你的字典数据 ==========
    vector<string> dictionary = {
        "cat",     // K1
        "dog",     // K2
        "fox",     // K3
        "pig",     // K4
        "zoo"      // K5
    };

    // 成功概率（查找单词的概率）
    vector<double> successProb = {
        0.15,  // cat
        0.10,  // dog
        0.05,  // fox
        0.10,  // pig
        0.20   // zoo
    };

    // 失败概率（查找空隙的概率）
    vector<double> failProb = {
        0.05,  // d0: < cat
        0.10,  // d1: cat-dog 之间
        0.05,  // d2: dog-fox 之间
        0.05,  // d3: fox-pig 之间
        0.05,  // d4: pig-zoo 之间
        0.10   // d5: > zoo
    };
    // =================================

    // 验证概率和是否为1
    double sumP = 0, sumQ = 0;
    for (double x : successProb) sumP += x;
    for (double x : failProb) sumQ += x;
    cout << "总概率 = " << sumP + sumQ << " (应等于1)\n";

    // 构建最优BST
    DictionaryOBST obst(dictionary, successProb, failProb);
    double minCost = obst.build();

    // 打印结果
    obst.printTree();

    return 0;
}