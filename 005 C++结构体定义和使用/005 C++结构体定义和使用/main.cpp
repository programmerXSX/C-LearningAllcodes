#include <iostream>
#include <conio.h>
using namespace std;

struct student 
{
	int number;
	string name;
	int score;
};
struct teacher
{
	string name;
	int age;
	student students[3];

};
struct GirlFriend
{
	string name;
	int years;
	string temper;
	int height;
	int weight;
};

void printstudent1(student zs);
void printstudent2(student* p);
void printstudent3(const student* p);

int main()
{
	/*�ṹ��������������*/
	student zs = { 1,"dazhut",12 };
	printstudent1(zs);
	printstudent2(&zs);

	/*�ṹ��Ƕ��*/
	teacher xsx;
	xsx.students[0].name = "������";
	cout << "��˳�ε�ѧ����" << xsx.students[0].name << endl;

	/*�ṹ��ָ��*/
	student* p1 = &zs;
	cout << p1->name <<" "<< p1->number<<" " << p1->score << endl;

	/*�ṹ������*/
	student students[3] =
	{
		{1,"����",59},
		{2,"����",61},
		{3,"����",99}
	};	
	cout << students[0].name<<students[1].name<<students[2].name << endl;


	/*�ṹ��ʹ��*/
	GirlFriend jzt;
	jzt.height = 170;
	jzt.name = "������";
	jzt.temper = "Ƣ�����꣬���۸�������";
	jzt.weight = 50;
	jzt.years = 20;

	cout << "Ů����������" << jzt.name << "\n���䣺" << jzt.years << "��\n���أ�" << jzt.weight;
	cout << "kg\n��ߣ�" << jzt.height << "cm\n" << jzt.temper << endl;

	system("pause");
	return 0;
}


void printstudent1(student zs)
{
	cout << "������" << zs.name << endl;
}

void printstudent2(struct student* p)
{

	cout << "������" << p->name << endl;
}

void printstudent3(const student* p)
{
	int a = 1;
	//p->number = &a;		����const��ֹ�޸Ľṹ�����
}

