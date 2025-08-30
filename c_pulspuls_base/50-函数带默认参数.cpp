#include <iostream>
using namespace std;

// 如果形参有默认值，实参如果传递了参数，就使用传递的，如果没传递，就用默认的
// 默认形参的顺序必须是从右向左来定义的，如果某个形参有默认值，那么它右侧的所有的形参都得有默认值
// 函数一般我们会在声明的时候定义默认参数，在函数的定义的时候就不再写默认值
int getMax(int a, int b = 100, int c = 50);
int main()
{
	cout << getMax(10, 20, 80) << endl;
	return 0;
}
int getMax(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

// 作业：定义函数，任意输入一个范围，比如100~200，可以在其范围中过滤出来回文素数，将遍历出来的回文素数存放到一个数组中进行返回。