#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void homework09()
//{
//    // 原文件路径
//    string sourceFilePath = "D:\\file.txt";
//    // 目标文件路径
//    string destinationFilePath = "D:\\filecopy.txt";
//
//    // 打开原文件
//    ifstream inFile(sourceFilePath);
//    if (!inFile.is_open()) 
//    {
//        cerr << "无法打开原文件 " << sourceFilePath << "！" << endl;
//    }
//
//    // 创建目标文件
//    ofstream outFile(destinationFilePath);
//    if (!outFile.is_open()) 
//    {
//        cerr << "无法创建目标文件 " << destinationFilePath << "！" << endl;
//        inFile.close();
//    }
//
//    // 逐行读取原文件内容并写入目标文件
//    string line;
//    while (getline(inFile, line)) 
//    {
//        outFile << line << endl;
//    }
//
//    // 关闭文件
//    inFile.close();
//    outFile.close();
//
//    cout << "文件内容已成功复制到 " << destinationFilePath << endl;
//}

//方法二：
void homework02()
{
	//思路：可以一个字符一个字符操作，读一个字符写一个字符，也可以整体计算需要读出来的字符数，然后申请动态空间保存，然后写入新的文件。
	//第一种：使用get和put方法，一个字符为单位来操作，优点是占用空间很小，不用考虑文件大小。
	//ifstream infile("D:\\file.txt");
	//ofstream outfile("D:\\filecopy.txt");
	//char ch;
	//while (!infile.eof())
	//{
	//	if (infile.fail())
	//	{
	//		break;
	//	}
	//	infile.get(ch);
	//	outfile.put(ch);
	//}
	//infile.close();
	//outfile.close();

	//第二种：整体读出来，写入堆内存，然后写道拷贝文件中
	ifstream infile("D:\\file.txt");
	infile.seekg(0, ios::end);//读指针移动到末尾
	streampos len_of_file = infile.tellg();//获取文件长度
	char* data = new char[len_of_file];
	//接下来读取文件保存到data中
	infile.seekg(0, ios::beg);//读指针再移动回头部
	infile.read(data, len_of_file);
	//开始写入拷贝文件
	ofstream outfile("D:\\filecopy.txt");
	outfile.write(data, len_of_file);
	delete[]data;
	data = NULL;
	infile.close();
	outfile.close();
}
int main()
{

	//homework09();
	homework02();

	return 0;
}