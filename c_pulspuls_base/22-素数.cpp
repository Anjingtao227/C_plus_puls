#include <iostream>
using namespace std;
int main()
{
	// ����һ�����֣��ж��Ƿ�������
	//int  num, i;
	//cin >> num;
	//for (i = 2; i < num; i++)
	//{
	//	if (num % i == 0)
	//	{
	//		break;
	//	}
	//}
	//if (i == num)
	//{
	//	cout << num << "������" << endl;
	//}
	//else
	//{
	//	cout << num << "�Ǻ���" << endl;
	//}


	int num, flag = 1; // num���������û���������֣�flag�Ǳ�־λ�������1�����������������Ǻ���
	cin >> num;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			// ����������ܱ�������������ͽ�flag��Ϊ0
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << num << "������" << endl;
	}
	else
	{
		cout << num << "�Ǻ���" << endl;
	}
	return 0;
}