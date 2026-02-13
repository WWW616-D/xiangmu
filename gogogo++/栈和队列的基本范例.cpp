#include "gogogo++.h"
using namespace std;

// 车辆类
class Car {
public:
    string licensePlate;  // 车牌号
    int arrivalTime;      // 到达时间

    Car(string plate, int time)
        : licensePlate(plate), arrivalTime(time) {
    }
};

// 停车场模拟系统
class ParkingLot {
private:
    stack<Car> parkingStack;  // 停车场（栈结构：后进先出）
    queue<Car> waitingQueue;  // 等待区（队列结构：先进先出）

public:
    // 车辆到达
    void carArrives(string licensePlate, int time) {
        if (parkingStack.size() < 5) {  // 假设停车场容量为5
            parkingStack.push(Car(licensePlate, time));
            cout << "车辆 " << licensePlate << " 停入停车场" << endl;
        }
        else {
            waitingQueue.push(Car(licensePlate, time));
            cout << "车辆 " << licensePlate << " 进入等待区" << endl;
        }
    }

    // 车辆离开
    void carLeaves(string licensePlate, int time) {
        stack<Car> tempStack;  // 临时栈，用于移动车辆

        bool found = false;
        int moveCount = 0;

        // 在停车场中查找车辆
        while (!parkingStack.empty()) {
            Car current = parkingStack.top();
            parkingStack.pop();

            if (current.licensePlate == licensePlate) {
                // 找到目标车辆
                found = true;
                int parkingTime = time - current.arrivalTime;
                cout << "车辆 " << licensePlate << " 离开，停车时间: "
                    << parkingTime << " 分钟" << endl;
                cout << "移动了 " << moveCount << " 辆车来腾出位置" << endl;
                break;
            }
            else {
                // 不是目标车辆，先移到临时栈
                tempStack.push(current);
                moveCount++;
            }
        }

        // 把临时栈的车移回停车场
        while (!tempStack.empty()) {
            parkingStack.push(tempStack.top());
            tempStack.pop();
        }

        // 如果找到车辆且等待队列有车，让等待的车进入停车场
        if (found && !waitingQueue.empty()) {
            Car nextCar = waitingQueue.front();
            waitingQueue.pop();
            parkingStack.push(nextCar);
            cout << "车辆 " << nextCar.licensePlate
                << " 从等待区进入停车场" << endl;
        }

        if (!found) {
            cout << "未找到车牌号为 " << licensePlate << " 的车辆" << endl;
        }
    }

    // 显示当前状态
    void displayStatus() {
        cout << "\n=== 停车场状态 ===" << endl;

        // 显示停车场（栈：需要反转显示）
        cout << "停车场内车辆（栈顶是最近停入的）:" << endl;
        stack<Car> temp = parkingStack;
        vector<Car> cars;

        while (!temp.empty()) {
            cars.push_back(temp.top());
            temp.pop();
        }

        // 反向显示，让最早停入的显示在前面
        for (int i = cars.size() - 1; i >= 0; i--) {
            cout << "  车牌: " << cars[i].licensePlate
                << ", 到达时间: " << cars[i].arrivalTime << endl;
        }
        cout << "  当前停车场有 " << parkingStack.size() << " 辆车" << endl;

        // 显示等待队列
        cout << "\n等待区车辆（队列）:" << endl;
        queue<Car> tempQueue = waitingQueue;
        int pos = 1;

        while (!tempQueue.empty()) {
            Car car = tempQueue.front();
            tempQueue.pop();
            cout << "  " << pos++ << ". 车牌: " << car.licensePlate
                << ", 到达时间: " << car.arrivalTime << endl;
        }
        cout << "  当前等待区有 " << waitingQueue.size() << " 辆车" << endl;
    }
};

// 简单的栈和队列基础操作示例
void basicExamples() {
    cout << "\n=== 栈和队列基础操作 ===" << endl;

    // 1. 栈的使用（后进先出 LIFO）
    cout << "\n1. 栈操作（后进先出）:" << endl;
    stack<int> myStack;

    // 压栈
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    cout << "   压入: 10, 20, 30" << endl;

    // 查看栈顶
    cout << "   栈顶元素: " << myStack.top() << endl;

    // 弹出
    cout << "   弹出: " << myStack.top() << endl;
    myStack.pop();
    cout << "   弹出后栈顶: " << myStack.top() << endl;

    // 栈大小
    cout << "   栈大小: " << myStack.size() << endl;

    // 2. 队列的使用（先进先出 FIFO）
    cout << "\n2. 队列操作（先进先出）:" << endl;
    queue<int> myQueue;

    // 入队
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    cout << "   入队: 10, 20, 30" << endl;

    // 查看队首和队尾
    cout << "   队首元素: " << myQueue.front() << endl;
    cout << "   队尾元素: " << myQueue.back() << endl;

    // 出队
    cout << "   出队: " << myQueue.front() << endl;
    myQueue.pop();
    cout << "   出队后队首: " << myQueue.front() << endl;

    // 队列大小
    cout << "   队列大小: " << myQueue.size() << endl;

    // 3. 用栈反转队列
    cout << "\n3. 用栈反转队列:" << endl;
    queue<int> q;
    for (int i = 1; i <= 5; i++) q.push(i);

    cout << "   原始队列: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    // 用栈反转
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    cout << "\n   反转后队列: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// 括号匹配检查（栈的经典应用）
bool checkParentheses(const string& expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main_456() {
    cout << "=== 栈和队列综合示例 ===\n" << endl;

    // 基础示例
    basicExamples();

    // 括号匹配检查
    cout << "\n=== 括号匹配检查（栈的应用） ===" << endl;
    vector<string> tests = {
        "(a+b)",
        "{[()]}",
        "([)]",
        "((())",
        ""
    };

    for (const string& test : tests) {
        bool valid = checkParentheses(test);
        cout << "表达式 \"" << test << "\" : "
            << (valid ? " 括号匹配" : " 括号不匹配") << endl;
    }

    // 停车场系统演示
    cout << "\n=== 停车场系统模拟（栈和队列结合） ===" << endl;
    ParkingLot parkingLot;

    // 初始状态
    parkingLot.displayStatus();

    // 车辆到达
    cout << "\n--- 车辆到达 ---" << endl;
    parkingLot.carArrives("京A12345", 900);   // 9:00
    parkingLot.carArrives("京B67890", 905);   // 9:05
    parkingLot.carArrives("沪C11223", 910);   // 9:10
    parkingLot.carArrives("粤D44556", 915);   // 9:15
    parkingLot.carArrives("川E77889", 920);   // 9:20
    parkingLot.carArrives("陕F33445", 925);   // 9:25（应该进入等待区）

    parkingLot.displayStatus();

    // 车辆离开
    cout << "\n--- 车辆离开 ---" << endl;
    parkingLot.carLeaves("京B67890", 930);    // 9:30离开

    parkingLot.displayStatus();

    // 更多操作
    cout << "\n--- 更多操作 ---" << endl;
    parkingLot.carArrives("津G66778", 935);   // 9:35
    parkingLot.carLeaves("沪C11223", 940);    // 9:40离开

    // 最终状态
    parkingLot.displayStatus();

    return 0;
}