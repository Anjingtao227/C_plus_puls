#include <iostream>
using namespace std;

inline int addNum(int a, int b)
{
	return a + b;
}
int main()
{
	cout << addNum(10, 20) << endl;
	return 0;
}