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
	// ����ṹ����������Ŷ��ѧ������Ϣ
	student s[5] =
	{
		{2025001, 'f', 18, 10},
		{2025002, 'm', 20, 20},
		{2025003, 'f', 28, 30},
		{2025004, 'm', 38, 40},
		{2025005, 'f', 88, 50}
	};

	cout << "������ѧ���������ǣ�" << s[2].age << endl;

	// �ṹ��ָ��
	// �ṹ��ָ��Ķ���
	// �ṹ������ *�ṹ��ָ�������
	student *p = s;
	cout << "������ѧ���������ǣ�" << p[2].age << endl;
	cout << "������ѧ���������ǣ�" << (*(p + 2)).age << endl;
	cout << "������ѧ���������ǣ�" << (p + 2)->age << endl;
	cout << "���ĸ�ѧ���������ǣ�" << s[3].age << endl;
	return 0;
}