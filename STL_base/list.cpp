#include <list>
#include <iostream>
using namespace std;

/*
6 ����list
	6.1�������
		������һ�������ϲ������Ĵ洢�ṹ����֧�������ȡ��ͨ���±�ȡֵ�������ݵ�Ԫ���߼�˳����ͨ�������е�ָ������ʵ�ֵġ�
		�������ɵ�Ԫ����㣬��������������ֹ��ɣ��������ָ����
		STL�е�list������һ��˫�������������򣬿�ǰ�ɺ�
		����list���е�������֧�ֱ��������ǵ�����ֻ�ܵ���λ�ƣ�ÿ��ֻ����ǰ������ƶ�һλ����֧��ָ�����㡣
		������ص㣺
			�ŵ㣺
				���������ŵ��ǲ����ɾ������ʮ�ָ�Ч���޸�ָ�뼴�ɣ�����Ҫ�����ƶ�Ԫ�ء�ͬ��������ɵ�������ʧЧ��
				����Ҳ�Ƕ�̬�ڴ����ģ���������ڴ��˷�Ҳ�������ڴ������
			ȱ�㣺
				����Ԫ��Ч��̫��
	6.2list����
		list<T> lst;
		list<T> lst(beg,end);//��[beg,end)�����Ԫ�ؿ�������ǰҪ�����list��beg��end�ǵ�����
		list(n,ele);//n��eleԪ�ع��쵱ǰlist
		list(const list& lst);//��������
*/
//��ӡlist�ĺ���ģ��
//ʹ��for��Χ������������������
template<typename T>
void printList(list<T>& L)
{
	for (auto ele : L) { cout << ele << " "; }
	cout << endl;
}

void test01()
{
	//����
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
	6.3list��ֵ�ͽ���
		��ֵ���������=
		assign(beg,end);//��[beg,end)�����Ԫ�ظ�ֵ����ǰlist
		assign(n,ele);//��n��eleԪ�ظ�ֵ����ǰlist
		swap(lst);//����list�����ڲ���Ԫ��
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

	cout << "����L1��L4��" << endl;
	L1.swap(L4);
	cout << "L1=";
	printList(L1);
	cout << "L4=";
	printList(L4);
}

/*
6.4list��С���
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
	6.5list�����ɾ��
		push_back(ele);
		pop_back();
		push_front(ele);
		pop_front();
		insert(pos,ele);//��posָ����λ�ò���eleԪ�أ����ز���Ԫ�ص�λ�õ�����
		insert(pos,n,ele);//��posָ����λ�ò���n��eleԪ��
		insert(pos,beg,end);//��posָ����λ�ò���[beg,end)֮���Ԫ��
		clear();
		erase(pos);//ɾ��posλ�õ�Ԫ�أ�������һ��λ��
		erase(beg,end);//ɾ��[beg,end)֮���Ԫ�أ�������һ��λ��
		remove(ele);//ɾ��list�����е�eleԪ�أ�ele�п����ظ���
	6.6list���ݴ�ȡ
		front();//ȡͷ����һ��Ԫ��
		back();//ȡ���һ��Ԫ��
*/
void test04()
{
	list<int> L;
	L.push_back(10);//β������
	L.push_back(20);
	L.push_back(30);
	L.push_front(100);//ͷ������
	L.push_front(200);
	L.push_front(300);
	cout << "L:";
	printList(L);

	//����
	L.pop_back();//����30
	L.pop_front();//������300
	cout << "����ͷβ���ˣ�";
	printList(L);

	L.insert(++L.begin(), 1000);//ע�⣬list��������֧��+����-���������֧��++����--��ע��++д��ǰ�棬��������ȡֵ
	cout << "�ڵڶ���λ�ò���1000:";
	printList(L);

	L.erase(++L.begin());
	cout << "ɾ���ڶ���λ�õ�ֵ��";
	printList(L);

	L.insert(L.begin(), 3, 0);
	cout << "�ڵ�һ��λ�ò���3��0��";
	printList(L);

	list<int> L1;
	L1.assign(5, 8);
	cout << "L1:";
	printList(L1);
	L1.insert(L1.begin(), L.begin(), L.end());
	cout << "��L1��ͷλ�ò���Lȫ����ֵ��";
	printList(L1);

	//remove(ele);//ɾ��list�����е�eleԪ�أ�ele�п����ظ���
	L.remove(0);
	cout << "ɾ�����е�0֮��L��";
	printList(L);

	//���ݴ�ȡ
	cout << "L��Ԫ�أ�";
	cout << L.front() << endl;
	cout << "LβԪ�أ�";
	cout << L.back() << endl;
	L.clear();
	cout << L.size() << endl;//0
}
//���ڵ�����ʧЧ����
//list�����������Ƿ�ɢ�洢�ġ����Բ����ɾ��������������ڵ����Ӱ�졣���Բ����Ľڵ��Լ���˵��ɾ��������Ȼ�ᵼ�µ�ǰ������ʧЧ����Ȼ��Ҫ���µ�������
//������������ᵼ���κε�����ʧЧ������Ҫ���µ�������
void test05()
{
	list<int> ls = { 5,2,8,2 };
	for (list<int>::iterator it = ls.begin(); it != ls.end(); it++)
	{
		if (*it==2)
		{
			ls.insert(it, 0);//���벻��Ҫ���µ�����
		}
	}
	cout << "����֮��ls:" << endl;
	printList(ls);
}
//ɾ�������ᵼ�µ�ǰλ�õ�����ʧЧ����Ҫ���µ�����
void test06()
{
	list<int> ls = { 5,2,8,2 };
	for (list<int>::iterator it = ls.begin(); it != ls.end(); )
	{
		if (*it == 2)
		{
			it=ls.erase(it);//ɾ��������Ҫ���µ�ǰ������
		}
		else
		{
			it++;
		}
	}
	cout << "ɾ��֮��ls:" << endl;
	printList(ls);
}

/*
	6.7list��ת������
		reverse();//��ת����ע�����ﲻ���㷨
		sort();//�������򣬲����㷨sort()����Ϊ�㷨�е�����sort��֧��list������list�Լ�������һ����������
		sort(func);//��func��������
		//ע�⣺�����Զ������͵����ݣ���list�����򣬱����ֶ�ָ��������򣬷���sort������֪���������
*/
//����������
bool myCompare(int v1, int v2) { return v1 > v2; }
void test07()
{
	list<int> L = { 8,5,9,3 };
	printList(L);
	//����
	L.reverse();//��ת
	printList(L);
	L.sort();//����
	printList(L);
	
	//ͨ������������ָ���������ʵ�ֽ���
	L.sort(myCompare);
	printList(L);
}

//������ҵ��ʹ��list�洢��������Person(m_Name,m_Age),Ȼ������������򣺰�����������������������ͬ�������������н�������
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//������
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
		cout << "������" << it->m_Name << ",���䣺" << it->m_Age << endl;
	}
}

//��ҵ��ȥ�����ϸ���ֻ�����
//�ؼ��ǶԹ����ʵ�֣�11λ���֣�������1��ͷ����ϸ�
//�����ж��Ƿ�������
bool every_is_num(string& str)
{
	//����ж�һ���ַ����е�ÿ���ַ����������ַ��أ�ͨ��ASCII�����жϡ������ַ�0-9֮���ASCII�뷶Χ��48-57
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
//��д�����������������ж�
bool isMeet(string& str)
{
	if (!every_is_num(str))//���ж��Ƿ�������
	{
		return false;
	}
	if (str.size()!=11)//���ж��Ƿ�11λ
	{
		return false;
	}
	if (str[0]!='1')//���ж��Ƿ���1��ͷ
	{
		return false;
	}
	return true;
}
//ȥ�����ϸ����ĺ���
void del_bad_num(list<string>& ls)
{
	for (list<string>::iterator it = ls.begin(); it != ls.end(); )
	{
		if (!isMeet(*it))
		{
			it = ls.erase(it);//��Ҫ���µ�����
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
	tel.push_back("18677889999");//�ϸ�
	tel.push_back("1867788999");//��һλ�����ϸ�
	tel.push_back("186778899a");//��ȫ�����֣����ϸ�
	tel.push_back("0867788999");//������1��ͷ�����ϸ�
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

