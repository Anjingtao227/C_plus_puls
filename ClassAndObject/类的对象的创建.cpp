#include "test1.h"

// 构造函数的实现
Person::Person(string n, int a) : name(n), age(a) {}

// 成员函数的实现
void Person::sayHello() 
{
    cout << "Hello, my name is " 
<< name << ", I am " << age << " years old." << endl;
}

string Person::getName() 
{
    return name;
}

int Person::getAge() 
{
    return age;
}

void Person::setName(string n) 
{
    name = n;
}

void Person::setAge(int a) 
{
    age = a;
}

// 新增功能的实现
bool Person::isValidAge() //Valid：有效的
{
    return age > 0 && age < 150;
}

string Person::getAgeCategory() //AgeCategory:类别
{
    if (age <= 12) 
    {
        return "Child";
    }
    else if (age <= 19) 
    {
        return "Teenager";
    }
    else if (age <= 64) 
    {
        return "Adult";
    }
    else 
    {
        return "Senior";
    }
}

int Person::getAgeInFuture(int years) 
{
    return age + years;
}

int Person::getRetirementAge() 
{
    if (age < 65) 
    {
        return 65 - age;
    }
    else 
    {
        return 0; // Already retired
    }
}

//int main() 
{
    // 创建对象
    Person p1("Alice", 20); // p1是Person类的对象
    p1.sayHello();          // 调用对象的成员函数

    Person* p2 = new Person("richard", 28);
    p2->sayHello();

    // 访问对象的成员变量（通过成员函数）
    cout << "Name: " << p1.getName() << ", Age: " << p1.getAge() << endl;

    // 修改对象的成员变量（通过成员函数）
    p1.setName("Bob");
    p1.setAge(25);
    p1.sayHello();

    // 新增功能的测试
    cout << "Is age valid? " << (p1.isValidAge() ? "Yes" : "No") << endl;
    cout << "Age category: " << p1.getAgeCategory() << endl;
    cout << "Age in 10 years: " << p1.getAgeInFuture(10) << endl;
    cout << "Years to retirement: " << p1.getRetirementAge() << endl;

    

    return 0;
}