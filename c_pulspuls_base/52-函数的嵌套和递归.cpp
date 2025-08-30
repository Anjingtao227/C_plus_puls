#include <iostream>
using namespace std;
// 函数的嵌套调用
void func1()
{
	cout << "func1函数调用" << endl;
}

void func2()
{
	func1();
	cout << "func2函数调用" << endl;
}

// 定义两个函数来实现计算阶乘的和：1！+2！+3！......+n！
// 第一个函数实现阶乘的计算
int f1(int m)
{
	int s = 1;
	for (int i = 1; i <= m; i++)
	{
		s *= i;			//就是把变量 s 的当前值乘以 i，然后把结果再存回 s;s=s*i
	}
	return s;
}
// 第二个函数实现对阶乘和的计算
int f2(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += f1(i);
	}
	return sum;
}

// 函数的递归调用
// 定义函数来计算n的阶乘
int power(int n)
{
	int f;
	if (n > 1)
	{
		f = n * power(n - 1);
	}
	else
	{
		f = 1;
	}
	return f; // 返回的是n的阶乘
}

/*
power(4)
4 * power(3)
4 * (3 * power(2))
4 * (3 * (2 * power(1)))
4 * (3 * (2 * 1))
4 * (3 * 2)
4 * 6
24
*/
int main()
{
	/*cout << f2(3) << endl;*/
	cout << power(4) << endl;
	return 0;
}