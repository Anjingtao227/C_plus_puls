#include<iostream>
using namespace std;

//定义一个点类Point
class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
		cout << x << "," << y << "在构造" << endl;
	}
	Point(const Point& p)
	{
		this->x = p.x;
		this->y = p.y;
		cout << x << "," << y << "在拷贝构造" << endl;
	}
	int getX() { return x; }
	int getY() { return y; }
};
//组合类circle，其中包含了point类的对象
class Circle
{
	const double PI;
	double radius;
	Point center;//内嵌对象，这是圆的圆心
public:
	Circle(double r, const Point& p) :PI(3.14), center(p)//注意这里center(p）调用的是拷贝构造函数
	{
		radius = r;
		cout << "Circle在构造" << endl;
	}
	Circle(const Circle& c) :PI(3.14), center(c.center)//拷贝构造函数的语法格式
	{
		radius = c.radius;
		cout << "Circle在拷贝构造" << endl;
	}
};
void test01()
{
	Point p(20, 30);
	Circle c(10, p);
}
/*
组合类的构造过程：
	如果组合类中含有多个内嵌对象，则构造过程如下:
		1)按照内嵌对象的声明顺序依次调用内嵌对象的构造函数或者拷贝构造函数完成构造
		2）执行组合类自己的构造函数
*/
//含有多个内嵌对象的组合类：三角形类
class Triangle//类名
{
	//疑问：定义三个Point型的变量？+
	// //三角形需要三个点,组合类构造的顺序跟这里的声明顺序有关
	Point point1;
	Point point2;
	Point point3;
public:
	//第一个构造函数，传入三个点
	Triangle(const Point& p1, const Point& p2, const Point& p3):point1(p1), point2(p2), point3(p3)//成员初始化列表
	{
		cout << "Tirangle在构造" << endl;
	}
	//第二个构造函数，传入坐标，需要六个
	Triangle(int a, int b, int c, int d, int e, int f):point1(a,b),point2(c,d),point3(e,f)
	{
		cout << "Triangle在构造" << endl;
	}
	void show()
	{
		cout << "第一个点：" << point1.getX() << "," << point1.getY() << endl;
		cout << "第二个点：" << point2.getX() << "," << point2.getY() << endl;
		cout << "第三个点：" << point3.getX() << "," << point3.getY() << endl;
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
//定义一个child类
class Child
{
	//定义一个静态属性
	static int count;//用于统计该类实例化的对象的个数
	//下面是普通属性，每个对象有自己独立的拷贝
	int number;//学号
	char name[20];//姓名
	int age;//年龄
public:
	Child(const char* n, int a)//构造的时候，不传入学号参数，而是通过自增的方式设置一个学号
	{
		//每调用一次构造函数，就在统计数字上面+1
		count++;
		number = 2025100 + count;
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
	}
	int getNumber() { return number; }
	char* getName() { return name; }
	int getAge() { return age; }
	int getCount() { return count; }
	//添加一个静态方法，用来访问静态属性
	static int getStaticCount() 
	{
		return count; 
		//静态方法不能访问普通成员
		//cout << number << endl;
		//getAge();

	}
//添加一个常函数
	void show() const
	{
		cout << "执行常成员函数show() const" << endl;
		cout << number << "，" << name << "，" << count << endl;//常函数可以访问普通属性和静态属性
		//getNumber();//可见常函数不能调用常函数
		getStaticCount();//可见常函数可以调用静态函数
	}
};
//在类外初始化静态属性
int Child::count = 0;
void test03()
{
	Child c1("张三", 7);
	Child c2("李四", 6);
	Child c3("王五", 8);
	Child c4("杨二", 14);
	Child c5("杨大", 19);
	cout << c1.getNumber() << "，" << c1.getName() << "，" << c1.getAge() << "，" << c1.getCount() << endl;
	cout << c2.getNumber() << "，" << c2.getName() << "，" << c2.getAge() << "，" << c2.getCount() << endl;
	cout << c3.getNumber() << "，" << c3.getName() << "，" << c3.getAge() << "，" << c3.getCount() << endl;
	cout << c4.getNumber() << "，" << c4.getName() << "，" << c4.getAge() << "，" << c4.getCount() << endl;
	cout << c5.getNumber() << "，" << c5.getName() << "，" << c5.getAge() << "，" << c5.getCount() << endl;
	//访问静态函数
	cout << c1.getCount() << endl;//普通对象可以调用静态函数
	cout << Child::getStaticCount() << endl;//类名也可以访问静态函数
	//常对象和常函数
	const Child const_c("赵六", 6);
	const_c.show();//常对象应该调用常函数
	const_c.getStaticCount();//常对象也可以调用静态函数
	//const_c.getName();//可见常对象不能调用普通函数
	c1.show();//普通对象可以调用常函数
}
//演示常函数和普通函数的重载
class Data
{
	int value;
public:
		Data(int v):value(v){}//普通构造函数
		//普通成员函数，用于获取value值
		int& getValue() 
		{
			cout << "调用普通函数" << endl;
			return value; 
		}
		//常成员函数
		const int& getValue() const 
		{ 
			cout << "调用常函数" << endl;
			return value; 
		}

};
void test04()
{
	Data d(10);
	cout << d.getValue() << endl;//调用普通函数

	const Data const_d(20);
	cout << const_d.getValue() << endl;//调用常函数

}
void test05()//对象数组
{
	Child c[3] = { Child("张三",7),Child("李四",6),Child("王五",6) };
	c[0].show();
	c[1].show();
	c[2].show();

}
void test06()//对象指针
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