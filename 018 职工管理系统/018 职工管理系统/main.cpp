#include <iostream>
#include <fstream>
#include "addEmployeeInformation.h"
#include "clearAllEmployeeInformation.h"
#include "deleteEx-employee.h"
#include "displayEmployeeInformation.h"
#include "findEmployeeInformation.h"
#include "interface.h"
#include "modifyEmployeeInformation.h"
#include "sortByNumber.h"
#include <Windows.h>
#include "employeeCategory.h"
using namespace std;

int main()
{
	while (true)
	{
		system("cls");
		int option = Interface(); //初始界面
		switch (option)
		{
		case 1:
			addEmployeeInformation();//增加职工信息
			break;
		case 2:
			displayEmployeeInformation();//显示职工信息
			break;
		case 3:
			deleteExemployee();//删除离职职工
			break;
		case 4:
			modifyEmployeeInformation();//修改职工信息
			break;
		case 5:
			findEmployeeInformation();//查找职工信息
			break;
		case 6:
			sortByNumber();//按照编号排序
			break;
		case 7:
			clearAllEmployeeInformation();//清空所有职工信息	
			break;
		case 0:
			return 0;//退出程序
		default:
			MessageBox(NULL, TEXT("请正确输入选项！"), TEXT("提示"), MB_ICONERROR);
			break;
		}
	}

	return 0;
}
