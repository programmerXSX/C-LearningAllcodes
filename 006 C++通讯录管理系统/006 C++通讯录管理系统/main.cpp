#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

/*������ϵ�˽ṹ��*/
struct contact
{
	string name;
	string sex;
	int age;
	long long Phone;
	string home;
}
contacts[1000];		//������ϵ������

char option;//����ѡ��
int sum = 0;//��ϵ������

void ShowMenu();		//չʾͨѶ¼
void contacts_add();	//��ϵ�����
void contacts_show();	//��ϵ����ʾ
void contacts_delete();	//��ϵ��ɾ��
void contacts_find();	//��ϵ�˲���
void contacts_change();	//��ϵ���޸�
void contacts_empty();	//��ϵ�����

int main()
{
	while (1)
	{
		system("cls");
		ShowMenu();
		cin >> option;
		switch (option)
		{
		case '1':
			contacts_add();			//��ϵ�����
			break;
		case '2':
			contacts_show();		//��ϵ����ʾ
			break;
		case '3':
			contacts_delete();		//��ϵ��ɾ��
			break;
		case '4':
			contacts_find(); 		//��ϵ�˲���
			break;
		case '5':
			contacts_change();		//��ϵ���޸�
			break;
		case '6':
			contacts_empty();		//��ϵ�����
			break;
		case '0':
			return 0;
			break;
		default:
			MessageBox(NULL, TEXT("����ȷ���룡��"), TEXT("����"), MB_OK | MB_ICONERROR);
			break;
		}
	}
	return 0;
}


void ShowMenu()		//չʾͨѶ¼
{
	cout << "|-������������-����������-|" << endl;
	cout << "|-��������ͨѶ¼-��������-|" << endl;
	cout << "|                         |" << endl;
	cout << "|����1�������ϵ�ˡ�������|" << endl;
	cout << "|����2����ʾ��ϵ�ˡ�������|" << endl;
	cout << "|����3��ɾ����ϵ�ˡ�������|" << endl;
	cout << "|����4��������ϵ�ˡ�������|" << endl;
	cout << "|����5���޸���ϵ�ˡ�������|" << endl;
	cout << "|����6�������ϵ�ˡ�������|" << endl;
	cout << "|����0���˳�ͨѶ¼��������|" << endl;
	cout << "|-������������-����������-|" << endl;
	cout << "��ѡ�������"<<endl;
}

void contacts_add()	//��ϵ�����
{
	cout << "�������" << sum + 1 << "λ��ϵ�˵�������" << endl;
	cin >> contacts[sum + 1 - 1].name;
	cout << "�������" << sum + 1 << "λ��ϵ�˵��Ա�" << endl;
	cin >> contacts[sum + 1 - 1].sex;
	cout << "�������" << sum + 1 << "λ��ϵ�˵����䣺" << endl;
	cin >> contacts[sum + 1 - 1].age;
	cout << "�������" << sum + 1 << "λ��ϵ�˵���ϵ�绰��" << endl;
	cin >> contacts[sum + 1 - 1].Phone;
	cout << "�������" << sum + 1 << "λ��ϵ�˵ļ�ͥסַ��" << endl;
	cin >> contacts[sum + 1 - 1].home;
	MessageBox(NULL, TEXT("��ϵ��������!"), TEXT(""), MB_OK);
	sum++;
}

void contacts_show()	//��ϵ����ʾ
{
	if (sum == 0)cout << "ͨѶ¼Ϊ�գ�" << endl;
	for (int i = 0; i < sum; i++)
	{
		cout << "��ϵ��" << i + 1 << ":" << endl;
		cout << "\t������" << contacts[i].name << endl;
		cout << "\t�Ա�" << contacts[i].sex << endl;
		cout << "\t���䣺" << contacts[i].age << endl;
		cout << "\t��ϵ�绰��" << contacts[i].Phone << endl;
		cout << "\t��ͥסַ��" << contacts[i].home << endl;
	}
	system("pause");
}

void contacts_delete()	//��ϵ��ɾ��
{
	int number_delete;
	string name_delete;
	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	cin >> name_delete;
	for (int i = 0; i < sum; i++)
	{
		if (contacts[i].name.compare(name_delete) == 0)
		{
			for (int j = i; j < sum; j++)
			{
				contacts[j].name = contacts[j+1].name;
				contacts[j].age = contacts[j+1].age;
				contacts[j].home = contacts[j+1].home;
				contacts[j].Phone = contacts[j+1].Phone;
				contacts[j].sex = contacts[j+1].sex;
			}
			sum--;
			cout << "��ɾ����ϵ��" << name_delete << endl;
			break;
		}
		cout << "���޴���" << endl;
		break;
	}
	system("pause");
}

void contacts_find()	//��ϵ�˲���
{
	string name_find;
	cout << "������Ҫ������ϵ�˵�������" << endl;
	cin >> name_find;
	for (int i = 0; i < sum; i++)
	{
		if (name_find.compare(contacts[i].name) == 0)
		{
			cout << "��ϵ��" << i + 1 << ":" << endl;
			cout << "\t������" << contacts[i].name << endl;
			cout << "\t�Ա�" << contacts[i].sex << endl;
			cout << "\t���䣺" << contacts[i].age << endl;
			cout << "\t��ϵ�绰��" << contacts[i].Phone << endl;
			cout << "\t��ͥסַ��" << contacts[i].home << endl;
			break;
		}
		cout << "���޴���" << endl;
		break;
	}
	system("pause");
}

void contacts_change()	//��ϵ���޸�
{
	string name_change;
	cout << "������Ҫ�޸���ϵ�˵�������" << endl;
	cin >> name_change;
	for (int i = 0; i < sum; i++)
	{
		if (contacts[i].name.compare(name_change) == 0)
		{
			cout << "���ҵ����������������ϵ����Ϣ" << endl;
			cout << "���������ϵ�˵�������" << endl;
			cin >> contacts[i].name;
			cout << "���������ϵ�˵��Ա�" << endl;
			cin >> contacts[i].sex;
			cout << "���������ϵ�˵����䣺" << endl;
			cin >> contacts[i].age;
			cout << "���������ϵ�˵���ϵ�绰��" << endl;
			cin >> contacts[i].Phone;
			cout << "���������ϵ�˵ļ�ͥסַ��" << endl;
			cin >> contacts[i].home;
			break;
		}
		cout << "���޴���" << endl;
	}
	system("pause");
}

void contacts_empty()	//��ϵ�����
{
	int yes_no = MessageBox(NULL, TEXT("ȷ��Ҫ���������ϵ�ˣ�"), TEXT("��ʾ"), MB_YESNO | MB_ICONQUESTION);
	if (yes_no == IDYES)
	{
		sum = 0;
		cout << "�����������ϵ��" << endl;
		system("pause");
	}
}




















