#include <iostream>
using namespace std;
int main()
{
	int arr[5] = { 10,20,30,40,50 };
	int* p = arr; 
	p++; // p指向数组的第一个元素，所以p++就是移动到第二个元素的地址上
	cout << *p << endl;

	// 定义数组指针，指向整个数组
	// 虽然arr 和 &arr的地址是一样的，但是含义不同，arr是数组的首地址，&arr是整个数组的地址
	int(*p1)[5] = &arr;
	//cout << p1 << endl;
	//p1++; // 因为p1是指向整个数组的，所以p1++是移动了整个数组空间长度
	//cout << p1 << endl;

	// 利用数组指针来遍历数组中的元素
	for (int i = 0; i < 5; i++)
	{
		/*cout << (*p1)[i] << " ";*/
		cout << *(*p1 + i) << " ";
	}
	cout << endl;
	// 利用数组指针来遍历二维数组的元素
	int arr1[2][3] = { 10,20,30,40,50,60 };
	int(*p2)[2][3];
	// 用数组指针来存放二维数组的地址
	p2 = &arr1;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//cout << (*p2)[i][j] << " ";
			// *p2 就是 arr1, 所以 *((*p2) + i) 就是每行的首地址 *((*p2) + i) + j 就是每行的每一个元素的地址 
			// *(*((*p2) + i) + j) 就是二维数组中的每一个值
			cout << *(*((*p2) + i) + j) << " ";
		}
		cout << endl;
	}


	return 0;
}