#include <iostream>
using namespace std;
int main()
{
	// �����ļӼ��˳�
	int a = 10, b = 20;
	cout << a - b << endl; // -10
	cout << a + b << endl; // 30
	cout << a * b << endl; // 200
	cout << a / b << endl; // 0 ����������������
	cout << 10.0 / 20.0 << endl; // �������������Ǹ�����

	// ȡ�����
	cout << b % a << endl; // 0
	cout << a % b << endl;// 10
	
	// ֻ�ܶ���������ȡ�����
	// cout << 10.0 % b << endl;

	// ����ַ��������㣬�����ַ���Ӧ��ASCII��ֵ������
	char ch = 'A'; // A��Ӧ��ASCII��ֵ��65
	cout << ch + 1 << endl; // 66
	return 0;
}