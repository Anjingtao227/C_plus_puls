#include <stack>
#include <queue>
#include <iostream>
using namespace std;

/*
4 ջstack
	4.1ջ�Ļ�������
		ջ��һ�����ݽṹ���������ص����Ƚ��������Ϊ��ֻ��һ�����ڣ���ջ����
		ջֻ����ջ������Ԫ�ز���Ԫ�أ�����˵��Ԫ�ؽ���������ɾ������������ջ��֮�⣬����λ�õ�Ԫ�ض����ɷ��ʡ�
		ѹ��Ԫ�ص�ջ������Ϊ��ջ������ջ����Ԫ�أ���Ϊ��ջ��
		ջ�����б�����Ϊ�ģ�û�е�������Ҳ��֧��������ʣ�ͨ���±���ʣ���
	4.2ջ�ĳ��ú���
		���캯����
			stack<T> stk;//�޲ι���
			stack<T> stk(const stack& s);//��������
		��ֵ��
			��ֵ���������
			stack& operator=(const stack& s);
		���ݴ�ȡ��
			push(ele);//���Ԫ�ص�ջ��
			pop();//��ջ��Ԫ��ɾ��
			top();//����ջ��Ԫ��
		��С��أ�
			empty();//�ж�ջ�Ƿ�Ϊ��
			size();//����ջ�Ĵ�С
*/
void test01()
{
	stack<int> s;
	//��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	//��������
	stack<int> s1(s);
	cout << "sջ��Ԫ�أ�" << s.top() << endl;//30
	cout << "sջ�Ĵ�С��" << s.size() << endl;//3
	cout << "sջ�Ƿ�Ϊ�գ�" << s.empty() << endl;//0
	//��ջ
	s.pop();//30
	s.pop();//20
	s.pop();//10
	cout << "sջ�Ƿ�Ϊ�գ�" << s.empty() << endl;//1
	//���s1�����
	cout << "s1ջ��Ԫ�أ�" << s1.top() << endl;//30
	cout << "s1ջ�Ĵ�С��" << s1.size() << endl;//3
	cout << "s1ջ�Ƿ�Ϊ�գ�" << s1.empty() << endl;//0
	//��ֵ=
	stack<int> s2;
	s2 = s1;
	cout << "s2ջ��Ԫ�أ�" << s2.top() << endl;//30
	cout << "s2ջ�Ĵ�С��" << s2.size() << endl;//3
	cout << "s2ջ�Ƿ�Ϊ�գ�" << s2.empty() << endl;//0
}
//˼������Ȼջֻ�ܷ���ջ��Ԫ�أ���ô��δ�ӡ��������վ�ڵ�Ԫ���أ�
//˼·��ͨ����ջ�����ı�ջ��Ԫ�أ��Ϳ��Է�������Ԫ�أ�ֱ��ջΪ�ս���
void test02()
{
	//forѭ����ʹ��size��Ϊ�߽�����
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	int size = s.size();//���ʹ��size��Ϊforѭ����������Ҫ��size��ֵ�õ�ѭ�����棬����ѭ�����е�s.size()ÿ�ζ������ڳ�ջ����
	for (int i = 0; i < size; i++)
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	//ʹ��while����ջ��Ϊ����Ϊѭ������
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
//дһ����ӡջ�ĺ���ģ��
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

//������ϰ������ƥ������
//����һ������()���ַ��������������п����ǲ�ƥ�䣬��Ҫ��д���������ж�ĳ���ַ����е������ǲ���ƥ��ģ�
//������ƥ�䣺abc(e(f)g(h)88)  ��ƥ�䣺)ab(cd(ef)  (ab)c(d)ef(   (a)bc)def(12(3) 
//˼·������ⲻ�ܰ��մ�ͳ˼·ȥ�����Ҫ����ջ�����ݽṹ�Ƚ�������ص�ȥ�����ջ�ں������úͶ�����������ʱ���õ�������֮����Ƕ�׹�ϵ��ǡ���������ŵ�Ƕ�׹�ϵ��
//��������������ַ��������������ţ�����ջ����һ�������ž��������ģ��ڶ��������ž��ǵڶ��㣬�Դ����ơ�
//���������ţ���Ҫ����ˣ���ʱ��Ҫ��������Ǹ���������ԣ�������ջ�����Ǹ�����ʱ��Ҫ��ջ���������ų�ջ�����ԡ�
//���ǣ���ջ����������Ե�ʱ��ջ�п����ǿյģ�����ǿյģ�ֱ�ӷ���flase�����������Գ�ջ��
//��ѭ�������󣬼��ջ�Ľ�������ջ�ǿյģ�˵�����������Ŷ�����ˣ��Ǿ�˵��ƥ�䡣����˵�����䵥�������ţ�˵����ƥ�䡣
bool isMatch(string str)
{
	stack<char> stk;//��������ŵ�ջ
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

//1.�������ŵ���Чƥ��
//����һ���ɴ����ţ������ţ�С���ź������ַ���ɵ��ַ������ж����������Ƿ�ɶԳ��֡�
//��������ϰ��������ֻ��Ҫ��������Ե�ʱ����ǰ�ж��Ƿ�Ϊͬ���͵�����
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
	stack<char> stk;//��������ŵ�ջ
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
				if (sameType(stk.top(),str[i]))//�������ж��Ƿ�Ϊͬ���͵�
				{
					stk.pop();//��Գ�ջ
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
	string s1 = "ab{c[d(12)],[(34)5]}";//ƥ��
	string s2 = "{abc[(de)f}gg]";//��ƥ��
	cout << "s1:" << isMatchMore(s1) << endl;
	cout << "s2:" << isMatchMore(s2) << endl;
}
/*
5 ����queue
	5.1���еĸ���
		������һ���Ƚ��ȳ������ݽṹ�����ж�ͷ�Ͷ�β����βֻ�ܽ�������ӣ���ͷֻ�ܳ����г��ӡ�����λ�õ�Ԫ���޷����ʡ�
		û�е�������û�б�����Ϊ�����������ȡ��ͨ���±���ʣ���ֻ�ܲ�����ͷ�Ͷ�β��
	5.2queue�ĳ��ú���
		���캯����
			queue<T> que;//�޲ι���
			queue<T> que(const queue& q);//��������
		��ֵ��
			queue& operator=(const queue& q);
		���ݴ�ȡ��
			push(ele);//���Ԫ�ص���β
			pop();//����ͷԪ��ɾ��
			back();//���ض�βԪ��
			front();//���ض�ͷԪ��
		��С��أ�
			empty();//�ж϶����Ƿ�Ϊ��
			size();//���ض��еĴ�С
*/

//��ӡ���еĺ���ģ��
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
	cout << "��ͷ��" << que.front() << endl;
	cout << "��β��" << que.back() << endl;
	que.pop();
	cout << "��ͷ��" << que.front() << endl;
	cout << "��β��" << que.back() << endl;
	cout << "��С��" << que.size() << endl;
	cout << "�Ƿ�Ϊ�գ�" << que.empty() << endl;
	printQueue(que);
}

//1.����ż������
vector<queue<int>> numType(queue<int>& que)
{
	queue<int> q1;//��������
	queue<int> q2;//ż������
	vector<queue<int>> v;
	while (!que.empty())
	{
		if (que.front()%2!=0)//����
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
	//�����鿴
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

//2.���˿���
void card(queue<int>& q)
{
	//�����ε���չʾȻ����ӣ�ż���ε��Ƴ�������ӣ�����չʾ
	bool b = true;
	while (!q.empty())
	{
		if (b)
		{
			cout << q.front() << " ";//�����Σ������Ȼ�����
			q.pop();
		}
		else
		{
			//����Ҫ����ӣ��ٳ��ӣ������ò������ֵ��
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
