/*
�麯���ͳ����ࣺ
	�ڶ�̬���У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ����������д������
	��˿��Խ��麯����Ϊ ���麯��
	���麯���﷨��virtual ����ֵ���� �������������б�= 0;
	���������˴��麯���������Ҳ��Ϊ�����࣬�����಻����ʵ����
�������ص㣺
	�޷�ʵ��������
	���������д�������еĴ��麯��������Ҳ�ǳ�����
*/
#include <iostream>
using namespace std;
class Base
{
public:
	virtual void func() = 0;

};
class Son :public Base
{
public:
	void func()
	{
		cout << "����ʵ�ָ��ി�麯��" << endl;
	}
};

int main()
{
																										
	Base* base = new Son;
	base->func();


	return 0;
}