#include <iostream>
#include <conio.h>
using namespace std;
	
class C1
{
	int A;	//Ĭ��Ȩ�� ˽��
};

struct C2
{
	int A;	//Ĭ��Ȩ�޹���
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
		name = "����";
		Car = "����";
		PassWord = "xia123456";

	}
};


int main()
{
	C2 lll;
	lll.A = 12;
	lll.fun();


	Person p1;
	p1.name = "����";
	//p1.Car  �����Է���



	system("pause");
	return 0;
}