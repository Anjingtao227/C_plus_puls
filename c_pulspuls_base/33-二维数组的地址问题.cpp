#include <iostream>
using namespace std;
int main()
{

	int arr[3][4] =
	{
		{10,20,30,40},
		{20,30,40,50},
		{30,40,50,60}
	};

	// arr 、arr[0]、&arr[0][0]都是第一行的首地址
	cout << arr << " " << arr[0] << " " << &arr[0][0] << endl;
	// arr+1、arr[1]、&arr[1][0]
	cout << arr+1 << " " << arr[1] << " " << &arr[1][0] << endl;
	// arr+2、arr[2]、&arr[2][0]
	cout << arr + 2 << " " << arr[2] << " " << &arr[2][0] << endl;

	// 使用arr获取第二行的第三个元素
	cout << *(*(arr + 1) + 2) << endl;
	cout << *(arr[1] + 2) << endl;


	// 作业：用二维数组名，直接遍历二维数组中的所有元素
	return 0;
}