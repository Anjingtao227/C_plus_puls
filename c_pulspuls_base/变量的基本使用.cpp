#include <iostream>
using namespace std;
int main()
{
	// 变量在使用之前必须要完成初始化
	int number;
	number = 100;
	number = 200;
	cout << number << endl;

	// 相同类型的多个变量可以在一个语句中来进行定义，变量名之间用空格来隔开即可
	int number1 = 200, number2 = 300, number3 = 400;
	cout << "number1 = " << number1 << "," << "number2 = " << number2 << "," << "number3 = " << number3 << endl;

	// 数据类型可以是C++中任意类型，包括基本类型或者自定义类型
	// 浮点类型变量
	double number4 = 200.3;
	cout << "number4 = " << number4 << endl;
	// 自定义类型,C++本身自带的string字符串类型
	string str = "我是一个字符串";

	//// 同一个作用域中，不能出现名称相同的变量
	//int number = 1000;
	//cout << number << endl;

	// 变量初始化的其他方式
	int number5(1000);

	// C++ 11提供了统一的初始化方式
	int number6{ 10000 };
	return 0;
}