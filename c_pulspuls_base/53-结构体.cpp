#include <iostream>
using namespace std;
// ����ṹ��
struct student
{
	int number; // ѧ��
	char gender; // �Ա�
	int age; // ����
	double score; // ����
};
int main()
{
	// ����ṹ��ı�����ʹ��
	student s1;
	s1.number = 2025001;
	s1.gender = 'f';
	s1.age = 18;
	s1.score = 88;

	// ��ӡ�ṹ���е�����
	cout << "ѧ�ţ�" << s1.number << endl;
	cout << "�Ա�" << s1.gender << endl;
	cout << "���䣺" << s1.age << endl;
	cout << "������" << s1.score << endl;

	// �����������ʽ���Խṹ����и�ֵ
	student s2 = { 2025002, 'm', 19, 85 };
	cout << "ѧ�ţ�" << s2.number << endl;
	cout << "�Ա�" << s2.gender << endl;
	cout << "���䣺" << s2.age << endl;
	cout << "������" << s2.score << endl;
	return 0;
}