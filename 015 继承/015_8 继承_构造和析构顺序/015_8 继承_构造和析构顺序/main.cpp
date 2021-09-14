/*
继承中会先执行父类的构造，然后是子类的构造
然后执行子类的析构，最后是父类的析构
	我理解为：
		就像进入了多层for循环，首先进去最外层，然后是内层，
		执行完以后，先退出内层循环，然后退出外层循环
*/
#include <iostream>
using namespace std;
class Base
{
public:
	Base()
	{
		cout << "Base构造函数" << endl;
	}
	~Base()
	{
		cout << "Base析构函数" << endl;
	}
};
class Son :public Base
{
public:
	Son()
	{
		cout << "Son的构造函数" << endl;
	}
	~Son()
	{
		cout << "Son的析构函数" << endl;
	}
};


int main()
{
	Son s;


	return 0;
}