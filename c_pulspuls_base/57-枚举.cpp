#include <iostream>
using namespace std;

// ö�ٶ���
enum weekday { Mon=1, Tue, Wed, Thu, Fri, Sat, Sun };
int main()
{
	int day = 2;
	switch (day)
	{
		case Mon:
			cout << "��������һ" << endl;
			break;
		case Tue:
			cout << "�������ܶ�" << endl;
			break;
		case Wed:
			cout << "����������" << endl;
			break;
		case Thu:
			cout << "����������" << endl;
			break;
		case Fri:
			cout << "����������" << endl;
			break;
		case Sat:
			cout << "����������" << endl;
			break;
		case Sun:
			cout << "����������" << endl;
			break;
		default:
			cout << "�������������" << endl;
	}
	return 0;
}