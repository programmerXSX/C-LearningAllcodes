#include "addEmployeeInformation.h"
#include "employeeCategory.h"
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>

//����ְ����Ϣ�ĺ���
void addEmployeeInformation()
{
	while (inputStaff()){}
	system("pause");
}
bool inputStaff()
{
	fstream fsStaff("staffInformation.txt",ios::out|ios::binary|ios::app);
	fstream fsManager("managerInformation.txt",ios::out|ios::binary|ios::app);
	fstream fsBoss("bossInformation.txt",ios::out|ios::binary|ios::app);

	Boss  boss[5];
	Manager manager[10];
	Staff staff[100];
	//��������ְ��������
	int staffNumber = 1, managerNumber = 1, bossNumber = 1;
	fstream fsRead("Number.txt", ios::in);//��ȡ��������
	if (fsRead.is_open())//�򿪳ɹ� 
	{
		if (!fsRead.eof())
		{
			fsRead >> staffNumber >> managerNumber >> bossNumber;
		}
	}
	//����ְ��
	cout << "����������ְ����ְλ(�˳�������886)��\n\t1����ְͨ��\n\t2������\n\t3���ϰ�\n";
	int station;
	cin >> station;
	switch (station)
	{
	case 1:
		staff[staffNumber - 1] = inputInformation(staff[staffNumber - 1]);
		fsStaff.write((const char*)&staff[staffNumber - 1], sizeof(staff[staffNumber - 1]));
		staffNumber++;
		MessageBox(NULL, TEXT("�ѳɹ�����"), TEXT(""), MB_OK);
		break;
	case 2:
		manager[managerNumber - 1] = inputInformation(manager[managerNumber - 1]);
		fsManager.write((const char*)&manager[managerNumber - 1], sizeof(manager[managerNumber - 1]));
		managerNumber++;
		MessageBox(NULL, TEXT("�ѳɹ�����"), TEXT(""), MB_OK);
		break;
	case 3:
		boss[bossNumber - 1] = inputInformation(boss[bossNumber - 1]);
		fsBoss.write((const char*)&boss[bossNumber - 1], sizeof(boss[bossNumber - 1]));
		bossNumber++;
		MessageBox(NULL, TEXT("�ѳɹ�����"), TEXT(""), MB_OK);
		break;
	case 886:
		return false;
	default:
		MessageBox(NULL, TEXT("����"), TEXT("��ʾ"), MB_ICONERROR);
		return true;
	}
	fstream fsWrite("Number.txt", ios::out);
	fsWrite << staffNumber << " "
		<< managerNumber << " "
		<< bossNumber << endl;
	return true;
	//�ر���Դ
	fsStaff.close();
	fsManager.close();
	fsBoss.close();
}
Staff& inputInformation(Staff& staff)
{
	string str;
	cout << "������ְ��������";
	cin >> str;
	staff.name = str.data();
	cout << "������ְ����ţ�";
	cin >> str;
	staff.number = str.data();
	return staff;
}
Manager& inputInformation(Manager& manager)
{
	string str;
	cout << "������ְ��������";
	cin >> str;
	manager.name = str.data();
	cout << "������ְ����ţ�";
	cin >> str;
	manager.number = str.data();
	return manager;
}
Boss& inputInformation(Boss& boss)
{
	string str;
	cout << "������ְ��������";
	cin >> str;
	boss.name = str.data();
	cout << "������ְ����ţ�";
	cin >> str;
	boss.number = str.data();
	return boss;
}