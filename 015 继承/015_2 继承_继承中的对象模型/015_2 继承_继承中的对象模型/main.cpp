/*
父类中所有非静态成员属性都会被继承下去
只不过私有成员属性被编译器隐藏了，无法访问
*/

#include<iostream>
using namespace std;

class Base
{
public :
	int m1;
protected:
	int m2;
protected:
	int m3;
};

class Son : public Base
{
public:
	int m4;
};
int main()
{
	Base base;
	Son son;
	cout << "父类sizeof = " << sizeof(Base) << endl;//12
	cout << "子类sizeof = " << sizeof(Son) << endl;//16
	//可见，父类所有成员都会被继承

	return 0;
}