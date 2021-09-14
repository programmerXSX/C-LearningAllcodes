#include "deleteEx-employee.h"
#include "employeeCategory.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
//ɾ����ְԱ���ĺ���
void deleteExemployee()
{
	while (true)
	{
		//¼��ְ�����
		cout << "��������Ҫɾ��ְ���ı��(�˳�������END)��";
		char number[64];
		cin >> number;
		if (strcmp(number, "END") == 0) { break; }

		//����ְ����ɾ��
		findDeleteEmployee(number);	
	}
	system("pause");
}
//����ְ����ɾ��
bool findDeleteEmployee(char number[64])
{
	//��������
	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	string if_find  = "NO";
	int staffNumber = 0, managerNumber = 0, bossNumber = 0, goalNumber = 0,
		fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	//��ȡְ������
	fstream fsRead("Number.txt", ios::in);
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;

	//������ְͨ��
	fstream fsStaff("staffInformation.txt", ios::in | ios::binary );
	while (fsStaff.read((char*)&staff[staffNumber], sizeof(staff[staffNumber])))
	{
		if (strcmp( staff[staffNumber].number,number) == 0)
		{
			cout << "���Ϊ" << number << "��ְ�����ҵ�:" << endl;
			cout << "\t������" << staff[staffNumber].name << endl;
			cout << "\t��ţ�" << staff[staffNumber].number << endl;
			cout << "\tְλ��" << staff[staffNumber].station << endl;
			cout << "\tְ��" << staff[staffNumber].responsibility << "\n" << endl;
			goalNumber = staffNumber;
			if_find = "STAFF";
		}
		if (++staffNumber == fStaffNumber) { break; }
	}

	//���Ҿ���
	fstream fsManager("managerInformation.txt", ios::in | ios::binary);
	while (fsManager.read((char*)&manager[managerNumber],sizeof(manager[managerNumber])))
	{
		if (strcmp( manager[managerNumber].number , number) == 0)
		{
			cout << "���Ϊ" << number << "��ְ�����ҵ�:" << endl;
			cout << "\t������" << manager[managerNumber].name << endl;
			cout << "\t��ţ�" << manager[managerNumber].number << endl;
			cout << "\tְλ��" << manager[managerNumber].station << endl;
			cout << "\tְ��" << manager[managerNumber].responsibility << "\n" << endl;
			goalNumber = managerNumber;
			if_find = "MANAGER";
		}
		if (++managerNumber == fManagerNumber) { break; }
	}

	//�����ϰ�
	fstream fsBoss("bossInformation.txt", ios::in | ios::binary);
	while (fsBoss.read((char*)&boss[bossNumber], sizeof(boss[bossNumber])))
	{
		if (strcmp( boss[bossNumber].number , number) == 0)
		{
			cout << "���Ϊ" << number << "��ְ�����ҵ�:" << endl;
			cout << "\t������" << boss[bossNumber].name << endl;
			cout << "\t��ţ�" << boss[bossNumber].number << endl;
			cout << "\tְλ��" << boss[bossNumber].station << endl;
			cout << "\tְ��" << boss[bossNumber].responsibility << "\n" << endl;
			goalNumber = bossNumber;
			if_find = "BOSS";
		}
		if (++bossNumber == fBossNumber) { break; }
	}

	//���ҵ���ɾ��
	if (!ifFind_Delete(if_find, goalNumber, staff, manager, boss)) { return false; }
	return true;
}
bool ifFind_Delete(string if_find,int goalNumber, Staff staff[100],Manager manager[10], Boss boss[5])
{
//�ж��Ƿ��ҵ�����������
	if(if_find._Equal("NO"))
	{
		cout << "û���ҵ���ְ������ȷ������ְ�������ȷ" << endl;
		return false;
	}
	else
	{
		int choice = MessageBox(NULL, TEXT("�Ƿ�ȷ��ɾ����ְ����"), TEXT("��ʾ"), MB_YESNO);
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
	//�޸�ְ������
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << --fStaffNumber << " " << fManagerNumber << " " << fBossNumber;
	//����д���ļ�
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
	//�޸�ְ������
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << fStaffNumber << " " << --fManagerNumber << " " << fBossNumber;
	//����д���ļ�
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
	//�޸�ְ������
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << fStaffNumber<<" " << fManagerNumber<<" " << --fBossNumber;
	//����д���ļ�
	fstream fsBossWrite("bossInformation.txt", ios::out | ios::trunc);
	for (int i = 0; i < fBossNumber; i++)
	{
		fsBossWrite.write((const char*)&boss[i], sizeof(boss[i]));
	}
}