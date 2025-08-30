#include <iostream>
using namespace std;

// 定义函数来交换两个变量的值
// 值传递，不会改变实参的值，因为实参和形参在内存中占用不同的存储单元
void swap1(int x, int y)
{
	cout << "交换之前的值：" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
	int temp = x;
	x = y;
	y = temp;
	cout << "交换之后的值：" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
}

// 指针作为函数的参数
// 因为x获取的是a的地址，y获取的是b的地址，所以对x和y的操作实际上就是对a和b的操作
// 指针作为函数的参数，会改变实参的值
void swap2(int* x, int* y)
{
	cout << "交换之前的值：" << endl;
	cout << "x = " << *x << "\ty = " << *y << endl;
	int temp = *x;
	*x = *y;
	*y = temp;
	cout << "交换之后的值：" << endl;
	cout << "x = " << *x << "\ty = " << *y << endl;
}

// 引用作为函数的参数
// 会直接改变实参的值，因为引用就是一种别名机制
void swap3(int& x, int& y)
{
	cout << "交换之前的值：" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
	int temp = x;
	x = y;
	y = temp;
	cout << "交换之后的值：" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
}
int main()
{
	int a = 10, b = 20;
	//swap1(a, b);
	//swap2(&a, &b);
	swap3(a,b);
	cout << "a = " << a << "\tb = " << b << endl;
	return 0;
}