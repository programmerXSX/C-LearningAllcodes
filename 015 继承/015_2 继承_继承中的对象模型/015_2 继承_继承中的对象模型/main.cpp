/*
���������зǾ�̬��Ա���Զ��ᱻ�̳���ȥ
ֻ����˽�г�Ա���Ա������������ˣ��޷�����
*/

#include<iostream>
using namespace std;

class Base
{
public :
	int m1;
protected:
	int m2;
protected:
	int m3;
};

class Son : public Base
{
public:
	int m4;
};
int main()
{
	Base base;
	Son son;
	cout << "����sizeof = " << sizeof(Base) << endl;//12
	cout << "����sizeof = " << sizeof(Son) << endl;//16
	//�ɼ����������г�Ա���ᱻ�̳�

	return 0;
}