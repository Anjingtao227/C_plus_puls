#include <iostream>
using namespace std;
int main()
{
	char ch[20] = "C++ Program";
	
	// strlen()�����ַ����ĳ���
	cout << strlen(ch) << endl;

	// strcpy_s() �ַ����ĸ��Ʋ���
	char ch1[20] = { 'C', '+', '+'};
	char ch2[20] = "abcdef";
	strcpy_s(ch1, ch2); // ��ch2��ֵ��ch1, Ҫ��֤ch1�ĳ���Ҫ���ڵ���ch2�ĳ���
	strcpy_s(ch1, "java");
	cout << ch1 << endl;

	// strcat_s() ���ַ���ƴ�ӵ��ַ�����ĺ���
	// Ҫ��֤ƴ�Ӻ���ַ���Ҫ�ܴ�ŵ�ָ�����ַ������У�������������ӣ�ch3+ch4�Ľ��Ҫ�ܱ��浽ch3�У�ch3Ҫ���㹻�����鳤������Ž��
	char ch3[20] = "C++";
	char ch4[20] = "program";
	strcat_s(ch3, ch4);  // ��ch4ƴ�ӵ�ch3�Ľ�β
	cout << ch3 << endl;

	// strcmp(�ַ���1,�ַ���2); �Ƚ������ַ����Ĵ�С
	// �ȽϵĹ��򣺴������ַ����ĵ�һ���ַ���ʼ������Ƚ�ÿ���ַ���Ӧ��ASCII��ֵ��ֱ�����ֲ�ͬ��С����ֱ�ӵ����ַ�����ĩβΪֹ����������˲�ͬ��С���ַ�����ô�����״β�ͬ���ַ��Ĵ�С�ȶԽ��Ϊ׼��ֱ�Ӿ��������ַ����Ĵ�С�����һֱ�����β����ͬ����˵�������ַ�����ȡ�
	char ch5[10] = "Program";
	char ch6[10] = "Programer";
	// �ַ�����ȣ����صĽ����0
	cout << strcmp(ch5, "Program") << endl;
	// ǰ����ַ����Ⱥ�����ַ����󣬷��صĽ��1
	cout << strcmp(ch6, ch5) << endl;
	// ǰ����ַ����Ⱥ�����ַ���С�����صĽ��-1
	cout << strcmp(ch5, ch6) << endl;

	// _strlwr_s() �������Խ��ַ����еĴ�д��ĸת��ΪСд��ĸ
	// _strupr_s() �������Խ��ַ����е�Сд��ĸת��Ϊ��д��ĸ
	_strlwr_s(ch6);
	cout << ch6 << endl;
	_strupr_s(ch6);
	cout << ch6 << endl;


	// ��ҵ���û�����������һ��Ӣ�ĵ��ַ�������д��������з�ת֮��������
	// ���磺����� abcdef������Ľ��Ϊ��fedcba

	//char ch[100] = "abcdef";
	//.....
	//cout << ch << endl; // fedcba
	return 0;
}