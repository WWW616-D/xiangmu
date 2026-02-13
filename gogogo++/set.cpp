#include "gogogo++.h"
using namespace std;

int main_unorderedSet() {
    // 1. 创建 unordered_set
    unordered_set<int> mySet;

    // 2. 插入元素
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // 这个不会被插入，因为 10 已存在
    mySet.insert(30);

    // 3. 检查元素是否存在
    if (mySet.find(20) != mySet.end()) {
        cout << "20 存在于集合中" << endl;
    }

    // 4. 获取集合大小（不同元素的数量）
    cout << "集合大小: " << mySet.size() << endl;  // 输出 3

    // 5. 遍历集合
    for (int num : mySet) {
        cout << num << " ";  // 输出顺序不确定，可能是 30 20 10
    }
    cout << endl;

    // 6. 删除元素
    mySet.erase(20);

    // 7. 清空集合
    mySet.clear();

    return 0;
}



int main_set() {
    // 1. 创建 set（默认升序）
    set<int> mySet;

    // 2. 插入元素
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(10);  // 这个不会被插入，因为 10 已存在

    // 3. 遍历集合（元素会自动排序）
    cout << "集合元素（升序）: ";
    for (int num : mySet) {
        cout << num << " ";  // 输出: 10 20 30
    }
    cout << endl;

    // 4. 获取集合大小
    cout << "集合大小: " << mySet.size() << endl;  // 输出 3

    // 5. 检查元素是否存在
    if (mySet.find(20) != mySet.end()) {
        cout << "20 存在于集合中" << endl;
    }
    // 6. 反向遍历（从大到小）
    cout << "反向遍历: ";
    for (auto it = mySet.rbegin(); it != mySet.rend(); ++it) {
        cout << *it << " ";  // 输出: 30 20 10
    }
    cout << endl;

    // 7. 删除元素
    mySet.erase(20);

    // 8. 清空集合
    mySet.clear();

    return 0;
}
