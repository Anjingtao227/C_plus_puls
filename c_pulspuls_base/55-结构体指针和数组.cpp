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
	// 定义结构体数组来存放多个学生的信息
	student s[5] =
	{
		{2025001, 'f', 18, 10},
		{2025002, 'm', 20, 20},
		{2025003, 'f', 28, 30},
		{2025004, 'm', 38, 40},
		{2025005, 'f', 88, 50}
	};

	cout << "第三个学生的年龄是：" << s[2].age << endl;

	// 结构体指针
	// 结构体指针的定义
	// 结构体名称 *结构体指针变量名
	student *p = s;
	cout << "第三个学生的年龄是：" << p[2].age << endl;
	cout << "第三个学生的年龄是：" << (*(p + 2)).age << endl;
	cout << "第三个学生的年龄是：" << (p + 2)->age << endl;
	cout << "第四个学生的年龄是：" << s[3].age << endl;
	return 0;
}