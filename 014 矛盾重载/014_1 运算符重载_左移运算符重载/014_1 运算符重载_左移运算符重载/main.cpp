#include <iostream>
#include <conio.h>
using namespace std;

class Person
{
public:
	string name;
	int age;
private:

};
/*在成员函数中重载是 p.operator<<() 的格式 ， 简化为 p<< , 并不是cout<< 的格式
因此需要在全局函数重载
*/
ostream& operator<<(ostream& cout, Person p)
{
	cout << p.name << "的年龄是" << p.age << "岁";
	return cout;
}



void test01()
{
	Person p1;
	p1.age = 18;
	p1.name = "夏顺鑫";
	cout << p1 << endl;
}

int main() 
{
	test01();


	return 0;
}