#include <iostream>
using namespace std;
int main()
{
	// 分配单个空间
	// 分配一个int类型的空间
	int *p = (int*)malloc(sizeof(int));
	if (p == NULL)
	{
		cout << "p是一个空指针" << endl;
	}
	else
	{
		*p = 10;
		cout << *p << endl;
	}
	// 将p指向的内存空间给释放掉
	free(p);


	// 如果分配多个连续的空间
	int* p1 = (int*)malloc(sizeof(int) * 5);
	if (p1 == NULL)
	{
		cout << "p1是一个空指针" << endl;
	}
	else
	{ 
		// 给每个空间进行赋值
		for (int i = 0; i < 5; i++)
		{
			*(p1 + i) = i + 10;
		}

		for (int i = 0; i < 5; i++)
		{
			cout << p1[i] << " ";
		}
	}
	// 将p1连续的空间进行释放
	free(p1);
	p1 = NULL;
	return 0;
}