#include <iostream>
using namespace std;

// ���庯������������������ֵ
// ֵ���ݣ�����ı�ʵ�ε�ֵ����Ϊʵ�κ��β����ڴ���ռ�ò�ͬ�Ĵ洢��Ԫ
void swap1(int x, int y)
{
	cout << "����֮ǰ��ֵ��" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
	int temp = x;
	x = y;
	y = temp;
	cout << "����֮���ֵ��" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
}

// ָ����Ϊ�����Ĳ���
// ��Ϊx��ȡ����a�ĵ�ַ��y��ȡ����b�ĵ�ַ�����Զ�x��y�Ĳ���ʵ���Ͼ��Ƕ�a��b�Ĳ���
// ָ����Ϊ�����Ĳ�������ı�ʵ�ε�ֵ
void swap2(int* x, int* y)
{
	cout << "����֮ǰ��ֵ��" << endl;
	cout << "x = " << *x << "\ty = " << *y << endl;
	int temp = *x;
	*x = *y;
	*y = temp;
	cout << "����֮���ֵ��" << endl;
	cout << "x = " << *x << "\ty = " << *y << endl;
}

// ������Ϊ�����Ĳ���
// ��ֱ�Ӹı�ʵ�ε�ֵ����Ϊ���þ���һ�ֱ�������
void swap3(int& x, int& y)
{
	cout << "����֮ǰ��ֵ��" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
	int temp = x;
	x = y;
	y = temp;
	cout << "����֮���ֵ��" << endl;
	cout << "x = " << x << "\ty = " << y << endl;
}
int main()
{
	int a = 10, b = 20;
	//swap1(a, b);
	//swap2(&a, &b);
	swap3(a,b);
	cout << "a = " << a << "\tb = " << b << endl;
	return 0;
}