#include <iostream>
using namespace std;

int addSum(int x, int y)
{
	return x + y;
}
int main()
{
	// ���庯��ָ�������溯���ĵ�ַ
	int(*fp)(int, int);

	// ��fp���溯���ĵ�ַ
	fp = addSum;
	
	cout << fp(10, 20) << endl;
	cout << fp(30, 20) << endl;
	return 0;
}