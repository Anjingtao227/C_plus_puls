#pragma once

//����һ�������࣬������Rect
class Rect
{
	//���������������ȺͿ��
	//����Ҳ�������淶��m_����������д+������������ʹ�ô��շ壩
private:
	int m_nLength;
	int m_nWidth;
	//����
	//���������淶��һ��������������ɣ���һ������ȫСд��������������ĸ��д
public:
	//�Լ�����һ�����캯���������������ʵ�ֳ�ʼ�����������Լ�д�˹��캯��֮�󣬱������Ͳ�������Ĭ�ϵ��Ǹ��޲ι��캯��
	Rect();//�����޲ι��캯��
	Rect(int nLength, int nWidth);//�����вι��캯��������������
	Rect(int nLength);
	void setLength(int nLength);//���þ��εĳ���
	void setWidth(int nWidth);//���þ��εĿ��
	int getArea();//������ε����
	int getPerimeter();//������ε��ܳ�
};