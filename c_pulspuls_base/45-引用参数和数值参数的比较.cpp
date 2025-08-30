#include <iostream>
using namespace std;
// 引用作为参数和数值作为参数的比较
// 引用作为函数的形参，实参只能是变量名,如果是数值作为函数参数，实参可以是变量、常量或者表达式

// 计算圆的面积
const double PI = 3.14;
double area1(double radius)
{
	return PI * radius * radius;
}

double area2(double& radius)
{
	return PI * radius * radius;
}
int main()
{
	double r = 10.0;
	// 值传递，实参可以是变量、常量、表达式
	cout << "area1(r) = " << area1(r) << endl;
	cout << "area1(100) = " << area1(100) << endl;
	cout << "area1(2*r) = " << area1(2*r) << endl;

	// 引用传递，实参只能是变量名
	cout << "area2(r) = " << area2(r) << endl;
	//cout << "area2(100) = " << area2(100) << endl;
	//cout << "area2(2*r) = " << area2(2 * r) << endl;
	return 0;
}