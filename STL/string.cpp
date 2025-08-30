#include <string>
#include <iostream>
using namespace std;

/*
1.STL����
	Ϊ�˽������ݽṹ���㷨��һ�ױ�׼����߸����ԣ�������STL��standard template library����׼ģ���
	STL�������˷��ͱ��ʵ�֣����漸��������ģ��ͺ���ģ�塣
	STL��Ϊ���󲿷֣�������container�����㷨��algorithm������������iterator����
		�����������ݵĵط���STL����ʵ���˳��������ݽṹ��������֯�ʹ洢���ݡ�
		�㷨�����ڶ����ݽ�������ģ����ڽ������ķ������������򡢲��ҵȵȡ�
		������������ָ�������е�ÿ��Ԫ�أ���������Ԫ�أ������Ͼ���һ����װ��ָ����ࡣ
2.STL�еĳ�������
	1 string����
		1.1��������
			string��STL�ﶨ����ַ�����������һ���࣬��һ�������������Ԫ������ֻ����char���͡�
			string��char*������
				char*��һ��ָ�룬��string��һ���࣬���ڲ���װ��char*
				string����char*��������ڴ棬���Ҳ��õ���Խ������⣬�������������string��װ�˺ܶ��Ա������ʹ�������ǳ�����
		1.2string����
			string();//����һ���յ��ַ���
			string(const char* s);//ʹ���ַ���s����ʼ��string����
			string(const string& str);//ʹ��string����str����ʼ��string����
			string(int n,char c);//ʹ��n���ַ�c����ʼ��string����
*/
void test01()
{
	string s1;//�޲ι��죬����һ���յ��ַ���
	cout << "s1=" << s1 << endl;

	const char* str = "hello world";
	string s2(str);//ʹ���ַ���s����ʼ��string����
	cout << "s2=" << s2 << endl;

	string s3(s2);//��������
	cout << "s3=" << s3 << endl;

	string s4(10, 'a');//ʹ��n���ַ�char����ʼ��string����
	cout << "s4=" << s4 << endl;
}

/*
1.3string��ֵ����
			���ظ�ֵ�������
				string& operator=(const char* s);//�ַ���������ֵ
				string& operator=(const string& s);//string����ĸ�ֵ
				string& operator=(char c);//�����ַ���ֵ
			��ֵ����assign():
				string& assign(const char* s);//�ַ���������ֵ
				string& assign(const char* s,int n);//���ַ���s��ǰn���ַ���ֵ��string
				string& assign(const string& s);//ʹ��string������ɸ�ֵ
				string& assign(int n,char c);//ʹ��n���ַ�c����ֵ
*/

void test02()
{
	//��ֵ�����=
	string str1;
	str1 = "hello world";
	cout << "str1=" << str1 << endl;
	string str2;
	str2 = str1;
	cout << "str2=" << str2 << endl;
	string str3;
	str3 = 'A';
	cout << "str3=" << str3 << endl;

	cout << "�����Ǹ�ֵ������ɵģ�" << endl;
	//��ֵ����assign()
	string str4;
	str4.assign("hello C++");
	cout << "str4=" << str4 << endl;
	string str5;
	str5.assign("hello C++", 5);
	cout << "str5=" << str5 << endl;
	string str6;
	str6.assign(str5);
	cout << "str6=" << str6 << endl;
	string str7;
	str7.assign(5, 'x');
	cout << "str7=" << str7 << endl;
}

/*
1.4string�ַ���ƴ��
			���ַ���ĩβƴ���ַ���
			���������+=:
				string& operator+=(const char* s);
				string& operator+=(const string& str);
				string& operator+=(char c);
			append������
				string& append(const char* s);
				string& append(const char* s,int n);//���ַ���s��ǰn���ַ�ƴ�ӵ�string�ַ���
				string& append(const string& s);
				string& append(const string& s,int pos,int n);//pos����positionλ�ã���0��ʼ���±ꡣ��posλ�ÿ�ʼ�����ַ���s�����n���ַ�ƴ�ӵ���ǰ�ַ���
*/
void test03()
{
	//���������+=
	string str1 = "��";
	str1 += "������Ϸ";
	cout << "str1=" << str1 << endl;
	str1 += ':';
	cout << "str1=" << str1 << endl;
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1=" << str1 << endl;

	//append������
	string str3 = "I";
	str3.append(" like ");
	str3.append("play game such as ", 10);
	str3.append(str2, 4, 3);
	cout << "str3=" << str3 << endl;
}

/*
1.5string���Һ��滻
			���ң�����ָ�����ַ����Ƿ���ڣ��ҵ��᷵�ض�Ӧ��λ�ã��Ҳ�������-1��-1��string::npos���������ǳ�����
				�������Ҳ��ң�find
					int find(const string& str,int pos=0) const;//�����ַ���str����������һ�γ��ֵ�λ�ã���posλ�ÿ�ʼ�ң�posĬ��ֵ��0������ͷλ��
					int find(const char* s,int pos=0) const;
					int find(const char* s,int pos=0,int n) const;//��posλ�ÿ�ʼ�����ַ���s��ǰn���ַ���һ�γ��ֵ�λ��
					int find(char c,int pos=0) const;//��posλ�ò����ַ�c��һ�γ��ֵ�λ��
				����������ң�rfind
					int rfind(const string& str,int pos=npos) const;//�����������str���һ�γ��ֵ�λ�ã���posλ�ÿ�ʼ���ң�posĬ��ֵ��npos��npos��string��ľ�̬��������ʾ�ַ�������
					int rfind(const char* s,int pos=npos) const;
					int rfind(const string& s,int pos=npos��int n) const;//��pos��ʼ�����������s�ַ�����ǰn���ַ����һ�γ��ֵ�λ��
					int rfind(char c,int pos=npos) const;
			�滻����ָ����λ���滻�ַ���
				string& replace(int pos,int n,const string& str);//��posλ�ÿ�ʼ��n���ַ����滻Ϊ�ַ���str
				string& replace(int pos,int n,const char* s);//��posλ�ÿ�ʼ��n���ַ����滻Ϊ�ַ���s
*/
void test04()
{
	//�������Ҳ��ң�find
	string str1 = "abcdefgde";
	int pos=str1.find("de");
	cout << "��һ��de�ַ�����λ�ã�" << pos << endl;//3
	pos=str1.find("de", 5);
	cout << "�ڶ���de�ַ�����λ�ã�" << pos << endl;//7
	pos = str1.find("fgde", 0, 2);//ʵ���ϲ��ҵ���fg
	cout << "fg��λ�ã�" << pos << endl;//5
	pos = str1.find('f');
	cout << "f��λ�ã�" << pos << endl;//5

	//����������ң�rfind
	cout << "����������ң�" << endl;
	pos = str1.rfind("de");
	cout << "��һ��de�ַ�����λ�ã�" << pos << endl;//7
	pos=str1.rfind("de", 5);
	cout << "�ڶ���de�ַ�����λ�ã�" << pos << endl;//3
	pos = str1.rfind("fgde", -1, 2);//ʵ���ϲ��ҵ���fg
	cout << "fg��λ�ã�" << pos << endl;//5
	pos = str1.rfind('d');
	cout << "d��λ�ã�" << pos << endl;//7

	//�滻����ָ����λ���滻�ַ���
	str1.replace(1, 4, "8888");
	cout << "���滻��str1=" << str1 << endl;
}

/*
1.6string�ַ����Ƚ�
			�ȽϷ�ʽ���ǰ����ַ�����ÿ���ַ���ASCII������Ƚϣ�����Ƚϳ���С�ͷ��ؽ�������ֱ��������û�бȽϳ���С��֤�������ַ�����ȡ�
			���ԣ��ȽϷ�����Ҫ�����þ����ж������ַ����Ƿ���ȣ����ڴ�Сûʵ�����塣
			����ֵ����ȵ�ʱ�򷵻�0�����ڵ�ʱ�򷵻�1��С�ڷ���-1
				int compare(const string& str) const;//��ǰ�ַ������ַ���str�Ƚ�
				int compare(const char* s) const;//��ǰ�ַ������ַ���s�Ƚ�
*/
void test05()
{
	string s1 = "hello";
	string s2 = "hello";
	string s3 = "Hello";
	int ret1 = s1.compare(s2);//0
	int ret2 = s1.compare(s3);//1
	cout << ret1 << "," << ret2 << endl;
}

/*
1.7string�����ɾ��
			���룺
				string& insert(int pos,const char* s);//��posλ�ò����ַ���s
				string& insert(int pos,const string& str);//��posλ�ò����ַ���str
				string& insert(int pos,int n,char c);//��posλ�ò���n���ַ�c
			ɾ����
				string& erase(int pos,int n);//ɾ����pos��ʼ��n���ַ�
*/
void test06()
{
	string str = "hello world";
	str.insert(1, "888");
	cout << "str=" << str << endl;
	str.insert(1, 3, 'a');
	cout << "str=" << str << endl;
	str.erase(1, 6);
	cout << "str=" << str << endl;
}

/*
1.8string��ȡ���ַ���
			���ַ����н�ȡ��Ҫ�����ַ���
			string& substr(int pos,int n=npos) const;//���ش�pos��ʼ��n���ַ���ɵ����ַ���,n��Ĭ��ֵ��npos���������
		1.9��ȡ����
			size():��ȡ�ַ����ĳ��ȣ�Ҳ�����ַ���
*/
void test07()
{
	string str = "abcdefg";
	string subStr1 = str.substr(1, 3);
	cout << "subStr1=" << subStr1 << endl;
	string subStr2 = str.substr(3);//�ڶ�������ʹ��Ĭ��ֵ����ȡ�����
	cout << "subStr2=" << subStr2 << endl;
	cout << "str��Ԫ�ظ�����" << str.size() << endl;
}

/*
		1.10stringԪ�صĴ�ȡ
			string�е����ַ���ȡ����ͨ������������ʽ��
				char& operator[](int n);//��������أ�ͨ��[index]ȡֵ��index�����±�
				char& at(int n);//ͨ��at��Ա����ȡֵ��nҲ���±�
*/
void test08()
{
	//ȡ������ѯ
	string str = "hello world";
	cout << str[4] << endl;
	cout << str.at(6) << endl;

	//�棬���޸ı���
	str[0] = 'H';
	str[6] = 'W';
	cout << str << endl;

	//ע�⣺Խ�������
	//���ʹ��[]����Ԫ�أ����������Խ����±��������ᵼ�³������
	//cout << str[12] << endl;
	//����ͨ���޶��±꣬��ֹԽ��
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i];
	}
	cout << endl;
	//����ʹ��at���������ʣ�������׳��쳣out_of_range�����ǲ����쳣���д�����
	try
	{
		cout << str.at(12);
	}
	catch (out_of_range& e)
	{
		cout << "Խ����" << endl;
		cout << e.what() << endl;//��ӡ�쳣����
	}
	catch (const std::exception&)
	{
		cout << "�����쳣" << endl;
	}
}

//��ҵ��1.��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"_"��
void replace_space(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]==' ')
		{
			s[i] = '_';
		}
	}
}
void test09()
{
	string s = "We are happy.";
	replace_space(s);
	cout << s << endl;
}
//��ҵ��2.����һ���ַ������һ������
string last_word(string& s)
{
	//˼·�������һ���ո�Ȼ���ȡ
	int index = s.rfind(' ');//�ҵ����ո��λ��
	string sub = s.substr(index + 1);
	return sub;
}
void test10()
{
	string s = "my name is tommy";
	string sub = last_word(s);
	cout << sub << endl;
}
//��ҵ��3.��֤.com���������Ч��
//���򣺱������@, ����@���ܳ����ڵ�һ��λ�ã�Ҫ��.com��β
bool verity_com_email(string& s)
{
	//˼·�������ж�ÿ����Ҫ����������������һ�������㣬��return false�����retrun true
	int index = s.find('@');
	if (index==-1 || index==0)//���û�ҵ�@���߳�������λ��������
	{
		return false;
	}
	index = s.find(".com");
	if (index==-1 || index!=(s.size()-4))//���û�ҵ�.com���߲��������λ��������
	{
		return false;
	}
	return true;
}
void test11()
{
	string e1 = "294950398@qq.com";
	string e2 = "hello123@sina.com";
	string e3 = "welcome@163.com.cn";
	cout << verity_com_email(e1) << endl;
	cout << verity_com_email(e2) << endl;
	cout << verity_com_email(e3) << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//test08();
	//test09();
	//test10();
	test11();
	return 0;
}
