#include <iostream>
using namespace std;
int main()
{
	// �Ƚ������
	int a = 10, b = 20;
	cout << "a > b ? " << (a > b) << endl; // 0
	cout << "a >= b ? " << (a >= b) << endl; // 0
	cout << "a < b ? " << (a < b) << endl; // 1
	cout << "a <= b ? " << (a <= b) << endl; // 1
	cout << "a == b ? " << (a == b) << endl; // 0
	cout << "a != b ? " << (a != b) << endl; // 1

	// �߼������
	int c = 30;
	// �߼���
	cout << "a < b && a > c ��" << (a < b && a > c) << endl; // 0
	cout << "a < b && a < c ��" << (a < b && a < c) << endl; // 1

	// �߼���
	cout << "a < b || a > c ��" << (a < b || a > c) << endl; // 1
	cout << "a > b || a > c ��" << (a > b || a > c) << endl; // 0

	// �߼��ǣ�ȡ����
	cout << "!(c > b) ? " << !(c > b) << endl; // 0

	// �߼���·
	int num1 = 0, num2 = 200;
	// num1 == 0 , �൱����false��ֱ�Ӿ����˱��ʽ�Ľ�������Բ�ȥ�������ı��ʽ
	num1 && (num2 = num2 + 300);
	cout << num2 << endl; // 200

	// num1 == 0�� �޷������������ʽ�Ľ��������Ҫ�������ı��ʽ
	num1 || (num2 = num2 + 300);
	cout << num2 << endl; // 500
	return 0;
}