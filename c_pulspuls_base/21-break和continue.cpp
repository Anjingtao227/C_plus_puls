#include <iostream>
using namespace std;
int main()
{
	for (int i = 1; i < 6; i++)
	{
		if (i == 3)
		{
			cout << "第" << i << "个苹果有虫子，丢掉" << endl;
			//break; // 打破整个循环
			continue; // 跳过本次循环，继续执行下一次循环
		}
		cout << "我正在吃第" << i << "个苹果" << endl;
	}


	// 判断一个数是不是素数（质数）
	// 只能被1和它本身整除的数就是质数

	// 判断水仙花数，100~999之间 153 =   1 + 125 + 27

	return 0;
}