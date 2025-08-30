#include <set>
#include <iostream>
#include <functional>
using namespace std;

/*
7 集合set/multiset
	7.1基本概念
		set叫做集合，它的特点是所有的元素会在插入的时候自动完成排序（默认升序）。
		set在物理空间上也不是连续的，所以也不支持随机存取（下标取值）。它的迭代器也不支持指针运算，只能++或者--
		set的底层数据结构是红黑树。
		set和multiset的区别：
			set不允许有重复的元素
			multiset可以有重复的元素
			除此之外，它们的成员函数基本是一样的。
		集合是基于红黑树实现的，可以添加删除元素，但是禁止修改元素，因为修改会导致树的结构发生改变，导致红黑树的有序结构被破坏。
		所以set的元素都是const的，set的迭代器也是const的，set调用的函数也是常函数。
	7.2set构造、插入、赋值、删除
		构造：
			set<T> st;
			set(const set& st);
			set<T,仿函数> st;//通过仿函数来指定排序规则，默认是升序
		赋值：
			重载赋值预算符=
		插入、删除：
			insert(ele);//在容器中插入元素
			clear();
			erase(pos);//删除pos迭代器指向的元素，返回下一个元素的迭代器
			erase(beg,end);//删除区间[beg,end)内的元素，返回下一个迭代器
			erase(ele);//删除容器中的ele元素
	7.3set大小和交换
		size();
		empty();
		swap(st);
*/

//打印set的函数模板
template<typename T>
void printSet(set<T>& s)
{
	for (auto ele : s)
	{
		cout << ele << " ";
	}
	cout << endl;
}

void test01()
{
	set<int> s1;
	//插入无序的值
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);
	printSet(s1);//会自动升序排序

	set<int> s2(s1);
	printSet(s2);

	set<int> s3;
	s3 = s2;
	printSet(s3);

	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);//这是它的特殊用法
	printSet(s1);
	cout << "s1的大小：" << s1.size() << endl;
	s1.swap(s2);
	cout << "交换之后：" << endl;
	cout << "s1:";
	printSet(s1);
	cout << "s2:";
	printSet(s2);
	s1.erase(s1.begin(), s1.end());
	cout << s1.empty() << endl;
}

/*
7.4set查找和统计
		find(ele);//找到返回迭代器位置，找不到返回end迭代器
		count(ele);//统计ele元素的个数，对于set来说，只能是0或者1
	multiset的成员函数跟set一样，区别就是它的元素可以重复。
*/
void test02()
{
	set<int> s1;
	//插入无序的值
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);
	printSet(s1);//会自动升序排序

	set<int>::iterator pos = s1.find(30);
	if (pos!=s1.end())
	{
		cout << "找到了：" << *pos << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	cout << s1.count(30) << endl;//1
	cout << s1.count(50) << endl;//0
}

//迭代器失效问题，只有删除操作会导致当前迭代器失效，需要更新迭代器，其他操作不需要
void test03()
{
	//插入操作不需要更新迭代器
	set<int> s = { 2,3,5,6 };
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it==2)
		{
			s.insert(0);
		}
	}
	printSet(s);

	//删除操作需要更新迭代器
	for (set<int>::iterator it = s.begin(); it != s.end(); )
	{
		if (*it == 2)
		{
			it = s.erase(it);//更新迭代器
		}
		else
		{
			it++;
		}
	}
	printSet(s);
}

//multiset允许元素重复
void test04()
{
	multiset<int> ms;
	ms.insert(30);
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	for (auto ele : ms) { cout << ele << " "; }
	cout << endl;
	cout << "30的个数:" << ms.count(30) << endl;//2
}

/*
7.5仿函数（函数对象）
		仿函数本质是一个类对象，不是函数，它在类内部重载了运算符()，使用起来像函数。
		使用仿函数，可以当作参数去指定容器的排序规则，尤其是自定义类型的数据，必须要在set初始化的时候就指定排序规则，否则无法插入元素。
		返回值是bool类型的仿函数，叫做谓词。
		内置的仿函数，通过引入头文件#include <functional>
			关系仿函数：
				equal_to 等于
				not_equal_to 不等于
				greater 大于
				greater_equal 大于等于
				less 小于
				less_equal 小于等于
			算术仿函数：
				plus 加法
				minus 减法
				multiplies 乘法
				divides 除法
				negate 取反
			逻辑仿函数
				logical_and 逻辑与
				logical_or 逻辑或
				logical_not 逻辑非
*/

//利用仿函数实现set<int>降序排序
class MyCompare
{
	//重载()运算符
public:
	bool operator()(int v1, int v2) const //要声明为常函数，因为set禁止修改元素，属于常对象
	{
		return v1 > v2;
	}
};
void test05()
{
	set<int, MyCompare> s1;//构造了降序排序的集合
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(10);
	for (auto ele : s1) { cout << ele << " "; }
	cout << endl;

	//使用系统提供的仿函数greater实现降序集合，注意greater是函数模板
	set<int, greater<int>> s2;
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);
	s2.insert(10);
	for (auto ele : s2) { cout << ele << " "; }
	cout << endl;
}

//课堂练习：使用set集合保存多个Person(m_Name,m_Age),指定排序规则：按照年龄降序
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//仿函数实现年龄降序
class ComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.m_Age > p2.m_Age;
	}
};
void test06()
{
	Person p1("aaa", 10);
	Person p2("bbb", 12);
	Person p3("ccc", 8);
	set<Person, ComparePerson> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	for (auto ele : s) { cout << ele.m_Name << "," << ele.m_Age << endl; }
}

//1.已知两个set集合，合并成一个集合，去掉重复元素
set<int> mergeSet(set<int>& s1, set<int>& s2)
{
	set<int> res;
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		res.insert(*it);
	}
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		res.insert(*it);
	}
	return res;
}
void test07()
{
	set<int> s1 = { 1,3,6,9,11,17 }, s2 = { 1,4,6,8,13,15 };
	set<int> res = mergeSet(s1, s2);
	printSet(res);
}
//作业：2.已知两个set<int>集合s1和s2，合并成一个集合，保留所有元素，并按降序排序
multiset<int, greater<int>> mergeMultiSet(set<int>& s1, set<int>& s2)
{
	multiset<int, greater<int>> mst;
	for (auto ele : s1) { mst.insert(ele); }
	for (auto ele : s2) { mst.insert(ele); }
	return mst;
}
void test08()
{
	set<int> s1 = { 1,3,6,9,11,17 }, s2 = { 1,4,6,8,13,15 };
	multiset<int,greater<int>> res = mergeMultiSet(s1, s2);
	for (auto ele : res) { cout << ele << " "; }
}
int main() {

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}

