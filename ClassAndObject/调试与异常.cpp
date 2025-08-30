#include<iostream>//ÊäÈëÊä³öÁ÷
using namespace std;

void mySwap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	mySwap(&a, &b);
	cout << "a=" << a << "£¬b=" << b << endl;

}
void test02()
{
	int sum = 0;
	int i;
	for (i = 1; i <= 100; i++)
	{
		sum += i;
	}
}



int main()
{
	
	//test01();
	test02();

	return 0;

}