#include <iostream>
#include <conio.h>
using namespace std;
#define PI 3.1415926

class student		//���ѧ����
{
public:
	string name;
	long long number;
	void ShowName()
	{
		cout << name << "��ѧ����" << number << endl;
	}
};

class Circle		//���Բ��
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
	student1.name = "����";
	student1.number = 123456;
	student1.ShowName();





	Circle O1;
	O1.R = 2;

	
	cout << "�뾶Ϊ2��Բ���Ϊ" << O1.area() << endl; 
	

	system("pause");
	return 0;
}