#include <string>
#include <iostream>
using namespace std;

/*
1.STL概念
	为了建立数据结构和算法的一套标准，提高复用性，诞生了STL（standard template library）标准模板库
	STL都采用了泛型编程实现，里面几乎都是类模板和函数模板。
	STL分为三大部分：容器（container）、算法（algorithm）、迭代器（iterator）。
		容器：放数据的地方，STL容器实现了常见的数据结构，用来组织和存储数据。
		算法：用于对数据进行运算的，用于解决问题的方法。比如排序、查找等等。
		迭代器：用于指向容器中的每个元素，用来访问元素，本质上就是一个封装了指针的类。
2.STL中的常用容器
	1 string容器
		1.1基本概念
			string是STL里定义的字符串，本质是一个类，是一个特殊的容器，元素类型只能是char类型。
			string和char*的区别：
				char*是一个指针，而string是一个类，类内部封装了char*
				string管理char*所分配的内存，而且不用担心越界的问题，由类来负责管理，string封装了很多成员方法，使用起来非常方便
		1.2string构造
			string();//创建一个空的字符串
			string(const char* s);//使用字符串s来初始化string对象
			string(const string& str);//使用string对象str来初始化string对象
			string(int n,char c);//使用n个字符c来初始化string对象
*/
void test01()
{
	string s1;//无参构造，创建一个空的字符串
	cout << "s1=" << s1 << endl;

	const char* str = "hello world";
	string s2(str);//使用字符串s来初始化string对象
	cout << "s2=" << s2 << endl;

	string s3(s2);//拷贝构造
	cout << "s3=" << s3 << endl;

	string s4(10, 'a');//使用n个字符char来初始化string对象
	cout << "s4=" << s4 << endl;
}

/*
1.3string赋值操作
			重载赋值运算符：
				string& operator=(const char* s);//字符串常量赋值
				string& operator=(const string& s);//string对象的赋值
				string& operator=(char c);//单个字符赋值
			赋值函数assign():
				string& assign(const char* s);//字符串常量赋值
				string& assign(const char* s,int n);//将字符串s的前n个字符赋值给string
				string& assign(const string& s);//使用string对象完成赋值
				string& assign(int n,char c);//使用n个字符c来赋值
*/

void test02()
{
	//赋值运算符=
	string str1;
	str1 = "hello world";
	cout << "str1=" << str1 << endl;
	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;
	string str3;
	str3 = 'A';
	cout << "str3=" << str3 << endl;

	cout << "下面是赋值函数完成的：" << endl;
	//赋值函数assign()
	string str4;
	str4.assign("hello C++");
	cout << "str4=" << str4 << endl;
	string str5;
	str5.assign("hello C++", 5);
	cout << "str5=" << str5 << endl;
	string str6;
	str6.assign(str5);
	cout << "str6=" << str6 << endl;
	string str7;
	str7.assign(5, 'x');
	cout << "str7=" << str7 << endl;
}

/*
1.4string字符串拼接
			在字符串末尾拼接字符串
			重载运算符+=:
				string& operator+=(const char* s);
				string& operator+=(const string& str);
				string& operator+=(char c);
			append函数：
				string& append(const char* s);
				string& append(const char* s,int n);//把字符串s的前n个字符拼接到string字符串
				string& append(const string& s);
				string& append(const string& s,int pos,int n);//pos代表position位置，从0开始的下标。从pos位置开始，将字符串s后面的n个字符拼接到当前字符串
*/
void test03()
{
	//重载运算符+=
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1=" << str1 << endl;
	str1 += ':';
	cout << "str1=" << str1 << endl;
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	//append函数：
	string str3 = "I";
	str3.append(" like ");
	str3.append("play game such as ", 10);
	str3.append(str2, 4, 3);
	cout << "str3=" << str3 << endl;
}

/*
1.5string查找和替换
			查找：查找指定的字符串是否存在，找到会返回对应的位置，找不到返回-1（-1即string::npos），查找是常函数
				从左往右查找：find
					int find(const string& str,int pos=0) const;//查找字符串str，返回它第一次出现的位置，从pos位置开始找，pos默认值是0，即开头位置
					int find(const char* s,int pos=0) const;
					int find(const char* s,int pos=0,int n) const;//从pos位置开始查找字符串s的前n个字符第一次出现的位置
					int find(char c,int pos=0) const;//从pos位置查找字符c第一次出现的位置
				从右往左查找：rfind
					int rfind(const string& str,int pos=npos) const;//从右往左查找str最后一次出现的位置，从pos位置开始查找，pos默认值是npos，npos是string类的静态常量，表示字符串结束
					int rfind(const char* s,int pos=npos) const;
					int rfind(const string& s,int pos=npos，int n) const;//从pos开始从右往左查找s字符串的前n个字符最后一次出现的位置
					int rfind(char c,int pos=npos) const;
			替换：在指定的位置替换字符串
				string& replace(int pos,int n,const string& str);//从pos位置开始的n个字符被替换为字符串str
				string& replace(int pos,int n,const char* s);//从pos位置开始的n个字符被替换为字符串s
*/
void test04()
{
	//从左往右查找：find
	string str1 = "abcdefgde";
	int pos=str1.find("de");
	cout << "第一个de字符串的位置：" << pos << endl;//3
	pos=str1.find("de", 5);
	cout << "第二个de字符串的位置：" << pos << endl;//7
	pos = str1.find("fgde", 0, 2);//实际上查找的是fg
	cout << "fg的位置：" << pos << endl;//5
	pos = str1.find('f');
	cout << "f的位置：" << pos << endl;//5

	//从右往左查找：rfind
	cout << "从右往左查找：" << endl;
	pos = str1.rfind("de");
	cout << "第一个de字符串的位置：" << pos << endl;//7
	pos=str1.rfind("de", 5);
	cout << "第二个de字符串的位置：" << pos << endl;//3
	pos = str1.rfind("fgde", -1, 2);//实际上查找的是fg
	cout << "fg的位置：" << pos << endl;//5
	pos = str1.rfind('d');
	cout << "d的位置：" << pos << endl;//7

	//替换：在指定的位置替换字符串
	str1.replace(1, 4, "8888");
	cout << "被替换后，str1=" << str1 << endl;
}

/*
1.6string字符串比较
			比较方式：是按照字符串中每个字符的ASCII码逐个比较，如果比较出大小就返回结果，如果直到结束都没有比较出大小，证明两个字符串相等。
			所以，比较方法主要的作用就是判断两个字符串是否相等，至于大小没实际意义。
			返回值：相等的时候返回0，大于的时候返回1，小于返回-1
				int compare(const string& str) const;//当前字符串跟字符串str比较
				int compare(const char* s) const;//当前字符串跟字符串s比较
*/
void test05()
{
	string s1 = "hello";
	string s2 = "hello";
	string s3 = "Hello";
	int ret1 = s1.compare(s2);//0
	int ret2 = s1.compare(s3);//1
	cout << ret1 << "," << ret2 << endl;
}

/*
1.7string插入和删除
			插入：
				string& insert(int pos,const char* s);//在pos位置插入字符串s
				string& insert(int pos,const string& str);//在pos位置插入字符串str
				string& insert(int pos,int n,char c);//在pos位置插入n个字符c
			删除：
				string& erase(int pos,int n);//删除从pos开始的n个字符
*/
void test06()
{
	string str = "hello world";
	str.insert(1, "888");
	cout << "str=" << str << endl;
	str.insert(1, 3, 'a');
	cout << "str=" << str << endl;
	str.erase(1, 6);
	cout << "str=" << str << endl;
}

/*
1.8string截取子字符串
			从字符串中截取想要的子字符串
			string& substr(int pos,int n=npos) const;//返回从pos开始的n个字符组成的子字符串,n的默认值是npos，代表最后
		1.9获取长度
			size():获取字符串的长度，也就是字符数
*/
void test07()
{
	string str = "abcdefg";
	string subStr1 = str.substr(1, 3);
	cout << "subStr1=" << subStr1 << endl;
	string subStr2 = str.substr(3);//第二个参数使用默认值，截取到最后
	cout << "subStr2=" << subStr2 << endl;
	cout << "str的元素个数：" << str.size() << endl;
}

/*
		1.10string元素的存取
			string中单个字符存取可以通过下面两个方式：
				char& operator[](int n);//运算符重载，通过[index]取值，index代表下标
				char& at(int n);//通过at成员函数取值，n也是下标
*/
void test08()
{
	//取，即查询
	string str = "hello world";
	cout << str[4] << endl;
	cout << str.at(6) << endl;

	//存，即修改保存
	str[0] = 'H';
	str[6] = 'W';
	cout << str << endl;

	//注意：越界的问题
	//如果使用[]访问元素，如果传入了越界的下标索引，会导致程序崩溃
	//cout << str[12] << endl;
	//可以通过限定下标，防止越界
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
	//但是使用at函数来访问，则可以抛出异常out_of_range，我们捕获异常进行处理即可
	try
	{
		cout << str.at(12);
	}
	catch (out_of_range& e)
	{
		cout << "越界了" << endl;
		cout << e.what() << endl;//打印异常类型
	}
	catch (const std::exception&)
	{
		cout << "发生异常" << endl;
	}
}

//作业：1.请实现一个函数，把字符串 s 中的每个空格替换成"_"。
void replace_space(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]==' ')
		{
			s[i] = '_';
		}
	}
}
void test09()
{
	string s = "We are happy.";
	replace_space(s);
	cout << s << endl;
}
//作业：2.返回一个字符串最后一个单词
string last_word(string& s)
{
	//思路：找最后一个空格，然后截取
	int index = s.rfind(' ');//找到最后空格的位置
	string sub = s.substr(index + 1);
	return sub;
}
void test10()
{
	string s = "my name is tommy";
	string sub = last_word(s);
	cout << sub << endl;
}
//作业：3.验证.com类邮箱的有效性
//规则：必须包含@, 并且@不能出现在第一个位置；要以.com结尾
bool verity_com_email(string& s)
{
	//思路：依次判断每个需要满足的条件，如果有一个不满足，就return false，最后retrun true
	int index = s.find('@');
	if (index==-1 || index==0)//如果没找到@或者出现在首位，都不行
	{
		return false;
	}
	index = s.find(".com");
	if (index==-1 || index!=(s.size()-4))//如果没找到.com或者不在组后四位，都不行
	{
		return false;
	}
	return true;
}
void test11()
{
	string e1 = "294950398@qq.com";
	string e2 = "hello123@sina.com";
	string e3 = "welcome@163.com.cn";
	cout << verity_com_email(e1) << endl;
	cout << verity_com_email(e2) << endl;
	cout << verity_com_email(e3) << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	test11();
	return 0;
}
