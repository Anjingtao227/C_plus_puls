#include <iostream>
using namespace std;
int main()
{
	// 输入一个数字，判断是否是素数
	//int  num, i;
	//cin >> num;
	//for (i = 2; i < num; i++)
	//{
	//	if (num % i == 0)
	//	{
	//		break;
	//	}
	//}
	//if (i == num)
	//{
	//	cout << num << "是素数" << endl;
	//}
	//else
	//{
	//	cout << num << "是合数" << endl;
	//}


	int num, flag = 1; // num是来接收用户输入的数字，flag是标志位，如果是1代表是素数，否则是合数
	cin >> num;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			// 如果出现了能被整除的情况，就将flag置为0
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << num << "是素数" << endl;
	}
	else
	{
		cout << num << "是合数" << endl;
	}
	return 0;
}