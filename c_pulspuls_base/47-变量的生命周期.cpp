#include <iostream>
using namespace std;
//int i = 1;

void print()
{
	// ��̬�����ڳ������е�ʱ��ֻ��ʼ��һ�Σ������ٵ��ú�������̬�����Ͳ����ٳ�ʼ����
	static int number = 1;
	number++;
	cout << number << endl;
}

// ���þ�̬���������1~10�Ľ׳�
int fact(int n)
{
	// fֻ��ʼ��һ��
	static int f = 1;
	// ÿ�γ˷������f����������Ľ��
	f = n * f;
	return f;
}
int main()
{
	for (int i = 1; i <= 10; i++)
	{
		cout << fact(i) << endl;
	}

	//for (int i = 0; i < 10; i++)
	//{
	//	print();
	//}
	
	//cout << "ȫ�ֱ���i = " << i << endl;
	//// �����ľֲ�����
	//int i = 5;
	//{
	//	int i = 10;
	//	cout << "��ֲ�����i = " << i << endl;
	//	// �ھֲ���ʹ��ȫ�ֱ���
	//	cout << "ȫ�ֱ���i = " << ::i << endl;
	//}

	//cout << "�ֲ�����i = " << i << endl;
	//cout << "ȫ�ֱ���i = " << ::i << endl;
	return 0;
}