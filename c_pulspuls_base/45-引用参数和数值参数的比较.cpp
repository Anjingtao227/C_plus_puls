#include <iostream>
using namespace std;
// ������Ϊ��������ֵ��Ϊ�����ıȽ�
// ������Ϊ�������βΣ�ʵ��ֻ���Ǳ�����,�������ֵ��Ϊ����������ʵ�ο����Ǳ������������߱��ʽ

// ����Բ�����
const double PI = 3.14;
double area1(double radius)
{
	return PI * radius * radius;
}

double area2(double& radius)
{
	return PI * radius * radius;
}
int main()
{
	double r = 10.0;
	// ֵ���ݣ�ʵ�ο����Ǳ��������������ʽ
	cout << "area1(r) = " << area1(r) << endl;
	cout << "area1(100) = " << area1(100) << endl;
	cout << "area1(2*r) = " << area1(2*r) << endl;

	// ���ô��ݣ�ʵ��ֻ���Ǳ�����
	cout << "area2(r) = " << area2(r) << endl;
	//cout << "area2(100) = " << area2(100) << endl;
	//cout << "area2(2*r) = " << area2(2 * r) << endl;
	return 0;
}