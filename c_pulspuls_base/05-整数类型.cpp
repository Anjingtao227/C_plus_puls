#include <iostream>
using namespace std;
int main()
{
	// ������
	short s1 = 30000;
	// �޷��Ŷ�����
	unsigned short us1 = 40000;
	cout << "us1 = " << us1 << endl;
	// ���ͣ���׼���ͣ�
	int i1 = 1000;
	// �����ͣ�windows����ϵͳ�º�int�ķ�Χ��Сһ�£�
	long l1 = 2000;
	// ��������
	long long ll1 = 3000;
	cout << "s1 = " << s1 << "ռ�õ��ֽ�����" << sizeof(s1) << endl;
	cout << "i1 = " << i1 << "ռ�õ��ֽ�����" << sizeof(i1) << endl;
	cout << "l1 = " << l1 << "ռ�õ��ֽ�����" << sizeof(l1) << endl;
	cout << "ll1 = " << ll1 << "ռ�õ��ֽ�����" << sizeof(ll1) << endl;
	return 0;
}