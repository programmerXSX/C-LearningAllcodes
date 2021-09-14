#include "employeeCategory.h"
#include "deleteEx-employee.h"
#include "addEmployeeInformation.h"
#include <iostream>
using namespace std;
//修改职工信息的函数
void modifyEmployeeInformation()
{
	while (true)
	{
		cout << "请输入需要修改的职工编号(退出请输入END)：";
		char number[64];
		cin >> number;
		if (strcmp(number, "END") == 0) { break; }
		//删除该职工此时的信息
		if (findDeleteEmployee(number))
		{
			//重新添加该职工新的信息
			inputStaff();
		}
	}
}