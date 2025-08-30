#include <iostream>
using namespace std;
int main()
{
	// new 和 delete
	// 单个空间的分配和释放
	int* p1;
	p1 = new int(10);
	cout << *p1 << endl;
	delete p1;
	p1 = NULL;
	if (p1 == NULL)
	{
		cout << "p1是空指针" << endl;
	}
	else
	{
		cout << *p1 << endl;
	}

	// 多个空间的分配和释放

	int* p2;
	int number = 10;
	// 分配10个连续的int类型空间，将首地址赋值给p2
	p2 = new int[number];

	// 为每个单元来进行赋值
	for (int i = 0; i < 10; i++)
	{
		*(p2 + i) = i + 10;
	}

	// 获取连续空间中的值
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << p2[i] << " ";
	//}

	for (int i = 0; i < 10; i++)
	{
		cout << *(p2 + i) << " ";
	}
	
	// 释放p2指向的多个连续的内存空间
	delete[] p2;
	p2 = NULL;
	cout << endl;
}