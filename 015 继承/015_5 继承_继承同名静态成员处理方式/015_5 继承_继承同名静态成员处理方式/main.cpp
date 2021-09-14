/*
静态成员特点：
	所有对象共享同一份数据，编译阶段就分配内存
	类内声明，类外初始化
	静态成员函数只能访问静态成员函数和静态成员变量
*/
#include<iostream>
using namespace std;
class Base
{
public:
	static int m_num;
	static void work()
	{
		cout << "父类函数" << endl;
	}
};
int Base::m_num = 100;
class Son : public Base
{
public:
	static int m_num;
	static void work()
	{
		cout << "子类函数" << endl;
	}

};
int Son::m_num = 90;
int main()
{
//同名静态成员属性
	//通过对象访问
	Son s;
	cout << "子类m_num = " << s.m_num << endl;
	cout << "父类m_num = " << s.Base::m_num << endl;
	//通过类名访问
	cout << "子类m_num = " << Son::m_num << endl;
	cout << "父类m_num = " << Son::Base::m_num << endl;
//同名静态成员函数
	//通过对象访问
	s.work();
	s.Base::work();
	//通过类名访问
	Son::work();
	Son::Base::work();


	return 0;
}