#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	// 如果代码看到了引用，会自动转化为int *const ref = &a
	// 所以引用不可以指向两个不同的地址
	int& ref = a;

	// 内部发现ref是引用，自动转化为*ref = 20;
	ref = 20;

	cout << "a = " << a << endl;
	cout << "ref = " << ref << endl;
	return 0;
}