#include <iostream>
using namespace std;
int main()
{
	/*
		ʮ���ƣ���0~9��10���������
		�˽��ƣ���0~7�����
		�����ƣ���1��0���
		ʮ�����ƣ���0~9��a~f�����
	*/
	// ʮ����
	int dec_num = 20;
	// �˽��ƣ���0��ͷ
	int oct_num = 075;
	// ʮ�����ƣ���0x��ͷ
	int hex_num = 0xfe;

	cout << "dec_num = " << dec_num << endl;
	// ���ֱ��������ᰴ��ʮ���Ƶķ�ʽ����Ҫ����˽��ƵĽ������Ҫ��oct��ת��
	cout << "oct_num = " << oct << oct_num << endl;
	cout << "hex_num = " << hex << hex_num << endl;
	// �м������oct�ȶ��������������ת������Ӱ���������������Ի���Ҫ��dec_numת��Ϊʮ������������ܽ����������ݶ�����ʮ���Ƶķ�ʽ������չʾ
	cout << "dec_num = " << dec << dec_num << endl;
	return 0;
}