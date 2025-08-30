#include <iostream>
using namespace std;
// 定义结构体
struct student
{
	int number; // 学号
	char gender; // 性别
	int age; // 年龄
	double score; // 分数
};
int main()
{
	// 定义结构体的变量来使用
	student s1;
	s1.number = 2025001;
	s1.gender = 'f';
	s1.age = 18;
	s1.score = 88;

	// 打印结构体中的数据
	cout << "学号：" << s1.number << endl;
	cout << "性别：" << s1.gender << endl;
	cout << "年龄：" << s1.age << endl;
	cout << "分数：" << s1.score << endl;

	// 利用数组的形式来对结构体进行赋值
	student s2 = { 2025002, 'm', 19, 85 };
	cout << "学号：" << s2.number << endl;
	cout << "性别：" << s2.gender << endl;
	cout << "年龄：" << s2.age << endl;
	cout << "分数：" << s2.score << endl;
	return 0;
}