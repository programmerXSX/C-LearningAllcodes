/*
�̳��л���ִ�и���Ĺ��죬Ȼ��������Ĺ���
Ȼ��ִ�����������������Ǹ��������
	�����Ϊ��
		��������˶��forѭ�������Ƚ�ȥ����㣬Ȼ�����ڲ㣬
		ִ�����Ժ����˳��ڲ�ѭ����Ȼ���˳����ѭ��
*/
#include <iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base���캯��" << endl;
	}
	~Base()
	{
		cout << "Base��������" << endl;
	}
};
class Son :public Base
{
public:
	Son()
	{
		cout << "Son�Ĺ��캯��" << endl;
	}
	~Son()
	{
		cout << "Son����������" << endl;
	}
};


int main()
{
	Son s;


	return 0;
}