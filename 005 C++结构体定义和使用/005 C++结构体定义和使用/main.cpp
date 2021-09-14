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
	/*结构体作参数传函数*/
	student zs = { 1,"dazhut",12 };
	printstudent1(zs);
	printstudent2(&zs);

	/*结构体嵌套*/
	teacher xsx;
	xsx.students[0].name = "金子婷";
	cout << "夏顺鑫的学生叫" << xsx.students[0].name << endl;

	/*结构体指针*/
	student* p1 = &zs;
	cout << p1->name <<" "<< p1->number<<" " << p1->score << endl;

	/*结构体数组*/
	student students[3] =
	{
		{1,"张三",59},
		{2,"李四",61},
		{3,"王五",99}
	};	
	cout << students[0].name<<students[1].name<<students[2].name << endl;


	/*结构体使用*/
	GirlFriend jzt;
	jzt.height = 170;
	jzt.name = "金子婷";
	jzt.temper = "脾气暴躁，爱欺负男朋友";
	jzt.weight = 50;
	jzt.years = 20;

	cout << "女朋友姓名：" << jzt.name << "\n年龄：" << jzt.years << "岁\n体重：" << jzt.weight;
	cout << "kg\n身高：" << jzt.height << "cm\n" << jzt.temper << endl;

	system("pause");
	return 0;
}


void printstudent1(student zs)
{
	cout << "姓名：" << zs.name << endl;
}

void printstudent2(struct student* p)
{

	cout << "姓名：" << p->name << endl;
}

void printstudent3(const student* p)
{
	int a = 1;
	//p->number = &a;		报错，const防止修改结构体参数
}

