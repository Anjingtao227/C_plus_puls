#include <iostream>
using namespace std;
// �����޷���ֵ�����βεĺ���
void print()
{
	cout << "�޷���ֵ���βεĺ�������" << endl;
}

// �޷���ֵ�����βεĺ���
void printSum(int a, int b)
{
	cout << a + b << endl;
}

// �з���ֵ�����βεĺ���
int getSum(int a, int b)
{
	// ʹ��return ��������ֵ
	return a + b;
}
int main()
{
	print();
	printSum(10,20);
	cout << getSum(100, 200) << endl;
	return 0;
}