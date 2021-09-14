/*
多继承语法：
	C++允许多继承（一个类继承多个类）
	语法：class 子类 ：继承方式 父类1， 继承方式 父类2...
	多继承可能会引起父类中有同名成员出现，需要加作用域区分
注：C++实际开发中不建议使用多继承！
*/
#include <iostream>
using namespace std;
class Base1
{
public:
	Base1() 
	{
		num = 19;
	}
	int num;
};
class Base2
{
public:
	Base2()
	{
		num = 20;
	}
	int num;
};
class Son :public Base1, public Base2
{
public:
	Son()
	{
		num = 90;
	}
	int num;
};

int main()
{
	//
	Son s;
	cout << "父类1 num = " << s.Base1::num << endl;
	cout << "父类2 num = " << s.Base2::num << endl;
	cout << "子类 num = " << s.num << endl;


	return 0;
}