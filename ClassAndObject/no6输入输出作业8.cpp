#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void homework08()
//{
//    // �ļ�·��
//    string filePath = "file.txt";
//    // Ҫд�������
//    string wenben = "Hello, World! This is a test file.";
//
//    // �����ļ���д������
//    ofstream outFile(filePath);
//    if (outFile.is_open())
//    {
//        outFile << wenben;
//        outFile.close();
//        cout << "�ļ��Ѵ�����д�����ݡ�" << endl;
//    }
//    else
//    {
//        cerr << "�޷������ļ���" << endl;
//    }
//
//    // ��ȡ�ļ�����
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
//        cerr << "�޷����ļ���" << endl;
//        
//    }
//
//    // �������Ļ
//    cout << "�ļ����ݣ�" << endl;
//    cout << filewenben;
//}
    
//��������
void homework01()
{
	//˼·��д���ļ�ʹ����������󣬷����кܶ࣬ʹ�ò��������<<����ȡ�ķ���ʹ������������ʹ��get
	ofstream outfile("D:\\file.txt");
	outfile << "abcdef1234567";
	outfile.close();
	//��ʼ��ȡ
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