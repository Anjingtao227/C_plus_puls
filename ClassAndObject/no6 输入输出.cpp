#include<iostream>//���������
#include<iomanip>
#include<fstream>
using namespace std;


void test01()
{
	char c[] = "c++programming";
	cout.put('A').put('B').put('\n');
	cout.write(c, strlen(c)).put('\n');
	cout.write("ABCDEFG", 5).put('\n');
}
void test02()
{
//��ȡ��������� >>
	int a, b;
	cout << "�����������������ո�ָ���";
	cin >> a >> b;
	cout << "a=" << a << ",b=" << b << endl;
//get������ȡ�����ַ�
	char c0;
	cin.get(c0);
	cout << "c0=" << c0 << endl;

//get����ѭ����ȡ����ַ�
	char c;
	int n = 0;
	cin.get(c);
//ÿ��ȡһ���ַ����������Ļ���Ҽ�¼��ȡ�ַ��ĸ�����ֱ�����н���
	while (c != '\n')
	{
		n++;
		cout << c;
		cin.get(c);
	}
	cout << endl<< n << endl;//����������ַ�����

//getline�������Զ�ȡ�ַ���
	char str1[20], str2[20], str3[20];
	cin.getline(str1, 11);
	cin.getline(str2, 11);
	cin.getline(str3, 11);
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
	cout << "str3:" << str3 << endl;
}
void test03()
{
	//���������ȣ�ע�⣬ֻ���´������Ч
	//�����������ݿ�ȱ����õ�С�������Ҷ���ķ�ʽ��������Ĭ��ʹ�ÿո����
	//�����������ݿ�ȱ����õĴ󣬻�������е����ݣ�������Ч
	cout << "1234567890" << endl;//��׼���
	//ʹ�������Ʒ�setw����������
	cout<<setw(6)<< 4.5 << endl;
	cout<<setw(6) << 4.5 <<setw(5) << 6.7<< endl;
	//ʹ�ó�Ա����width����������
	const char* str[3] = { "abc","abcde","abcdefg" };
	cout << "1234567890" << endl;//��׼���
	for (int i = 0; i < 3; i++)
	{
		cout.width(6);
		cout << str[i] << endl;
	}
}
void test04()
{
	//����ַ���ʹ�������Ʒ�setfill��fill����
	//���ã����ÿհ�λ�õ�����ַ���ע�⣬���������������Ч�ģ�ֱ���ٴα��޸�
	//�����Ʒ�setfillʵ��
	double value[] = { 3.25,541,562.528,152 };
	cout << "1234567890" << endl;//��׼���
	cout << setfill('*');
	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << value[i] << endl;
	}
	//ʹ��fill����ʵ�֣��������Է��ؾɵ�����
	cout << "1234567890" << endl;//��׼���
	char oldFill = cout.fill('#');
	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << value[i] << endl;
	}
	//�ָ�Ϊ�ɵ�����
	cout.fill(oldFill);
	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << value[i] << endl;
	}
	cout.fill(' ');
	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << value[i] << endl;
	}
}
void test05()
{
	//����������ȣ���������setprecidion��precision����
	//������Ч��ֱ�����޸�
	//ע�⣺���ȱ�ʾ���ֵ�������ȣ�������������С������
	double pi = 3.1415926545;
	double e = 5.325145124852;
	//ʹ�ú������þ��ȣ�ͬʱ����ɾ���
	int oldPre = cout.precision(4);
	cout << pi << endl;
	cout << e << endl;
	//ʹ�������Ʒ����þ���
	cout << setprecision(8) << pi << endl;
	//�ָ�Ĭ�����ã�����double��Ĭ�Ͼ���
	cout << setprecision(oldPre)<< pi << endl;
}
void test06()
{
	//���������ʽ�����ֽ���
	//������Ч��ֱ�����޸�
	//ʮ���ƣ�dec  �˽��ƣ�oct  ʮ�����ƣ�hex
	int n = 1000;//Ĭ�ϵ�ʮ����
	cout << "ʮ���ƣ�" << n << endl;
	cout <<oct<< "�˽��ƣ�" << n << endl;
	cout <<hex<< "ʮ�����ƣ�" << n << endl;
	cout <<dec<< "ʮ���ƣ�" << n << endl;
}

void test07()
{
	//д���ļ����������
	ofstream out_file("D:\\data.txt", ios::out);//�����ļ���������󣬲����ļ���ʹ��out�ķ�ʽ��
	//1��ʹ�ò����������д�ļ������ַ�ʽ�����ڻ������ͺ��ַ���
	out_file << "hello" << " " << 234 << endl;

	out_file.close();//���ǵùر��ļ�

}

void test08()
{
	//д���ļ����������
	ofstream out_file("D:\\data.txt", ios::app);//�����ļ���������󣬲����ļ���ʹ��app�ķ�ʽ��

	//2��ʹ��put������һ��ֻ��д��һ���ַ�
	out_file.put('A');

	out_file.close();//���ǵùر��ļ�

}
void test09()
{
	//д���ļ����������
	ofstream out_file;
	out_file.open("D:\\data.txt", ios::out|ios::binary);//�����ļ����������Ȼ����ļ���ʹ�ö����Ƶķ�ʽ�򿪣�д���������ַ��ı���ʽ

	//3��ʹ��wirte���������Խ��ڴ���һ������������д���ļ�������˵���顢����ȵ�
	int arr[] = { 23,56,43,45 };
	//write����������������
	//��һ����������ָ���ڴ���ʼ��ַ��������char*��������Ͳ�ƥ�䣬��Ҫ��ת��
	//�ڶ�����������ָ����д���ֽ���������ͨ��sizeof��ȡ
	out_file.write((char*)arr, sizeof(arr));//ע���һ��������Ҫת����char*


	out_file.close();//���ǵùر��ļ�
}


//ʹ��write��������ļ���
class MyClass
{
	int m_nLen;
	int m_nWid;

public:
	MyClass() {};
	MyClass(int x, int y)
	{
		m_nLen = x;
		m_nWid = y;

	}
	void setLen(int len) { m_nLen = len; }
	void setWin(int wid) { m_nWid = wid; }
	void show() { cout << m_nLen << "��" << m_nWid << endl; }
};


void test10()
{
	//д������ļ��У���Ҫ�����ƴ��ļ�
	ofstream outfile;
	outfile.open("D:\\test.txt", ios::out | ios::binary);
	MyClass c(10, 20);
	outfile.write((char*)&c, sizeof(c));
	outfile.close();

}

/*
��ȡ�ļ����������룬��Ҫ�����ʶ�����������ifstream����������
*/
void test11()
{
	//д���ļ����������
	ofstream out_file("D:\\read.txt", ios::out);//�����ļ���������󣬲����ļ���ʹ��out�ķ�ʽ��
	//1��ʹ�ò����������д�ļ������ַ�ʽ�����ڻ������ͺ��ַ���
	out_file << "hello" << " " << 234 << endl;

	out_file.close();//���ǵùر��ļ�

}
void test12()
{
	//1��ʹ����ȡ�����>>����ȡ�ļ��������ڻ������ͺ��ַ���
	//���ҿո��Ʊ�����س����з�������Ϊ���ݶ�ȡ,������Ϊ�ָ���
	char s[10];
	int i;
	ifstream in_file("D:\\data.txt", ios::in);
	in_file >> s >> i;//�ո��Ƿָ�����hello����s��234����i
	cout << "s=" << s << "��i=" << i << endl;
	in_file.close();
	
}
void test13()
{
	//2��ʹ��get�������������Զ�ȡ��һ���ַ�
	char c;
	ifstream in_file("D:\\read.txt");//�ڶ�������ʹ��Ĭ��
	in_file.get(c);
	cout << c << endl;
	in_file.close();
}
void test14()
{
	//ʹ��getline����һ�ζ�ȡһ��
	//�ú�������������
	//��һ�����������ڴ�Ŷ��������ݵ��ڴ��ַ
	//�ڶ�������:ָ����ȡ������ַ�
	//�������ַ�������ָ���ָ�����Ĭ���ǻ��з�
	//��read.txt�ļ������Ӽ�������
	//һ�ζ�һ�У�ÿһ�����ݶ�����ͬһ�����鱣�棬Ȼ�����
	char a[100];
	ifstream in_file("D:\\read.txt");//�ڶ�������ʹ��Ĭ��
	//Ŀǰ�ļ������������ˣ�ʹ��getline��Ҫ������
	for (int i = 0; i < 3; i++) 
	{
		in_file.getline(a, 100);
		cout << a << endl;
	}
	in_file.close();
}

void test15()
{
	//4��read���������Զ�ȡ��������ݵ��ڴ��У������Ƿ��ַ����ݡ����ı����ݣ������������
	//read����������������
	//��һ�����������ڱ�����������ݵ��ڴ��ַ��Ҫ����char*���ͣ�������ǣ���Ҫת������
	//�ڶ�������������ָ����ȡ���ٸ��ַ���ʹ��sizeof��ȡ
	//�ղ���texe.txt�ļ���д��һ��Myclass����c��10��20��������ʹ��read�����������浽һ��ͬ���͵Ķ���ռ���
	ifstream infile("D:\\test.txt", ios::in | ios::binary);//ע���������ʹ�ö����ƶ�ȡ
	MyClass m;//��������������ն�������Ϣ
	infile.read((char*)&m, sizeof(m));
	m.show();
	infile.close();
}

void test16()
{
	//ʹ�ö�дָ�룬���ļ���д������MyClass����Ȼ��ͨ���ƶ���ָ�룬�����ڶ�������
	MyClass c1(100, 200);
	MyClass c2(200, 300);
	ofstream outfile("D:\\obj.txt", ios::out | ios::binary);
	//��ʼд
	outfile.write((char*)&c1, sizeof(c1));
	outfile.write((char*)&c2, sizeof(c2));
	outfile.close();
	//��ʼ�����ƶȵڶ�������
	ifstream infile("D:\\obj.txt", ios::in | ios::binary);
	MyClass c;//������������洢����������
	//������Ҫ�ƶ���ָ�뵽�ڶ�������ͷ��λ�ã���������һ������
	infile.seekg(sizeof(c1), ios::beg);//�ӿ�ͷ���ƶ���һ����С���ֽ������������˵�һ������
	infile.read((char*)&c, sizeof(c));//�ڶ����������������c��
	c.show();//չʾ���Ƕ���������
	infile.close();

}

void test17()
{
	char c;
	ifstream infile("D:\\euftest.txt");
	if (infile.good())
	{
		while (!infile.eof())
		{
			infile.get(c);
			cout << c;
			//�ɼ����������d�ַ���ԭ����eof��������ֻ�ж�����������ʱ��ŷ���true,���������һ�ε�ʱ��,��Ҫ����������ڶ��ξͶ����������ˣ��ڶ��ζ�ȡʧ��
		}
	}
	infile.close();
}

void test18()
{
	//�����������⣬�����֮ǰ������һ�μ�⣬�����ܷ�ɹ���ȡ�������ȡʧ�ܾͲ������
	char c;
	ifstream infile("D:\\euftest.txt");
	if (infile.good())
	{
		while (!infile.eof())
		{
			infile.get(c);
			if (infile.fail())
			{
				break;
			}
			cout << c;
			}
	}
	infile.close();
}

void test19()
{
	char a[100];
	ifstream ifs("D:\\euftest.txt");
	while (!ifs.eof())
	{
		//ʹ��getlineһ�ζ�һ�У������ܵ�eof������Ӱ��
		ifs.getline(a, 100);
		cout << a << endl;

	}
	ifs.close();

}
/*
fstream��������ļ�������������������������ܶ��ļ�����д�ļ���ע�⣺fstream�ܶ���д
*/
void test20()
{
	//ʹ��fstream��D���ļ�d.txt���ж�д����
	fstream iofile("D:\\d.txt", ios::in|ios::out);
	//�����������ļ��е��������ݱ��浽���ڴ棬��ȥͳ���ļ����ܴ�С���Ѿ�������ȥ������Ķ��ڴ�
	iofile.seekg(0, ios::end);//����ָ���ƶ�����β
	//��ȡ��ָ���λ�ã��᷵��һ�����ͣ���������ʹ����ļ���С���ֽ���
	streampos len_of_file = iofile.tellg();
	//����len_of_file��������ڴ�
	char* data = new char[len_of_file];
	//���������ļ����ݶ������ڴ���
	iofile.seekg(0,ios::beg);//ע�⣺��ָ��Ҫ�����ƶ�����ͷ
	cout << "���ļ��ж��������ݣ�" << endl;
	iofile.read(data, len_of_file);

	for (int i = 0; i < len_of_file; i++)
	{
		cout << data[i];
	}
	//����������д�������Ѷ����������ٴ�д���ļ�
	iofile.seekg(0, ios::end);
	iofile.write(data, len_of_file);
	delete[]data;
	data = NULL;
	iofile.close();


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
	//test11();
	//test12();
	//test13();
	//test14();
	//test15();
	//test16();
	//test17();
	//test18();
	//test19();
	test20();


	return 0;
}