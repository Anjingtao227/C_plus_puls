#include <iostream>
using namespace std;

//定义动物类Animal，属性有姓名、年龄
//定义派生类Cat，继承父类Animal的属性和方法
//定义Dog类，继承Animal的属性和方法，并新增自己的属性和方法，属性：品种，方法：看家
class Animal
{
	char m_cName[20];
	int m_nAge;
public:
	Animal(const char* name, int nAge)
	{
		strcpy_s(m_cName, strlen(name) + 1, name);
		m_nAge = nAge;
		cout << "animal在构造" << endl;
	}
	~Animal()
	{
		cout << "animal在析构" << endl;
	}
	void running()
	{
		cout << m_cName << "正在跑" << endl;
	}
	void barking()
	{
		cout << m_cName << "正在叫" << endl;
	}
	char* getName()
	{
		return m_cName;
	}
};

//子类Cat
class Cat :public Animal
{
	//子类继承父类的时候，需要在子类中调用父类的构造函数，先完成父类的构造，然后才可以继承
public:
	Cat(const char* name, int nAge) :Animal(name, nAge)
	{
		cout << "cat在构造" << endl;
	}
	~Cat()
	{
		cout << "cat在析构" << endl;
	}
};
//子类dog
class Dog :public Animal
{
	char m_cType[20];
public:
	Dog(const char* name, int nAge, const char* type) :Animal(name, nAge)
	{
		strcpy_s(m_cType, strlen(type) + 1, type);
		cout << "dog在构造" << endl;
	}
	~Dog()
	{
		cout << "dog在析构" << endl;
	}
	void lookingHouse()
	{
		cout << getName() << "正在看家" << endl;
	}
	//方法的隐藏或方法的重定义
	//在子类中定义和父类中完全同名的方法，就可以屏蔽父类中的方法，从而调用子类自己的方法
	void barking()
	{
		cout << m_cType << getName() << "正在汪汪汪叫" << endl;
		//cout << m_cName << endl;	//子类不可以访问父类中私有成员，错的所以
	}
};
//保护继承，Pig类
class Pig :protected Animal
{
public:
	Pig(const char* name, int nAge) : Animal(name, nAge) { cout << "Pig在构造" << endl; }
	~Pig() { cout << "Pig在析构" << endl; }
	void show() { running(); }
};
void test01()
{
	Animal a1("宠物", 5);
	a1.running();
	a1.barking();
	cout << a1.getName() << endl;
	Cat c1("缅因猫", 3);
	c1.running();
	c1.barking();
	Dog d1("大黄", 4, "柯基");
	d1.running();
	d1.barking();	//子类屏蔽了父类的同名函数，调用自己的方法
	d1.lookingHouse();		//Dog类独有的，父类没有的
}
void test02()
{
	Pig p1("猪猪侠", 5);
	//这里是类外，能不能再这里使用p1对象调用running方法？答案是不能，因为Pig类对Animal的running方法在Pig中就变成了保护权限
	//p1。running（）；//保护权限在类外是不能访问的
 }

//保护权限指的是不能被类外访问，但是可以被他的派生类访问
//再写一个孙子辈的类，野猪类，他公有继承Pig类
class Yezhu :public Pig
{
public:
	Yezhu(const char* name, int nAge) :Pig(name, nAge){cout << "Yezhu在构造" << endl; }
	~Yezhu() { cout << "Yezhu在析构" << endl; }
	void show() { running(); }//running方法是Animal的，但是被Pig保护继承了，所以它相当于Pig中的保护方法，所以可以给Pig的子类YeZhu使用
};
void test03()
{
	Yezhu yezhu("野猪", 6);
	yezhu.show();
	//yezhu.running();//因为running是保护成员，类外不能使用
}

//私有继承，鸟类
class bird :private Animal
{
public:
	bird(const char* name, int nAge) :Animal(name, nAge) { cout << "bird在构造" << endl; }
	~bird() { cout << "bird在析构" << endl; }
	void show() { running(); }//running仍然是父类公有成员，所有这里是子类，当人可以调用
};
//鸟类的子类：鹦鹉类
class yingwu :public bird
{
public:
	yingwu(const char* name, int nAge) :bird(name, nAge) { cout << "yingwu在构造" << endl; }
	~yingwu() { cout << "yingwu在析构" << endl; }
	void show(){
	//running仍然是Animal公有成员，但是被bird私有继承，所以他在bord中属于私有成员了，这里作为bird的子类，自然无法范围
	cout << "我是一只鹦鹉" << endl;
	}
};
void test04()
{
	yingwu y1("鹦鹉", 3);
	//
	y1.show();
}
//演示一个多继承
class BaseA
{
	int m_a;
	int m_b;
public:
	BaseA(int a, int b) :m_a(a), m_b(b)
	{
		cout << "BaseA在构造" << endl;
	}
	~BaseA() { cout << "BaseA在析构" << endl; }
};
class BaseB
{
	int m_a;
	int m_b;
public:
	BaseB(int a, int b) :m_a(a), m_b(b)
	{
		cout << "BaseB在构造" << endl;
	}
	~BaseB() { cout << "BaseB在析构" << endl; }
};
//子类，继承上面两个类
class C :public BaseA, public BaseB
{
	int m_c;
public:
	C(int a, int b, int c, int d, int e) :BaseA(a, b), BaseB(c, d)
	{
		m_c = e;
		cout << "C在构造" << endl;
	}
	~C() { cout << "C在析构" << endl; }
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
