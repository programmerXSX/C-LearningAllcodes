#include <iostream>
#include <conio.h>
using namespace std;
#define PI 3.1415926

class student		//设计学生类
{
public:
	string name;
	long long number;
	void ShowName()
	{
		cout << name << "的学号是" << number << endl;
	}
};

class Circle		//设计圆类
{
public:
	int R;
	double area()
	{
		return 2 * PI * R;
	}

};

int main()
{
	student student1;
	student1.name = "夏敏";
	student1.number = 123456;
	student1.ShowName();





	Circle O1;
	O1.R = 2;

	
	cout << "半径为2的圆面积为" << O1.area() << endl; 
	

	system("pause");
	return 0;
}