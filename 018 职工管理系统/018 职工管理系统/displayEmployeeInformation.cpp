#include "displayEmployeeInformation.h"
#include "employeeCategory.h";
#include <fstream>
#include <iostream>

//��ʾְ����Ϣ�ĺ���
void displayEmployeeInformation()
{
	//�����ļ���ȡ�����������
	fstream fsStaff("staffInformation.txt", ios::in | ios::binary);
	fstream fsManager("managerInformation.txt", ios::in | ios::binary);
	fstream fsBoss("bossInformation.txt", ios::in | ios::binary);
	fstream fsRead("Number.txt", ios::in);
	Boss boss;
	Manager manager;
	Staff staff;
	int staffNumber = 0, managerNumber = 0, bossNumber = 0;
	fsRead >> staffNumber >> managerNumber >> bossNumber;
	//��ȡ����
	//����ϰ�
	cout << "�ϰ�" << bossNumber << "��:" << endl;
	while (fsBoss.read((char*)&boss, sizeof(boss)))
	{
		printEmployeeIntformation(boss);
	}
	//�������
	cout << "����" << managerNumber << "����" << endl;
	while (fsManager.read((char*)&manager, sizeof(manager)))
	{
		printEmployeeIntformation(manager);
	}
	//�����ְͨ��
	cout << "��ְͨ��"<< staffNumber << "����" << endl;
	while (fsStaff.read((char*)&staff, sizeof(staff)))
	{
		printEmployeeIntformation(staff);
	}
	system("pause");
}
void printEmployeeIntformation(Staff staff)
{
	cout << "\t������"<< staff.name << endl;
	cout << "\t��ţ�"<< staff.number << endl;
	cout << "\tְλ��"<< staff.station << endl;
	cout << "\tְ��"<< staff.responsibility << "\n" << endl;
}
void printEmployeeIntformation(Manager manager)
{
	cout << "\t������" << manager.name << endl;
	cout << "\t��ţ�" << manager.number << endl;
	cout << "\tְλ��" << manager.station << endl;
	cout << "\tְ��" << manager.responsibility << "\n" << endl;
}
void printEmployeeIntformation(Boss boss)
{
	cout << "\t������" << boss.name << endl;
	cout << "\t��ţ�" << boss.number << endl;
	cout << "\tְλ��" << boss.station << endl;
	cout << "\tְ��" << boss.responsibility << "\n" << endl;
}