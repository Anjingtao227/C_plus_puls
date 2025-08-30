#include <iostream>
using namespace std;
int main()
{
	// 一维数组的定义方式
	// 数据类型 数组名[数组长度];
	int arr[5];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	// 数据类型 数组名[数组长度,] = { 值1,值2.... };
	int arr1[5] = { 100,200,300,400,500 };

	// 数据类型 数组名[] = { 值1,值2.... };
	int arr2[] = { 1000,2000,3000,4000,5000,6000 };

	//// 整个数组占用的空间大小
	//cout << sizeof(arr2) << endl;
	//// 单个元素占用的空间大小
	//cout << sizeof(arr2[0]) << endl;
	//// 计算数组的元素个数
	//cout << sizeof(arr2) / sizeof(arr2[0]) << endl;
	/*for (int i = 0; i <= 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;*/

	// 输入4个学生的成绩，用数组来存储4个成绩，计算它们的平均成绩
	int score[4];
	// sum来保总成绩，avg来保存平均成绩
	double avg, sum = 0;
	for (int i = 0; i < 4; i++)
	{
		cout << "正在输入第" << i + 1 << "个学生的成绩：" << endl;
		cin >> score[i];
		sum += score[i];
	}
	avg = sum / 4;
	cout << "平均成绩是：" << avg << endl;
 	return 0;
}