#include <iostream>
using namespace std;
int main()
{
	/*
		switch(���ʽ)
		{
			case ����1:
				ִ�����1;
				break;
			case ����2:
				ִ�����2;
				break;
				....
			case ����n:
				ִ�����n;
				break;
			default:
				ִ�����;
		}
	*/

	//int number = 3;
	//switch (number)
	//{
	//	case 1:
	//		cout << "��һ" << endl;
	//		break;
	//	case 2:
	//		cout << "�ܶ�" << endl;
	//		break;
	//	case 3:
	//		cout << "����" << endl;
	//		break;
	//	default:
	//		cout << "�������������" << endl;
	//	break;
	//}

	// ��ϰ���ж��û��ĳɼ������ĸ��ȼ� [90~100]A [80,89]B  [70,79]C [60,69]D [0,59]������
	int score = 100;
	// ��ȡ������ʮλ��
	score /= 10;
	switch (score)
	{
		// �����Ϊ10��ʱ��ֱ�Ӵ�͸��9ִ�д��뼴��
		case 10:
		case 9:
			cout << "A" << endl;
			break;
		case 8:
			cout << "B" << endl;
			break;
		case 7:
			cout << "C" << endl;
			break;
		case 6:
			cout << "D" << endl;
			break;
		default:
			cout << "������" << endl;
	}
	return 0;
}