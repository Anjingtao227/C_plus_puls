#include <iostream>
using namespace std;
int main()
{
	/*
		while(ѭ������)
		{
			ѭ����;
		}
	*/

	/*int number = 1;
	while (number <= 10)
	{
		cout << number << " ";
		number++;
	}
	cout << endl;*/


	////  �û��������룬����������123456������ʾ��¼�ɹ��������������������ݣ�����ʾ��¼ʧ�ܣ�����������
	//string passwd; // ���ַ������͵ı����������û����������
	//cout << "���������룺" << endl;
	//cin >> passwd;
	//while (passwd != "123456")
	//{
	//	cout << "��������������룺" << endl;
	//	cin >> passwd;
	//}
	//cout << "��½�ɹ�" << endl;

	//// ����ĳ�����Ľ׳� ��������������n�������1*2*3.....*n��ֵ
	//cout << "������һ��������" << endl;
	//int number;
	//cin >> number;
	//// i��1������number mul����ÿ�γ˷������Ľ��
	//int i = 1, mul = 1;
	//while (i <= number)
	//{
	//	mul *= i;
	//	i++;
	//}
	//cout << number << "�Ľ׳��ǣ�" << mul << endl;

	/*
		do
		{
			ѭ����;
		}while(ѭ������);
	*/
	/*int i = 11;
	do
	{
		cout << i << " ";
		i++;
	} while (i <= 10);*/

	//string passwd; // ���ַ������͵ı����������û����������
	//int flag = 1; // �趨����flag����ʶ�ǲ��ǵ�һ����������
	//do
	//{
	//	if (flag == 1) // ����ǵ�һ���������룬�ͽ�flag��Ϊ2�������ͻ�ִֻ��else���
	//	{
	//		cout << "���������룺" << endl;
	//		flag = 2;
	//	}
	//	else
	//	{
	//		cout << "�������룺" << endl;
	//	}
	//	cin >> passwd;
	//} while (passwd != "123456");

	//cout << "��½�ɹ�" << endl;

	// ����һ����0���������ж�����������ż��������0��ʱ���˳�ѭ��
	int num;
	do
	{
		cout << "�����������ж���ż��" << endl;
		cin >> num;
		if (num % 2 == 0)
		{
			cout << "ż��" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
	} while (num != 0);
	return 0;
}