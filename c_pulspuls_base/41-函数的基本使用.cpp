#include <iostream>
using namespace std;
// 定义无返回值、无形参的函数
void print()
{
	cout << "无返回值无形参的函数调用" << endl;
}

// 无返回值，有形参的函数
void printSum(int a, int b)
{
	cout << a + b << endl;
}

// 有返回值，有形参的函数
int getSum(int a, int b)
{
	// 使用return 给出返回值
	return a + b;
}
int main()
{
	print();
	printSum(10,20);
	cout << getSum(100, 200) << endl;
	return 0;
}