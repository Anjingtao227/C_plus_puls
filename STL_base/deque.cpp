#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

/*
3 deque˫�˶���
	3.1����
		dequeȫ����double-ended-queue,Ҳ��˫�����飬���Զ����˽��в���
		vector��deque������
			vector�ǵ��򿪿ڵ������ռ䣬deque��˫�򿪿ڵ������ռ䣬���Ը�Ч����ͷβ������Ԫ�صĲ����ɾ����������Ȼ������м�insert������Ч����Ȼ�ǵ͵ġ�
			dequeû������capacity�ĸ�������Էֶε������ռ���϶��ɵģ���ʱ��������һ���µĿռ�������������������vector������Ϊ�ռ䲻�㣬��������һ��ռ�Ĳ�����
		dequeͨ���ڲ����п�����ά����Щ�ֶε������ռ䡣�п���ά��ÿ�������ռ�ĵ�ַ��ʹ��������������
		deque�ĳ�Ա������vector����һ��������׸����

	3.2 deque���캯��
		����ԭ�ͣ�
		deque<T> deq; //Ĭ�Ϲ�����ʽ
		deque(beg, end); //������deque[beg, end)�����е�Ԫ�ؿ�����
		deque(n, ele); //��n��ele������
		deque(const deque &deq); //�������캯��
*/
//��ӡ����
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
3.3 deque��ֵ����
		����ԭ�ͣ�
		deque& operator=(const deque &deq); //���ظ�ֵ�����
		assign(beg, end); //������deque[beg, end)�����е����ݸ�ֵ
		assign(n, elem); //��n��elem��ֵ
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
3.4 deque��С����
		����ԭ�ͣ�
		empty(); //�ж������Ƿ�Ϊ��
		size(); //����������Ԫ�صĸ���
		resize(num); //����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ��
		���������ȵ�Ԫ�ر�ɾ����
		resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ�á����������̣���
		ĩβ�����������ȵ�Ԫ�ر�ɾ����
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
3.5 deque �����ɾ��
		����ԭ�ͣ�
		���˲��������
		push_back(elem); //������β�����һ������
		push_front(elem); //������ͷ������һ������
		pop_back(); //ɾ���������һ������
		pop_front(); //ɾ��������һ������
		ָ��λ�ò�����
		insert(pos,elem); //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
		insert(pos,n,elem); //��posλ�ò���n��elem���ݣ����������ݵ�λ�á�
		insert(pos,beg,end); //��posλ�ò�����һ��deque[beg,end)��������ݣ����������ݵ�λ�á�
		erase(beg,end); //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
		erase(pos); //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
		clear(); //�����������������
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
	3.6 deque ���ݴ�ȡ
		����ԭ�ͣ�
		at(int idx); //��������idx��ָ������
		operator[]; //�����±�������ָ������
		front(); //���������е�һ������Ԫ��
		back(); //

	3.7 deque Ԫ�ػ���swap

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

//1.����Ԫ��:���庯��������deque��ָ������Ԫ�ص��½ű꣬���������½ű���ɵ���deque���顣
deque<int> findIndex(deque<int>& d, int val)
{
	deque<int> newd;//�����½Ǳ��deque
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		if (*it==val)
		{
			newd.push_back(it - d.begin());//���������±�
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

//2. ��ί���
//ѡ����
class Person
{
public:
	string m_Name;
	int m_Score;//ƽ����
	Person(string name,int score):m_Name(name),m_Score(score){}
};
//��ֺ���
void addScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//�����֣�ȡֵ��Χ��60-100֮��������
			d.push_back(score);
		}
		cout << it->m_Name << "��������" << endl;
		for (int i = 0; i < d.size(); i++)
		{
			cout << d[i] << " ";
		}
		cout << endl;
		//����
		sort(d.begin(), d.end());
		//ȥ����ͷֺ���߷�
		d.pop_back();
		d.pop_front();
		//����ƽ����
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
		cout << v[i].m_Name << " ƽ���֣�" << v[i].m_Score << endl;
	}
}
void test07()
{
	//Ϊ�˱����������ÿ�����ɵ�һ��������Ӧ���޸�������ӣ��Ƚϼ򵥵ķ�����ֱ��ʹ�õ�ǰϵͳʱ����Ϊ������ӣ���Ҫͷ�ļ�#include <time.h>
	srand((unsigned int)time(NULL));
	//1.�������ѡ��,ƽ�ֳַ�ʼ��Ϊ0
	Person p1("ѡ��A", 0);
	Person p2("ѡ��B", 0);
	Person p3("ѡ��C", 0);
	Person p4("ѡ��D", 0);
	Person p5("ѡ��E", 0);
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

