#include <iostream>
using namespace std;
int main()
{
	/*
		switch(表达式)
		{
			case 常量1:
				执行语句1;
				break;
			case 常量2:
				执行语句2;
				break;
				....
			case 常量n:
				执行语句n;
				break;
			default:
				执行语句;
		}
	*/

	//int number = 3;
	//switch (number)
	//{
	//	case 1:
	//		cout << "周一" << endl;
	//		break;
	//	case 2:
	//		cout << "周二" << endl;
	//		break;
	//	case 3:
	//		cout << "周三" << endl;
	//		break;
	//	default:
	//		cout << "输入的内容有误" << endl;
	//	break;
	//}

	// 练习：判断用户的成绩属于哪个等级 [90~100]A [80,89]B  [70,79]C [60,69]D [0,59]不及格
	int score = 100;
	// 获取分数的十位数
	score /= 10;
	switch (score)
	{
		// 当结果为10的时候直接穿透到9执行代码即可
		case 10:
		case 9:
			cout << "A" << endl;
			break;
		case 8:
			cout << "B" << endl;
			break;
		case 7:
			cout << "C" << endl;
			break;
		case 6:
			cout << "D" << endl;
			break;
		default:
			cout << "不及格" << endl;
	}
	return 0;
}