#include <iostream>
using namespace std;
int main()
{

	int arr[3][4] =
	{
		{10,20,30,40},
		{20,30,40,50},
		{30,40,50,60}
	};

	// arr ��arr[0]��&arr[0][0]���ǵ�һ�е��׵�ַ
	cout << arr << " " << arr[0] << " " << &arr[0][0] << endl;
	// arr+1��arr[1]��&arr[1][0]
	cout << arr+1 << " " << arr[1] << " " << &arr[1][0] << endl;
	// arr+2��arr[2]��&arr[2][0]
	cout << arr + 2 << " " << arr[2] << " " << &arr[2][0] << endl;

	// ʹ��arr��ȡ�ڶ��еĵ�����Ԫ��
	cout << *(*(arr + 1) + 2) << endl;
	cout << *(arr[1] + 2) << endl;


	// ��ҵ���ö�ά��������ֱ�ӱ�����ά�����е�����Ԫ��
	return 0;
}