#include <iostream>
using namespace std;
// ������Ϊ�����Ĳ���
//void printArr(int arr[], int len)
void printArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
// 1����д������ʵ������ķ�ת��Ҫ��ԭ�����Ͻ��д���
// ���紫��֮ǰ��a[] = {10,20,30,40,50}, �����꺯��֮���ٶ�a���б�������{50,40,30,20,10}
void myReverse1(int* arr, int len)
{
	int temp;
	// ����1��
	//for (int i = 0; i < len / 2; i++)
	//{
	//	temp = arr[i];
	//	arr[i] = arr[len - 1 - i];
	//	arr[len - 1 - i] = temp;
	//}

	// ����2����������ѭ������ͬʱ���������ı���������
	int* i, * j;
	for (i = arr, j = arr + len - 1; i < j; i++, j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}
}

// 2����д������ʵ������ķ�ת��ͨ�����ú���ʱ�ķ���ֵ����ȡ��ת�������������תʱ��Ӱ��ԭ�����ֵ
//int newArr[5]; // �����鵱��ȫ��������Դ���
int* myReverse2(int* arr, int len)
{
	// ʹ�ö�̬�ڴ����������
	int* newArr = new int[len];
	int j = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		newArr[j] = arr[i];
		j++;
	}
	return newArr;
}

// �ַ�������Ϊ�����Ĳ���
void printCharArr(char* p)
{
	cout << p << endl;
}

// 3�����庯����ʵ�������ַ�����ƴ��
void stringCat(char* str1, char* str2)
{
	char* p;
	// ��pָ���һ���ַ����Ľ�����ʶ
	p = str1 + strlen(str1);
	while (*str2 != '\0')
	{
		// ��str2ָ���ֵ��ֵ��pָ���λ�ã�ÿ�θ�ֵ���Ҫ����ָ�����
		*p = *str2;
		p++;
		str2++;
	}
}
int main()
{
	//int a[5] = { 10,20,30,40,50 };
	//printArr(a, 5);
	//int *p = myReverse2(a, 5);
	//printArr(p, 5);
	//delete[] p;

	char a[100] = "ABCDE";
	char b[100] = "fg12345";
	// ���ַ�����aƴ�ӵ��ַ�������b�ĺ���
	stringCat(b, a);
	printCharArr(b);
	return 0;
}