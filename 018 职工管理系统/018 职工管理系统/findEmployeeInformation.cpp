#include "findEmployeeInformation.h"
#include "employeeCategory.h"
#include <iostream>
#include <fstream>
//����ְ����Ϣ
void findEmployeeInformation() 
{
	
	while (true)
	{
		//¼��ְ�����
		cout << "��������Ҫ����ְ���ı��(�˳�������END)��";
		char number[64];
		cin >> number;
		if (strcmp(number, "END") == 0) { break; }
		//����ְ��
		findEmployee(number);
		system("pause");
	}
}
bool findEmployee(char number[64])
{
	//��������
	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	string if_find = "NO";
	int staffNumber = 0, managerNumber = 0, bossNumber = 0, goalNumber = 0,
		fStaffNumber = 0, fManagerNumber = 0, fBossNumber = 0;
	//��ȡְ������
	fstream fsRead("Number.txt", ios::in);
	fsRead >> fStaffNumber >> fManagerNumber >> fBossNumber;

	//������ְͨ��
	fstream fsStaff("staffInformation.txt", ios::in | ios::binary);
	while (fsStaff.read((char*)&staff[staffNumber], sizeof(staff[staffNumber])))
	{
		if (strcmp(staff[staffNumber].number, number) == 0)
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
	while (fsManager.read((char*)&manager[managerNumber], sizeof(manager[managerNumber])))
	{
		if (strcmp(manager[managerNumber].number, number) == 0)
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
		if (strcmp(boss[bossNumber].number, number) == 0)
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
	if (if_find._Equal("NO")) 
	{
		cout << "δ�ҵ����Ϊ" << number << "��ְ������ȷ����������" << endl;
		return false; 
	}
	return true;
}