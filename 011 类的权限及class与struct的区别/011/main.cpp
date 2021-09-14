#include <iostream>
#include <conio.h>
using namespace std;
	
class C1
{
	int A;	//默认权限 私有
};

struct C2
{
	int A;	//默认权限公共
	void fun()
	{
		cout << A << endl;
	}
};

class Person
{
public:
	string name;
protected:
	string Car;
private:
	string PassWord;

	void func()
	{
		name = "夏敏";
		Car = "长安";
		PassWord = "xia123456";

	}
};


int main()
{
	C2 lll;
	lll.A = 12;
	lll.fun();


	Person p1;
	p1.name = "夏敏";
	//p1.Car  不可以访问



	system("pause");
	return 0;
}