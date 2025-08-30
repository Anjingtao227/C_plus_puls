#include <iostream>
using namespace std;
int main()
{
	/*
		十进制：由0~9这10个数字组成
		八进制：由0~7来组成
		二进制：由1和0组成
		十六进制：由0~9、a~f来组成
	*/
	// 十进制
	int dec_num = 20;
	// 八进制，以0开头
	int oct_num = 075;
	// 十六进制，以0x开头
	int hex_num = 0xfe;

	cout << "dec_num = " << dec_num << endl;
	// 如果直接输出，会按照十进制的方式处理，要输出八进制的结果，需要加oct来转化
	cout << "oct_num = " << oct << oct_num << endl;
	cout << "hex_num = " << hex << hex_num << endl;
	// 中间如果用oct等对数据输出进行了转化，会影响后续的输出，所以还需要将dec_num转化为十进制输出，才能将后续的数据都按照十进制的方式来进行展示
	cout << "dec_num = " << dec << dec_num << endl;
	return 0;
}