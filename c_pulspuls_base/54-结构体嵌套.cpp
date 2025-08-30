#include <iostream>
using namespace std;

// 定义生日日期结构体
struct date
{
	int year;
	int month;
	int day;
};
struct student
{
	int number; // 学号
	char gender; // 性别
	date birthday; // 生日
}s1; // 可以在结构体定义的结束分号之前声明结构体变量

// typedef 可以为结构体来定义简洁名称
// S代表student结构体名
typedef struct student S; //S 的作用就是“偷懒”——省掉 struct 这几个字母，让代码更简洁。
int main()
{
	// 初始化s1变量
	s1 = { 2025001, 'f', {2000,1,10} };
	cout << "学号：" << s1.number << endl;
	cout << "性别：" << s1.gender << endl;
	cout << "生日：" << s1.birthday.year << "年" << s1.birthday.month << "月" << s1.birthday.day << "日" << endl;
	// 利用结构体的简洁名称来初始化结构体变量
	S s2;
	//s2.gender = 'm';
	s2= { 2025002, 'm', { 2000,2,10 } };
	cout << "学号：" << s2.number << endl;
	cout << "性别：" << s2.gender << endl;
	cout << "生日：" << s2.birthday.year <<"年" << s2.birthday.month <<"月"<< s2.birthday.day <<"日"<< endl;
	return 0;
}