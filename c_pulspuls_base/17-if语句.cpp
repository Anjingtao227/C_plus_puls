#include <iostream>
using namespace std;


void test1()
{
	int age = 17;
	if (age >= 18)
	{
		cout << "�ѳ��꣬��������" << endl;
	}
	else
	{
		cout << "δ���꣬�Ӻ����û�м�ص��Ž���������" << endl;
	}
}
	

	/*
		if(�������1)
		{
			�����1;
		}
		else if(�������2)
		{
			�����2;
		}....
		else if(�������n)
		{
			�����n;
		}
		else
		{
			else�����;
		}
	*/
// if��֧��䣬�������������һ����֧���������ͻ�ִ�е�ǰ��Ӧ�Ĵ��룬 �������жϾͲ���ִ���ˡ�
void test2()
{
	int age = 14;
	if (age <= 6)
	{
		cout << "��Ʊ" << endl;
	}
	else if (age > 6 && age <= 14)
	{
		cout << "��Ʊ" << endl;
	}
	else
	{
		cout << "ȫƱ" << endl;
	}
}

int main()
{
	test1();

	return 0;
}