#include "gogogo++.h"
using namespace std;

int main_priority_queue() {
    // 创建最大堆（默认）
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 插入元素
    maxHeap.push(30);
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(50);
    maxHeap.push(40);

    // 查看顶部元素（最大值）
    cout << "堆顶元素: " << maxHeap.top() << endl;  // 50

    // 弹出顶部元素
    maxHeap.pop();
    cout << "弹出后堆顶: " << maxHeap.top() << endl;  // 40

    // 遍历（会破坏堆）
    cout << "弹出所有元素: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";  // 40 30 20 10
        maxHeap.pop();
    }

    return 0;
}