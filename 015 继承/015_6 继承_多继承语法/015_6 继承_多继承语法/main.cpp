/*
��̳��﷨��
	C++�����̳У�һ����̳ж���ࣩ
	�﷨��class ���� ���̳з�ʽ ����1�� �̳з�ʽ ����2...
	��̳п��ܻ�����������ͬ����Ա���֣���Ҫ������������
ע��C++ʵ�ʿ����в�����ʹ�ö�̳У�
*/
#include <iostream>
using namespace std;
class Base1
{
public:
	Base1() 
	{
		num = 19;
	}
	int num;
};
class Base2
{
public:
	Base2()
	{
		num = 20;
	}
	int num;
};
class Son :public Base1, public Base2
{
public:
	Son()
	{
		num = 90;
	}
	int num;
};

int main()
{
	//
	Son s;
	cout << "����1 num = " << s.Base1::num << endl;
	cout << "����2 num = " << s.Base2::num << endl;
	cout << "���� num = " << s.num << endl;


	return 0;
}