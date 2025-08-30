#include <iostream>
using namespace std;
int main()
{
	int a, * p1, ** p2;
	double b, * p3, ** p4;

	a = 10;
	b = 20.22;

	p1 = &a; // p1保存a的地址，是一个一级指针
	p3 = &b;

	p2 = &p1; // p2是二级指针，保存的是p1的地址
	p4 = &p3;

	cout << a << " " << *p1 << " "	<< **p2 << endl;
	cout << b << " " << *p3 << " " << **p4 << endl;

	// 因为 p2 &a 和 p1 的地址都一样，所以修改p2指向的内存空间的值，其他的两个都会受影响
	**p2 = 200;
	**p4 = 10.21;

	cout << a << " " << *p1 << " " << **p2 << endl;
	cout << b << " " << *p3 << " " << **p4 << endl;

	// 定义一个三级指针
	int*** p5 = &p2;
	cout << ***p5 << endl;
	return 0;
}