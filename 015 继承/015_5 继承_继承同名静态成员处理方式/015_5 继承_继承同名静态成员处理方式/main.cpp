/*
��̬��Ա�ص㣺
	���ж�����ͬһ�����ݣ�����׶ξͷ����ڴ�
	���������������ʼ��
	��̬��Ա����ֻ�ܷ��ʾ�̬��Ա�����;�̬��Ա����
*/
#include<iostream>
using namespace std;
class Base
{
public:
	static int m_num;
	static void work()
	{
		cout << "���ຯ��" << endl;
	}
};
int Base::m_num = 100;
class Son : public Base
{
public:
	static int m_num;
	static void work()
	{
		cout << "���ຯ��" << endl;
	}

};
int Son::m_num = 90;
int main()
{
//ͬ����̬��Ա����
	//ͨ���������
	Son s;
	cout << "����m_num = " << s.m_num << endl;
	cout << "����m_num = " << s.Base::m_num << endl;
	//ͨ����������
	cout << "����m_num = " << Son::m_num << endl;
	cout << "����m_num = " << Son::Base::m_num << endl;
//ͬ����̬��Ա����
	//ͨ���������
	s.work();
	s.Base::work();
	//ͨ����������
	Son::work();
	Son::Base::work();


	return 0;
}