#include <iostream>
using namespace std;
namespace NameSpace1
{
	int number = 10;
	void func()
	{
		cout << "我是命名空间ns1中的函数" << endl;
	}
}

namespace ns1 = NameSpace1;

namespace ns2
{
	int func(int x, int y);
}

namespace ns3
{
	int func(int x, int y);
	namespace ns4
	{
		int func(int x, int y);
	}
}

// 定义命名空间中的函数
int ns2::func(int x, int y)
{
	return x + y;
}

int ns3::func(int x, int y)
{
	return x - y;
}

int ns3::ns4::func(int x, int y)
{
	return x * y;
}

//使用using namespace 命名空间名的方式来使用其中的内容
using namespace ns2;
int main()
{
	//cout << NameSpace1::number << endl;
	//ns1::func();

	/*cout << ns2::func(10, 20) << endl;
	cout << ns3::func(10, 20) << endl;
	cout << ns3::ns4::func(10, 20) << endl;*/

	cout << func(10, 20) << endl;
	return 0;
}