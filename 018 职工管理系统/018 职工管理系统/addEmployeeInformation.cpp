#include "addEmployeeInformation.h"
#include "employeeCategory.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>

//增加职工信息的函数
void addEmployeeInformation()
{
	while (inputStaff()){}
	system("pause");
}
bool inputStaff()
{
	fstream fsStaff("staffInformation.txt",ios::out|ios::binary|ios::app);
	fstream fsManager("managerInformation.txt",ios::out|ios::binary|ios::app);
	fstream fsBoss("bossInformation.txt",ios::out|ios::binary|ios::app);

	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	//读出三种职工的数量
	int staffNumber = 1, managerNumber = 1, bossNumber = 1;
	fstream fsRead("Number.txt", ios::in);//读取数组序列
	if (fsRead.is_open())//打开成功 
	{
		if (!fsRead.eof())
		{
			fsRead >> staffNumber >> managerNumber >> bossNumber;
		}
	}
	//新增职工
	cout << "请输入新增职工的职位(退出请输入886)：\n\t1、普通职工\n\t2、经理\n\t3、老板\n";
	int station;
	cin >> station;
	switch (station)
	{
	case 1:
		staff[staffNumber - 1] = inputInformation(staff[staffNumber - 1]);
		fsStaff.write((const char*)&staff[staffNumber - 1], sizeof(staff[staffNumber - 1]));
		staffNumber++;
		MessageBox(NULL, TEXT("已成功加入"), TEXT(""), MB_OK);
		break;
	case 2:
		manager[managerNumber - 1] = inputInformation(manager[managerNumber - 1]);
		fsManager.write((const char*)&manager[managerNumber - 1], sizeof(manager[managerNumber - 1]));
		managerNumber++;
		MessageBox(NULL, TEXT("已成功加入"), TEXT(""), MB_OK);
		break;
	case 3:
		boss[bossNumber - 1] = inputInformation(boss[bossNumber - 1]);
		fsBoss.write((const char*)&boss[bossNumber - 1], sizeof(boss[bossNumber - 1]));
		bossNumber++;
		MessageBox(NULL, TEXT("已成功加入"), TEXT(""), MB_OK);
		break;
	case 886:
		return false;
	default:
		MessageBox(NULL, TEXT("错误！"), TEXT("提示"), MB_ICONERROR);
		return true;
	}
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << staffNumber << " "
		<< managerNumber << " "
		<< bossNumber << endl;
	return true;
	//关闭资源
	fsStaff.close();
	fsManager.close();
	fsBoss.close();
}
Staff& inputInformation(Staff& staff)
{
	string str;
	cout << "请输入职工姓名：";
	cin >> str;
	staff.name = str.data();
	cout << "请输入职工编号：";
	cin >> str;
	staff.number = str.data();
	return staff;
}
Manager& inputInformation(Manager& manager)
{
	string str;
	cout << "请输入职工姓名：";
	cin >> str;
	manager.name = str.data();
	cout << "请输入职工编号：";
	cin >> str;
	manager.number = str.data();
	return manager;
}
Boss& inputInformation(Boss& boss)
{
	string str;
	cout << "请输入职工姓名：";
	cin >> str;
	boss.name = str.data();
	cout << "请输入职工编号：";
	cin >> str;
	boss.number = str.data();
	return boss;
}