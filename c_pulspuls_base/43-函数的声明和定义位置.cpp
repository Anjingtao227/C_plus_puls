#include <iostream>
using namespace std;
// 函数声明
// 在函数使用之前必须要先进行声明，定义可以放在调用的后面
void print(int number);
int main()
{
	print(100);
	return 0;
}

void print(int number)
{
	cout << number << endl;
}