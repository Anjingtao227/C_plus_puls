#include <iostream>
using namespace std;
namespace NameSpace1
{
	int number = 10;
	void func()
	{
		cout << "���������ռ�ns1�еĺ���" << endl;
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

// ���������ռ��еĺ���
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

//ʹ��using namespace �����ռ����ķ�ʽ��ʹ�����е�����
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