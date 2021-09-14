#include<iostream>
using namespace std;
class Base
{
public:
	int m;
	void func()
	{
		cout << "父类func函数调用" << endl;
	}void func(int a)
	{
		cout << "父类func函数调用" << endl;
	}
};
class Son :public Base
{
public:
	int m;
	void func()
	{
		cout << "子类func函数调用" << endl;
	}
};
int main()
{
	Son s;
	s.m = 100;
	cout << "子类中的m = " << s.m << endl;
	s.Base::m = 200;
	cout << "父类中的m = " << s.Base::m << endl;

	s.func();
	s.Base::func();
	//如果子类中出现了和父类的同名成员函数，父类中的所有同名成员函数都被隐藏
	//s.func(90);
	s.Base::func(90);

	return 0;
}