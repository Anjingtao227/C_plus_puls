#include <iostream>
using namespace std;
int main()
{
	int a = 100;
	// ��������b��Ϊa�ı�����ʹ��
	int& b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 1000;
	cout << "b = " << b << endl;
	cout << "a = " << a << endl;

	// ���õ�ע���
	// ���ñ���Ҫ��ʼ��
	int& c = a;
	// ��ʼ��֮�󲻿�����Ϊ��������������ʹ��
	int num = 10000;
	c = num; // �����Ǹ�ֵ����˼��������c��Ϊnum�ı���ʹ��

	// a  b  c�Ľ������10000���޸���c��ֵ�����޸���a��ֵ���޸���a��ֵ�����޸���b��ֵ
	// ��Ϊb��c����a�ı���
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	return 0;
}