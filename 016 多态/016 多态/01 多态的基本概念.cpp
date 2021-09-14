/*
多态是C++面向对象三大特性之一
	多态分为两类：
		静态多态：函数重载和运算符重载都属于静态多态，复用函数名
		动态多态：派生类和虚函数实现运行时多态
	静态多态和动态多态的区别：
		静态多态的函数地址早绑定 - 编译阶段确定函数地址
		动态多态的函数地址晚绑定 - 运行阶段确定函数地址
*//*
	动态多态满足条件：
		1、有继承关系
		2、子类重写父类虚函数（感觉有点像Java抽象（abstract）函数）
	动态多态使用：
		父类的指针或引用指向子类对象
	重写：函数返回值类型，函数名，参数列表完全一致称为重写
*/

#include <iostream>
using namespace std;
class Animal
{
public:
	virtual void speak()//虚函数
	{
		cout << "动物在说话" << endl;
	}
};
class Cat :public Animal
{
public :
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "狗仔又说话" << endl;
	}
};
//执行说话的函数
void doSpeak(Animal& aniaml)
{
	aniaml.speak();
}
int main()
{
	Cat cat;
	doSpeak(cat);//Aniaml& animal = cat

	Dog dog;
	doSpeak(dog);//Animal& animal = dog

	return 0;
}