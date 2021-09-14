#include "deleteEx-employee.h"
#include "employeeCategory.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
//删除离职员工的函数
void deleteExemployee()
{
	while (true)
	{
		//录入职工编号
		cout << "请输入想要删除职工的编号(退出请输入END)：";
		char number[64];
		cin >> number;
		if (strcmp(number, "END") == 0) { break; }

		//查找职工并删除
		findDeleteEmployee(number);	
	}
	system("pause");
}
//查找职工并删除
bool findDeleteEmployee(char number[64])
{
	//定义数组
	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	string if_find  = "NO";
	int staffNumber = 0, managerNumber = 0, bossNumber = 0, goalNumber = 0,
		fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	//读取职工数量
	fstream fsRead("Number.txt", ios::in);
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;

	//查找普通职工
	fstream fsStaff("staffInformation.txt", ios::in | ios::binary );
	while (fsStaff.read((char*)&staff[staffNumber], sizeof(staff[staffNumber])))
	{
		if (strcmp( staff[staffNumber].number,number) == 0)
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
	while (fsManager.read((char*)&manager[managerNumber],sizeof(manager[managerNumber])))
	{
		if (strcmp( manager[managerNumber].number , number) == 0)
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
		if (strcmp( boss[bossNumber].number , number) == 0)
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

	//已找到则删除
	if (!ifFind_Delete(if_find, goalNumber, staff, manager, boss)) { return false; }
	return true;
}
bool ifFind_Delete(string if_find,int goalNumber, Staff staff[100],Manager manager[10], Boss boss[5])
{
//判断是否找到并给出处理
	if(if_find._Equal("NO"))
	{
		cout << "没有找到该职工，请确定输入职工编号正确" << endl;
		return false;
	}
	else
	{
		int choice = MessageBox(NULL, TEXT("是否确定删除该职工？"), TEXT("提示"), MB_YESNO);
		if (choice == IDYES)
		{
			if (if_find._Equal("STAFF"))
			{
				deleteEmployee(goalNumber, staff);
			}
			else if (if_find._Equal("MANAGER"))
			{
				deleteEmployee(goalNumber, manager);
			}
			else if(if_find._Equal("BOSS"))
			{
				deleteEmployee(goalNumber, boss);
			}
		}
		return true;
	}
}
void deleteEmployee(int goalNumber, Staff staff[100])
{
	int fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	fstream fsRead("Number.txt", ios::in);
	
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;
	for (int i = goalNumber; i < fStaffNumber; i++)
	{
		staff[i] = staff[i + 1];
	}
	//修改职工数量
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << --fStaffNumber << " " << fManagerNumber << " " << fBossNumber;
	//重新写入文件
	fstream fsStaffWrite("staffInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fStaffNumber; i++)
	{
		fsStaffWrite.write((const char*)&staff[i], sizeof(staff[i]));
	}
}
void deleteEmployee(int goalNumber, Manager manager[10])
{
	int fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	fstream fsRead("Number.txt", ios::in);
	
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;
	for (int i = goalNumber; i < fManagerNumber; i++)
	{
		manager[i] = manager[i + 1];
	}
	//修改职工数量
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << fStaffNumber << " " << --fManagerNumber << " " << fBossNumber;
	//重新写入文件
	fstream fsManagerWrite("managerInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fManagerNumber; i++)
	{
		fsManagerWrite.write((const char*)&manager[i], sizeof(manager[i]));
	}
}
void deleteEmployee(int goalNumber, Boss boss[5])
{
	int fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	fstream fsRead("Number.txt", ios::in);
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;
	for (int i = goalNumber; i < fBossNumber; i++)
	{
		boss[i] = boss[i + 1];
	}
	//修改职工数量
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << fStaffNumber<<" " << fManagerNumber<<" " << --fBossNumber;
	//重新写入文件
	fstream fsBossWrite("bossInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fBossNumber; i++)
	{
		fsBossWrite.write((const char*)&boss[i], sizeof(boss[i]));
	}
}