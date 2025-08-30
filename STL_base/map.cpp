#include <map>
#include <iostream>
using namespace std;

/*
8 pair对组
	这个数据结构是存储成对的数据
	pair中有两个数据，第一个叫做key（键值），起到了索引作用，第二个叫做value（实际的值）,对组也叫键值对。
	对组的创建方式：
		pair<type,type> p(key,value);//构造函数
		pair<type,type> p=make_pair(key,value);//辅助函数
	对组的访问方式：
		可以通过队组的两个属性来分别访问两个值：first、second
*/
//对组的使用
void test01()
{
	//构造函数
	pair<string, int> p1("tom", 20);
	//辅助函数
	pair<string, int> p2 = make_pair("jerry", 21);
	//访问对组中的key和value
	cout << p1.first << ":" << p1.second << endl;
	cout << p2.first << ":" << p2.second << endl;
}

//打印map的函数模板
template<typename T1,typename T2>
void printMap(map<T1, T2>& m)
{
	for (auto p : m) { cout << p.first << ":" << p.second << " "; }
	cout << endl;
}
//打印multimap的函数模板
template<typename T1, typename T2>
void printMultiMap(multimap<T1, T2>& m)
{
	for (auto p : m) { cout << p.first << ":" << p.second << " "; }
	cout << endl;
}

/*
9 map\multimap字典
	9.1map概念
		map也是基于红黑树的数据结构，所以它的元素也会自动排序（默认升序，它是根据key来排序的），它也不能修改key的值。但是，我们可以修改value的值。
		它也不支持随机存取，因为不是连续的物理空间，所以它的迭代器也不支持算术运算，只能++或者--
		可以通过map的key拿到对应的value：如map[key]就能拿到这个key对应的value。
		map不允许key重复
		multimap则允许key重复。
	9.2map构造、赋值、取值、插入、删除
		构造：
			map<T1,T2> mp;
			map(const map& mp);
			map<T1,T2,仿函数> mp;//仿函数指定排序规则，对于自定义类型必须要有。
		赋值：
			重载赋值运算符=
		取值：
			map[key];//通过key得到对应的value
			map.at(key);//通过at方法取值
		插入：
			insert(ele);//插入元素ele，ele是个对组
			map[key]=value	//key存在时是修改，key不存在时是添加（尽量不要使用这种方式添加）
		删除：
			erase(pos);//删除迭代器所指元素，返回下一个迭代器
			erase(beg,end);//删除迭代器区间的元素，返回下一个迭代器
			erase(key);//删除索引为key的对组
			clear(); //清空
*/
void test02()
{
	//构造
	map<int, int> m;
	m.insert(pair<int, int>(3, 30));//无序插入
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	printMap(m);

	//拷贝构造
	map<int, int> m1(m);
	printMap(m1);

	//赋值=
	map<int, int> m2;
	m2 = m1;
	printMap(m2);

	//其他插入方式
	m.insert(make_pair(4, 40));
	m[5] = 50;//key不存在则变成插入
	printMap(m);

	//修改value
	cout << m[3] << endl;//30
	m[3] = 300;
	cout << m[3] << endl;//300

	//删除
	m.erase(m.begin());//1:10
	printMap(m);
	m.erase(m.begin(), ++m.begin());//区间删除，删除第一个值
	printMap(m);
	m.erase(3);
	printMap(m);
}
//迭代器失效问题，只有删除会导致当前迭代器失效，需要更新
void test03()
{
	map<int, int> m;
	m.insert(pair<int, int>(3, 30));//无序插入
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	printMap(m);
	for (map<int,int>::iterator it = m.begin(); it != m.end();)
	{
		if ((*it).first==2)
		{
			it = m.erase(it);//删除同时更新迭代器
		}
		else
		{
			it++;
		}
	}
	printMap(m);

	//插入不会导致迭代器失效
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if ((*it).first == 3)
		{
			m.insert(make_pair(2, 20));
		}
	}
	printMap(m);
}

/*
9.3map大小和交换
		size();
		empty();
		swap(mp);
	9.4查找和统计
		find(key);//根据key查找，存在则返回迭代器位置，不存在返回end迭代器
		count(key);//统计key的个数，对于map来说，只能是0或者1
	multimap的成员函数跟map一样，区别是允许key重复。
*/
void test04()
{
	map<int, int> m = { {3,30},{1,10},{2,20} };
	cout << "m:";
	printMap(m);

	cout << "size:" << m.size() << ",empty:" << m.empty() << endl;
	map<int, int> m1 = { {4,40},{5,50},{6,60} };
	cout << "m1:";
	printMap(m1);
	m.swap(m1);
	cout << "交换后：" << endl;
	cout << "m:";
	printMap(m);
	cout << "m1:";
	printMap(m1);

	//查找和统计
	map<int, int>::iterator pos = m.find(5);
	cout << pos->first << ":" << pos->second << endl;
	cout << m.count(5) << endl;//1
	cout << m.count(7) << endl;//0
}
//multimap允许key重复，那么如何通过key去取值？此时就不能通过[]和at函数取值了
//解决思路：如果key重复了，可以先统计有个重复的key，然后找到第一个key的位置，然后依次使用迭代器++往后取值
void test05()
{
	multimap<string, int> mp = { {"tom",10},{"tom",20},{"tom",30}, {"jerry",25},{"lucy",18} };
	printMultiMap(mp);
	int num = mp.count("tom");//先查一下有几个重复的key
	multimap<string,int>::iterator pos=mp.find("tom");//拿到第一个tom的位置
	for (int i = 0; i < num; i++)
	{
		cout << pos->first << ":" << pos->second << endl;
		pos++;
	}
}

//通过仿函数改变排序规则
//实现一个map<int,int>的降序排序
class MyCompare
{
public:
	bool operator()(int v1, int v2) const { return v1 > v2; }
};
void test06()
{
	map<int, int, MyCompare> m;
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	for (auto p : m) { cout << p.first << ":" << p.second << endl; }
}
//对于自定义类型的数据，必须在构造map的同时指定排序规则，否则无法插入
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//根据年龄降序排序
class ComparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		return p1.m_Age > p2.m_Age;
	}
};
void test07()
{
	map<Person, int, ComparePerson> m = { {Person("tom",20),20251001},{Person("jerry",18),20251009},{Person("lucy",10),20251006} };
	for (auto p : m) { cout << p.first.m_Name << "," << p.first.m_Age << ":" << p.second << endl; }
}

//作业：1.修改密码
class User
{
public:
	string name;
	string pwd;
	User(string n,string p):name(n),pwd(p){}
};
void resetUser(map<string, User>& muser, string username)
{
	map<string,User>::iterator pos =muser.find(username);
	if (pos==muser.end())
	{
		//没找到，新建用户并且插入容器
		User u(username, "888888");
		muser.insert(make_pair(username, u));
	}
	else
	{
		pos->second.pwd = "888888";
	}
}
void test08()
{
	User u1("tom", "111111"), u2("jerry", "222222"), u3("lucy", "333333");
	map<string, User> muser;
	muser.insert(make_pair("tom", u1));
	muser.insert(make_pair("jerry", u2));
	muser.insert(make_pair("lucy", u3));
	resetUser(muser, "lucy");//lucy存在，密码被重置
	resetUser(muser, "tommy");//tommy不存在，会新建到容器中
	for (auto p:muser )
	{
		cout << p.first << ":" << p.second.pwd << endl;
	}
}

//作业：2.统计字符重复次数
//思路：遍历字符串，每个字符都去map中查找是否存在，不存在，就存入并且+1，存在就给数量+1
map<char, int> countChar(string& str)
{
	map<char, int> m;
	for (int i = 0; i < str.size(); i++)
	{
		if (m.find(str[i])==m.end())//不存在就新建并且数量设置为1
		{
			m[str[i]] = 1;
		}
		else
		{
			m[str[i]] += 1;
		}
	}
	return m;
}
void test09()
{
	string s1 = "abbcccdddd";
	map<char, int> m = countChar(s1);
	printMap(m);
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

/*

	容器总结：
		各容器共性：
			1）STL容器提供的都是值拷贝，当容器插入元素的时候，容器内部实现了拷贝动作，将我们要插入的元素拷贝了一份放到容器中。
			2）除了栈和队列之外，其他容器都提供了迭代器。
			3）每个容器都提供了默认的构造函数和拷贝构造函数。
			4）每个容器都提供了size和empty函数。
			5）物理上连续的存储结构的容器，都支持随机存储，支持指针运算。非连续空间数据结构的容器，迭代器只能++或--
			6）连续空间存储的容器，如vector和deque，插入和删除操作，会引起迭代器失效，导致大量元素移动，对于非连续存储的list、set、map来说，
			   只有删除操作会导致当前迭代器失效，插入则不会。如果要再次使用迭代器，需要做更新。
			7）基于红黑树的容器set和map，都会自动升序排序，如果要插入自定义类型，必须用仿函数指定排序规则。它们都不能修改排序的值。
		容器使用时机：
			1）vector适合存储历史操作记录，比如说日志。因为历史记录一般不删除，只是新增或查看。
			2）deque适合排队购票的场景，涉及的主要是头尾两头的操作，这时候用vector就不适合，因为头部操作效率很低。
			3）list适合数据频繁的插入删除，并且不是在确定位置。但是list遍历效率太低，所以不适合频繁的查找需求。
			4）set适合需要排序的数据，并且数据量较大，红黑树的查找和增删效率都不错。比如说游戏玩家的排行榜。
			5）map适合存储成对的数据，并且数据较大，需要考虑查询效率。比如说用户的信息包含id和详情信息，

		相似数据结构的比较：

​		1.vector和deque的比较

​			1）vector.at()比deque.at()效率高，因为vector头部元素是不支持push和pop的，也就是vector.at(0)基本是固定的。而deque头尾两端同时都在push和pop，deque.at(0)不固定

​			2）deque支持头尾两头的快速插入和移除，这是它的优势，vector头部的操作太消耗。

​		2.stack和queue的比较
​			1）这两个都不支持随机访问，不支持at和[]，不能遍历。

​			2）stack是先进后出，只支持栈顶添加和移除。

​			3）queue是先进先出，队尾添加，队头移除。

​		3.map和set的比较

​			相同点：map和set的底层都是通过红黑树实现的，map和set都不允许插入重复元素。

​			map和set的区别有：

​			1）map中的元素是key-value键值对；而set中的元素自己就是关键字；
​			2）set的迭代器是const的,所以不允许修改元素的值；map也不允许修改key的值，但可以修改value的值，因为依靠key来排序。底层的红黑树需要依靠关键字保持有序性。
​			3）map支持索引操作，而set不支持索引操作。

*/