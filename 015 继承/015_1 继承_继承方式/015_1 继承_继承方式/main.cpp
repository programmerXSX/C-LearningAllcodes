/*
继承有三种方式：
	公共继承：
		父类中的private属性不可访问,pubilc和protected属性可访问，
		并成为子类的public和protected属性
	保护继承：
		父类中的private属性不可访问,pubilc和protected属性可访问，
		并成为子类的protected属性
	私有继承：
		父类中的private属性不可访问,pubilc和protected属性可访问，
		并成为子类中的private属性
*/
#include<iostream>
using namespace std;

//父类
class Base
{
public:
	int m_num1;
protected:
	int m_num2;
private:
	int m_num3;
};
//公共继承
class sonPublic : public Base
{
	void func1()
	{
		m_num1 = 10;//类内、外都可访问
		m_num2 = 20;//保护属性，子类、类内可以访问，类外不可访问
		//m_num3 = 30;//私有属性不可访问
	}
};
//保护继承
class sonProtected : protected Base
{
	void func2()
	{
		m_num1 = 10;
		m_num2 = 20;
		//m_num3 = 30;//私有属性不可访问
	}
};

//私有继承
class sonPrivate : private Base
{
	void func3()
	{
		m_num1 = 10;
		m_num2 = 20;
		//m_num3 = 30;//私有属性不可访问
	}
};

int main()
{



	return 0;
}