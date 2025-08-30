#include <set>
#include <iostream>
#include <functional>
using namespace std;

/*
7 ����set/multiset
	7.1��������
		set�������ϣ������ص������е�Ԫ�ػ��ڲ����ʱ���Զ��������Ĭ�����򣩡�
		set������ռ���Ҳ���������ģ�����Ҳ��֧�������ȡ���±�ȡֵ�������ĵ�����Ҳ��֧��ָ�����㣬ֻ��++����--
		set�ĵײ����ݽṹ�Ǻ������
		set��multiset������
			set���������ظ���Ԫ��
			multiset�������ظ���Ԫ��
			����֮�⣬���ǵĳ�Ա����������һ���ġ�
		�����ǻ��ں����ʵ�ֵģ��������ɾ��Ԫ�أ����ǽ�ֹ�޸�Ԫ�أ���Ϊ�޸Ļᵼ�����Ľṹ�����ı䣬���º����������ṹ���ƻ���
		����set��Ԫ�ض���const�ģ�set�ĵ�����Ҳ��const�ģ�set���õĺ���Ҳ�ǳ�������
	7.2set���졢���롢��ֵ��ɾ��
		���죺
			set<T> st;
			set(const set& st);
			set<T,�º���> st;//ͨ���º�����ָ���������Ĭ��������
		��ֵ��
			���ظ�ֵԤ���=
		���롢ɾ����
			insert(ele);//�������в���Ԫ��
			clear();
			erase(pos);//ɾ��pos������ָ���Ԫ�أ�������һ��Ԫ�صĵ�����
			erase(beg,end);//ɾ������[beg,end)�ڵ�Ԫ�أ�������һ��������
			erase(ele);//ɾ�������е�eleԪ��
	7.3set��С�ͽ���
		size();
		empty();
		swap(st);
*/

//��ӡset�ĺ���ģ��
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
	//���������ֵ
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);
	printSet(s1);//���Զ���������

	set<int> s2(s1);
	printSet(s2);

	set<int> s3;
	s3 = s2;
	printSet(s3);

	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);//�������������÷�
	printSet(s1);
	cout << "s1�Ĵ�С��" << s1.size() << endl;
	s1.swap(s2);
	cout << "����֮��" << endl;
	cout << "s1:";
	printSet(s1);
	cout << "s2:";
	printSet(s2);
	s1.erase(s1.begin(), s1.end());
	cout << s1.empty() << endl;
}

/*
7.4set���Һ�ͳ��
		find(ele);//�ҵ����ص�����λ�ã��Ҳ�������end������
		count(ele);//ͳ��eleԪ�صĸ���������set��˵��ֻ����0����1
	multiset�ĳ�Ա������setһ���������������Ԫ�ؿ����ظ���
*/
void test02()
{
	set<int> s1;
	//���������ֵ
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);
	printSet(s1);//���Զ���������

	set<int>::iterator pos = s1.find(30);
	if (pos!=s1.end())
	{
		cout << "�ҵ��ˣ�" << *pos << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
	cout << s1.count(30) << endl;//1
	cout << s1.count(50) << endl;//0
}

//������ʧЧ���⣬ֻ��ɾ�������ᵼ�µ�ǰ������ʧЧ����Ҫ���µ�������������������Ҫ
void test03()
{
	//�����������Ҫ���µ�����
	set<int> s = { 2,3,5,6 };
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		if (*it==2)
		{
			s.insert(0);
		}
	}
	printSet(s);

	//ɾ��������Ҫ���µ�����
	for (set<int>::iterator it = s.begin(); it != s.end(); )
	{
		if (*it == 2)
		{
			it = s.erase(it);//���µ�����
		}
		else
		{
			it++;
		}
	}
	printSet(s);
}

//multiset����Ԫ���ظ�
void test04()
{
	multiset<int> ms;
	ms.insert(30);
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	for (auto ele : ms) { cout << ele << " "; }
	cout << endl;
	cout << "30�ĸ���:" << ms.count(30) << endl;//2
}

/*
7.5�º�������������
		�º���������һ������󣬲��Ǻ������������ڲ������������()��ʹ������������
		ʹ�÷º��������Ե�������ȥָ����������������������Զ������͵����ݣ�����Ҫ��set��ʼ����ʱ���ָ��������򣬷����޷�����Ԫ�ء�
		����ֵ��bool���͵ķº���������ν�ʡ�
		���õķº�����ͨ������ͷ�ļ�#include <functional>
			��ϵ�º�����
				equal_to ����
				not_equal_to ������
				greater ����
				greater_equal ���ڵ���
				less С��
				less_equal С�ڵ���
			�����º�����
				plus �ӷ�
				minus ����
				multiplies �˷�
				divides ����
				negate ȡ��
			�߼��º���
				logical_and �߼���
				logical_or �߼���
				logical_not �߼���
*/

//���÷º���ʵ��set<int>��������
class MyCompare
{
	//����()�����
public:
	bool operator()(int v1, int v2) const //Ҫ����Ϊ����������Ϊset��ֹ�޸�Ԫ�أ����ڳ�����
	{
		return v1 > v2;
	}
};
void test05()
{
	set<int, MyCompare> s1;//�����˽�������ļ���
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	s1.insert(10);
	for (auto ele : s1) { cout << ele << " "; }
	cout << endl;

	//ʹ��ϵͳ�ṩ�ķº���greaterʵ�ֽ��򼯺ϣ�ע��greater�Ǻ���ģ��
	set<int, greater<int>> s2;
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);
	s2.insert(10);
	for (auto ele : s2) { cout << ele << " "; }
	cout << endl;
}

//������ϰ��ʹ��set���ϱ�����Person(m_Name,m_Age),ָ��������򣺰������併��
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name, int age) :m_Name(name), m_Age(age) {}
};
//�º���ʵ�����併��
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

//1.��֪����set���ϣ��ϲ���һ�����ϣ�ȥ���ظ�Ԫ��
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
//��ҵ��2.��֪����set<int>����s1��s2���ϲ���һ�����ϣ���������Ԫ�أ�������������
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

