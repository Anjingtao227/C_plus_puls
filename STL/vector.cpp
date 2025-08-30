#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
2 vector��̬����
	2.1vector�Ļ�������
	vector�����ݽṹ������ǳ����ƣ�Ҳ�����������顣
	vector����������������Ǿ�̬�ģ�һ������������ĳ��ȣ��ǲ��ɱ�ġ���vector�Ƕ�̬�ģ����ĳ��ȿ��Զ�̬��չ��
		��չԭ�����ռ䲻���ʱ���������Ԫ�أ�vector����������һ�������ڴ�ռ䣬���ҽ��ɿռ�����ݿ������¿ռ䣬Ȼ���ͷžɿռ䡣
		�漰�������������capacity �� ��Сsize������ָ���ǿռ���ܴ�С��sizeָ����ʵ�ʴ�ŵ�Ԫ������
	2.2vector���캯��
		vector<T> v;//������ģ��ʵ�֣��޲ι��죬������һ���յ�vector����������v
		vector<T> vec(v.begin(),v.end());//����������������������λ�ã�v��һ��vector���󣬽�v[begin,end)�����е�Ԫ�ؿ�������ǰvec������ɹ��졣
		vector<T> v(const vector& vec);//��������
		vector<T> v(n,ele);//ele��element����Ԫ�ء�ʹ��n��eleԪ����ɵ�ǰvector����Ĺ��졣
*/

//��ӡ����
void printVector(vector<int>& v)
{
	//ʹ�õ��������������е�������ӡ
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	vector<int> v1;//�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//vector<T> vec(v.begin(),v.end());//����������������������λ��
	vector<int> v2(v1.begin(),v1.end());
	printVector(v2);
	//vector<T> v(const vector& vec);//��������
	vector<int> v3(v2);
	printVector(v3);
	//vector<T> v(n,ele);
	vector<int> v4(10, 100);
	printVector(v4);
}

/*
2.3vector��ֵ
		���ظ�ֵ�������
			vector& operator=(const vector& vec);
		��Ա����assign:
			assign(beg,end);//��vector[beg,end)�����Ԫ�ظ�ֵ����ǰ��vector����beg��end������������λ��
			assign(n,ele);//��n��eleԪ�ظ�ֵ����ǰvector
*/
void test02()
{
	vector<int> v1;//�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	//���ظ�ֵ�����
	vector<int> v2;
	v2 = v1;
	printVector(v2);
	//��Ա����assign
	vector<int> v3;
	v3.assign(v1.begin() + 2, v1.end() - 2);//ȥ����ǰ���2��Ԫ��
	printVector(v3);
	vector<int> v4;
	v4.assign(10, 100);
	printVector(v4);
}

/*
2.4vector�����ʹ�С
		empty();//�ж������Ƿ�Ϊ��
		capacity();//��������������
		size();//����������Ԫ�صĸ���
		resize(int num);//����ָ��������sizeΪnum�����������size����ˣ�����Ĭ��ֵ�������λ�ã����size�����ˣ���ɾ�������Ԫ�ء�
		resize(int num,ele);//����ָ��������sizeΪnum�����������size����ˣ�����eleԪ���������λ�ã����size�����ˣ���ɾ�������Ԫ�ء�
*/
void test03()
{
	vector<int> v1;//�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1��������" << v1.capacity() << endl;
		cout << "v1�Ĵ�С��" << v1.size() << endl;
	}
	//resize(int num)
	v1.resize(5);
	printVector(v1);
	v1.resize(10);
	printVector(v1);
	v1.resize(15, 100);
	printVector(v1);
	//����
	v1.resize(5);
	printVector(v1);
	cout << "v1��������" << v1.capacity() << endl;//�ɼ�������û������resize����С����С���������ڴ���˷�
	//������������˷ѿռ䣬����ʹ��һ�����ݺ���
	v1.shrink_to_fit();
	cout << "����֮��" << endl;
	cout << "v1��������" << v1.capacity() << endl;
}

/*
2.5vector�����ɾ��
		β��������
			push_back(ele);//β������һ��Ԫ��ele
			pop_back();//β�����һ��Ԫ��ele������
		ָ��λ�ò��룺insert
			insert(iterator pos,ele);//������ָ��λ��pos����Ԫ��ele�����ҷ����²���Ԫ�ص�λ�õ�������
			insert(iterator pos,int n,ele);//������ָ��λ��pos����n��Ԫ��ele�����ҷ����²�����Ԫ�صĵ�һ��Ԫ�ص�λ�õ�������
			insert(iterator pos,beg,end);//��posλ�ò�����һ��������[beg,end)�����е�ֵ
		ɾ����erase
			erase(iterator pos);//ɾ����������ָ���Ԫ�أ����ر�ɾ��Ԫ�ص���һ��������λ�á�
			erase(iterator beg,iterator end);//ɾ��beg��end֮���Ԫ�أ�������end
			clear();//��������е�����Ԫ��
		ע�⣺ɾ�����߲���������ᵼ��ɾ���Ͳ���λ���Լ��Ժ�λ�õĵ������ı䣬�������Ҫ����ʹ�õ����������������Ԫ�أ��ͱ�����µ�������
			���ԭ�������������ռ�����ݽṹ��������������Ҫѧϰ������һ������deque�����Ƕ��ں�����ѧϰ�Ļ�����������������������Ͳ������ˡ�����list��map��set�ȡ�
*/
void test04()
{
	//β������
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	//β��ɾ��
	v1.pop_back();
	printVector(v1);
	v1.pop_back();
	printVector(v1);
	//ָ��λ�ò��룺insert
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	vector<int> v2 = { 6,7,8,9,0 };//��ʼ���б�����ʼ������
	v1.insert(v1.begin(), v2.begin(), v2.begin() + 2);
	printVector(v1);
	//ɾ����erase
	v1.erase(v1.begin());
	printVector(v1);
	v1.erase(v1.begin(), v1.begin() + 2);
	printVector(v1);

	//����insert�ķ���ֵ������Ԫ�ص�ǰ��λ��
	vector<int>::iterator it = v1.insert(v1.begin() + 1, 500);
	printVector(v1);
	cout << *it << endl;//500

	//ɾ��erase�᷵�ر�ɾԪ�ص���һ��Ԫ�ص�λ��
	vector<int>::iterator it_erase = v1.erase(v1.begin() + 1);
	printVector(v1);
	cout << *it_erase << endl;
	it_erase = v1.erase(v1.begin(), v1.begin() + 2);//ɾ��ǰ����ֵ
	printVector(v1);
	cout << *it_erase << endl;
}

//���ڵ�����ʧЧ������
void test05()
{
	vector<int> v = {10,20,30,30,40,50};
	printVector(v);
	////ɾ�������е�30
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (*it==30)
	//	{
	//		v.erase(it);//���ɾ�������ᵼ�µ�ǰλ�úͺ�������λ�õĵ�����ʧЧ����Ϊ�����Ԫ����ǰ�ƶ���
	//	}
	//}

	////�������Ҫ����ʹ�õ����������������Ԫ�أ��ͱ�����µ�����
	//for (vector<int>::iterator it = v.begin(); it != v.end(); )
	//{
	//	if (*it == 30)
	//	{
	//		it=v.erase(it);//erase�᷵�ر�ɾԪ�ص���һ��Ԫ�صĵ���������it���и��²���������it���൱������++����
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}
	//printVector(v);

	////whileѭ����ʵ��
	//vector<int>::iterator it = v.begin();
	//while (it!=v.end())
	//{
	//	if (*it==30)
	//	{
	//		it = v.erase(it);
	//	}
	//	else
	//	{
	//		it++;
	//	}
	//}
	//printVector(v);


	////�������Ҳ�ᵼ�µ�����ʧЧ��Ҫ��30��λ�ò���100
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	if (*it==30)
	//	{
	//		it=v.insert(it,100);//�����������ѭ������Ϊinsert�᷵�ز���Ԫ�ص�λ�ã����λ�þ���30֮ǰ��λ�ã��൱��it--��
	//		it++;//������Ҫ��������һ�����õ������ص�����λ��
	//	}
	//}
	//printVector(v);

	//whileѭ��ʵ��
	vector<int>::iterator it = v.begin();
	while (it!=v.end())
	{
		if (*it==30)
		{
			it = v.insert(it, 100);
			it++;
		}
		it++;
	}
	printVector(v);
}

/*
2.6vector���ݴ�ȡ
		operator[];//������[]�����������ͨ���±�ȡֵ
		at(int index);//��������indexλ�õ�Ԫ��
		front();//���������е�һ��Ԫ��
		back();//�������������һ��Ԫ��
*/
void test06()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);
	cout << v1[2]<<"," << v1.at(3)<<","<<v1.front()<<","<<v1.back();
}

/*
2.7vector����
		����ʵ������vector����Ԫ�صĻ���
		v1.swap(v2);//v1��v2����Ԫ��
*/
void test07()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	cout << "v1:";
	printVector(v1);
	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	cout << "v2:";
	printVector(v2);
	//����
	v1.swap(v2);
	cout << "������" << endl;
	cout << "v1:";
	printVector(v1);
	cout << "v2:";
	printVector(v2);
}

/*
2.8vectorԤ���ռ�
		��vector�洢���������ܴ�ʱ������vector�Ķ�̬�������ԣ��ᵼ�¶�εĶ�̬��չ�����������ή��Ч�ʡ�
		Ϊ�˱�������չ�����������������һ��ʼ��ָ��һЩԤ���Ŀռ䣬��ʵ����ָ����capacity��ֵ��
		reserve(int len);//������Ԥ��len��Ԫ�ص�λ�ã�Ԥ����λ�ò��ɷ��ʣ���Ϊû�б���ʼ����
*/
void test08()
{
	vector<int> v;
	//v.reserve(10);//Ԥ��10��λ��
	v.reserve(9);//Ԥ��9��λ��
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		//����ͨ���۲��ַ������û�з�����̬��չ
		cout << &v[0] <<" ";//ʼ�ղ鿴��һ��Ԫ�صĵ�ַ������б仯��˵�������˶�̬��չ
		cout << v.capacity() << endl;;
	}
}

/*
	2.9�������õ��㷨��������Ҫ����ͷ�ļ�#include <algorithm>��
		�����㷨�������ڴ󲿷������ģ�����vector�ĳ�Ա����
		����
			sort(iterator beg,iterator end);//�������ڵ�Ԫ�ؽ�������Ĭ�����򣬴�С����
			sort(iterator beg,iterator end,func);//�������ڵ�Ԫ�ؽ�������ʹ��funcָ������ʽ
		��ת��
			reverse(iterator beg,iterator end);//��������Ԫ�ط�ת����
		���ƣ�
			copy(Դ������ʼλ�ã�Դ��������λ�ã�Ŀ����������ʼλ��);//��Դ����������Ԫ�ظ��Ƶ�Ŀ������ָ��λ�ã�ע�����滻���¸��ƽ�ȥ��ֵ�滻��ԭ��λ�õ�ֵ
		���ң�
			find(iterator beg,iterator end,ele);//�������ڲ���Ԫ��ele���ҵ���������λ�õĵ��������Ҳ�������end��������ע�����endָ����������ָ����endλ�ã���һ��������������end()��
		������
			for_each(iterator beg,iterator end,func);//�������������ڵ�Ԫ�أ�func�Ǹ��������߷º�����ָ������ʱ��Ԫ�صĲ�����
	2.10�ܽ�
		vector�ǵ������飬��������β���Ĳ����ɾ������Ч�ʺܸߣ�����������λ����insert���������ʱ��Ч�ʺܵͣ�ԭ���ǻ���������Ԫ�ص��ƶ���
		ͬʱ���������Ƕ�̬���飬�������洢������ռ䣬���Կ���ͨ���±�ֱ�ӷ��ʣ����Բ���Ч�ʺܸߡ�

*/

//����������
bool cap(int a, int b) { return a > b; }//��������
//���ڱ���ʱ����Ԫ�صĺ���
void myPrint(int val)
{
	val++;
	cout << val << " ";
}
void test09()
{
	vector<int> v1 = { 39,5,42,68,49,22,55 };
	//��������
	sort(v1.begin(), v1.end());
	cout << "���������";
	printVector(v1);
	//ʵ�ֽ���������Ҫ�Լ�дһ������ָ�������������������Խ�������������
	sort(v1.begin(), v1.end(), cap);
	cout << "���������";
	printVector(v1);
	
	//��ת
	reverse(v1.begin(), v1.begin() + 5);
	cout << "��תǰ���ֵ��";
	printVector(v1);

	//����
	vector<int> v2;
	v2.assign(10, 100);
	printVector(v2);
	//��������v1��ǰ���ֵ���Ƹ�v2�Ŀ�ͷ��
	copy(v1.begin(), v1.begin() + 5, v2.begin());
	cout << "v1��ǰ���ֵ���Ƹ�v2�Ŀ�ͷ��:";
	printVector(v2);

	//����
	vector<int>::iterator it =find(v1.begin(), v1.begin() + 5, 68);
	if (it==(v1.begin()+5))
	{
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ��ˣ�����ֵ�ǣ�" << *it << "�������±��ǣ�" << it - v1.begin() << endl;
	}

	//����
	for_each(v1.begin(), v1.end(), myPrint);
}

//������ҵ��1.ʹ�����ֲ�ͬ�ķ�ʽ��vector���д�ӡ
void print_for_each(int value) { cout << value << " "; }
void test10()
{
	vector<int> v = { 1,2,3,4,5 };
	//1.������+forѭ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	//2.�±�����+forѭ��
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl;
	//3.for_each�㷨
	for_each(v.begin(), v.end(), print_for_each);
}
//��չ��ʵ��һ����ӡvector�����ĺ���ģ��
template<typename T>
void print_vector(const vector<T>& vec)
{
	//const��������ʹ��const_iterator������
	//���ʹ����ģ�壬������iterator֮ǰ����typename������������һ������
	for (typename vector<T>::const_iterator it= vec.begin(); it!=vec.end();it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test11()
{
	const vector<int> int_v = { 1,2,3,4,5 };//const���ε����������ڲ�Ԫ�ؽ�ֹ�޸�
	vector<string> str_v = { "hello","world","C++" };
	print_vector(int_v);
	print_vector(str_v);
}
//������ҵ��2.ʹ��vector�����洢���Person(m_Name,m_Age)���󣬸���������н�������������ÿ�����������
class Person
{
public:
	string m_Name;
	int m_Age;
	Person(string name,int age):m_Name(name),m_Age(age){}
};
//�������併�������������
bool compare_by_age(Person& p1, Person& p2) { return p1.m_Age > p2.m_Age; }
void test12()
{
	vector<Person> v;
	Person p1("lucy", 10);
	Person p2("tommy", 8);
	Person p3("john", 12);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	//�������
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).m_Name << ",���䣺" << it->m_Age << endl;//����ȡ���Եķ�ʽ
	}
	sort(v.begin(), v.end(), compare_by_age);
	cout << "����֮��" << endl;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << (*it).m_Name << ",���䣺" << it->m_Age << endl;//����ȡ���Եķ�ʽ
	}
}
//������ҵ��3.vector�����д洢���vector<int>���������ÿ��vector<int>�е�Ԫ��
void test13()
{
	//�����������
	vector<vector<int>> v;
	//�����ڲ�����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	v1 = { 1,2 };
	v2 = { 1,2,3 };
	v3 = { 1,2,3,4 };
	v4 = { 1,2,3,4,5 };
	v = { v1,v2,v3,v4 };
	//��������Ҫ˫��ѭ��
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator vit = it->begin(); vit != it->end(); vit++)
		{
			cout << *vit << " ";
		}
		cout << endl;
	}
}

//��ҵ1.����һ��������vector��̬���� nums������ÿ�����ֵ�ƽ����ɵ��¶�̬���飬Ҫ����������
//˼·���������飬��ÿ�����ֵ�ƽ����Ȼ�󽫽�����������飬�ٽ�������
vector<int> num_to_power(vector<int>& v)
{
	vector<int> res;
	for (int i = 0; i < v.size(); i++)
	{
		res.push_back(v.at(i) * v.at(i));
	}
	sort(res.begin(), res.end());
	return res;
}
void test14()
{
	vector<int> v1 = { -4,3,0,-1,10 };
	vector<int> res = num_to_power(v1);
	printVector(res);
}

//��ҵ2.����һ����̬���� nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//˼·�����ҵ���ɾ����ͬʱ��¼ɾ�˼����������ӵ�ĩβ
void backZero(vector<int>& v)
{
	int num = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); )
	{
		if (*it==0)
		{
			it = v.erase(it);
			num++;
		}
		else
		{
			it++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		v.push_back(0);
	}
}
void test15()
{
	vector<int> v1 = { 0,1,0,3,12 };
	backZero(v1);
	printVector(v1);
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
	test15();

	return 0;
}
