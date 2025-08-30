#include <iostream>
using namespace std;

void print(int a)
{
	cout << a << endl;
}
// 不能按照返回值的类型来区分函数的重载
//int print(int a)
//{
//	cout << a << endl;
//	return a;
//}
void print(int a, double b)
{
	cout << a << endl;
	cout << b << endl;
}

void print(double a, double b)
{
	cout << a << endl;
	cout << b << endl;
}
void print(double a)
{
	cout << a << endl;
}

double getSum(double a, double b)
{
	cout << "两个double类型的函数" << endl;
	return a + b;
}

int getSum(int a, int b)
{
	cout << "两个int类型的函数" << endl;
	return a + b;
}

int getSum(int a, int b, int c)
{
	cout << "三个int类型的函数" << endl;
	return a + b+ c;
}
int main()
{

	cout << getSum(10, 20) << endl;
	cout << getSum(10.1, 20.22) << endl;
	cout << getSum(10,20,30) << endl;
	return 0;
}