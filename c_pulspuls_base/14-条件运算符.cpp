#include <iostream>
using namespace std;
int main()
{
	
	//cout << (100 ? 200 : 300) << endl; // 200
	//cout << (0 ? 200 : 300) << endl; // 300

	// ���û��ӿ���̨������������������ϴ�ֵ�ͽ�Сֵ
	//int a, b;
	//cout << "����������������" << endl;
	//cin >> a >> b;
	//int max = a > b ? a : b;
	//int min = a < b ? a : b;
	//cout << "max = " << max << endl;
	//cout << "min = " << min << endl;

	// ���û�����������ͬ��������������ֵ����Сֵ��һ�б��ʽ���
	// ˼·���ȱȽ��������Ĵ�С��Ȼ���ٺ͵����������бȽ�
	int a = 10, b = 20, c = 30;
	// ����1��
	int max = (a > b ? a : b) > c ? (a > b ? a : b) : c;
	// ����2��
	max = a > b ? (a > c ? a : c) : (b > c ? b : c);

	int min = (a < b ? a : b) < c ? (a < b ? a : b) : c;
	cout << max << " " << min << endl;
	return 0;
}