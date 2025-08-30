#include <iostream>
using namespace std;
int main()
{
	//// 1、指针的算术运算
	//int a, * p1, * p2;
	//double b, * p3, * p4;

	//p1 = &a;
	//p3 = &b;

	//cout << "p1 = " << p1 << "\tp3  = " << p3 << endl;
	//// p1是int类型的指针，+1相当于向后移动4个字节
	//p2 = p1 + 1;
	//// p3是double类型的指针，+1相当于向后移动8个字节
	//p4 = p3 + 1;
	//cout << "p2 = " << p2 << "\tp4  = " << p4 << endl;

	//// 指针减法
	////p1是int类型的指针，-1相当于向前移动4个字节
	//p2 = p1 - 1;
	//// p3是double类型的指针， - 1相当于向前移动8个字节
	//p4 = p3 - 1;
	//cout << "p2 = " << p2 << "\tp4  = " << p4 << endl;

	//// 指针加法运算时，增加的数字比较大
	//p2 = p1 + 4; // 向后移动16个字节
	//p4 = p3 + 4; // 向后移动32个字节
	//cout << "p2 = " << p2 << "\tp4  = " << p4 << endl;


	// 2、指针的关系运算
	
	int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int* p1, * p2;
	// 将第2个元素的地址赋值给p1
	p1 = &arr[1];
	// 将第4个元素的地址赋值给p2
	p2 = &arr[3];

	cout << *p1 << " " << *p2 << endl;

	cout << "p1 > p2 ? " << (p1 > p2) << endl; // 0
	cout << "p1 < p2 ? " << (p1 < p2) << endl; // 1
	cout << "p1 == p2 ? " << (p1 == p2) << endl; // 0
	cout << "p1 != p2 ? " << (p1 != p2) << endl; // 1

	int* p3 = NULL;
	if (p3 == NULL)
	{
		cout << p3 << endl; // 输出的结果是00000000
		cout << "p3是空指针" << endl;
	}
	else
	{
		cout << *p3 << endl;
	}
	return 0;
}