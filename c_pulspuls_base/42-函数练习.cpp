#include<iostream>
using namespace std;
// ���庯������ȡ����int���������е����ֵ
int getMax(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

// ���庯����x��n�η�
int getPower(int x, int n)
{
	int a = 1;
	// n����ѭ���Ĵ������൱�ھ���xҪ���Լ�n-1��
	for (int i = 0; i < n; i++)
	{
		a *= x;
	}
	return a;
}
int main()
{
	//cout << getMax(10, 20) << endl;
	cout << getPower(10, 4) << endl;

	// ��ҵ��1�����庯����ʵ�ִ�ӡn�е�����ͼ�Σ�ʵ�δ��ݵ��Ǽ��У����Ǵ�ӡ��������
	/*
	���������n��7
		---
		    *
		   ***
		  *****
		*******
		  *****
		   ***
		    * 
			
		----
			*/
	return 0;
}