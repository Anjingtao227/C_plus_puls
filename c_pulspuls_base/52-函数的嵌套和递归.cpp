#include <iostream>
using namespace std;
// ������Ƕ�׵���
void func1()
{
	cout << "func1��������" << endl;
}

void func2()
{
	func1();
	cout << "func2��������" << endl;
}

// ��������������ʵ�ּ���׳˵ĺͣ�1��+2��+3��......+n��
// ��һ������ʵ�ֽ׳˵ļ���
int f1(int m)
{
	int s = 1;
	for (int i = 1; i <= m; i++)
	{
		s *= i;			//���ǰѱ��� s �ĵ�ǰֵ���� i��Ȼ��ѽ���ٴ�� s;s=s*i
	}
	return s;
}
// �ڶ�������ʵ�ֶԽ׳˺͵ļ���
int f2(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += f1(i);
	}
	return sum;
}

// �����ĵݹ����
// ���庯��������n�Ľ׳�
int power(int n)
{
	int f;
	if (n > 1)
	{
		f = n * power(n - 1);
	}
	else
	{
		f = 1;
	}
	return f; // ���ص���n�Ľ׳�
}

/*
power(4)
4 * power(3)
4 * (3 * power(2))
4 * (3 * (2 * power(1)))
4 * (3 * (2 * 1))
4 * (3 * 2)
4 * 6
24
*/
int main()
{
	/*cout << f2(3) << endl;*/
	cout << power(4) << endl;
	return 0;
}