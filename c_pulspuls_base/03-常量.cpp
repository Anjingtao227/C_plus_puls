#include <iostream>
#define PI 3.14
using namespace std;
int main()
{
	// ֱ�ӳ���
	cout << "����һ���ַ���" << endl;
	cout << 1000 << endl;

	// ���ų���
	// ʹ�ú궨�壺 #define ���� ֵ
	cout << PI << endl;
	// ʹ��const�����ж��壺const ����˵���� ������ = ����ֵ;
	const int month = 12;
	// ����õĳ���ֵ�����ٱ��ı�
	// month = 100;
	cout << "һ����" << month << "����" << endl;
	return 0;
}