/*
	运算符重载相当于调用函数：
		如p1.operator+(p2) 
			 ==> p1 + p2
			 可简化如此
*/
#include <iostream>
#include <conio.h>
using namespace std;

//创建一个类
class Person
{
public:
	//定义成员函数重载+运算符
	Person operator+(Person p)
	{
		Person temp;
		temp.age = p.age + this->age;
		temp.name = p.name +"-" + this->name;
		return temp;
	}
	Person();
	~Person();
	string name;
	int age;
private:

};

Person::Person()
{
}

Person::~Person()
{
}
void test01()
{
	Person p1;
	p1.age = 10;
	p1.name = "xiamm";
	Person p2;
	p2.age = 38;
	p2.name = "iisiancl";

	//调用+重载
	Person p3 = p1 + p2;
	//输出
	cout << "p3的姓名是" << p3.name << endl;
	cout << "p3的年龄是" << p3.age << endl;

}
int main()
{
	test01();



	return 0;
}