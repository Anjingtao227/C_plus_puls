#include <iostream>
using namespace std;

/*
3.��ģ��
	3.1 ��ģ��
		���ã�����һ��ͨ���࣬���еĳ�Ա�����Ժͷ������õ����������Ϳ��Բ�����ָ������һ������ķ���������
		��ģ��ͺ���ģ�����Ҫ������ģ��û���Զ��Ƶ���ʹ�÷�ʽ��ֻ����ʽָ�����͵�����nkk
		�﷨��������ģ�����ƣ��������һ����ģ������������ʹ��template<typename T>����template<class T>
*/
//����һ����ģ�壬Person�࣬���������������䣬���������䶼ʹ�÷��ͱ�ʾ
template<class NameType,class AgeType=int> //����ķ���Ĭ��ֵ��int����
class Person
{
	NameType m_Name;
	AgeType m_Age;
public:
	Person(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}
	void show() { cout << "name:" << m_Name << "��age:"<<m_Age << endl; }
	//��дһ������ģ��
	void setValue(NameType name, AgeType age) { m_Name = name; m_Age = age; }
};
void test01()
{
	Person<string, int> p1("��߸", 3000);//ע�⣬��ģ��û���Զ��Ƶ����͵��÷���������ʽָ��
	Person<string, string> p2("�����", "��ǧ��");
	//ʹ�����䷺�͵�Ĭ��ֵ
	Person<string> p3("��ɮ", 30);
	p1.show();
	p2.show();
	p3.show();
	//ʹ�����еĺ���ģ���޸�����
	p1.setValue("����", 18);
	p2.setValue("����", "ʮ����");
	p1.show();
	p2.show();
}

/*
3.2 ��ģ���Ϻ���ģ���ʹ�ã�����ģ���������������ʹ�ã�
	��ģ��ʵ���������Ķ����������Σ��ݻ������ֲ�ͬ�ı仯��
		1�����ε�ʱ��ָ������Ķ������ͣ�����⣬�������Ȳ���
		2���������ģ�������ȡ��������һ��ģ�廯�������������
		3���������������ģ�廯���������
*/
//1�����ε�ʱ��ָ������Ķ�������
void show_01(Person<string, int>& p) { p.show(); }
//2���������ģ�������ȡ��������һ��ģ�廯
template<typename T1,typename T2>
void show_02(Person<T1, T2>& p)
{
	p.show();
	cout << "T1�������ǣ�" << typeid(T1).name() << endl;
	cout << "T2�������ǣ�" << typeid(T2).name() << endl;
}
//3���������������ģ�廯
template<typename T>
void show_03(T& p)
{
	p.show();
	cout << "T�������ǣ�" << typeid(T).name() << endl;
}
//��Ե������������дһ����Student
class Student
{
public:
	string m_Name;
	int m_Age;
	Student(string name,int age):m_Name(name),m_Age(age){}
	void show() { cout << "name:" << m_Name << "��age:" << m_Age << endl; }
};
void test02()
{
	Person<string, int> p1("����", 18);
	Person<string, string> p2("����", "ʮ��");
	//ʹ����������������д���
	//1�����ε�ʱ��ָ������Ķ�������
	show_01(p1); //Ҫ����봫��Person<string, int>���͵Ķ���
	//2���������ģ�������ȡ��������һ��ģ�廯
	show_02(p1);//���Դ���Person<string, int>���͵Ķ���
	show_02(p2);//Ҳ����Person<string, string>���͵Ķ���
	//3���������������ģ�廯
	Student s1("Tom", 15);
	show_03(p1);//���Դ���Person<string, int>���͵Ķ���
	show_03(p2);//Ҳ����Person<string, string>���͵Ķ���
	show_03(s1);//��������һ����Ķ����ˣ�����Person�ˣ�����Student
}
int main()
{
	//test01();
	test02();
	return 0;
}