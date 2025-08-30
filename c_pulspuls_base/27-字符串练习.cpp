#include <iostream>
using namespace std;

void test1()
{
	//1、 输入一个字符串，判断这个字符串是否是回文，比如："12321"、"abcba"是回文、 "12323"不是回文
	char s[80];
	cout << "请输入一个字符串：";
	cin >> s;//cin 会读取用户输入的字符，直到遇到空格或换行符为止。因此，如果用户输入了多个单词，只有第一个单词会被存储在 s 中。
	int n = strlen(s);
	int flag = 1; // 设置标志位 为1，代表是回文
	for (int i = 0; i < n / 2; i++)
	{
		// 判断s[i] 和 s[n - 1 -i] 是否是相等的情况
		if (s[i] != s[n - 1 - i])
		{
			// 如果出现了不相等的字符，就将flag置为0即可
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		cout << "是回文" << endl;
	}
	else
	{
		cout << "不是回文" << endl;
	}

}
	
void test2()
{
	// 判断一个字符是不是数字
	cout << isdigit('3') << endl; //如果是数字字符就返回非0整数，如果不是数字字符就返回0
	// 判断一个字符是不是字母
	cout << isalpha('z') << endl; // 如果是字母字符就返回非0整数，如果不是字母字符就返回0
}

void test3()
{
	// 2、字符数组分类
	// 已知有字符数组a、要求将数组a中的数字字符保存到数组b中，字母字符保存到数组c中，其他字符保存到数组d中
	char a[20] = "lasd,@12a,3";
	char b[20] = ""; // 保存数字字符
	char c[20] = ""; // 保存字母字符
	char d[20] = ""; // 保存其他字符

	// 定义下标给数组b  c d来使用
	int j = 0, k = 0, m = 0;
	for (int i = 0; a[i] != '\0'; i++)//在C语言中，'\0'是一个非常重要的字符，它被称为空字符或字符串结束符。
	{
		// 如果是数字
		if (isdigit(a[i]))
		{
			b[j] = a[i];
			j++;
		}
		// 如果是字母
		else if (isalpha(a[i]))
		{
			c[k] = a[i];
			k++;
		}
		else
		{
			d[m] = a[i];
			m++;
		}
	}
	// 在每一个数组的结尾添加结束标识
	b[j] = '\0';
	c[k] = '\0';
	d[m] = '\0';
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
}


	
int main()
{
	test1();
	return 0;
}