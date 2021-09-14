#include "clearAllEmployeeInformation.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
using namespace std;
//清空所有职工信息
void clearAllEmployeeInformation()
{
	int choice = MessageBox(NULL, TEXT("提示"), TEXT("确定要清空所有记录？"), MB_YESNO);
	if (choice == IDYES)
	{
		//删除文件
		fstream fsStaff("staffInformation.txt", ios::out | ios::trunc);
		fstream fsManager("managerInformation.txt", ios::out | ios::trunc);
		fstream fsBoss("bossInformation.txt", ios::out | ios::trunc);
		fstream fsRead("Number.txt", ios::out | ios::trunc);
		if (fsStaff.is_open()&& fsManager.is_open()&& fsBoss.is_open()&& fsRead.is_open())
		{
			cout << "已清空所有记录" << endl;
		}
		//关闭文件
		fsStaff.close();
		fsManager.close();
		fsBoss.close();
		fsRead.close();
	}
	system("pause");
}