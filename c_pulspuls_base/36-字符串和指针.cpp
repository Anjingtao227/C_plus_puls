#include <iostream>
using namespace std;
int number = 10;
int main()
{
	char ch1[] = "hello world";
	// �����ַ����͵�ָ��
	char* p;
	p = ch1;

	cout << "p = " << p << endl; // hello world
	cout << "*p = " << *p << endl; // h
	p++;
	cout << "*p = " << *p << endl; // h


	// ָ���ַ���������ʱ�򣬱��뽫ָ�붨��Ϊ����ָ�룬��Ϊֵ�����Ըı�
	const char * p1 = "Hello C++";
	cout << p1 << endl;

	// �����ַ�ָ���������ַ����е�����
	char d[] = "abcdef";
	char* p2;
	for (p2 = d; *p2 != '\0'; p2++)
	{
		cout << *p2 << " ";
	}
	cout << endl;

	// ����p3������ַ����ĳ���
	const char* p3 = "hello";
	int len = 0;
	for (; *p3 != '\0'; p3++)
	{
		len++;
	}
	cout << len << endl;
	return 0;
}