#include <iostream>
using namespace std;
int main()
{
	// һά����Ķ��巽ʽ
	// �������� ������[���鳤��];
	int arr[5];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 40;
	arr[4] = 50;

	// �������� ������[���鳤��,] = { ֵ1,ֵ2.... };
	int arr1[5] = { 100,200,300,400,500 };

	// �������� ������[] = { ֵ1,ֵ2.... };
	int arr2[] = { 1000,2000,3000,4000,5000,6000 };

	//// ��������ռ�õĿռ��С
	//cout << sizeof(arr2) << endl;
	//// ����Ԫ��ռ�õĿռ��С
	//cout << sizeof(arr2[0]) << endl;
	//// ���������Ԫ�ظ���
	//cout << sizeof(arr2) / sizeof(arr2[0]) << endl;
	/*for (int i = 0; i <= 5; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;*/

	// ����4��ѧ���ĳɼ������������洢4���ɼ����������ǵ�ƽ���ɼ�
	int score[4];
	// sum�����ܳɼ���avg������ƽ���ɼ�
	double avg, sum = 0;
	for (int i = 0; i < 4; i++)
	{
		cout << "���������" << i + 1 << "��ѧ���ĳɼ���" << endl;
		cin >> score[i];
		sum += score[i];
	}
	avg = sum / 4;
	cout << "ƽ���ɼ��ǣ�" << avg << endl;
 	return 0;
}