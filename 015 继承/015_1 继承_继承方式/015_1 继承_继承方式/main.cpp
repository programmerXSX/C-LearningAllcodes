/*
�̳������ַ�ʽ��
	�����̳У�
		�����е�private���Բ��ɷ���,pubilc��protected���Կɷ��ʣ�
		����Ϊ�����public��protected����
	�����̳У�
		�����е�private���Բ��ɷ���,pubilc��protected���Կɷ��ʣ�
		����Ϊ�����protected����
	˽�м̳У�
		�����е�private���Բ��ɷ���,pubilc��protected���Կɷ��ʣ�
		����Ϊ�����е�private����
*/
#include<iostream>
using namespace std;

//����
class Base
{
public:
	int m_num1;
protected:
	int m_num2;
private:
	int m_num3;
};
//�����̳�
class sonPublic : public Base
{
	void func1()
	{
		m_num1 = 10;//���ڡ��ⶼ�ɷ���
		m_num2 = 20;//�������ԣ����ࡢ���ڿ��Է��ʣ����ⲻ�ɷ���
		//m_num3 = 30;//˽�����Բ��ɷ���
	}
};
//�����̳�
class sonProtected : protected Base
{
	void func2()
	{
		m_num1 = 10;
		m_num2 = 20;
		//m_num3 = 30;//˽�����Բ��ɷ���
	}
};

//˽�м̳�
class sonPrivate : private Base
{
	void func3()
	{
		m_num1 = 10;
		m_num2 = 20;
		//m_num3 = 30;//˽�����Բ��ɷ���
	}
};

int main()
{



	return 0;
}