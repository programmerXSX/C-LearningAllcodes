#include "clearAllEmployeeInformation.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
using namespace std;
//�������ְ����Ϣ
void clearAllEmployeeInformation()
{
	int choice = MessageBox(NULL, TEXT("��ʾ"), TEXT("ȷ��Ҫ������м�¼��"), MB_YESNO);
	if (choice == IDYES)
	{
		//ɾ���ļ�
		fstream fsStaff("staffInformation.txt", ios::out | ios::trunc);
		fstream fsManager("managerInformation.txt", ios::out | ios::trunc);
		fstream fsBoss("bossInformation.txt", ios::out | ios::trunc);
		fstream fsRead("Number.txt", ios::out | ios::trunc);
		if (fsStaff.is_open()&& fsManager.is_open()&& fsBoss.is_open()&& fsRead.is_open())
		{
			cout << "��������м�¼" << endl;
		}
		//�ر��ļ�
		fsStaff.close();
		fsManager.close();
		fsBoss.close();
		fsRead.close();
	}
	system("pause");
}