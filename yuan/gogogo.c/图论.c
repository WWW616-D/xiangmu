#include<stdio.h>
#include<stdlib.h>

int main_6543()
{
	int map[100][100];
	for (int i=0;i<100;i++)
	{
		for (int j=0;j<100;j++)
		{
			map[i][j] = 0;
		}
	}
	//若存在边则设置对应位置为1
	//当边稀疏的时候，可以考虑制作一个链表数组，每个链表存储对应节点的所有邻居
}
//拓扑排序判断有无环的应用kahn算法（bfs加邻接表）队列可以避免无效的扫描
//typedef struct {
//    int* items;      // 队列数组
//    int front;       // 队首索引
//    int rear;        // 队尾索引
//    int capacity;    // 队列容量
//} Queue;
//
//// 创建队列
//Queue* createQueue(int capacity) {
//    Queue* q = (Queue*)malloc(sizeof(Queue));
//    q->items = (int*)malloc(capacity * sizeof(int));
//    q->front = 0;
//    q->rear = -1;
//    q->capacity = capacity;
//    return q;
//}
//
//// 判断队列是否为空
//bool isEmpty(Queue* q) {
//    return q->front > q->rear;
//}
//
//// 入队
//void enqueue(Queue* q, int item) {
//    if (q->rear < q->capacity - 1) {
//        q->items[++(q->rear)] = item;
//    }
//}
//
//// 出队
//int dequeue(Queue* q) {
//    if (isEmpty(q)) {
//        return -1;
//    }
//    return q->items[(q->front)++];
//}
//
//// 释放队列
//void freeQueue(Queue* q) {
//    free(q->items);
//    free(q);
//}
//
//bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
//    // 1. 创建邻接表（链表实现）
//    typedef struct Node {
//        int vertex;
//        struct Node* next;
//    } Node;
//
//    // 创建邻接表和入度数组
//    Node** graph = (Node**)malloc(numCourses * sizeof(Node*));
//    int* indegree = (int*)calloc(numCourses, sizeof(int));
//
//    // 初始化邻接表
//    for (int i = 0; i < numCourses; i++) {
//        graph[i] = NULL;
//    }
//
//    // 2. 构建图并计算入度
//    // prerequisites[i][0] 依赖于 prerequisites[i][1]
//    // 所以边是：prerequisites[i][1] → prerequisites[i][0]
//    for (int i = 0; i < prerequisitesSize; i++) {
//        int course = prerequisites[i][0];      // 课程
//        int pre = prerequisites[i][1];         // 先修课
//
//        // 添加边 pre → course 到邻接表
//        Node* newNode = (Node*)malloc(sizeof(Node));
//        newNode->vertex = course;
//        newNode->next = graph[pre];
//        graph[pre] = newNode;
//
//        // course的入度+1
//        indegree[course]++;
//    }
//
//    // 3. 创建队列，将所有入度为0的课程入队
//    Queue* queue = createQueue(numCourses);
//
//    for (int i = 0; i < numCourses; i++) {
//        if (indegree[i] == 0) {
//            enqueue(queue, i);
//        }
//    }
//
//    // 4. Kahn算法核心：处理队列
//    int count = 0;  // 已完成的课程数
//
//    while (!isEmpty(queue)) {
//        int current = dequeue(queue);
//        count++;  // 完成一门课程
//
//        // 遍历当前课程的所有后续课程
//        Node* temp = graph[current];
//        while (temp != NULL) {
//            int nextCourse = temp->vertex;
//            indegree[nextCourse]--;  // 减少后续课程的入度
//
//            // 如果入度变为0，加入队列
//            if (indegree[nextCourse] == 0) {
//                enqueue(queue, nextCourse);
//            }
//
//            temp = temp->next;
//        }
//    }
//
//    // 5. 清理内存
//    // 释放邻接表
//    for (int i = 0; i < numCourses; i++) {
//        Node* temp = graph[i];
//        while (temp != NULL) {
//            Node* toFree = temp;
//            temp = temp->next;
//            free(toFree);
//        }
//    }
//    free(graph);
//    free(indegree);
//    freeQueue(queue);
//
//    // 6. 判断是否能完成所有课程
//    return count == numCourses;
//}
// DFS拓扑排序（并判断是否为环）(建议添加入度数组配合使用)
//int* topologicalSortDFS(int numCourses, int** prerequisites, int prerequisitesSize, int* returnSize) {
//    // ... 构建图
//
//    int* result = (int*)malloc(numCourses * sizeof(int));
//    int* stack = (int*)malloc(numCourses * sizeof(int));
//    int top = -1;  // 栈顶指针
//    int* visited = (int*)calloc(numCourses, sizeof(int));
//    bool hasCycle = false;
//
//    // DFS函数
//    void dfs(int u) {
//        visited[u] = 1;  // 1表示访问中
//
//        Node* temp = graph[u];
//        while (temp != NULL) {
//            int v = temp->vertex;
//
//            if (visited[v] == 1) {
//                hasCycle = true;
//                return;
//            }
//
//            if (visited[v] == 0) {
//                dfs(v);
//            }
//
//            temp = temp->next;
//        }
//
//        visited[u] = 2;  // 2表示已访问完成
//
//        // 关键：顶点u的所有后继都访问完成后，将u入栈
//        stack[++top] = u;
//    }
//
//    // 对每个未访问的顶点进行DFS
//    for (int i = 0; i < numCourses; i++) {
//        if (visited[i] == 0) {
//            dfs(i);
//            if (hasCycle) {
//                free(result);
//                free(stack);
//                free(visited);
//                *returnSize = 0;
//                return NULL;
//            }
//        }
//    }
//
//    // 关键：栈中元素出栈顺序就是拓扑排序结果
//    // 栈顶是最后一个完成的顶点，应该在排序的最后
//    for (int i = 0; i < numCourses; i++) {
//        result[i] = stack[top--];  // 出栈，顺序反转
//    }
//
//    *returnSize = numCourses;
//
//    // 清理内存...
//    return result;
//}