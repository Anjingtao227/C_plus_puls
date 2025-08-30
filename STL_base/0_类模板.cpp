#include <iostream>
using namespace std;

/*
3.类模板
	3.1 类模板
		作用：建立一个通用类，类中的成员（属性和方法）用到的数据类型可以不具体指定，用一个虚拟的泛型来代表。
		类模板和函数模板的主要区别：类模板没有自动推导的使用方式，只能显式指定泛型的类型nkk
		语法：跟函数模板相似，在类的上一行做模板声明，可以使用template<typename T>或者template<class T>
*/
//定义一个类模板，Person类，属性有姓名和年龄，姓名和年龄都使用泛型表示
template<class NameType,class AgeType=int> //年龄的泛型默认值是int类型
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
	void show() { cout << "name:" << m_Name << "，age:"<<m_Age << endl; }
	//再写一个函数模板
	void setValue(NameType name, AgeType age) { m_Name = name; m_Age = age; }
};
void test01()
{
	Person<string, int> p1("哪吒", 3000);//注意，类模板没有自动推导泛型的用法，必须显式指定
	Person<string, string> p2("孙悟空", "八千岁");
	//使用年龄泛型的默认值
	Person<string> p3("唐僧", 30);
	p1.show();
	p2.show();
	p3.show();
	//使用类中的函数模板修改属性
	p1.setValue("张三", 18);
	p2.setValue("李四", "十八岁");
	p1.show();
	p2.show();
}

/*
3.2 类模板结合函数模板的使用（将类模板对象当作函数参数使用）
	类模板实例化出来的对象，向函数传参，演化出三种不同的变化：
		1）传参的时候指定传入的对象类型，好理解，但是灵活度不高
		2）将对象的模板参数提取出来，进一步模板化，提升了灵活性
		3）将整个对象的类模板化，灵活度最高
*/
//1）传参的时候指定传入的对象类型
void show_01(Person<string, int>& p) { p.show(); }
//2）将对象的模板参数提取出来，进一步模板化
template<typename T1,typename T2>
void show_02(Person<T1, T2>& p)
{
	p.show();
	cout << "T1的类型是：" << typeid(T1).name() << endl;
	cout << "T2的类型是：" << typeid(T2).name() << endl;
}
//3）将整个对象的类模板化
template<typename T>
void show_03(T& p)
{
	p.show();
	cout << "T的类型是：" << typeid(T).name() << endl;
}
//针对第三种情况，再写一个类Student
class Student
{
public:
	string m_Name;
	int m_Age;
	Student(string name,int age):m_Name(name),m_Age(age){}
	void show() { cout << "name:" << m_Name << "，age:" << m_Age << endl; }
};
void test02()
{
	Person<string, int> p1("张三", 18);
	Person<string, string> p2("李四", "十岁");
	//使用上面两个对象进行传参
	//1）传参的时候指定传入的对象类型
	show_01(p1); //要求必须传入Person<string, int>类型的对象
	//2）将对象的模板参数提取出来，进一步模板化
	show_02(p1);//可以传入Person<string, int>类型的对象
	show_02(p2);//也可以Person<string, string>类型的对象
	//3）将整个对象的类模板化
	Student s1("Tom", 15);
	show_03(p1);//可以传入Person<string, int>类型的对象
	show_03(p2);//也可以Person<string, string>类型的对象
	show_03(s1);//传入另外一个类的对象了，不是Person了，而是Student
}
int main()
{
	//test01();
	test02();
	return 0;
}