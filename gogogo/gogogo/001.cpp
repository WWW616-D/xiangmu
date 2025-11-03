#include<iostream>
using namespace std;
//这是一个宏常量
#define day 7
int main()
{
	/* char 是字符型 单引号 单个字符
	对应的ascll码被存入了存储单元，所以可以比大小
	*/
	/*A-65
	a-97
	*/
	char ch = 'a';

	/*以下是实型用于表示小数
	* float 单精度 4字节 7位有效数字
	* double 8字节 15 16 位有效数字
	* 小数默认6位有效数字
	*/
	float f1 = 34.14156987f;
	float f2 = 3e5f;//科学计数法

	//常量
	/*标识符可以有数字字母下划线
	但第一个只能是字母或者_
	*/
	/*short 短整型 (-32768~32767)2
	* int 整型4
	* long 长整型4
	* long long 长长整型8
	*/ 
	int a = 10;

	//转义字符
	//换行符 \n
	// 输出单斜杠\\
	//水平制表符\t:8格自填空对齐(大于8变16)
	 
	//这里是输出区
	cout << (int)ch << endl;
	cout << "char的占用内存空间为" << sizeof(char) << endl;
	cout << "int的占用内存空间为" << sizeof(int) << endl;
	cout << "一周有" << day << "天" << endl;
	cout << "a=" << a << endl;
	cout << ch << endl;
	cout << "f1=" << f1 << endl;
	cout << "f2=" << f2 << endl;
	cout << "hello\nworld" << endl;
	cout << "a\tnihaonihaonihao" << endl;
	system("pause");
	return 0;
}