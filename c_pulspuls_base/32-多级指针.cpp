#include <iostream>
using namespace std;
int main()
{
	int a, * p1, ** p2;
	double b, * p3, ** p4;

	a = 10;
	b = 20.22;

	p1 = &a; // p1����a�ĵ�ַ����һ��һ��ָ��
	p3 = &b;

	p2 = &p1; // p2�Ƕ���ָ�룬�������p1�ĵ�ַ
	p4 = &p3;

	cout << a << " " << *p1 << " "	<< **p2 << endl;
	cout << b << " " << *p3 << " " << **p4 << endl;

	// ��Ϊ p2 &a �� p1 �ĵ�ַ��һ���������޸�p2ָ����ڴ�ռ��ֵ������������������Ӱ��
	**p2 = 200;
	**p4 = 10.21;

	cout << a << " " << *p1 << " " << **p2 << endl;
	cout << b << " " << *p3 << " " << **p4 << endl;

	// ����һ������ָ��
	int*** p5 = &p2;
	cout << ***p5 << endl;
	return 0;
}