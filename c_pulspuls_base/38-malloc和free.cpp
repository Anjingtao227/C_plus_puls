#include <iostream>
using namespace std;
int main()
{
	// ���䵥���ռ�
	// ����һ��int���͵Ŀռ�
	int *p = (int*)malloc(sizeof(int));
	if (p == NULL)
	{
		cout << "p��һ����ָ��" << endl;
	}
	else
	{
		*p = 10;
		cout << *p << endl;
	}
	// ��pָ����ڴ�ռ���ͷŵ�
	free(p);


	// ��������������Ŀռ�
	int* p1 = (int*)malloc(sizeof(int) * 5);
	if (p1 == NULL)
	{
		cout << "p1��һ����ָ��" << endl;
	}
	else
	{ 
		// ��ÿ���ռ���и�ֵ
		for (int i = 0; i < 5; i++)
		{
			*(p1 + i) = i + 10;
		}

		for (int i = 0; i < 5; i++)
		{
			cout << p1[i] << " ";
		}
	}
	// ��p1�����Ŀռ�����ͷ�
	free(p1);
	p1 = NULL;
	return 0;
}