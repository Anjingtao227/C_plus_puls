#include <stack>
#include <queue>
#include <iostream>
using namespace std;

/*
4 栈stack
	4.1栈的基本概念
		栈是一种数据结构，它最大的特点是先进后出，因为它只有一个出口，即栈顶。
		栈只能在栈顶访问元素操作元素，比如说对元素进行新增和删除操作。除了栈顶之外，其他位置的元素都不可访问。
		压入元素到栈顶，称为入栈，弹出栈顶的元素，称为出栈。
		栈不具有遍历行为的，没有迭代器，也不支持随机访问（通过下标访问）。
	4.2栈的常用函数
		构造函数：
			stack<T> stk;//无参构造
			stack<T> stk(const stack& s);//拷贝构造
		赋值：
			赋值运算符重载
			stack& operator=(const stack& s);
		数据存取：
			push(ele);//添加元素到栈顶
			pop();//将栈顶元素删除
			top();//返回栈顶元素
		大小相关：
			empty();//判断栈是否为空
			size();//返回栈的大小
*/
void test01()
{
	stack<int> s;
	//入栈
	s.push(10);
	s.push(20);
	s.push(30);
	//拷贝构造
	stack<int> s1(s);
	cout << "s栈顶元素：" << s.top() << endl;//30
	cout << "s栈的大小：" << s.size() << endl;//3
	cout << "s栈是否为空：" << s.empty() << endl;//0
	//出栈
	s.pop();//30
	s.pop();//20
	s.pop();//10
	cout << "s栈是否为空：" << s.empty() << endl;//1
	//输出s1的情况
	cout << "s1栈顶元素：" << s1.top() << endl;//30
	cout << "s1栈的大小：" << s1.size() << endl;//3
	cout << "s1栈是否为空：" << s1.empty() << endl;//0
	//赋值=
	stack<int> s2;
	s2 = s1;
	cout << "s2栈顶元素：" << s2.top() << endl;//30
	cout << "s2栈的大小：" << s2.size() << endl;//3
	cout << "s2栈是否为空：" << s2.empty() << endl;//0
}
//思考：既然栈只能访问栈顶元素，那么如何打印遍历所有站内的元素呢？
//思路：通过出栈操作改变栈顶元素，就可以访问所有元素，直到栈为空结束
void test02()
{
	//for循环，使用size作为边界条件
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	int size = s.size();//如果使用size作为for循环条件，需要将size的值拿到循环外面，否则循环体中的s.size()每次都会由于出栈减少
	for (int i = 0; i < size; i++)
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	//使用while，用栈不为空作为循环条件
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}	
}
//写一个打印栈的函数模板
template<typename T>
void printStack(stack<T>& stk)
{
	while (!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
}
void test03()
{
	stack<string> s1;
	s1.push("abc");
	s1.push("bcd");
	s1.push("efg");
	stack<int> s2;
	s2.push(10);
	s2.push(20);
	s2.push(30);
	printStack(s1);
	printStack(s2);
}

//课堂练习：括号匹配问题
//给你一个包含()的字符串，但是括号有可能是不匹配，需要你写个函数，判断某个字符串中的括号是不是匹配的？
//举例：匹配：abc(e(f)g(h)88)  不匹配：)ab(cd(ef)  (ab)c(d)ef(   (a)bc)def(12(3) 
//思路：这个题不能按照传统思路去解决，要按照栈的数据结构先进后出的特点去解决。栈在函数调用和对象构造析构的时候都用到。函数之间有嵌套关系，恰似这里括号的嵌套关系。
//具体操作：遍历字符串，遇到左括号，先入栈，第一个左括号就是最外层的，第二个左括号就是第二层，以此类推。
//遇到右括号，需要配对了，此时需要跟最近的那个左括号配对，就是在栈顶的那个。此时需要将栈顶的左括号出栈完成配对。
//但是，跟栈顶左括号配对的时候，栈有可能是空的，如果是空的，直接返回flase，否则才能配对出栈。
//当循环结束后，检查栈的结果，如果栈是空的，说明所有左括号都配对了，那就说明匹配。否则说明有落单的左括号，说明不匹配。
bool isMatch(string str)
{
	stack<char> stk;//存放左括号的栈
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			stk.push('(');
		}
		else if (str[i]==')')
		{
			if (stk.empty())
			{
				return false;
			}
			else
			{
				stk.pop();
			}
		}
	}
	if (stk.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test04()
{
	string s1 = "abc(e(f)g(h)88)";
	string s2 = ")ab(cd(ef)";
	string s3 = "(ab)c(d)ef(";
	string s4 = "(a)bc)def(12(3)";
	cout << isMatch((s1)) << endl;//1
	cout << isMatch((s2)) << endl;//0
	cout << isMatch((s3)) << endl;//0
	cout << isMatch((s4)) << endl;//0
}

//1.多种括号的有效匹配
//给定一个由大括号，中括号，小括号和其它字符组成的字符串，判断左右括号是否成对出现。
//跟课堂练习比起来，只需要在括号配对的时候，提前判断是否为同类型的括号
bool sameType(char c1, char c2)
{
	if (c1=='(' and c2==')')
	{
		return true;
	}
	else if (c1=='[' and c2==']')
	{
		return true;
	}
	else if (c1=='{' and c2=='}')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isMatchMore(string str)
{
	stack<char> stk;//存放左括号的栈
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' or str[i]=='[' or str[i]=='{')
		{
			stk.push(str[i]);
		}
		else if (str[i] == ')' or str[i] == ']' or str[i] == '}')
		{
			if (stk.empty())
			{
				return false;
			}
			else
			{
				if (sameType(stk.top(),str[i]))//这里先判断是否为同类型的
				{
					stk.pop();//配对出栈
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (stk.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}
void test06()
{
	string s1 = "ab{c[d(12)],[(34)5]}";//匹配
	string s2 = "{abc[(de)f}gg]";//不匹配
	cout << "s1:" << isMatchMore(s1) << endl;
	cout << "s2:" << isMatchMore(s2) << endl;
}
/*
5 队列queue
	5.1队列的概念
		队列是一种先进先出的数据结构，它有队头和队尾，队尾只能进，叫入队，队头只能出，叫出队。其他位置的元素无法访问。
		没有迭代器，没有遍历行为，不能随机存取（通过下标访问）。只能操作队头和队尾。
	5.2queue的常用函数
		构造函数：
			queue<T> que;//无参构造
			queue<T> que(const queue& q);//拷贝构造
		赋值：
			queue& operator=(const queue& q);
		数据存取：
			push(ele);//添加元素到队尾
			pop();//将队头元素删除
			back();//返回队尾元素
			front();//返回队头元素
		大小相关：
			empty();//判断队列是否为空
			size();//返回队列的大小
*/

//打印队列的函数模板
template<typename T>
void printQueue(queue<T>& que)
{
	while (!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
}
void test05()
{
	queue<int> que;
	for (int i = 0; i < 10; i++)
	{
		que.push(i);
	}
	cout << "队头：" << que.front() << endl;
	cout << "队尾：" << que.back() << endl;
	que.pop();
	cout << "队头：" << que.front() << endl;
	cout << "队尾：" << que.back() << endl;
	cout << "大小：" << que.size() << endl;
	cout << "是否为空：" << que.empty() << endl;
	printQueue(que);
}

//1.奇数偶数分类
vector<queue<int>> numType(queue<int>& que)
{
	queue<int> q1;//奇数队列
	queue<int> q2;//偶数队列
	vector<queue<int>> v;
	while (!que.empty())
	{
		if (que.front()%2!=0)//奇数
		{
			q1.push(que.front());
			que.pop();
		}
		else
		{
			q2.push(que.front());
			que.pop();
		}
	}
	v.push_back(q1);
	v.push_back(q2);
	return v;
}
void test07()
{
	queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	que.push(5);
	que.push(6);
	vector<queue<int>> v;
	v = numType(que);
	//遍历查看
	for (auto ele : v)
	{
		while (!ele.empty())
		{
			cout << ele.front() << " ";
			ele.pop();
		}
		cout << endl;
	}
}

//2.翻扑克牌
void card(queue<int>& q)
{
	//奇数次的牌展示然后出队，偶数次的牌出队再入队，不用展示
	bool b = true;
	while (!q.empty())
	{
		if (b)
		{
			cout << q.front() << " ";//奇数次，输出，然后出队
			q.pop();
		}
		else
		{
			//这里要先入队，再出队，否则拿不到这个值了
			q.push(q.front());
			q.pop();
		}
		b = !b;
	}
	cout << endl;
}
void test08()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	card(q);
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
	test08();
	return 0;
}
