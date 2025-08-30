#include <iostream>
using namespace std;

// 枚举定义
enum weekday { Mon=1, Tue, Wed, Thu, Fri, Sat, Sun };
int main()
{
	int day = 2;
	switch (day)
	{
		case Mon:
			cout << "今天是周一" << endl;
			break;
		case Tue:
			cout << "今天是周二" << endl;
			break;
		case Wed:
			cout << "今天是周三" << endl;
			break;
		case Thu:
			cout << "今天是周四" << endl;
			break;
		case Fri:
			cout << "今天是周五" << endl;
			break;
		case Sat:
			cout << "今天是周六" << endl;
			break;
		case Sun:
			cout << "今天是周日" << endl;
			break;
		default:
			cout << "输入的数字有误" << endl;
	}
	return 0;
}