#include<iostream>
using namespace std;

void test(int a)
{
	cout << "第4次修改" << endl;
}

int main()
{
	float add(float x, float y);
	float a, b, c;
	cout << "请输入两个数，用空格隔开：" << endl;
	cin >> a >> b;
	c = add(a, b);
	cout << "两数之和为：" << c << endl;
	//第一次修改

	return 0;
}

float add(float x, float y)
{
	float z;
	z = x + y;
	return(z);
}