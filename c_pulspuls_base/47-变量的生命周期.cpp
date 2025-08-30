#include <iostream>
using namespace std;
//int i = 1;

void print()
{
	// 静态变量在程序运行到时候，只初始化一次，后续再调用函数，静态变量就不会再初始化了
	static int number = 1;
	number++;
	cout << number << endl;
}

// 利用静态变量来输出1~10的阶乘
int fact(int n)
{
	// f只初始化一次
	static int f = 1;
	// 每次乘法运算后f都保留计算的结果
	f = n * f;
	return f;
}
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << fact(i) << endl;
	}

	//for (int i = 0; i < 10; i++)
	//{
	//	print();
	//}
	
	//cout << "全局变量i = " << i << endl;
	//// 函数的局部变量
	//int i = 5;
	//{
	//	int i = 10;
	//	cout << "块局部变量i = " << i << endl;
	//	// 在局部中使用全局变量
	//	cout << "全局变量i = " << ::i << endl;
	//}

	//cout << "局部变量i = " << i << endl;
	//cout << "全局变量i = " << ::i << endl;
	return 0;
}