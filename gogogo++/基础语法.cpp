//#include<iostream>
//#include<string>
//#include <vector>
////using namespace std;
//using std::cout;
//using std::endl;
//using std::cin;
//using std::string;
//using std::vector;
//struct Point {
//	int x, y;
//	// C++ struct可以有函数！
//	void print() {
//		cout << "(" << x << ", " << y << ")" << endl;
//	}
//};
//void swap_cpp(int& a, int& b) {
//	int temp = a;  // 直接使用，不用解引用，编译器自动解引用
//	a = b;
//	b = temp;
//}
//template<typename T>
//T max(T a, T b) {
//	return (a > b) ? a : b;
//}
//template<typename T,typename U>
//inline auto add(T a,U b)
//{
//	return a + b;
//}
//int main_354()
//{
//	//不太一样的输入输出
//	int num = 100;
//	int& AnotherNum = num;//不可更换绑定
//	//cin >> num;
//	cout << "hello world"<<endl<<num<<endl;
//	cout << endl;
//	cout << AnotherNum << endl;
//
//	//基本一致的循环(下面这个是新的)
//	int arr[] = { 1, 2, 3, 4, 5 };
//	for (int x : arr) 
//	{  
//		cout << x << " ";
//	}
//
//	//函数完全一样，但可以靠参数不同达到重命名
//	//可以设置默认参数  默认参数在最右边:void func(int a, int b = 5, int c = 10) {}
//
//	int a = 50;
//	int b = 100;
//	swap_cpp(a, b);
//	cout << a << b << endl;
//	cout << max(a, b)<< endl;
//	cout << add(a, b)<< endl;
//
//	//结构体里面可以有函数而且不用写struct哦
//	Point p1;
//	p1.x = 10;
//	p1.y = 20;
//	p1.print();
//
//	//动态分配belike
//	int* arr_cpp = new int[10] {};      // 动态数组 初始化为0
//	delete[] arr_cpp;                // 必须配对使用
//
//	int* single = new int(42);       // 单个对象  括号里面不写就是初始化为0
//	delete single;
//
//	//字符串
//	string s1 = "Hello";      // 拷贝初始化
//	string s2("World");       // 直接初始化
//	string s3(5, 'A');        // "AAAAA"
//	string str = s1;			// 拷贝构造
//	str += str;
//	//str.assign("ABCDEFGHIJKLMN", 5);  // 只取前5个字符
//	//str.assign(str, 2, 4); // 从2开始取4个字符
//	string str1 = str.substr(0, 5); //取字串
//	str.append(" World");      // 追加
//	str.insert(6, "Awesome "); // 插入  插入到某个位置前面哦 要插一部分就再加两个数（开始位置，数目）
//								//也可以插入多个相同字符，第二个变量是数字，第三个变量是复制对象
//	str.erase(5, 3);           // 删除
//	str.replace(6, 3, "CPP");  // 替换
//	auto pos1 = str.find("H"); // 查找第一次出现位置 (可以再加一个数字确定开始查找的位置)
//
//	//动态数组
//	
//	// 创建动态数组（推荐方式）
//	std::vector<int> vec;
//
//	// 添加元素（自动扩容）
//	for (int i = 0; i < 10; i++) {
//		vec.push_back(i * i);
//	}
//
//	// 访问元素
//	cout << "第一个元素: " << vec[0] << endl;
//	cout << "安全访问: " << vec.at(0) << endl;  // 带边界检查
//
//	// 自动知道大小
//	cout << "数组大小: " << vec.size() << endl;
//
//	// 多种初始化方式
//	std::vector<int> v1;                 // 空向量
//	std::vector<int> v2(5);              // 5个元素，默认值0
//	std::vector<int> v3(5, 10);          // 5个元素，每个都是10
//	std::vector<int> v4 = { 1, 2, 3, 4, 5 }; // 初始化列表
//	std::vector<int> v5(v4);             // 拷贝构造
//
//	// 指定容量（优化性能）
//	std::vector<int> v6;
//	v6.reserve(100);  // 预分配100个元素的内存
//
//	// 1. 添加元素
//	vec.push_back(4);       // 末尾添加
//	vec.push_back(5);
//
//	// 2. 删除元素
//	vec.pop_back();         // 删除最后一个
//	vec.erase(vec.begin() + 1);  // 删除第二个元素
//
//	// 3. 插入元素
//	vec.insert(vec.begin() + 1, 99);  // 在第二个位置插入99
//
//	// 4. 访问元素
//	int a = vec[0];         // 快速访问（不检查边界）
//	int b = vec.at(0);      // 安全访问（检查边界，越界抛异常）
//	int c = vec.front();    // 第一个元素
//	int d = vec.back();     // 最后一个元素
//
//	// 5. 大小和容量
//	cout << "大小: " << vec.size() << std::endl;
//	cout << "容量: " << vec.capacity() << std::endl;
//	cout << "是否空: " << vec.empty() << std::endl;
//
//	// 创建 3行 x 4列 的二维数组，全部初始化为0
//	vector<std::vector<int>> matrix(3, vector<int>(4));
//
//	// 赋值
//	matrix[0][0] = 1;
//	matrix[1][2] = 5;
//
//	// 打印
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 4; j++) {
//			std::cout << matrix[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//}
