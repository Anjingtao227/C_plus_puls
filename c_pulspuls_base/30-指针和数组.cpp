#include <iostream>
using namespace std;
int main()
{
	int arr[5] = { 10,20,30,40,50 };

	// arr数组名本身就是数组的首地址，所以可以直接赋值给一个指针变量
	// 使用指针变量来保存数组的地址
	int* p = arr;

	//cout << *p << endl; // 输出数组中的第一个元素的值  10
	//p++; // 将指针从第一个元素的地址移动到第二个元素的地址
	//cout << *p << endl; // 20

	cout << "-------------------" << endl;
	// 利用指针变量来遍历输出数组中的所有元素
	for (int i = 0; i < 5; i++)
	{
		/*cout << *p << " ";
		p++;*/
		//cout << *(p + i) << " ";
		// p和arr实际上是一样的，所以arr[i]可以 p[i]也可以
		//cout << p[i] << " ";
		cout << *p++ << endl;
	}
	cout << endl;
	return 0;
}