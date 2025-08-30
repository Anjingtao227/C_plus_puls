#include <iostream>
using namespace std;
// 数组作为函数的参数
//void printArr(int arr[], int len)
void printArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
// 1、编写函数来实现数组的翻转，要在原数组上进行处理
// 比如传递之前的a[] = {10,20,30,40,50}, 调用完函数之后再对a进行遍历就是{50,40,30,20,10}
void myReverse1(int* arr, int len)
{
	int temp;
	// 方法1：
	//for (int i = 0; i < len / 2; i++)
	//{
	//	temp = arr[i];
	//	arr[i] = arr[len - 1 - i];
	//	arr[len - 1 - i] = temp;
	//}

	// 方法2：利用两个循环变量同时向数组中心遍历来处理
	int* i, * j;
	for (i = arr, j = arr + len - 1; i < j; i++, j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}

// 2、编写函数来实现数组的翻转，通过调用函数时的返回值来获取反转后的数组结果，翻转时不影响原数组的值
//int newArr[5]; // 将数组当成全局数组可以处理
int* myReverse2(int* arr, int len)
{
	// 使用动态内存分配来处理
	int* newArr = new int[len];
	int j = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		newArr[j] = arr[i];
		j++;
	}
	return newArr;
}

// 字符数组作为函数的参数
void printCharArr(char* p)
{
	cout << p << endl;
}

// 3、定义函数来实现两个字符串的拼接
void stringCat(char* str1, char* str2)
{
	char* p;
	// 让p指向第一个字符串的结束标识
	p = str1 + strlen(str1);
	while (*str2 != '\0')
	{
		// 将str2指向的值赋值给p指向的位置，每次赋值完成要进行指针后移
		*p = *str2;
		p++;
		str2++;
	}
}
int main()
{
	//int a[5] = { 10,20,30,40,50 };
	//printArr(a, 5);
	//int *p = myReverse2(a, 5);
	//printArr(p, 5);
	//delete[] p;

	char a[100] = "ABCDE";
	char b[100] = "fg12345";
	// 将字符数组a拼接到字符串数组b的后面
	stringCat(b, a);
	printCharArr(b);
	return 0;
}