#include <iostream>
using namespace std;
int main()
{
	// ������ʹ��֮ǰ����Ҫ��ɳ�ʼ��
	int number;
	number = 100;
	number = 200;
	cout << number << endl;

	// ��ͬ���͵Ķ������������һ������������ж��壬������֮���ÿո�����������
	int number1 = 200, number2 = 300, number3 = 400;
	cout << "number1 = " << number1 << "," << "number2 = " << number2 << "," << "number3 = " << number3 << endl;

	// �������Ϳ�����C++���������ͣ������������ͻ����Զ�������
	// �������ͱ���
	double number4 = 200.3;
	cout << "number4 = " << number4 << endl;
	// �Զ�������,C++�����Դ���string�ַ�������
	string str = "����һ���ַ���";

	//// ͬһ���������У����ܳ���������ͬ�ı���
	//int number = 1000;
	//cout << number << endl;

	// ������ʼ����������ʽ
	int number5(1000);

	// C++ 11�ṩ��ͳһ�ĳ�ʼ����ʽ
	int number6{ 10000 };
	return 0;
}