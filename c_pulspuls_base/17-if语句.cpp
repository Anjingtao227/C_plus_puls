#include <iostream>
using namespace std;


void test1()
{
	int age = 17;
	if (age >= 18)
	{
		cout << "已成年，来上网吧" << endl;
	}
	else
	{
		cout << "未成年，从后面的没有监控的门进来上网。" << endl;
	}
}
	

	/*
		if(条件语句1)
		{
			语句组1;
		}
		else if(条件语句2)
		{
			语句组2;
		}....
		else if(条件语句n)
		{
			语句组n;
		}
		else
		{
			else语句组;
		}
	*/
// if分支语句，如果满足了其中一个分支的条件，就会执行当前对应的代码， 后续的判断就不再执行了。
void test2()
{
	int age = 14;
	if (age <= 6)
	{
		cout << "免票" << endl;
	}
	else if (age > 6 && age <= 14)
	{
		cout << "半票" << endl;
	}
	else
	{
		cout << "全票" << endl;
	}
}

int main()
{
	test1();

	return 0;
}