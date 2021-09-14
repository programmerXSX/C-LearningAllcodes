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
	//重载前置递增运算符
	MyInteger& operator++()//如果需要套娃，返回引用
	{
		m_Num++;
		return *this;
	}
	//重载后置递增运算符
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