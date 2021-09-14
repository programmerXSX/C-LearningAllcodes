#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//����ǰ�õ��������
	MyInteger& operator++()//�����Ҫ���ޣ���������
	{
		m_Num++;
		return *this;
	}
	//���غ��õ��������
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_Num++;
		return temp;
	}
private:
	int m_Num;
};

ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.m_Num ;
	return cout;
}
int main()
{
	MyInteger myint;
	cout << myint << endl;//0
	++myint;
	cout << (myint++)++ << endl;//1
	cout << myint << endl;//2

	return 0;
}