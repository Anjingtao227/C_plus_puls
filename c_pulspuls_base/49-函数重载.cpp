#include <iostream>
using namespace std;

void print(int a)
{
	cout << a << endl;
}
// ���ܰ��շ���ֵ�����������ֺ���������
//int print(int a)
//{
//	cout << a << endl;
//	return a;
//}
void print(int a, double b)
{
	cout << a << endl;
	cout << b << endl;
}

void print(double a, double b)
{
	cout << a << endl;
	cout << b << endl;
}
void print(double a)
{
	cout << a << endl;
}

double getSum(double a, double b)
{
	cout << "����double���͵ĺ���" << endl;
	return a + b;
}

int getSum(int a, int b)
{
	cout << "����int���͵ĺ���" << endl;
	return a + b;
}

int getSum(int a, int b, int c)
{
	cout << "����int���͵ĺ���" << endl;
	return a + b+ c;
}
int main()
{

	cout << getSum(10, 20) << endl;
	cout << getSum(10.1, 20.22) << endl;
	cout << getSum(10,20,30) << endl;
	return 0;
}