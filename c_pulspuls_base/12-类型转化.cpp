#include <iostream>
using namespace std;
int main()
{
	// ��ʽת��
	// int �� double������ӣ������double����
	int c = 10;
	double b = 20.22;
	cout << c + b << endl;

	// ǿ������ת��
	// �������ε����
	double s1, s2, s3, a, h;
	a = 3.0;
	h = 5.0;
	// 1/2��������������������������0��s1�Ľ������0
	s1 = 1 / 2 * a * h;
	cout << "s1 = " << s1 << endl;
	// ����˵����(���ʽ)
	s2 = double(1) / 2 * a * h;
	cout << "s2 = " << s2 << endl;
	// (����˵����)(���ʽ)
	s3 = 1 / (double)(2) * a * h;
	cout << "s3 = " << s3 << endl;
	return 0;
}