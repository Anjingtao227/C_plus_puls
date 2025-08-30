#include <iostream>
using namespace std;
int main()
{
	char ch[20] = "C++ Program";
	
	// strlen()计算字符串的长度
	cout << strlen(ch) << endl;

	// strcpy_s() 字符串的复制操作
	char ch1[20] = { 'C', '+', '+'};
	char ch2[20] = "abcdef";
	strcpy_s(ch1, ch2); // 将ch2赋值给ch1, 要保证ch1的长度要大于等于ch2的长度
	strcpy_s(ch1, "java");
	cout << ch1 << endl;

	// strcat_s() 将字符串拼接到字符数组的后面
	// 要保证拼接后的字符串要能存放到指定的字符数组中，比如下面的例子，ch3+ch4的结果要能保存到ch3中，ch3要有足够的数组长度来存放结果
	char ch3[20] = "C++";
	char ch4[20] = "program";
	strcat_s(ch3, ch4);  // 将ch4拼接到ch3的结尾
	cout << ch3 << endl;

	// strcmp(字符串1,字符串2); 比较两个字符串的大小
	// 比较的规则：从两个字符串的第一个字符开始，逐个比较每对字符对应的ASCII码值，直到出现不同大小或者直接到达字符串的末尾为止，如果出现了不同大小的字符，那么就以首次不同的字符的大小比对结果为准，直接决定两个字符串的大小，如果一直到达结尾都相同，就说明两个字符串相等。
	char ch5[10] = "Program";
	char ch6[10] = "Programer";
	// 字符串相等，返回的结果是0
	cout << strcmp(ch5, "Program") << endl;
	// 前面的字符串比后面的字符串大，返回的结果1
	cout << strcmp(ch6, ch5) << endl;
	// 前面的字符串比后面的字符串小，返回的结果-1
	cout << strcmp(ch5, ch6) << endl;

	// _strlwr_s() 函数可以将字符串中的大写字母转化为小写字母
	// _strupr_s() 函数可以将字符串中的小写字母转化为大写字母
	_strlwr_s(ch6);
	cout << ch6 << endl;
	_strupr_s(ch6);
	cout << ch6 << endl;


	// 作业：用户输入任意多的一个英文的字符串，编写程序将其进行翻转之后进行输出
	// 例如：输入的 abcdef，输出的结果为：fedcba

	//char ch[100] = "abcdef";
	//.....
	//cout << ch << endl; // fedcba
	return 0;
}