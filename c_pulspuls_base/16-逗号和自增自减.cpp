#include <iostream>
using namespace std;
int main()
{
	int i, a = 10, b = 20;
	// 赋值运算符的优先级比逗号运算符的优先级高，所以只是将a赋值给了i
	i = a, b;
	cout << "i = " << i << endl; // 10

	// 如果加了括号，会将赋值运算符右侧的当做一个整体对待，只会返回,最后一个表达式的值
	int j = (a, b);
	cout << "j = " << j << endl; // 20

	// 自增运算符
	int c = 20, res;
	// ++c 先进行自加1 然后再参与整个表达式的运算
	// res = ++c + 10;
	// cout << res << endl; //31

	// 先参与表达式的运算，然后再进行自加1的操作
	// 后置自增使用的场景更多，主要是我们对某一个变量进行++时，不希望参与当前的表达式运算
	res = c++ + 10;
	cout << res << endl; // 30
	cout << c << endl; // 21
	// 自减运算符的思路和自加相同

	return 0;
}

