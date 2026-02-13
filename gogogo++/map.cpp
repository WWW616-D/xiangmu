#include "gogogo++.h"
using namespace std;

int main_Unordered_map() {
    // 1. 创建 unordered_map
    unordered_map<string, int> wordCount;

    // 2. 插入/更新元素
    wordCount["apple"] = 3;      // 插入
    wordCount["banana"] = 2;
    wordCount["apple"] = 5;      // 更新，现在 apple: 5

    // 3. 使用 insert（不会覆盖）
    wordCount.insert({ "cherry", 1 });  // 成功插入
    wordCount.insert({ "apple", 10 });  // 不会覆盖，apple 还是 5

    // 4. 访问元素
    cout << "apple 出现次数: " << wordCount["apple"] << endl;  // 5
    cout << "banana 出现次数: " << wordCount["banana"] << endl; // 2

    // 5. 检查键是否存在
    if (wordCount.find("orange") == wordCount.end()) {
        cout << "orange 不存在" << endl;
    }

    // 6. 遍历
    cout << "\n所有单词计数:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 7. 删除元素
    wordCount.erase("banana");

    // 8. 大小和清空
    cout << "\n大小: " << wordCount.size() << endl;
    wordCount.clear();

    return 0;
}

int main_map() {
    cout << "=== map 基本操作 ===" << endl;

    // 1. 创建和初始化
    map<string, int> scores = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78}
    };

    // 2. 插入元素
    scores["David"] = 95;          // 使用下标插入
    scores.insert({ "Eve", 88 });    // 使用insert插入

    // 3. 访问元素
    cout << "\n1. 访问元素:" << endl;
    cout << "Alice的分数: " << scores["Alice"] << endl;
    cout << "Bob的分数: " << scores.at("Bob") << endl;  // 更安全，会检查边界

    // 4. 检查元素是否存在
    cout << "\n2. 检查元素存在:" << endl;
    if (scores.find("Frank") != scores.end()) {
        cout << "找到Frank" << endl;
    }
    else {
        cout << "未找到Frank" << endl;
    }

    // 5. 遍历map
    cout << "\n3. 遍历map（按键自动排序）:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 6. 使用迭代器遍历
    cout << "\n4. 使用迭代器遍历:" << endl;
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    // 7. 修改元素
    cout << "\n5. 修改元素:" << endl;
    scores["Alice"] = 90;  // 修改现有值
    scores["Frank"] = 82;  // 不存在则创建

    // 8. 删除元素
    cout << "\n6. 删除元素:" << endl;
    scores.erase("Charlie");  // 删除键为"Charlie"的元素

    // 9. 大小和空检查
    cout << "\n7. 大小检查:" << endl;
    cout << "map大小: " << scores.size() << endl;
    cout << "是否为空: " << (scores.empty() ? "是" : "否") << endl;

    // 10. 边界查询
    cout << "\n8. 边界查询:" << endl;
    scores["Anna"] = 79;
    scores["Zack"] = 85;

    // lower_bound: 第一个 >= key 的元素
    auto lb = scores.lower_bound("C");
    cout << "第一个 >= 'C' 的是: " << lb->first << endl;

    // upper_bound: 第一个 > key 的元素  
    auto ub = scores.upper_bound("D");
    cout << "第一个 > 'D' 的是: " << ub->first << endl;

    // 11. 范围遍历
    cout << "\n9. 遍历C到E之间的元素:" << endl;
    auto start = scores.lower_bound("C");
    auto end = scores.upper_bound("E");
    for (auto it = start; it != end; ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // 12. 获取最小和最大键
    cout << "\n10. 最小和最大键:" << endl;
    if (!scores.empty()) {
        cout << "最小键: " << scores.begin()->first << endl;
        cout << "最大键: " << scores.rbegin()->first << endl;
    }

    // 13. 清空map
    cout << "\n11. 清空map:" << endl;
    scores.clear();
    cout << "清空后大小: " << scores.size() << endl;

    return 0;
}