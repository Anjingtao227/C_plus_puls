#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//void homework09()
//{
//    // ԭ�ļ�·��
//    string sourceFilePath = "D:\\file.txt";
//    // Ŀ���ļ�·��
//    string destinationFilePath = "D:\\filecopy.txt";
//
//    // ��ԭ�ļ�
//    ifstream inFile(sourceFilePath);
//    if (!inFile.is_open()) 
//    {
//        cerr << "�޷���ԭ�ļ� " << sourceFilePath << "��" << endl;
//    }
//
//    // ����Ŀ���ļ�
//    ofstream outFile(destinationFilePath);
//    if (!outFile.is_open()) 
//    {
//        cerr << "�޷�����Ŀ���ļ� " << destinationFilePath << "��" << endl;
//        inFile.close();
//    }
//
//    // ���ж�ȡԭ�ļ����ݲ�д��Ŀ���ļ�
//    string line;
//    while (getline(inFile, line)) 
//    {
//        outFile << line << endl;
//    }
//
//    // �ر��ļ�
//    inFile.close();
//    outFile.close();
//
//    cout << "�ļ������ѳɹ����Ƶ� " << destinationFilePath << endl;
//}

//��������
void homework02()
{
	//˼·������һ���ַ�һ���ַ���������һ���ַ�дһ���ַ���Ҳ�������������Ҫ���������ַ�����Ȼ�����붯̬�ռ䱣�棬Ȼ��д���µ��ļ���
	//��һ�֣�ʹ��get��put������һ���ַ�Ϊ��λ���������ŵ���ռ�ÿռ��С�����ÿ����ļ���С��
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

	//�ڶ��֣������������д����ڴ棬Ȼ��д�������ļ���
	ifstream infile("D:\\file.txt");
	infile.seekg(0, ios::end);//��ָ���ƶ���ĩβ
	streampos len_of_file = infile.tellg();//��ȡ�ļ�����
	char* data = new char[len_of_file];
	//��������ȡ�ļ����浽data��
	infile.seekg(0, ios::beg);//��ָ�����ƶ���ͷ��
	infile.read(data, len_of_file);
	//��ʼд�뿽���ļ�
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