#include <iostream>
using namespace std;
int main()
{
	// new �� delete
	// �����ռ�ķ�����ͷ�
	int* p1;
	p1 = new int(10);
	cout << *p1 << endl;
	delete p1;
	p1 = NULL;
	if (p1 == NULL)
	{
		cout << "p1�ǿ�ָ��" << endl;
	}
	else
	{
		cout << *p1 << endl;
	}

	// ����ռ�ķ�����ͷ�

	int* p2;
	int number = 10;
	// ����10��������int���Ϳռ䣬���׵�ַ��ֵ��p2
	p2 = new int[number];

	// Ϊÿ����Ԫ�����и�ֵ
	for (int i = 0; i < 10; i++)
	{
		*(p2 + i) = i + 10;
	}

	// ��ȡ�����ռ��е�ֵ
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << p2[i] << " ";
	//}

	for (int i = 0; i < 10; i++)
	{
		cout << *(p2 + i) << " ";
	}
	
	// �ͷ�p2ָ��Ķ���������ڴ�ռ�
	delete[] p2;
	p2 = NULL;
	cout << endl;
}