#include "findEmployeeInformation.h"
#include "employeeCategory.h"
#include <iostream>
#include <fstream>
//查找职工信息
void findEmployeeInformation() 
{
	
	while (true)
	{
		//录入职工编号
		cout << "请输入想要查找职工的编号(退出请输入END)：";
		char number[64];
		cin >> number;
		if (strcmp(number, "END") == 0) { break; }
		//查找职工
		findEmployee(number);
		system("pause");
	}
}
bool findEmployee(char number[64])
{
	//定义数组
	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	string if_find = "NO";
	int staffNumber = 0, managerNumber = 0, bossNumber = 0, goalNumber = 0,
		fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	//读取职工数量
	fstream fsRead("Number.txt", ios::in);
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;

	//查找普通职工
	fstream fsStaff("staffInformation.txt", ios::in | ios::binary);
	while (fsStaff.read((char*)&staff[staffNumber], sizeof(staff[staffNumber])))
	{
		if (strcmp(staff[staffNumber].number, number) == 0)
		{
			cout << "编号为" << number << "的职工已找到:" << endl;
			cout << "\t姓名：" << staff[staffNumber].name << endl;
			cout << "\t编号：" << staff[staffNumber].number << endl;
			cout << "\t职位：" << staff[staffNumber].station << endl;
			cout << "\t职责：" << staff[staffNumber].responsibility << "\n" << endl;
			goalNumber = staffNumber;
			if_find = "STAFF";
		}
		if (++staffNumber == fStaffNumber) { break; }
	}

	//查找经理
	fstream fsManager("managerInformation.txt", ios::in | ios::binary);
	while (fsManager.read((char*)&manager[managerNumber], sizeof(manager[managerNumber])))
	{
		if (strcmp(manager[managerNumber].number, number) == 0)
		{
			cout << "编号为" << number << "的职工已找到:" << endl;
			cout << "\t姓名：" << manager[managerNumber].name << endl;
			cout << "\t编号：" << manager[managerNumber].number << endl;
			cout << "\t职位：" << manager[managerNumber].station << endl;
			cout << "\t职责：" << manager[managerNumber].responsibility << "\n" << endl;
			goalNumber = managerNumber;
			if_find = "MANAGER";
		}
		if (++managerNumber == fManagerNumber) { break; }
	}

	//查找老板
	fstream fsBoss("bossInformation.txt", ios::in | ios::binary);
	while (fsBoss.read((char*)&boss[bossNumber], sizeof(boss[bossNumber])))
	{
		if (strcmp(boss[bossNumber].number, number) == 0)
		{
			cout << "编号为" << number << "的职工已找到:" << endl;
			cout << "\t姓名：" << boss[bossNumber].name << endl;
			cout << "\t编号：" << boss[bossNumber].number << endl;
			cout << "\t职位：" << boss[bossNumber].station << endl;
			cout << "\t职责：" << boss[bossNumber].responsibility << "\n" << endl;
			goalNumber = bossNumber;
			if_find = "BOSS";
		}
		if (++bossNumber == fBossNumber) { break; }
	}
	if (if_find._Equal("NO")) 
	{
		cout << "未找到编号为" << number << "的职工，请确定输入无误" << endl;
		return false; 
	}
	return true;
}