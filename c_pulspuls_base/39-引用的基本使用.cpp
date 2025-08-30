#include <iostream>
using namespace std;
int main()
{
	int a = 100;
	// 定义引用b作为a的别名来使用
	int& b = a;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	b = 1000;
	cout << "b = " << b << endl;
	cout << "a = " << a << endl;

	// 引用的注意点
	// 引用必须要初始化
	int& c = a;
	// 初始化之后不可以作为其他变量别名来使用
	int num = 10000;
	c = num; // 这里是赋值的意思，不是让c作为num的别名使用

	// a  b  c的结果都是10000，修改了c的值就是修改了a的值，修改了a的值就是修改了b的值
	// 因为b和c都是a的别名
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	return 0;
}