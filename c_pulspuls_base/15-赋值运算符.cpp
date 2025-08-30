#include <iostream>
using namespace std;
int main()
{
	// a += 1 相当于 a = a + 1  
	// a*=1  相当于 a  = a * 1
	
	// 简单赋值
	int a = 10;
	a += 20;
	// a = a + 20
	cout << a << endl; // 30
	a -= 5;
	cout << a << endl; // 25
	a %= 4; // a = a % 4
	cout << a << endl; // 1

	// 复合赋值
	int b = 20;
	// b += 5 * 20 - 40; // b = b + (5 * 20 - 40)
	b *= 5 * 20 - 40; // b = b * (5 * 20 - 40)
	cout << b << endl; 
	return 0;
}