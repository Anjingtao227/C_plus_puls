#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

/*
3 deque双端队列
	3.1概念
		deque全称是double-ended-queue,也叫双端数组，可以对两端进行操作
		vector和deque的区别：
			vector是单向开口的连续空间，deque是双向开口的连续空间，可以高效地在头尾两端做元素的插入和删除操作。当然如果在中间insert操作，效率仍然是低的。
			deque没有容量capacity的概念，它是以分段的连续空间组合而成的，随时可以增加一段新的空间连接起来，它不会像vector那样因为空间不足，重新申请一块空间的操作。
		deque通过内部的中控器来维护这些分段的连续空间。中控器维护每个连续空间的地址，使它们连接起来。
		deque的成员函数跟vector几乎一样，不再赘述。

	3.2 deque构造函数
		函数原型：
		deque<T> deq; //默认构造形式
		deque(beg, end); //将参数deque[beg, end)区间中的元素拷贝。
		deque(n, ele); //将n个ele拷贝。
		deque(const deque &deq); //拷贝构造函数
*/
//打印函数
void printDeque(deque<int>& d)
{
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2(d1.begin(), d1.end());
	printDeque(d2);
	deque<int> d3(10, 100);
	printDeque(d3);
	deque<int> d4(d3);
	printDeque(d4);
}

/*
3.3 deque赋值操作
		函数原型：
		deque& operator=(const deque &deq); //重载赋值运算符
		assign(beg, end); //将参数deque[beg, end)区间中的数据赋值
		assign(n, elem); //将n个elem赋值
*/
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	deque<int> d2;
	d2 = d1;
	printDeque(d2);
	deque<int> d3;
	d3.assign(d1.begin(), d1.begin() + 5);
	printDeque(d3);
	deque<int> d4;
	d4.assign(8, 8);
	printDeque(d4);
}

/*
3.4 deque大小操作
		函数原型：
		empty(); //判断容器是否为空
		size(); //返回容器中元素的个数
		resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超
		出容器长度的元素被删除。
		resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。如果容器变短，则
		末尾超出容器长度的元素被删除。
*/
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	cout << d1.empty() << endl;//0
	cout << d1.size() << endl;//10
	d1.resize(5);
	printDeque(d1);
	d1.resize(15);
	printDeque(d1);
}

/*
3.5 deque 插入和删除
		函数原型：
		两端插入操作：
		push_back(elem); //在容器尾部添加一个数据
		push_front(elem); //在容器头部插入一个数据
		pop_back(); //删除容器最后一个数据
		pop_front(); //删除容器第一个数据
		指定位置操作：
		insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
		insert(pos,n,elem); //在pos位置插入n个elem数据，返回新数据的位置。
		insert(pos,beg,end); //在pos位置插入另一个deque[beg,end)区间的数据，返回新数据的位置。
		erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
		erase(pos); //删除pos位置的数据，返回下一个数据的位置。
		clear(); //清空容器的所有数据
*/
void test04()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);

	d.pop_front();
	d.pop_back();
	printDeque(d);

	d.insert(d.begin(), 1000);
	d.insert(d.begin() + 1, 3, 8);
	printDeque(d);

	deque<int> d1 = { 6,6,6,6,6,6 };
	d.insert(d.end() - 3, d1.begin(), d1.begin() + 3);
	printDeque(d);

	d.erase(d.begin());
	printDeque(d);
	d.erase(d.begin() + 1, d.begin() + 3);
	printDeque(d);
}

/*
	3.6 deque 数据存取
		函数原型：
		at(int idx); //返回索引idx所指的数据
		operator[]; //返回下标索引所指的数据
		front(); //返回容器中第一个数据元素
		back(); //

	3.7 deque 元素互换swap

*/
void test05()
{
	deque<int> d = { 2,3,4,5 };
	cout << d[2] << "," << d.at(3) << endl;
	cout << d.front() << "," << d.back() << endl;
	deque<int> d1;
	d1.assign(6, 6);
	d.swap(d1);
	printDeque(d);
	printDeque(d1);
}

//1.查找元素:定义函数，查找deque中指定整数元素的下脚标，返回所有下脚标组成的新deque数组。
deque<int> findIndex(deque<int>& d, int val)
{
	deque<int> newd;//返回下角标的deque
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		if (*it==val)
		{
			newd.push_back(it - d.begin());//迭代器求下标
		}
	}
	return newd;
}
void test06()
{
	deque<int> d1 = { 1,6,10,4,7,10,5,2,10,9 };
	deque<int> res = findIndex(d1, 10);
	printDeque(res);
}

//2. 评委打分
//选手类
class Person
{
public:
	string m_Name;
	int m_Score;//平均分
	Person(string name,int score):m_Name(name),m_Score(score){}
};
//打分函数
void addScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//随机打分，取值范围是60-100之间的随机数
			d.push_back(score);
		}
		cout << it->m_Name << "打分情况：" << endl;
		for (int i = 0; i < d.size(); i++)
		{
			cout << d[i] << " ";
		}
		cout << endl;
		//排序
		sort(d.begin(), d.end());
		//去除最低分和最高分
		d.pop_back();
		d.pop_front();
		//计算平均分
		int sum = 0;
		for (int i = 0; i < d.size(); i++)
		{
			sum += d.at(i);
		}
		int avg = sum / d.size();
		it->m_Score = avg;
	}
}
void showScore(vector<Person>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].m_Name << " 平均分：" << v[i].m_Score << endl;
	}
}
void test07()
{
	//为了避免随机数组每次生成的一样，我们应该修改随机种子，比较简单的方案是直接使用当前系统时间作为随机种子，需要头文件#include <time.h>
	srand((unsigned int)time(NULL));
	//1.创建五个选手,平局分初始化为0
	Person p1("选手A", 0);
	Person p2("选手B", 0);
	Person p3("选手C", 0);
	Person p4("选手D", 0);
	Person p5("选手E", 0);
	vector<Person> v = { p1,p2,p3,p4,p5 };
	addScore(v);
	showScore(v);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}

