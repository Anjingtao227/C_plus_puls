#include <iostream>
using namespace std;

int addSum(int x, int y)
{
	return x + y;
}
int main()
{
	// 定义函数指针来保存函数的地址
	int(*fp)(int, int);

	// 让fp保存函数的地址
	fp = addSum;
	
	cout << fp(10, 20) << endl;
	cout << fp(30, 20) << endl;
	return 0;
}