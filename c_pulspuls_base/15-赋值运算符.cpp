#include <iostream>
using namespace std;
int main()
{
	// a += 1 �൱�� a = a + 1  
	// a*=1  �൱�� a  = a * 1
	
	// �򵥸�ֵ
	int a = 10;
	a += 20;
	// a = a + 20
	cout << a << endl; // 30
	a -= 5;
	cout << a << endl; // 25
	a %= 4; // a = a % 4
	cout << a << endl; // 1

	// ���ϸ�ֵ
	int b = 20;
	// b += 5 * 20 - 40; // b = b + (5 * 20 - 40)
	b *= 5 * 20 - 40; // b = b * (5 * 20 - 40)
	cout << b << endl; 
	return 0;
}