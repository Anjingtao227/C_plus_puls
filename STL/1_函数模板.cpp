#include <iostream>
using namespace std;

/*
泛型编程（函数模板和类模板）
    本阶段针对C++的泛型编程和STL技术做讲解。STL中大量采用了泛型编程技术。
    1.模板的概念
        泛型的泛指的是泛泛，泛指，泛用。即在编程的时候可以建立通用的模板，来提高代码的复用性。
        例如生活中也有模板的案例，比如说产品的模具，比如说PPT模板。
        C++中有两种模板技术：函数模板和类模板
    2.函数模板
        函数模板的作用：建立一个通用函数，函数返回值类型和形参类型可以不具体指定，用一个虚拟的类型来表示，从而提高复用性，将类型参数化。
        语法：template<typename T>或者template<class T> 加到函数声明的上一行，就能声明一个函数模板，T叫做泛型，<>叫做模板参数列表
*/
//2.1 函数模板的基本用法
////举例：不使用模板
////1.交换两个int值
//void mySwap(int& a, int& b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}
////1.交换两个double值，采用了函数重载，函数名一样，参数不一样
//void mySwap(double& a, double& b)
//{
//    double temp = a;
//    a = b;
//    b = temp;
//}
//接下来使用模板技术，实现任意类型的交换
template<typename T>
void mySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
void test01()
{
    //交换两个int
    int n1 = 10;
    int n2 = 20;
    mySwap(n1, n2);
    cout << "交换后,n1=" << n1 << ",n2=" << n2 << endl;

    //交换两个double
    double d1 = 2.43;
    double d2 = 55.32;
    mySwap(d1, d2);
    cout << "交换后,d1=" << d1 << ",d2=" << d2 << endl;

    //交换两个char
    char c1 = 'a';
    char c2 = 'b';
    mySwap(c1, c2);
    cout << "交换后,c1=" << c1 << ",c2=" << c2 << endl;

    //使用函数模板的两种方式：自动类型推导、显式指定类型
    //以上全部使用的是自动类型推导的方式来确定T的类型

    //如何显式指定泛型的类型
    int n3 = 5;
    int n4 = 8;
    mySwap<int>(n3, n4);//使用模板参数列表<>指定了T的类型为int
    //mySwap<double>(n3,n4);//不匹配了
    cout << "交换后,n3=" << n3 << ",n4=" << n4 << endl;
}

/*
2.2 函数模板注意事项：
    1）如果使用自动类型推导的方式，必须推导出一致的类型，才可以使用
    2）模板必须要确定出T的类型，才可以使用，如果不能自动推导，需要手动指定。
*/
template<class T>
void func() { cout << "func被调用，此时T的类型是：" << typeid(T).name() << endl; }
void test02()
{
    //1）如果使用自动类型推导的方式，必须推导出一致的类型，才可以使用
    int n = 10;
    char c = 'a';
    //mySwap(n, c);//报错，因为推导出来的T的类型不一致

    //2）模板必须要确定出T的类型，才可以使用，如果不能自动推导，需要手动指定。
    //func();//报错，因为T无法确定类型
    func<int>();//只能通过手动显式指定泛型T的类型，来使用
    func<double>();//只能通过手动显式指定泛型T的类型，来使用
}

//课堂练习：1.写一个函数模板，比较两个值的大小，返回较大的那个值。
template<typename T>
T getLarger(T a, T b) { return a > b ? a : b; }
void test03()
{
    int n1 = 10;    
    int n2 = 20;
    double d1 = 3.54;
    double d2 = 23.99;
    char c1 = 'a';
    char c2 = 'b';
    cout << "n1和n2较大的值：" << getLarger(n1, n2) << endl;
    cout << "d1和d2较大的值：" << getLarger(d1, d2) << endl;
    cout << "c1和c2较大的值：" << getLarger(c1, c2) << endl;
}
//课堂作业：2.写一个函数模板，返回一个数组中的最大值
template<typename T>
T getMax(T arr[], int len)//数组传参传递的是首地址，丢失了长度信息，所以必须通过第二个参数传递长度
{
    T temp = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i]>temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}
void test04()
{
    //整型数组
    int int_arr[] = { 5,3,8,1,3,9 };
    cout << "int_arr的最大值：" << getMax(int_arr, 6) << endl;
    //char型数组
    char char_arr[] = { 'a','b','c','A','B','C' };
    cout << "char_arr的最大值：" << getMax(char_arr, 6);
}

/*
2.3 普通函数和函数模板的区别：
    普通函数调用时可以发生自动类型转换（隐式类型转换）
    函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换。如果显式指定了泛型的类型，也可以发生隐式类型转换。
*/
int add(int a, int b) { return a + b; }
template<typename T>
T add_tpl(T a, T b) { return a + b; }
void test05()
{
    //普通函数调用时可以发生自动类型转换（隐式类型转换）
    int a = 10;
    char c = 'a';
    cout << add(a, c) << endl;//没有报错，因为发生了隐式类型转换，将char型转换为了int型。字符'a'的ASCII码97就是转换成int的值。所以结果是107

    // 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换。如果显式指定了泛型的类型，也可以发生隐式类型转换
    //cout << add_tpl(a, c) << endl;//自动推导不会发生转换，报错
    cout << add_tpl<int>(a, c) << endl;//显式指定泛型类型后，发生了转换
}

/*
2.4 普通函数和函数模板同时存在时的调用规则
    1）如果普通函数和函数模板都可以实现，优先调用普通函数（具体的高于通用的）
    2）可以通过空的模板参数列表<>来强制调用函数模板
    3）函数模板之间也可以发生重载，可以定义多个同名的函数模板，参数不同。
    4）如果函数模板可以产生更好的匹配，优先调用函数模板
*/
//接下来既有普通函数，又有函数模板，而且实现了重载
void myPrint(int a, int b) { cout << "a=" << a << " b=" << b << "调用普通函数" << endl; }
template<typename T>
void myPrint(T a, T b){ cout << "a=" << a << " b=" << b << "调用函数模板：两个参数" << endl; }
template<typename T>
void myPrint(T a,T b,T c){ cout << "a=" << a << " b=" << b <<" c="<<c<<"调用函数模板：三个参数" << endl; }
void test06()
{
    //1）如果普通函数和函数模板都可以实现，优先调用普通函数（具体的高于通用的）
    int a = 10;
    int b = 20;
    myPrint(a, b);

    //2）可以通过空的模板参数列表<>来强制调用函数模板
    cout << "强制调用模板" << endl;
    myPrint<>(a, b);

    //3）函数模板之间也可以发生重载，可以定义多个同名的函数模板，参数不同。
    int c = 30;
    myPrint(a, b, c);

    //4）如果函数模板可以产生更好的匹配，优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    myPrint(c1, c2);
}

/*
2.5 特定的模板（解决模板的局限性）
    局限性：模板的通用性并不是万能的，在遇到自定义数据类型的时候，就无法处理了，此时需要定义特定模板
*/
//定义一个类，然后比较两个对象是否相等
class Student
{
public:
    string m_Name;//string是字符串类型，是STL中的一种类型
    int m_Age;
    Student(string name, int age) :m_Name(name), m_Age(age) {}
};
//写一个函数模板，比较两个值是否相等
template<typename T>
bool myCompare(T& a, T& b)
{
    cout << "调用函数模板myCompare(T& a, T& b)";
    if (a==b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//自定义类型，如Student对象，需要比较每个属性是否相等，才能得出结论
//写一个特定模板，为了支持特定类型
template<> bool myCompare(Student& s1, Student& s2)
{
    cout << "调用函数模板template<> bool myCompare(Student& s1, Student& s2)";
    if (s1.m_Name.compare(s2.m_Name)==0 and s1.m_Age==s2.m_Age)//名字和年龄都相等才能得出相等的结论
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test07()
{
    int n1 = 10;
    int n2 = 20;
    cout << "比较n1和n2是否相等：" << myCompare(n1, n2) << endl;//0
    Student s1("Tom", 10);
    Student s2("Jerry", 18);
    Student s3("Tom", 10);
    cout << "比较s1和s2是否相等：" << myCompare(s1, s2) << endl;//0
    cout << "比较s1和s3是否相等：" << myCompare(s1, s3) << endl;//1
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

