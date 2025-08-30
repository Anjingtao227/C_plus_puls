#include<iostream>
using namespace std;

//����һ������Point
class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
		cout << x << "," << y << "�ڹ���" << endl;
	}
	Point(const Point& p)
	{
		this->x = p.x;
		this->y = p.y;
		cout << x << "," << y << "�ڿ�������" << endl;
	}
	int getX() { return x; }
	int getY() { return y; }
};
//�����circle�����а�����point��Ķ���
class Circle
{
	const double PI;
	double radius;
	Point center;//��Ƕ��������Բ��Բ��
public:
	Circle(double r, const Point& p) :PI(3.14), center(p)//ע������center(p�����õ��ǿ������캯��
	{
		radius = r;
		cout << "Circle�ڹ���" << endl;
	}
	Circle(const Circle& c) :PI(3.14), center(c.center)//�������캯�����﷨��ʽ
	{
		radius = c.radius;
		cout << "Circle�ڿ�������" << endl;
	}
};
void test01()
{
	Point p(20, 30);
	Circle c(10, p);
}
/*
�����Ĺ�����̣�
	���������к��ж����Ƕ���������������:
		1)������Ƕ���������˳�����ε�����Ƕ����Ĺ��캯�����߿������캯����ɹ���
		2��ִ��������Լ��Ĺ��캯��
*/
//���ж����Ƕ���������ࣺ��������
class Triangle//����
{
	//���ʣ���������Point�͵ı�����+
	// //��������Ҫ������,����๹���˳������������˳���й�
	Point point1;
	Point point2;
	Point point3;
public:
	//��һ�����캯��������������
	Triangle(const Point& p1, const Point& p2, const Point& p3):point1(p1), point2(p2), point3(p3)//��Ա��ʼ���б�
	{
		cout << "Tirangle�ڹ���" << endl;
	}
	//�ڶ������캯�����������꣬��Ҫ����
	Triangle(int a, int b, int c, int d, int e, int f):point1(a,b),point2(c,d),point3(e,f)
	{
		cout << "Triangle�ڹ���" << endl;
	}
	void show()
	{
		cout << "��һ���㣺" << point1.getX() << "," << point1.getY() << endl;
		cout << "�ڶ����㣺" << point2.getX() << "," << point2.getY() << endl;
		cout << "�������㣺" << point3.getX() << "," << point3.getY() << endl;
	}
};
void test02()
{
	Triangle t1(20, 30, 40, 50, 60, 70);
	t1.show();
	Point p1(1, 2);
	Point p2(2, 3);
	Point p3(3, 4);
	Triangle t2(p1, p2, p3);
	t2.show();
}
//����һ��child��
class Child
{
	//����һ����̬����
	static int count;//����ͳ�Ƹ���ʵ�����Ķ���ĸ���
	//��������ͨ���ԣ�ÿ���������Լ������Ŀ���
	int number;//ѧ��
	char name[20];//����
	int age;//����
public:
	Child(const char* n, int a)//�����ʱ�򣬲�����ѧ�Ų���������ͨ�������ķ�ʽ����һ��ѧ��
	{
		//ÿ����һ�ι��캯��������ͳ����������+1
		count++;
		number = 2025100 + count;
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
	}
	int getNumber() { return number; }
	char* getName() { return name; }
	int getAge() { return age; }
	int getCount() { return count; }
	//���һ����̬�������������ʾ�̬����
	static int getStaticCount() 
	{
		return count; 
		//��̬�������ܷ�����ͨ��Ա
		//cout << number << endl;
		//getAge();

	}
//���һ��������
	void show() const
	{
		cout << "ִ�г���Ա����show() const" << endl;
		cout << number << "��" << name << "��" << count << endl;//���������Է�����ͨ���Ժ;�̬����
		//getNumber();//�ɼ����������ܵ��ó�����
		getStaticCount();//�ɼ����������Ե��þ�̬����
	}
};
//�������ʼ����̬����
int Child::count = 0;
void test03()
{
	Child c1("����", 7);
	Child c2("����", 6);
	Child c3("����", 8);
	Child c4("���", 14);
	Child c5("���", 19);
	cout << c1.getNumber() << "��" << c1.getName() << "��" << c1.getAge() << "��" << c1.getCount() << endl;
	cout << c2.getNumber() << "��" << c2.getName() << "��" << c2.getAge() << "��" << c2.getCount() << endl;
	cout << c3.getNumber() << "��" << c3.getName() << "��" << c3.getAge() << "��" << c3.getCount() << endl;
	cout << c4.getNumber() << "��" << c4.getName() << "��" << c4.getAge() << "��" << c4.getCount() << endl;
	cout << c5.getNumber() << "��" << c5.getName() << "��" << c5.getAge() << "��" << c5.getCount() << endl;
	//���ʾ�̬����
	cout << c1.getCount() << endl;//��ͨ������Ե��þ�̬����
	cout << Child::getStaticCount() << endl;//����Ҳ���Է��ʾ�̬����
	//������ͳ�����
	const Child const_c("����", 6);
	const_c.show();//������Ӧ�õ��ó�����
	const_c.getStaticCount();//������Ҳ���Ե��þ�̬����
	//const_c.getName();//�ɼ��������ܵ�����ͨ����
	c1.show();//��ͨ������Ե��ó�����
}
//��ʾ����������ͨ����������
class Data
{
	int value;
public:
		Data(int v):value(v){}//��ͨ���캯��
		//��ͨ��Ա���������ڻ�ȡvalueֵ
		int& getValue() 
		{
			cout << "������ͨ����" << endl;
			return value; 
		}
		//����Ա����
		const int& getValue() const 
		{ 
			cout << "���ó�����" << endl;
			return value; 
		}

};
void test04()
{
	Data d(10);
	cout << d.getValue() << endl;//������ͨ����

	const Data const_d(20);
	cout << const_d.getValue() << endl;//���ó�����

}
void test05()//��������
{
	Child c[3] = { Child("����",7),Child("����",6),Child("����",6) };
	c[0].show();
	c[1].show();
	c[2].show();

}
void test06()//����ָ��
{
	Child* pchild;
	Child c1("lucy", 10);
	pchild = &c1;
	pchild->show();
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}