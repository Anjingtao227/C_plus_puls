#include "test1.h"

// ���캯����ʵ��
Person::Person(string n, int a) : name(n), age(a) {}

// ��Ա������ʵ��
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

// �������ܵ�ʵ��
bool Person::isValidAge() //Valid����Ч��
{
    return age > 0 && age < 150;
}

string Person::getAgeCategory() //AgeCategory:���
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
    // ��������
    Person p1("Alice", 20); // p1��Person��Ķ���
    p1.sayHello();          // ���ö���ĳ�Ա����

    Person* p2 = new Person("richard", 28);
    p2->sayHello();

    // ���ʶ���ĳ�Ա������ͨ����Ա������
    cout << "Name: " << p1.getName() << ", Age: " << p1.getAge() << endl;

    // �޸Ķ���ĳ�Ա������ͨ����Ա������
    p1.setName("Bob");
    p1.setAge(25);
    p1.sayHello();

    // �������ܵĲ���
    cout << "Is age valid? " << (p1.isValidAge() ? "Yes" : "No") << endl;
    cout << "Age category: " << p1.getAgeCategory() << endl;
    cout << "Age in 10 years: " << p1.getAgeInFuture(10) << endl;
    cout << "Years to retirement: " << p1.getRetirementAge() << endl;

    

    return 0;
}