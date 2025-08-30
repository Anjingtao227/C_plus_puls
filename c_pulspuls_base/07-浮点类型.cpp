#include <iostream>
using namespace std;
int main()
{
	// float 代表单精度浮点，数值后面要加f，不加系统会默认为是double类型
	float f1 = 3.14f;

	//double 表示双精度浮点
	// 因为控制台的默认输出是保存6位数的，所以输出的位数不够完整，但是不影响d1的精度
	double d1 = 3.141592653;
	cout << "float的值：" << f1 << endl;
	cout << "double的值：" << d1 << endl;
	return 0;
}