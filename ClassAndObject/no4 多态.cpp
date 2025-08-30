#include <iostream>
using namespace std;

class Person//����
{
public:
	virtual void buyTicket() { cout << "��ͨ����Ҫȫ������Ʊ" << endl; }
};
class Student :public Person//������
{
public:
	virtual void buyTicket() { cout << "ѧ�����԰����Ʊ" << endl; }//�����п���дvirtualҲ���Բ�д������Ӱ������ִ�У�����д�ϣ���
};
class Child :public Person//������
{
public:
	void buyTicket() { cout << "6�����¶�ͯ������Ʊ" << endl; }
};
void test01()
{
	Person p1;
	p1.buyTicket();
	Student s1;
	s1.buyTicket();
	Child c1;
	c1.buyTicket();
}

void test02()
{
	//�����������ࣨ���ָࣩ��
	Person* p[3];
	Person p1;
	Student s1;
	Child c1;
	p[0] = &p1;//����ָ��ָ����p1�������
	p[1] = &s1;//����ָ��ָ����s1�������
	p[2] = &c1;//����ָ��ָ����c1�������
	//����ָ��
	p[0]->buyTicket();
	p[1]->buyTicket();
	p[2]->buyTicket();
	//ԭ����Ϊָ��p[i]����Ϊ����ָ�룬�ڱ���ʱֻ�ܰѸ���ָ��ָ��Ķ��������������Ϊ��������������ָ������������������Щ���������������Ͳ���֪������ķ�����
	//���ϣ��ͨ������ָ���ܷ�������İ취���Ǿ���Ҫʹ���麯����
}
/*
�麯���ĸ�ʽ��
	virtual �������� ��������������{�����壻}
	������ϣ����Ʊ��������ʹ�ø���ָ�붯̬���õ�ʱ�򣬿��Խ���Ʊ��������Ϊ�麯��,�麯����Ҫʵ�ָ���ĺ�����
*/
class Employee
{
	char* name = NULL;
	int age;
public:
	Employee(const char* n, int a)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
	}
	~Employee()
	{
		cout << "ִ��Employee������" << endl;
		if (name != NULL)
		{
			delete[]name;
			name = NULL;
		}
	}
};
class Teacher :public Employee
{
	char* m_course = NULL;//��ʦ�����Լ������ԣ��γ�
public:
	Teacher(const char* n, int a, const char* c) :Employee(n, a)
	{
		m_course = new char[strlen(c) + 1];
		strcpy_s(m_course, strlen(c) + 1, c);
	}
	~Teacher()
	{
		cout << "ִ��Teacher������" << endl;
		if (m_course != NULL)
		{
			delete[]m_course;
			m_course = NULL;
		}
	}

};
void test03()
{
	Employee* p[2];
	p[0] = new Employee("ĳԱ��", 30);
	p[1] = new Teacher("����ʦ", 39,"C++ϵ�пγ�");
	//����������������ʱ����Ҫ���գ���Ϊ�����������ڶ��ڴ洴��
	delete p[0];
	delete p[1];
	//�������Employeede���������������麯���Ļ�����ôTeacher�����������Ͳ�����ã����m_course����ڴ�ռ��޷��ͷ�
	//���������������ǰ�����virtual����ʵ�����������Ķ�̬����ʱp[1]ָ����Ȼ�Ǹ���ָ�룬����ָ�������࣬���Ի�����������������������ڴ��ͷš�
	//ע�⣺��������������ֻ���ڶ��ϴ����������û���ָ���������ʱ�򣬲������ֳ����������������ջ�ϴ����ģ���������ع���ջ�ڴ棬�����������������������
}


//����һ�����д��麯���ĳ�����
class Abs
{
public:
	virtual void say() = 0;//���麯��û�з����壬�ŵ���������ʵ�֣������൱��һ���ӿڡ�

};
//���������࣬ʵ�ֻ����еĴ��麯��
class Some :public Abs
{
public:
	virtual void say() { cout << "Some One Say" << endl; }
};
//�ٶ���һ�������࣬ʵ�ֻ����еĴ��麯��
class Other :public Abs
{
public:
	virtual void say() { cout << "Other One Say" << endl; }
};

void test04()
{
	Abs* abs_p[2];
	//Abs abs1;//�������޷�ʵ��������
	Some some1;
	Other other1;
	abs_p[0] = &some1;
	abs_p[1] = &other1;
	abs_p[0]->say();
	abs_p[1] ->say();
}
int main()
{
	//test01();
	//test02();
	//test03();
	test04();

	return 0;
}