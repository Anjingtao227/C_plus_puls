#include <iostream>
using namespace std;

// �����������ڽṹ��
struct date
{
	int year;
	int month;
	int day;
};
struct student
{
	int number; // ѧ��
	char gender; // �Ա�
	date birthday; // ����
}s1; // �����ڽṹ�嶨��Ľ����ֺ�֮ǰ�����ṹ�����

// typedef ����Ϊ�ṹ��������������
// S����student�ṹ����
typedef struct student S; //S �����þ��ǡ�͵��������ʡ�� struct �⼸����ĸ���ô������ࡣ
int main()
{
	// ��ʼ��s1����
	s1 = { 2025001, 'f', {2000,1,10} };
	cout << "ѧ�ţ�" << s1.number << endl;
	cout << "�Ա�" << s1.gender << endl;
	cout << "���գ�" << s1.birthday.year << "��" << s1.birthday.month << "��" << s1.birthday.day << "��" << endl;
	// ���ýṹ��ļ����������ʼ���ṹ�����
	S s2;
	//s2.gender = 'm';
	s2= { 2025002, 'm', { 2000,2,10 } };
	cout << "ѧ�ţ�" << s2.number << endl;
	cout << "�Ա�" << s2.gender << endl;
	cout << "���գ�" << s2.birthday.year <<"��" << s2.birthday.month <<"��"<< s2.birthday.day <<"��"<< endl;
	return 0;
}