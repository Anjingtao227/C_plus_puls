#include <iostream>
using namespace std;

//���嶯����Animal������������������
//����������Cat���̳и���Animal�����Ժͷ���
//����Dog�࣬�̳�Animal�����Ժͷ������������Լ������Ժͷ��������ԣ�Ʒ�֣�����������
class Animal
{
	char m_cName[20];
	int m_nAge;
public:
	Animal(const char* name, int nAge)
	{
		strcpy_s(m_cName, strlen(name) + 1, name);
		m_nAge = nAge;
		cout << "animal�ڹ���" << endl;
	}
	~Animal()
	{
		cout << "animal������" << endl;
	}
	void running()
	{
		cout << m_cName << "������" << endl;
	}
	void barking()
	{
		cout << m_cName << "���ڽ�" << endl;
	}
	char* getName()
	{
		return m_cName;
	}
};

//����Cat
class Cat :public Animal
{
	//����̳и����ʱ����Ҫ�������е��ø���Ĺ��캯��������ɸ���Ĺ��죬Ȼ��ſ��Լ̳�
public:
	Cat(const char* name, int nAge) :Animal(name, nAge)
	{
		cout << "cat�ڹ���" << endl;
	}
	~Cat()
	{
		cout << "cat������" << endl;
	}
};
//����dog
class Dog :public Animal
{
	char m_cType[20];
public:
	Dog(const char* name, int nAge, const char* type) :Animal(name, nAge)
	{
		strcpy_s(m_cType, strlen(type) + 1, type);
		cout << "dog�ڹ���" << endl;
	}
	~Dog()
	{
		cout << "dog������" << endl;
	}
	void lookingHouse()
	{
		cout << getName() << "���ڿ���" << endl;
	}
	//���������ػ򷽷����ض���
	//�������ж���͸�������ȫͬ���ķ������Ϳ������θ����еķ������Ӷ����������Լ��ķ���
	void barking()
	{
		cout << m_cType << getName() << "������������" << endl;
		//cout << m_cName << endl;	//���಻���Է��ʸ�����˽�г�Ա���������
	}
};
//�����̳У�Pig��
class Pig :protected Animal
{
public:
	Pig(const char* name, int nAge) : Animal(name, nAge) { cout << "Pig�ڹ���" << endl; }
	~Pig() { cout << "Pig������" << endl; }
	void show() { running(); }
};
void test01()
{
	Animal a1("����", 5);
	a1.running();
	a1.barking();
	cout << a1.getName() << endl;
	Cat c1("����è", 3);
	c1.running();
	c1.barking();
	Dog d1("���", 4, "�»�");
	d1.running();
	d1.barking();	//���������˸����ͬ�������������Լ��ķ���
	d1.lookingHouse();		//Dog����еģ�����û�е�
}
void test02()
{
	Pig p1("������", 5);
	//���������⣬�ܲ���������ʹ��p1�������running���������ǲ��ܣ���ΪPig���Animal��running������Pig�оͱ���˱���Ȩ��
	//p1��running������//����Ȩ���������ǲ��ܷ��ʵ�
 }

//����Ȩ��ָ���ǲ��ܱ�������ʣ����ǿ��Ա��������������
//��дһ�����ӱ����࣬Ұ���࣬�����м̳�Pig��
class Yezhu :public Pig
{
public:
	Yezhu(const char* name, int nAge) :Pig(name, nAge){cout << "Yezhu�ڹ���" << endl; }
	~Yezhu() { cout << "Yezhu������" << endl; }
	void show() { running(); }//running������Animal�ģ����Ǳ�Pig�����̳��ˣ��������൱��Pig�еı������������Կ��Ը�Pig������YeZhuʹ��
};
void test03()
{
	Yezhu yezhu("Ұ��", 6);
	yezhu.show();
	//yezhu.running();//��Ϊrunning�Ǳ�����Ա�����ⲻ��ʹ��
}

//˽�м̳У�����
class bird :private Animal
{
public:
	bird(const char* name, int nAge) :Animal(name, nAge) { cout << "bird�ڹ���" << endl; }
	~bird() { cout << "bird������" << endl; }
	void show() { running(); }//running��Ȼ�Ǹ��๫�г�Ա���������������࣬���˿��Ե���
};
//��������ࣺ������
class yingwu :public bird
{
public:
	yingwu(const char* name, int nAge) :bird(name, nAge) { cout << "yingwu�ڹ���" << endl; }
	~yingwu() { cout << "yingwu������" << endl; }
	void show(){
	//running��Ȼ��Animal���г�Ա�����Ǳ�bird˽�м̳У���������bord������˽�г�Ա�ˣ�������Ϊbird�����࣬��Ȼ�޷���Χ
	cout << "����һֻ����" << endl;
	}
};
void test04()
{
	yingwu y1("����", 3);
	//
	y1.show();
}
//��ʾһ����̳�
class BaseA
{
	int m_a;
	int m_b;
public:
	BaseA(int a, int b) :m_a(a), m_b(b)
	{
		cout << "BaseA�ڹ���" << endl;
	}
	~BaseA() { cout << "BaseA������" << endl; }
};
class BaseB
{
	int m_a;
	int m_b;
public:
	BaseB(int a, int b) :m_a(a), m_b(b)
	{
		cout << "BaseB�ڹ���" << endl;
	}
	~BaseB() { cout << "BaseB������" << endl; }
};
//���࣬�̳�����������
class C :public BaseA, public BaseB
{
	int m_c;
public:
	C(int a, int b, int c, int d, int e) :BaseA(a, b), BaseB(c, d)
	{
		m_c = e;
		cout << "C�ڹ���" << endl;
	}
	~C() { cout << "C������" << endl; }
};
void test05()
{
	C c(1, 2, 3, 4, 5);
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	return 0;
}
