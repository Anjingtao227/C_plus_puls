#include <iostream>
using namespace std;
int main()
{
	
	//cout << (100 ? 200 : 300) << endl; // 200
	//cout << (0 ? 200 : 300) << endl; // 300

	// 让用户从控制台输入两个整数，输出较大值和较小值
	//int a, b;
	//cout << "请输入两个整数：" << endl;
	//cin >> a >> b;
	//int max = a > b ? a : b;
	//int min = a < b ? a : b;
	//cout << "max = " << max << endl;
	//cout << "min = " << min << endl;

	// 让用户输入三个不同的整数，输出最大值和最小值，一行表达式完成
	// 思路：先比较两个数的大小，然后再和第三个数进行比较
	int a = 10, b = 20, c = 30;
	// 方法1：
	int max = (a > b ? a : b) > c ? (a > b ? a : b) : c;
	// 方法2：
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);

	int min = (a < b ? a : b) < c ? (a < b ? a : b) : c;
	cout << max << " " << min << endl;
	return 0;
}