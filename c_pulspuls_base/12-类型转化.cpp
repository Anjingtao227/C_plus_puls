#include <iostream>
using namespace std;
int main()
{
	// 隐式转换
	// int 和 double类型相加，结果是double类型
	int c = 10;
	double b = 20.22;
	cout << c + b << endl;

	// 强制类型转换
	// 求三角形的面积
	double s1, s2, s3, a, h;
	a = 3.0;
	h = 5.0;
	// 1/2是整数相除结果是整数，所以是0，s1的结果就是0
	s1 = 1 / 2 * a * h;
	cout << "s1 = " << s1 << endl;
	// 类型说明符(表达式)
	s2 = double(1) / 2 * a * h;
	cout << "s2 = " << s2 << endl;
	// (类型说明符)(表达式)
	s3 = 1 / (double)(2) * a * h;
	cout << "s3 = " << s3 << endl;
	return 0;
}