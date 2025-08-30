#include <iostream>
using namespace std;
int number = 10;
int main()
{
	char ch1[] = "hello world";
	// 定义字符类型的指针
	char* p;
	p = ch1;

	cout << "p = " << p << endl; // hello world
	cout << "*p = " << *p << endl; // h
	p++;
	cout << "*p = " << *p << endl; // h


	// 指向字符串常量的时候，必须将指针定义为常量指针，因为值不可以改变
	const char * p1 = "Hello C++";
	cout << p1 << endl;

	// 利用字符指针来遍历字符串中的内容
	char d[] = "abcdef";
	char* p2;
	for (p2 = d; *p2 != '\0'; p2++)
	{
		cout << *p2 << " ";
	}
	cout << endl;

	// 计算p3保存的字符串的长度
	const char* p3 = "hello";
	int len = 0;
	for (; *p3 != '\0'; p3++)
	{
		len++;
	}
	cout << len << endl;
	return 0;
}