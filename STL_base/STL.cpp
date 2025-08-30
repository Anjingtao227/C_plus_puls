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
int main()
{
    //test01();
    //test02();
    //test03();
    test04();

    return 0;
}

