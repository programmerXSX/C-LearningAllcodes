/*
	����������൱�ڵ��ú�����
		��p1.operator+(p2) 
			 ==> p1 + p2
			 �ɼ����
*/
#include <iostream>
#include <conio.h>
using namespace std;

//����һ����
class Person
{
public:
	//�����Ա��������+�����
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

	//����+����
	Person p3 = p1 + p2;
	//���
	cout << "p3��������" << p3.name << endl;
	cout << "p3��������" << p3.age << endl;

}
int main()
{
	test01();



	return 0;
}