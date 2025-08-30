#include <iostream>
using namespace std;
int main()
{
	// 输出双引号
	cout << "\"123\"" << endl;
	// 输出换行 n代表new line的意思
	cout << "hello\n";
	cout << "hello\n";
	
	// 输出反斜杠
	cout << "\\" << endl;

	// 制表符 \t是水平制表符，可以整齐的输出数据
	// \t的对齐规则是：\t前面的字符数量必须小于8的倍数，比如下面的字符，都在8~15之间，即可对齐，因为\t是每次对齐8个字符
	// ctrl + k + c 快速注释
	// ctrl + k + u 快速取消注释
	cout << "aaaaaaaaa\thello" << endl;
	cout << "aaaaaaaa\thello" << endl;
	cout << "aaaaaaaaaaaa\thello" << endl;
	return 0;
}