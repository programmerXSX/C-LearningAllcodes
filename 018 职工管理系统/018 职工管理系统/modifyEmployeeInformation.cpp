#include "employeeCategory.h"
#include "deleteEx-employee.h"
#include "addEmployeeInformation.h"
#include <iostream>
using namespace std;
//�޸�ְ����Ϣ�ĺ���
void modifyEmployeeInformation()
{
	while (true)
	{
		cout << "��������Ҫ�޸ĵ�ְ�����(�˳�������END)��";
		char number[64];
		cin >> number;
		if (strcmp(number, "END") == 0) { break; }
		//ɾ����ְ����ʱ����Ϣ
		if (findDeleteEmployee(number))
		{
			//������Ӹ�ְ���µ���Ϣ
			inputStaff();
		}
	}
}