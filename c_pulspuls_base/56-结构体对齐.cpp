#include <iostream>
using namespace std;

struct S1 // 8���ֽ�
{
	int i;//4
	char c;//1
};

struct S2 //  16���ֽ�
{
	double b;//8
	char c;//1
	int a;//4
};

struct S3
{
	char c1; // ռ1���ֽ�
	S2 s; // �ӵ�9����ַ��ʼ�洢
	double d; // ռ8���ֽ�
	// �ܹ�ռ��32���ֽ�
};


int main()
{
	cout << sizeof(S3) << endl;
	return 0;
}