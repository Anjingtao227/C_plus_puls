#include <iostream>
using namespace std;

struct S1 // 8个字节
{
	int i;//4
	char c;//1
};

struct S2 //  16个字节
{
	double b;//8
	char c;//1
	int a;//4
};

struct S3
{
	char c1; // 占1个字节
	S2 s; // 从第9个地址开始存储
	double d; // 占8个字节
	// 总共占用32个字节
};


int main()
{
	cout << sizeof(S3) << endl;
	return 0;
}