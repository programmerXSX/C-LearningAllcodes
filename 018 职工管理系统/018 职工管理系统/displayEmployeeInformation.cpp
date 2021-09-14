#include "displayEmployeeInformation.h"
#include "employeeCategory.h";
#include <fstream>
#include <iostream>

//显示职工信息的函数
void displayEmployeeInformation()
{
	//创建文件读取对象与类对象
	fstream fsStaff("staffInformation.txt", ios::in | ios::binary);
	fstream fsManager("managerInformation.txt", ios::in | ios::binary);
	fstream fsBoss("bossInformation.txt", ios::in | ios::binary);
	fstream fsRead("Number.txt", ios::in);
	Boss boss;
	Manager manager;
	Staff staff;
	int staffNumber = 0, managerNumber = 0, bossNumber = 0;
	fsRead >> staffNumber >> managerNumber >> bossNumber;
	//读取数据
	//输出老板
	cout << "老板" << bossNumber << "名:" << endl;
	while (fsBoss.read((char*)&boss, sizeof(boss)))
	{
		printEmployeeIntformation(boss);
	}
	//输出经理
	cout << "经理" << managerNumber << "名：" << endl;
	while (fsManager.read((char*)&manager, sizeof(manager)))
	{
		printEmployeeIntformation(manager);
	}
	//输出普通职工
	cout << "普通职工"<< staffNumber << "名：" << endl;
	while (fsStaff.read((char*)&staff, sizeof(staff)))
	{
		printEmployeeIntformation(staff);
	}
	system("pause");
}
void printEmployeeIntformation(Staff staff)
{
	cout << "\t姓名："<< staff.name << endl;
	cout << "\t编号："<< staff.number << endl;
	cout << "\t职位："<< staff.station << endl;
	cout << "\t职责："<< staff.responsibility << "\n" << endl;
}
void printEmployeeIntformation(Manager manager)
{
	cout << "\t姓名：" << manager.name << endl;
	cout << "\t编号：" << manager.number << endl;
	cout << "\t职位：" << manager.station << endl;
	cout << "\t职责：" << manager.responsibility << "\n" << endl;
}
void printEmployeeIntformation(Boss boss)
{
	cout << "\t姓名：" << boss.name << endl;
	cout << "\t编号：" << boss.number << endl;
	cout << "\t职位：" << boss.station << endl;
	cout << "\t职责：" << boss.responsibility << "\n" << endl;
}