#include <iostream>
using namespace std;
int main()
{
	/*
		while(循环条件)
		{
			循环体;
		}
	*/

	/*int number = 1;
	while (number <= 10)
	{
		cout << number << " ";
		number++;
	}
	cout << endl;*/


	////  用户输入密码，如果输入的是123456，就显示登录成功，如果输入的是其他内容，就显示登录失败，请重新输入
	//string passwd; // 用字符串类型的变量来接收用户输入的内容
	//cout << "请输入密码：" << endl;
	//cin >> passwd;
	//while (passwd != "123456")
	//{
	//	cout << "密码错误，重新输入：" << endl;
	//	cin >> passwd;
	//}
	//cout << "登陆成功" << endl;

	//// 计算某个数的阶乘 比如输入了数字n，则计算1*2*3.....*n的值
	//cout << "请输入一个整数：" << endl;
	//int number;
	//cin >> number;
	//// i从1遍历到number mul保存每次乘法运算后的结果
	//int i = 1, mul = 1;
	//while (i <= number)
	//{
	//	mul *= i;
	//	i++;
	//}
	//cout << number << "的阶乘是：" << mul << endl;

	/*
		do
		{
			循环体;
		}while(循环条件);
	*/
	/*int i = 11;
	do
	{
		cout << i << " ";
		i++;
	} while (i <= 10);*/

	//string passwd; // 用字符串类型的变量来接收用户输入的内容
	//int flag = 1; // 设定变量flag来标识是不是第一次输入密码
	//do
	//{
	//	if (flag == 1) // 如果是第一次输入密码，就将flag置为2，后续就会只执行else语句
	//	{
	//		cout << "请输入密码：" << endl;
	//		flag = 2;
	//	}
	//	else
	//	{
	//		cout << "重新输入：" << endl;
	//	}
	//	cin >> passwd;
	//} while (passwd != "123456");

	//cout << "登陆成功" << endl;

	// 输入一个非0的整数，判断是奇数还是偶数，输入0的时候退出循环
	int num;
	do
	{
		cout << "输入数字来判断奇偶：" << endl;
		cin >> num;
		if (num % 2 == 0)
		{
			cout << "偶数" << endl;
		}
		else
		{
			cout << "奇数" << endl;
		}
	} while (num != 0);
	return 0;
}