#include <iostream>
#include <fstream>
#include "employeeCategory.h"
#include"sortByNumber.h"

//按照编号排序
void sortByNumber()
{
	//定义数组
	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	string if_find = "NO";
	int fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	//读取职工数量
	fstream fsRead("Number.txt", ios::in);
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;
	//对普通职工排序
	if (fStaffNumber > 1)
	{
		fstream fsStaff("staffInformation.txt", ios::in | ios::binary);
		//读取staff数据
		for (int i = 0; i < fStaffNumber; i++)
		{
			fsStaff.read((char*)&staff[i], sizeof(staff[i]));
		}
		for (int i = 0; i < fStaffNumber - 1; i++)
		{
			for (int j = 0; j < fStaffNumber - 1 - i; j++)
			{
				if (strcmp(staff[j].number, staff[j + 1].number) > 0)
				{
					Staff s = staff[j];
					staff[j] = staff[j + 1];
					staff[j + 1] = s;
				}
			}
		}
	}

	//对经理排序
	if (fManagerNumber > 1)
	{
		fstream fsManager("managerInformation.txt", ios::in | ios::binary);
		//读取manager数据
		for (int i = 0; i < fStaffNumber; i++)
		{
			fsManager.read((char*)&manager[i], sizeof(manager[i]));
		}
		for (int i = 0; i < fManagerNumber - 1; i++)
		{
			for (int j = 0; j < fManagerNumber - 1 - i; j++)
			{
				if (strcmp(manager[j].number, manager[j + 1].number) > 0)
				{
					Manager s = manager[j];
					manager[j] = manager[j + 1];
					manager[j + 1] = s;
				}
			}
		}
	}
	//对老板排序
	if (fBossNumber > 1)
	{
		fstream fsBoss("bossInformation.txt", ios::in | ios::binary);
		//读取boss数据
		for (int i = 0; i < fStaffNumber; i++)
		{
			fsBoss.read((char*)&boss[i], sizeof(boss[i]));
		}
		for (int i = 0; i < fBossNumber - 1; i++)
		{
			for (int j = 0; j < fBossNumber - 1 - i; j++)
			{
				if (strcmp(boss[j].number, boss[j + 1].number) > 0)
				{
					Boss s = boss[j];
					boss[j] = boss[j + 1];
					boss[j + 1] = s;
				}
			}
		}
	}
	//重新写入文件
	//普通职工
	fstream fsStaffWrite("staffInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fStaffNumber; i++)
	{
		fsStaffWrite.write((const char*)&staff[i], sizeof(staff[i]));
	}
	//经理
	fstream fsManagerWrite("managerInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fManagerNumber; i++)
	{
		fsManagerWrite.write((const char*)&manager[i], sizeof(manager[i]));
	}
	//老板
	fstream fsBossWrite("bossInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fBossNumber; i++)
	{
		fsBossWrite.write((const char*)&boss[i], sizeof(boss[i]));
	}
	cout << "已按编号排序" << endl;
	system("pause");
}