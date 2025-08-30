#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void homework08()
//{
//    // 文件路径
//    string filePath = "file.txt";
//    // 要写入的内容
//    string wenben = "Hello, World! This is a test file.";
//
//    // 创建文件并写入内容
//    ofstream outFile(filePath);
//    if (outFile.is_open())
//    {
//        outFile << wenben;
//        outFile.close();
//        cout << "文件已创建并写入内容。" << endl;
//    }
//    else
//    {
//        cerr << "无法创建文件！" << endl;
//    }
//
//    // 读取文件内容
//    ifstream inFile(filePath);
//    string line;
//    string filewenben;
//
//    if (inFile.is_open())
//    {
//        while (getline(inFile, line))
//        {
//            filewenben += line + "\n";
//        }
//        inFile.close();
//    }
//    else
//    {
//        cerr << "无法打开文件！" << endl;
//        
//    }
//
//    // 输出到屏幕
//    cout << "文件内容：" << endl;
//    cout << filewenben;
//}
    
//方法二：
void homework01()
{
	//思路：写入文件使用输出流对象，方法有很多，使用插入运算符<<，读取的方法使用输入流对象，使用get
	ofstream outfile("D:\\file.txt");
	outfile << "abcdef1234567";
	outfile.close();
	//开始读取
	ifstream infile("D:\\file.txt");
	char ch;
	while (!infile.eof())
	{
		infile.get(ch);
		if (infile.fail())
		{
			break;
		}
		cout << ch;
	}
	infile.close();
}

int main()
{

    //homework08();
    homework01();

    return 0;
}