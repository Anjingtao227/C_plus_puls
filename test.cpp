#include<iostream>
using namespace std;

void test(int a)
{
	cout << "��4���޸�" << endl;
}

int main()
{
	float add(float x, float y);
	float a, b, c;
	cout << "���������������ÿո������" << endl;
	cin >> a >> b;
	c = add(a, b);
	cout << "����֮��Ϊ��" << c << endl;
	//��һ���޸�

	return 0;
}

float add(float x, float y)
{
	float z;
	z = x + y;
	return(z);
}