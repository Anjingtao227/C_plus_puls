#include <iostream>
using namespace std;
int main()
{
	// 常量指针，指针指向的内存地址中的值是不可以改变的
	int a = 10, b = 20;
	// const 修饰的是int，所以p指向的内存中的值是不可以修改的
	const int* p = &a;
	
	// 不能通过常量指针来修改它保存的地址指向的内存中的值
	// *p = 30;
	// 可以修改p中保存的地址
	p = &b;
	cout << *p << endl;


	// 指针常量，指针常量的指向不可以修改，但是指向的内存中的值是可以修改的
	// const修饰的是指针p1，所以p1的指向是不可以修改的
	int* const p1 = &a;
	// 指针常量的指向不可以改变
	// p1 = &b;

	// 指向的值可以改变
	*p1 = 200;
	cout << *p1 << endl;

	// 指向和值都不想让其改变
	const int* const p2 = &a;
	//*p2 = 100;
	//p2 = &b;
	return 0;
}