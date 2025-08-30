#include<iostream>
using namespace std;
// 定义函数，获取两个int类型数据中的最大值
int getMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

// 定义函数求x的n次方
int getPower(int x, int n)
{
	int a = 1;
	// n代表循环的次数，相当于就是x要乘自己n-1次
	for (int i = 0; i < n; i++)
	{
		a *= x;
	}
	return a;
}
int main()
{
	//cout << getMax(10, 20) << endl;
	cout << getPower(10, 4) << endl;

	// 作业：1、定义函数来实现打印n行的菱形图形，实参传递的是几行，就是打印几行菱形
	/*
	假设输入的n是7
		---
		    *
		   ***
		  *****
		*******
		  *****
		   ***
		    * 
			
		----
			*/
	return 0;
}