#include <iostream>
using namespace std;
int main()
{
	// 短整型
	short s1 = 30000;
	// 无符号短整型
	unsigned short us1 = 40000;
	cout << "us1 = " << us1 << endl;
	// 整型（标准整型）
	int i1 = 1000;
	// 长整型（windows操作系统下和int的范围大小一致）
	long l1 = 2000;
	// 长长整型
	long long ll1 = 3000;
	cout << "s1 = " << s1 << "占用的字节数：" << sizeof(s1) << endl;
	cout << "i1 = " << i1 << "占用的字节数：" << sizeof(i1) << endl;
	cout << "l1 = " << l1 << "占用的字节数：" << sizeof(l1) << endl;
	cout << "ll1 = " << ll1 << "占用的字节数：" << sizeof(ll1) << endl;
	return 0;
}