#include <iostream>
using namespace std;

class Person//基类
{
public:
	virtual void buyTicket() { cout << "普通人需要全价来买票" << endl; }
};
class Student :public Person//派生类
{
public:
	virtual void buyTicket() { cout << "学生可以半价买票" << endl; }//子类中可以写virtual也可以不写，都不影响程序的执行（建议写上）。
};
class Child :public Person//派生类
{
public:
	void buyTicket() { cout << "6岁以下儿童可以免票" << endl; }
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
	//定义三个父类（基类）指针
	Person* p[3];
	Person p1;
	Student s1;
	Child c1;
	p[0] = &p1;//父类指针指向了p1这个对象
	p[1] = &s1;//父类指针指向了s1这个对象
	p[2] = &c1;//父类指针指向了c1这个对象
	//父类指针
	p[0]->buyTicket();
	p[1]->buyTicket();
	p[2]->buyTicket();
	//原因：因为指针p[i]定义为父类指针，在编译时只能把父类指针指向的对象当作父类对象。因为编译器仅仅根据指针类型来决定调用那些方法，而父类类型并不知道子类的方法。
	//如果希望通过父类指针能访问子类的办法，那就需要使用虚函数。
}
/*
虚函数的格式：
	virtual 函数类型 函数名（参数表）{函数体；}
	当我们希望买票方法可以使用父类指针动态调用的时候，可以将买票方法定义为虚函数,虚函数需要实现父类的函数。
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
		cout << "执行Employee的析构" << endl;
		if (name != NULL)
		{
			delete[]name;
			name = NULL;
		}
	}
};
class Teacher :public Employee
{
	char* m_course = NULL;//教师类有自己是属性：课程
public:
	Teacher(const char* n, int a, const char* c) :Employee(n, a)
	{
		m_course = new char[strlen(c) + 1];
		strcpy_s(m_course, strlen(c) + 1, c);
	}
	~Teacher()
	{
		cout << "执行Teacher的析构" << endl;
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
	p[0] = new Employee("某员工", 30);
	p[1] = new Teacher("张老师", 39,"C++系列课程");
	//用完以上两个对象时，需要回收，因为两个对象是在堆内存创建
	delete p[0];
	delete p[1];
	//如果父类Employeede的析构函数不是虚函数的话，那么Teacher的析构函数就不会调用，造成m_course这个内存空间无法释放
	//讲父类的析构函数前面加上virtual即可实现析构函数的多态，此时p[1]指针虽然是父类指针，但是指向了子类，所以会调用子类的析构函数，完成内存释放。
	//注意：析构函数的作用只有在对上创建对象并且用基类指针来管理的时候，才能体现出来。如果对象是在栈上创建的，则编译器回管理栈内存，会调用这个对象的析构函数。
}


//定义一个含有纯虚函数的抽象类
class Abs
{
public:
	virtual void say() = 0;//纯虚函数没有方法体，放到派生类中实现，这里相当于一个接口。

};
//定义派生类，实现基类中的纯虚函数
class Some :public Abs
{
public:
	virtual void say() { cout << "Some One Say" << endl; }
};
//再定义一个派生类，实现基类中的纯虚函数
class Other :public Abs
{
public:
	virtual void say() { cout << "Other One Say" << endl; }
};

void test04()
{
	Abs* abs_p[2];
	//Abs abs1;//抽象类无法实例化对象
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