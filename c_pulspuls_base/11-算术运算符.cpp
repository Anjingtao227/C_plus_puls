#include <iostream>
using namespace std;
int main()
{
	// 整数的加减乘除
	int a = 10, b = 20;
	cout << a - b << endl; // -10
	cout << a + b << endl; // 30
	cout << a * b << endl; // 200
	cout << a / b << endl; // 0 整数相除结果是整数
	cout << 10.0 / 20.0 << endl; // 浮点型相除结果是浮点型

	// 取余操作
	cout << b % a << endl; // 0
	cout << a % b << endl;// 10
	
	// 只能对整数进行取余操作
	// cout << 10.0 % b << endl;

	// 如果字符参与运算，会用字符对应的ASCII码值来计算
	char ch = 'A'; // A对应的ASCII码值是65
	cout << ch + 1 << endl; // 66
	return 0;
}