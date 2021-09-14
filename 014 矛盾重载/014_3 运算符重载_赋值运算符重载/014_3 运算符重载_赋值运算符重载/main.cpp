#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		m_age = new int(age);
	}
	~Person()
	{
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}
	int* m_age;
	//���ظ�ֵ�����
	Person& operator=(Person &p)
	{
		//���ж��Ƿ��������ԣ�����У��ͷŸɾ�
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		//���
		m_age = new int(*p.m_age);
		return *this;
	}
};
int main()
{
	Person p1(12);
	Person p2(18);
	p2 = p1;
	cout << *p2.m_age << endl;


	return 0;
}