/*
虚函数和抽象类：
	在多态类中，通常父类中虚函数的实现是毫无意义的，主要调用子类重写的内容
	因此可以将虚函数改为 纯虚函数
	纯虚函数语法：virtual 返回值类型 函数名（参数列表）= 0;
	当类中有了纯虚函数，这个类也称为抽象类，抽象类不可以实例化
抽象类特点：
	无法实例化对象
	子类必须重写抽象类中的纯虚函数，否则也是抽象类
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
		cout << "子类实现父类纯虚函数" << endl;
	}
};

int main()
{
																										
	Base* base = new Son;
	base->func();


	return 0;
}