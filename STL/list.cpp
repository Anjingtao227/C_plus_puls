#include <list>
#include <iostream>
using namespace std;

/*
6 链表list
	6.1链表概念
		链表是一种物理上不连续的存储结构，不支持随机存取（通过下标取值）。数据单元的逻辑顺序是通过链表中的指针链接实现的。
		链表的组成单元：结点，结点又是由两部分构成：数据域和指针域。
		STL中的list链表是一种双向链表（两个方向，可前可后）
		链表list中有迭代器，支持遍历，但是迭代器只能单步位移，每次只能向前或向后移动一位。不支持指针运算。
		链表的特点：
			优点：
				链表最大的优点是插入和删除操作十分高效，修改指针即可，不需要大量移动元素。同样不会造成迭代器的失效。
				链表也是动态内存分配的，不会造成内存浪费也不会有内存溢出。
			缺点：
				遍历元素效率太低
	6.2list构造
		list<T> lst;
		list<T> lst(beg,end);//将[beg,end)区间的元素拷贝给当前要构造的list，beg和end是迭代器
		list(n,ele);//n个ele元素构造当前list
		list(const list& lst);//拷贝构造
*/
//打印list的函数模板
//使用for范围遍历的新特性来遍历
template<typename T>
void printList(list<T>& L)
{
	for (auto ele : L) { cout << ele << " "; }
	cout << endl;
}

void test01()
{
	//构造
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int> L2(L1.begin(), L1.end());
	printList(L2);

	list<int> L3(L2);
	printList(L3);

	list<int> L4(10, 1000);
	printList(L4);
}

/*
	6.3list赋值和交换
		赋值运算符重载=
		assign(beg,end);//将[beg,end)区间的元素赋值给当前list
		assign(n,ele);//将n个ele元素赋值给当前list
		swap(lst);//两个list交换内部的元素
*/
void test02()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int> L2;
	L2 = L1;
	printList(L2);

	list<int> L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int> L4;
	L4.assign(8, 8);
	printList(L4);

	cout << "交换L1和L4：" << endl;
	L1.swap(L4);
	cout << "L1=";
	printList(L1);
	cout << "L4=";
	printList(L4);
}

/*
6.4list大小相关
		size();
		empty();
		resize(int n);
		resize(int n,ele);
*/
void test03()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	cout << L1.empty() << endl;//0
	cout << L1.size() << endl;//4
	L1.resize(10);
	printList(L1);
	L1.resize(2);
	printList(L1);
}

/*
	6.5list插入和删除
		push_back(ele);
		pop_back();
		push_front(ele);
		pop_front();
		insert(pos,ele);//在pos指定的位置插入ele元素，返回插入元素的位置迭代器
		insert(pos,n,ele);//在pos指定的位置插入n个ele元素
		insert(pos,beg,end);//在pos指定的位置插入[beg,end)之间的元素
		clear();
		erase(pos);//删除pos位置的元素，返回下一个位置
		erase(beg,end);//删除[beg,end)之间的元素，返回下一个位置
		remove(ele);//删除list中所有的ele元素（ele有可能重复）
	6.6list数据存取
		front();//取头部第一个元素
		back();//取最后一个元素
*/
void test04()
{
	list<int> L;
	L.push_back(10);//尾部插入
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);//头部插入
	L.push_front(200);
	L.push_front(300);
	cout << "L:";
	printList(L);

	//弹出
	L.pop_back();//弹出30
	L.pop_front();//弹出了300
	cout << "弹出头尾两端：";
	printList(L);

	L.insert(++L.begin(), 1000);//注意，list迭代器不支持+或者-运算符，但支持++或者--，注意++写到前面，先自增后取值
	cout << "在第二个位置插入1000:";
	printList(L);

	L.erase(++L.begin());
	cout << "删除第二个位置的值：";
	printList(L);

	L.insert(L.begin(), 3, 0);
	cout << "在第一个位置插入3个0：";
	printList(L);

	list<int> L1;
	L1.assign(5, 8);
	cout << "L1:";
	printList(L1);
	L1.insert(L1.begin(), L.begin(), L.end());
	cout << "在L1开头位置插入L全部的值：";
	printList(L1);

	//remove(ele);//删除list中所有的ele元素（ele有可能重复）
	L.remove(0);
	cout << "删除所有的0之后，L：";
	printList(L);

	//数据存取
	cout << "L首元素：";
	cout << L.front() << endl;
	cout << "L尾元素：";
	cout << L.back() << endl;
	L.clear();
	cout << L.size() << endl;//0
}
//关于迭代器失效问题
//list是链表，数据是分散存储的。所以插入和删除都不会对其他节点造成影响。但对操作的节点自己来说，删除操作仍然会导致当前迭代器失效，仍然需要更新迭代器。
//而插入操作不会导致任何迭代器失效，不需要更新迭代器。
void test05()
{
	list<int> ls = { 5,2,8,2 };
	for (list<int>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		if (*it==2)
		{
			ls.insert(it, 0);//插入不需要更新迭代器
		}
	}
	cout << "插入之后，ls:" << endl;
	printList(ls);
}
//删除操作会导致当前位置迭代器失效，需要更新迭代器
void test06()
{
	list<int> ls = { 5,2,8,2 };
	for (list<int>::iterator it = ls.begin(); it != ls.end(); )
	{
		if (*it == 2)
		{
			it=ls.erase(it);//删除操作需要更新当前迭代器
		}
		else
		{
			it++;
		}
	}
	cout << "删除之后，ls:" << endl;
	printList(ls);
}

/*
	6.7list反转和排序
		reverse();//反转链表，注意这里不是算法
		sort();//升序排序，不是算法sort()，因为算法中的排序sort不支持list，所以list自己定义了一个排序函数。
		sort(func);//按func规则排序
		//注意：对于自定义类型的数据，在list中排序，必须手动指定排序规则，否则sort函数不知道如何排序。
*/
//排序器函数
bool myCompare(int v1, int v2) { return v1 > v2; }
void test07()
{
	list<int> L = { 8,5,9,3 };
	printList(L);
	//排序
	L.reverse();//反转
	printList(L);
	L.sort();//升序
	printList(L);
	
	//通过排序器函数指定排序规则，实现降序
	L.sort(myCompare);
	printList(L);
}

//课堂作业：使用list存储对象类型Person(m_Name,m_Age),然后排序，排序规则：按照年龄进行升序，如果年龄相同，按照姓名进行降序排序。
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//排序器
bool compaerPerson(Person& p1, Person& p2)
{
	if (p1.m_Age==p2.m_Age)
	{
		return p1.m_Name > p2.m_Name;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}
void test08()
{
	Person p1("a", 6);
	Person p2("b", 6);
	Person p3("c", 7);
	Person p4("d", 8);
	Person p5("e", 8);
	list<Person> L = { p1,p2,p3,p4,p5 };
	L.sort(compaerPerson);
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << ",年龄：" << it->m_Age << endl;
	}
}

//作业：去除不合格的手机号码
//关键是对规则的实现：11位数字，并且以1开头才算合格。
//首先判断是否都是数字
bool every_is_num(string& str)
{
	//如何判断一个字符串中的每个字符都是数字字符呢？通过ASCII码来判断。数字字符0-9之间的ASCII码范围是48-57
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]>=48 and str[i]<=57)
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}
//再写个函数，给出最终判定
bool isMeet(string& str)
{
	if (!every_is_num(str))//先判断是否都是数字
	{
		return false;
	}
	if (str.size()!=11)//再判断是否11位
	{
		return false;
	}
	if (str[0]!='1')//再判断是否以1开头
	{
		return false;
	}
	return true;
}
//去除不合格号码的函数
void del_bad_num(list<string>& ls)
{
	for (list<string>::iterator it = ls.begin(); it != ls.end(); )
	{
		if (!isMeet(*it))
		{
			it = ls.erase(it);//需要更新迭代器
		}
		else
		{
			it++;
		}
	}
}
void test09()
{
	list<string> tel;
	tel.push_back("18677889999");//合格
	tel.push_back("1867788999");//少一位，不合格
	tel.push_back("186778899a");//不全是数字，不合格
	tel.push_back("0867788999");//不是以1开头，不合格
	del_bad_num(tel);
	printList(tel);
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
	test09();
	return 0;
}

