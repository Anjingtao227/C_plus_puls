#include<iostream>//输入输出流
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
//提取运算符输入 >>
	int a, b;
	cout << "亲输入两个整数，空格分隔：";
	cin >> a >> b;
	cout << "a=" << a << ",b=" << b << endl;
//get方法读取单个字符
	char c0;
	cin.get(c0);
	cout << "c0=" << c0 << endl;

//get方法循环读取多个字符
	char c;
	int n = 0;
	cin.get(c);
//每读取一个字符就输出到屏幕并且记录读取字符的个数，直到换行结束
	while (c != '\n')
	{
		n++;
		cout << c;
		cin.get(c);
	}
	cout << endl<< n << endl;//输出读到的字符个数

//getline方法可以读取字符串
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
	//设置输出宽度，注意，只对下次输出有效
	//如果输出的数据宽度比设置的小，会以右对齐的方式输出，左边默认使用空格填充
	//如果输出的数据宽度比设置的大，会输出所有的数据，设置无效
	cout << "1234567890" << endl;//标准宽度
	//使用流控制符setw设置输出宽度
	cout<<setw(6)<< 4.5 << endl;
	cout<<setw(6) << 4.5 <<setw(5) << 6.7<< endl;
	//使用成员函数width设置输出宽度
	const char* str[3] = { "abc","abcde","abcdefg" };
	cout << "1234567890" << endl;//标准宽度
	for (int i = 0; i < 3; i++)
	{
		cout.width(6);
		cout << str[i] << endl;
	}
}
void test04()
{
	//填充字符，使用流控制符setfill和fill函数
	//作用：设置空白位置的填充字符，注意，这个设置是永久有效的，直到再次被修改
	//流控制符setfill实现
	double value[] = { 3.25,541,562.528,152 };
	cout << "1234567890" << endl;//标准宽度
	cout << setfill('*');
	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << value[i] << endl;
	}
	//使用fill函数实现，函数可以返回旧的设置
	cout << "1234567890" << endl;//标准宽度
	char oldFill = cout.fill('#');
	for (int i = 0; i < 4; i++)
	{
		cout << setw(10) << value[i] << endl;
	}
	//恢复为旧的设置
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
	//设置输出精度：控制流符setprecidion和precision函数
	//永久有效，直到被修改
	//注意：精度表示数字的整个宽度，包含了整数和小数部分
	double pi = 3.1415926545;
	double e = 5.325145124852;
	//使用函数设置精度，同时保存旧精度
	int oldPre = cout.precision(4);
	cout << pi << endl;
	cout << e << endl;
	//使用流控制符设置精度
	cout << setprecision(8) << pi << endl;
	//恢复默认设置，就是double的默认精度
	cout << setprecision(oldPre)<< pi << endl;
}
void test06()
{
	//设置输出显式的数字进制
	//永久有效，直到被修改
	//十进制：dec  八进制：oct  十六进制：hex
	int n = 1000;//默认的十进制
	cout << "十进制：" << n << endl;
	cout <<oct<< "八进制：" << n << endl;
	cout <<hex<< "十六进制：" << n << endl;
	cout <<dec<< "十进制：" << n << endl;
}

void test07()
{
	//写入文件，属于输出
	ofstream out_file("D:\\data.txt", ios::out);//创建文件输出流对象，并打开文件，使用out的方式打开
	//1、使用插入运算符来写文件，这种方式适用于基本类型和字符串
	out_file << "hello" << " " << 234 << endl;

	out_file.close();//最后记得关闭文件

}

void test08()
{
	//写入文件，属于输出
	ofstream out_file("D:\\data.txt", ios::app);//创建文件输出流对象，并打开文件，使用app的方式打开

	//2、使用put函数，一次只能写入一个字符
	out_file.put('A');

	out_file.close();//最后记得关闭文件

}
void test09()
{
	//写入文件，属于输出
	ofstream out_file;
	out_file.open("D:\\data.txt", ios::out|ios::binary);//创建文件输出流对象，然后打开文件，使用二进制的方式打开，写入数组这种非文本格式

	//3、使用wirte函数，可以将内存中一段连续的内容写入文件，比如说数组、对象等等
	int arr[] = { 23,56,43,45 };
	//write函数参数有两个：
	//第一个参数用于指定内存起始地址，类型是char*，如果类型不匹配，需要做转换
	//第二个参数用于指定缩写的字节数，可以通过sizeof获取
	out_file.write((char*)arr, sizeof(arr));//注意第一个参数需要转换成char*


	out_file.close();//最后记得关闭文件
}


//使用write输出对象到文件中
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
	void show() { cout << m_nLen << "，" << m_nWid << endl; }
};


void test10()
{
	//写入对象到文件中，需要二进制打开文件
	ofstream outfile;
	outfile.open("D:\\test.txt", ios::out | ios::binary);
	MyClass c(10, 20);
	outfile.write((char*)&c, sizeof(c));
	outfile.close();

}

/*
读取文件，属于输入，需要定义问二建输入流：ifstream对象来操作
*/
void test11()
{
	//写入文件，属于输出
	ofstream out_file("D:\\read.txt", ios::out);//创建文件输出流对象，并打开文件，使用out的方式打开
	//1、使用插入运算符来写文件，这种方式适用于基本类型和字符串
	out_file << "hello" << " " << 234 << endl;

	out_file.close();//最后记得关闭文件

}
void test12()
{
	//1、使用提取运算符>>来读取文件，适用于基本类型和字符串
	//并且空格、制表符、回车换行符不会作为数据读取,而是作为分隔符
	char s[10];
	int i;
	ifstream in_file("D:\\data.txt", ios::in);
	in_file >> s >> i;//空格是分隔符，hello给了s，234给了i
	cout << "s=" << s << "，i=" << i << endl;
	in_file.close();
	
}
void test13()
{
	//2、使用get函数来读，可以读取第一个字符
	char c;
	ifstream in_file("D:\\read.txt");//第二个参数使用默认
	in_file.get(c);
	cout << c << endl;
	in_file.close();
}
void test14()
{
	//使用getline函数一次读取一行
	//该函数有三个参数
	//第一个参数：用于存放读出的数据的内存地址
	//第二个参数:指定读取的最大字符
	//第三个字符：用于指定分隔符，默认是换行符
	//给read.txt文件多增加几行内容
	//一次读一行，每一行内容都放入同一个数组保存，然后输出
	char a[100];
	ifstream in_file("D:\\read.txt");//第二个参数使用默认
	//目前文件中有三行内人，使用getline需要读三次
	for (int i = 0; i < 3; i++) 
	{
		in_file.getline(a, 100);
		cout << a << endl;
	}
	in_file.close();
}

void test15()
{
	//4、read函数，可以读取整块的数据到内存中，可以是非字符数据、非文本数据，比如对象、数组
	//read函数有两个参数：
	//第一个参数：用于保存读出的数据的内存地址，要求是char*类型，如果不是，需要转换类型
	//第二个参数：用于指定读取多少个字符，使用sizeof获取
	//刚才往texe.txt文件中写入一个Myclass对象c（10，20），现在使用read读出来，保存到一个同类型的对象空间中
	ifstream infile("D:\\test.txt", ios::in | ios::binary);//注意对象类型使用二进制读取
	MyClass m;//这个对象用来接收读到的信息
	infile.read((char*)&m, sizeof(m));
	m.show();
	infile.close();
}

void test16()
{
	//使用读写指针，给文件中写入两个MyClass对象，然后通过移动都指针，读出第二个对象
	MyClass c1(100, 200);
	MyClass c2(200, 300);
	ofstream outfile("D:\\obj.txt", ios::out | ios::binary);
	//开始写
	outfile.write((char*)&c1, sizeof(c1));
	outfile.write((char*)&c2, sizeof(c2));
	outfile.close();
	//开始读，制度第二个对象
	ifstream infile("D:\\obj.txt", ios::in | ios::binary);
	MyClass c;//这个对象用来存储读到的内容
	//接下来要移动都指针到第二个对象开头的位置，即跳过第一个对象
	infile.seekg(sizeof(c1), ios::beg);//从开头处移动第一个大小的字节数，就跳过了第一个对象
	infile.read((char*)&c, sizeof(c));//第二个对象读出来存入c中
	c.show();//展示我们读到的内容
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
			//可见输出了两个d字符，原因是eof（）函数只有读到结束符的时候才返回true,所以输出第一次的时候,还要往后读，但第二次就读不到东西了，第二次读取失败
		}
	}
	infile.close();
}

void test18()
{
	//解决上面的问题，在输出之前，先做一次检测，看看能否成功读取，如果读取失败就不输出了
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
		//使用getline一次读一行，不会受到eof函数的影响
		ifs.getline(a, 100);
		cout << a << endl;

	}
	ifs.close();

}
/*
fstream输入输出文件流，既能输入又能输出，既能读文件又能写文件。注意：fstream能读能写
*/
void test20()
{
	//使用fstream对D盘文件d.txt进行读写操作
	fstream iofile("D:\\d.txt", ios::in|ios::out);
	//接下来，将文件中的所有内容保存到堆内存，先去统计文件的总大小，已决定我们去申请多大的堆内存
	iofile.seekg(0, ios::end);//将都指针移动到结尾
	//获取读指针的位置，会返回一个整型，这个整数就代表文件大小的字节数
	streampos len_of_file = iofile.tellg();
	//根据len_of_file来申请堆内存
	char* data = new char[len_of_file];
	//接下来将文件内容读到堆内存中
	iofile.seekg(0,ios::beg);//注意：都指针要重新移动到开头
	cout << "从文件中读到的内容：" << endl;
	iofile.read(data, len_of_file);

	for (int i = 0; i < len_of_file; i++)
	{
		cout << data[i];
	}
	//接下来进行写操作，把读到的内容再次写入文件
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