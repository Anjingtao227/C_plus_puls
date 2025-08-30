#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
2 vector动态数组
	2.1vector的基本概念
	vector的数据结构跟数组非常相似，也叫做单端数组。
	vector与数组的区别：数组是静态的，一旦声明了数组的长度，是不可变的。而vector是动态的，它的长度可以动态拓展。
		拓展原理：当空间不足的时候，再添加新元素，vector会重新申请一块更大的内存空间，并且将旧空间的数据拷贝到新空间，然后释放旧空间。
		涉及到两个概念：容量capacity 和 大小size，容量指的是空间的总大小，size指的是实际存放的元素数。
	2.2vector构造函数
		vector<T> v;//采用类模板实现，无参构造，构造了一个空的vector容器，就是v
		vector<T> vec(v.begin(),v.end());//参数是两个迭代器，两个位置，v是一个vector对象，将v[begin,end)区间中的元素拷贝给当前vec对象，完成构造。
		vector<T> v(const vector& vec);//拷贝构造
		vector<T> v(n,ele);//ele是element，即元素。使用n个ele元素完成当前vector对象的构造。
*/

//打印函数
void printVector(vector<int>& v)
{
	//使用迭代器对容器进行迭代，打印
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v1;//无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//vector<T> vec(v.begin(),v.end());//参数是两个迭代器，两个位置
	vector<int> v2(v1.begin(),v1.end());
	printVector(v2);
	//vector<T> v(const vector& vec);//拷贝构造
	vector<int> v3(v2);
	printVector(v3);
	//vector<T> v(n,ele);
	vector<int> v4(10, 100);
	printVector(v4);
}

/*
2.3vector赋值
		重载赋值运算符：
			vector& operator=(const vector& vec);
		成员函数assign:
			assign(beg,end);//将vector[beg,end)区间的元素赋值给当前的vector对象，beg和end是两个迭代器位置
			assign(n,ele);//将n个ele元素赋值给当前vector
*/
void test02()
{
	vector<int> v1;//无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//重载赋值运算符
	vector<int> v2;
	v2 = v1;
	printVector(v2);
	//成员函数assign
	vector<int> v3;
	v3.assign(v1.begin() + 2, v1.end() - 2);//去掉了前后各2个元素
	printVector(v3);
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

/*
2.4vector容量和大小
		empty();//判断容器是否为空
		capacity();//返回容器的容量
		size();//返回容器中元素的个数
		resize(int num);//重新指定容器的size为num，如果容器的size变多了，会以默认值填充多余的位置，如果size变少了，会删除多余的元素。
		resize(int num,ele);//重新指定容器的size为num，如果容器的size变多了，会以ele元素填充多余的位置，如果size变少了，会删除多余的元素。
*/
void test03()
{
	vector<int> v1;//无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量：" << v1.capacity() << endl;
		cout << "v1的大小：" << v1.size() << endl;
	}
	//resize(int num)
	v1.resize(5);
	printVector(v1);
	v1.resize(10);
	printVector(v1);
	v1.resize(15, 100);
	printVector(v1);
	//缩容
	v1.resize(5);
	printVector(v1);
	cout << "v1的容量：" << v1.capacity() << endl;//可见，容量没有随着resize的缩小而减小，这会造成内存的浪费
	//所以如果不想浪费空间，可以使用一个缩容函数
	v1.shrink_to_fit();
	cout << "缩容之后：" << endl;
	cout << "v1的容量：" << v1.capacity() << endl;
}

/*
2.5vector插入和删除
		尾部操作：
			push_back(ele);//尾部推入一个元素ele
			pop_back();//尾部最后一个元素ele被弹出
		指定位置插入：insert
			insert(iterator pos,ele);//迭代器指向位置pos插入元素ele，并且返回新插入元素的位置迭代器。
			insert(iterator pos,int n,ele);//迭代器指向位置pos插入n个元素ele，并且返回新插入多个元素的第一个元素的位置迭代器。
			insert(iterator pos,beg,end);//在pos位置插入另一个容器的[beg,end)区间中的值
		删除：erase
			erase(iterator pos);//删除迭代器所指向的元素，返回被删除元素的下一个迭代器位置。
			erase(iterator beg,iterator end);//删除beg到end之间的元素，不包括end
			clear();//清除容器中的所有元素
		注意：删除或者插入操作都会导致删除和插入位置以及以后位置的迭代器改变，所以如果要继续使用迭代器来操作后面的元素，就必须更新迭代器。
			这个原则适用于连续空间的数据结构，包括我们马上要学习的另外一个容器deque。但是对于后面再学习的基于链表或者是树的容器，就不适用了。比如list、map、set等。
*/
void test04()
{
	//尾部插入
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	//尾部删除
	v1.pop_back();
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	//指定位置插入：insert
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	vector<int> v2 = { 6,7,8,9,0 };//初始化列表来初始化容器
	v1.insert(v1.begin(), v2.begin(), v2.begin() + 2);
	printVector(v1);
	//删除：erase
	v1.erase(v1.begin());
	printVector(v1);
	v1.erase(v1.begin(), v1.begin() + 2);
	printVector(v1);

	//插入insert的返回值：插入元素当前的位置
	vector<int>::iterator it = v1.insert(v1.begin() + 1, 500);
	printVector(v1);
	cout << *it << endl;//500

	//删除erase会返回被删元素的下一个元素的位置
	vector<int>::iterator it_erase = v1.erase(v1.begin() + 1);
	printVector(v1);
	cout << *it_erase << endl;
	it_erase = v1.erase(v1.begin(), v1.begin() + 2);//删除前两个值
	printVector(v1);
	cout << *it_erase << endl;
}

//关于迭代器失效的问题
void test05()
{
	vector<int> v = {10,20,30,30,40,50};
	printVector(v);
	////删除容器中的30
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (*it==30)
	//	{
	//		v.erase(it);//这个删除操作会导致当前位置和后面所有位置的迭代器失效，因为后面的元素向前移动了
	//	}
	//}

	////所以如果要继续使用迭代器来操作后面的元素，就必须更新迭代器
	//for (vector<int>::iterator it = v.begin(); it != v.end(); )
	//{
	//	if (*it == 30)
	//	{
	//		it=v.erase(it);//erase会返回被删元素的下一个元素的迭代器，对it进行更新操作，这里it就相当于做了++操作
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}
	//printVector(v);

	////while循环来实现
	//vector<int>::iterator it = v.begin();
	//while (it!=v.end())
	//{
	//	if (*it==30)
	//	{
	//		it = v.erase(it);
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}
	//printVector(v);


	////插入操作也会导致迭代器失效，要在30的位置插入100
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (*it==30)
	//	{
	//		it=v.insert(it,100);//这里进入了死循环，因为insert会返回插入元素的位置，这个位置就是30之前的位置，相当于it--了
	//		it++;//所以需要再往后走一步，让迭代器回到正常位置
	//	}
	//}
	//printVector(v);

	//while循环实现
	vector<int>::iterator it = v.begin();
	while (it!=v.end())
	{
		if (*it==30)
		{
			it = v.insert(it, 100);
			it++;
		}
		it++;
	}
	printVector(v);
}

/*
2.6vector数据存取
		operator[];//重载了[]运算符，可以通过下标取值
		at(int index);//返回索引index位置的元素
		front();//返回容器中第一个元素
		back();//返回容器中最后一个元素
*/
void test06()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	cout << v1[2]<<"," << v1.at(3)<<","<<v1.front()<<","<<v1.back();
}

/*
2.7vector互换
		可以实现两个vector容器元素的互换
		v1.swap(v2);//v1和v2互换元素
*/
void test07()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1:";
	printVector(v1);
	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	cout << "v2:";
	printVector(v2);
	//互换
	v1.swap(v2);
	cout << "互换后：" << endl;
	cout << "v1:";
	printVector(v1);
	cout << "v2:";
	printVector(v2);
}

/*
2.8vector预留空间
		当vector存储的数据量很大时，由于vector的动态数组特性，会导致多次的动态扩展发生，这样会降低效率。
		为了避免多次拓展的情况发生，可以在一开始就指定一些预留的空间，其实就是指定了capacity的值。
		reserve(int len);//给容器预留len个元素的位置，预留的位置不可访问，因为没有被初始化。
*/
void test08()
{
	vector<int> v;
	//v.reserve(10);//预留10个位置
	v.reserve(9);//预留9个位置
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		//可以通过观察地址发现有没有发生动态拓展
		cout << &v[0] <<" ";//始终查看第一个元素的地址，如果有变化就说明发生了动态拓展
		cout << v.capacity() << endl;;
	}
}

/*
	2.9几个常用的算法函数（需要引入头文件#include <algorithm>）
		这是算法，适用于大部分容器的，不是vector的成员函数
		排序：
			sort(iterator beg,iterator end);//对区间内的元素进行排序，默认升序，从小到大
			sort(iterator beg,iterator end,func);//对区间内的元素进行排序，使用func指定排序方式
		反转：
			reverse(iterator beg,iterator end);//对区间内元素反转倒置
		复制：
			copy(源容器起始位置，源容器结束位置，目标容器的起始位置);//将源容器的区间元素复制到目标容器指定位置，注意是替换，新复制进去的值替换了原来位置的值
		查找：
			find(iterator beg,iterator end,ele);//在区间内查找元素ele，找到返回所在位置的迭代器，找不到返回end迭代器，注意这个end指的是区间中指定的end位置，不一定是整个容器的end()。
		遍历：
			for_each(iterator beg,iterator end,func);//遍历容器区间内的元素，func是个函数或者仿函数，指明遍历时对元素的操作。
	2.10总结
		vector是单端数组，所以它在尾部的插入和删除操作效率很高，但是在其他位置做insert插入操作的时候，效率很低，原因是会引起其他元素的移动。
		同时，由于它是动态数组，是连续存储的物理空间，所以可以通过下标直接访问，所以查找效率很高。

*/

//排序器函数
bool cap(int a, int b) { return a > b; }//降序排序
//用于遍历时操作元素的函数
void myPrint(int val)
{
	val++;
	cout << val << " ";
}
void test09()
{
	vector<int> v1 = { 39,5,42,68,49,22,55 };
	//升序排序
	sort(v1.begin(), v1.end());
	cout << "升序排序后：";
	printVector(v1);
	//实现降序排序，需要自己写一个函数指定排序规则，这个函数可以叫做排序器函数
	sort(v1.begin(), v1.end(), cap);
	cout << "降序排序后：";
	printVector(v1);
	
	//反转
	reverse(v1.begin(), v1.begin() + 5);
	cout << "反转前五个值：";
	printVector(v1);

	//复制
	vector<int> v2;
	v2.assign(10, 100);
	printVector(v2);
	//接下来将v1的前五个值复制给v2的开头处
	copy(v1.begin(), v1.begin() + 5, v2.begin());
	cout << "v1的前五个值复制给v2的开头处:";
	printVector(v2);

	//查找
	vector<int>::iterator it =find(v1.begin(), v1.begin() + 5, 68);
	if (it==(v1.begin()+5))
	{
		cout << "没找到" << endl;
	}
	else
	{
		cout << "找到了，它的值是：" << *it << "，它的下标是：" << it - v1.begin() << endl;
	}

	//遍历
	for_each(v1.begin(), v1.end(), myPrint);
}

//课堂作业：1.使用三种不同的方式对vector进行打印
void print_for_each(int value) { cout << value << " "; }
void test10()
{
	vector<int> v = { 1,2,3,4,5 };
	//1.迭代器+for循环
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//2.下标索引+for循环
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
	//3.for_each算法
	for_each(v.begin(), v.end(), print_for_each);
}
//拓展：实现一个打印vector容器的函数模板
template<typename T>
void print_vector(const vector<T>& vec)
{
	//const容器必须使用const_iterator来遍历
	//如果使用了模板，必须在iterator之前加上typename用来声明这是一个类型
	for (typename vector<T>::const_iterator it= vec.begin(); it!=vec.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test11()
{
	const vector<int> int_v = { 1,2,3,4,5 };//const修饰的容器，它内部元素禁止修改
	vector<string> str_v = { "hello","world","C++" };
	print_vector(int_v);
	print_vector(str_v);
}
//课堂作业：2.使用vector容器存储多个Person(m_Name,m_Age)对象，根据年龄进行降序排序，最后输出每个对象的属性
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name,int age):m_Name(name),m_Age(age){}
};
//按照年龄降序的排序器函数
bool compare_by_age(Person& p1, Person& p2) { return p1.m_Age > p2.m_Age; }
void test12()
{
	vector<Person> v;
	Person p1("lucy", 10);
	Person p2("tommy", 8);
	Person p3("john", 12);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//遍历输出
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << ",年龄：" << it->m_Age << endl;//两种取属性的方式
	}
	sort(v.begin(), v.end(), compare_by_age);
	cout << "排序之后：" << endl;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << ",年龄：" << it->m_Age << endl;//两种取属性的方式
	}
}
//课堂作业：3.vector容器中存储多个vector<int>容器，输出每个vector<int>中的元素
void test13()
{
	//创建外层容器
	vector<vector<int>> v;
	//创建内部容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	v1 = { 1,2 };
	v2 = { 1,2,3 };
	v3 = { 1,2,3,4 };
	v4 = { 1,2,3,4,5 };
	v = { v1,v2,v3,v4 };
	//遍历，需要双层循环
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = it->begin(); vit != it->end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//作业1.给你一个的整数vector动态数组 nums，返回每个数字的平方组成的新动态数组，要求按升序排序。
//思路：遍历数组，求每个数字的平方，然后将结果存入新数组，再进行排序
vector<int> num_to_power(vector<int>& v)
{
	vector<int> res;
	for (int i = 0; i < v.size(); i++)
	{
		res.push_back(v.at(i) * v.at(i));
	}
	sort(res.begin(), res.end());
	return res;
}
void test14()
{
	vector<int> v1 = { -4,3,0,-1,10 };
	vector<int> res = num_to_power(v1);
	printVector(res);
}

//作业2.给定一个动态数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//思路：先找到零删掉，同时记录删了几个，最后添加到末尾
void backZero(vector<int>& v)
{
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); )
	{
		if (*it==0)
		{
			it = v.erase(it);
			num++;
		}
		else
		{
			it++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		v.push_back(0);
	}
}
void test15()
{
	vector<int> v1 = { 0,1,0,3,12 };
	backZero(v1);
	printVector(v1);
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
	//test11();
	//test12();
	//test13();
	//test14();
	test15();

	return 0;
}
