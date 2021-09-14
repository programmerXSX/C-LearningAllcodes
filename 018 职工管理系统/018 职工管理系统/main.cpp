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
		int option = Interface(); //��ʼ����
		switch (option)
		{
		case 1:
			addEmployeeInformation();//����ְ����Ϣ
			break;
		case 2:
			displayEmployeeInformation();//��ʾְ����Ϣ
			break;
		case 3:
			deleteExemployee();//ɾ����ְְ��
			break;
		case 4:
			modifyEmployeeInformation();//�޸�ְ����Ϣ
			break;
		case 5:
			findEmployeeInformation();//����ְ����Ϣ
			break;
		case 6:
			sortByNumber();//���ձ������
			break;
		case 7:
			clearAllEmployeeInformation();//�������ְ����Ϣ	
			break;
		case 0:
			return 0;//�˳�����
		default:
			MessageBox(NULL, TEXT("����ȷ����ѡ�"), TEXT("��ʾ"), MB_ICONERROR);
			break;
		}
	}

	return 0;
}
