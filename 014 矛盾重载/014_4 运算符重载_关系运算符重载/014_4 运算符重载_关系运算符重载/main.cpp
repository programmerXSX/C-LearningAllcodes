#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age, string name)
	{
		this->age = age;
		this->name = name;
	}
	bool operator==(Person p)
	{
		if (age == p.age && name == p.name)return true;
		else return false;
	}
private:
	int age;
	string name;
};
int main()
{
	Person p1(12, "夏敏");
	Person p2(19, "下注");
	if (p1 == p2)
	{
		cout << "不想等" << endl;
	}
	else
	{
		cout << "不相等" << endl;
	}

	return 0;
}