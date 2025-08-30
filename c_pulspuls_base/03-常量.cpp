#include <iostream>
#define PI 3.14
using namespace std;
int main()
{
	// 直接常量
	cout << "我是一个字符串" << endl;
	cout << 1000 << endl;

	// 符号常量
	// 使用宏定义： #define 宏名 值
	cout << PI << endl;
	// 使用const来进行定义：const 类型说明符 常量名 = 常量值;
	const int month = 12;
	// 定义好的常量值不能再被改变
	// month = 100;
	cout << "一年有" << month << "个月" << endl;
	return 0;
}