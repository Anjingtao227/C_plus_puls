#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	// ������뿴�������ã����Զ�ת��Ϊint *const ref = &a
	// �������ò�����ָ��������ͬ�ĵ�ַ
	int& ref = a;

	// �ڲ�����ref�����ã��Զ�ת��Ϊ*ref = 20;
	ref = 20;

	cout << "a = " << a << endl;
	cout << "ref = " << ref << endl;
	return 0;
}