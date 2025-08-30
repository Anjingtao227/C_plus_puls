#include <iostream>
using namespace std;
int main()
{
	// 比较运算符
	int a = 10, b = 20;
	cout << "a > b ? " << (a > b) << endl; // 0
	cout << "a >= b ? " << (a >= b) << endl; // 0
	cout << "a < b ? " << (a < b) << endl; // 1
	cout << "a <= b ? " << (a <= b) << endl; // 1
	cout << "a == b ? " << (a == b) << endl; // 0
	cout << "a != b ? " << (a != b) << endl; // 1

	// 逻辑运算符
	int c = 30;
	// 逻辑与
	cout << "a < b && a > c ？" << (a < b && a > c) << endl; // 0
	cout << "a < b && a < c ？" << (a < b && a < c) << endl; // 1

	// 逻辑或
	cout << "a < b || a > c ？" << (a < b || a > c) << endl; // 1
	cout << "a > b || a > c ？" << (a > b || a > c) << endl; // 0

	// 逻辑非（取反）
	cout << "!(c > b) ? " << !(c > b) << endl; // 0

	// 逻辑短路
	int num1 = 0, num2 = 200;
	// num1 == 0 , 相当于是false，直接决定了表达式的结果，所以不去计算后面的表达式
	num1 && (num2 = num2 + 300);
	cout << num2 << endl; // 200

	// num1 == 0， 无法决定整个表达式的结果，所以要计算后面的表达式
	num1 || (num2 = num2 + 300);
	cout << num2 << endl; // 500
	return 0;
}