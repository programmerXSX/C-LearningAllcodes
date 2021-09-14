#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

/*定义联系人结构体*/
struct contact
{
	string name;
	string sex;
	int age;
	long long Phone;
	string home;
}
contacts[1000];		//定义联系人数组

char option;//操作选项
int sum = 0;//联系人总数

void ShowMenu();		//展示通讯录
void contacts_add();	//联系人添加
void contacts_show();	//联系人显示
void contacts_delete();	//联系人删除
void contacts_find();	//联系人查找
void contacts_change();	//联系人修改
void contacts_empty();	//联系人清空

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
			contacts_add();			//联系人添加
			break;
		case '2':
			contacts_show();		//联系人显示
			break;
		case '3':
			contacts_delete();		//联系人删除
			break;
		case '4':
			contacts_find(); 		//联系人查找
			break;
		case '5':
			contacts_change();		//联系人修改
			break;
		case '6':
			contacts_empty();		//联系人清空
			break;
		case '0':
			return 0;
			break;
		default:
			MessageBox(NULL, TEXT("请正确输入！！"), TEXT("错误"), MB_OK | MB_ICONERROR);
			break;
		}
	}
	return 0;
}


void ShowMenu()		//展示通讯录
{
	cout << "|-——————-—————-|" << endl;
	cout << "|-————通讯录-————-|" << endl;
	cout << "|                         |" << endl;
	cout << "|——1、添加联系人…………|" << endl;
	cout << "|——2、显示联系人…………|" << endl;
	cout << "|——3、删除联系人…………|" << endl;
	cout << "|——4、查找联系人…………|" << endl;
	cout << "|——5、修改联系人…………|" << endl;
	cout << "|——6、清空联系人…………|" << endl;
	cout << "|——0、退出通讯录…………|" << endl;
	cout << "|-——————-—————-|" << endl;
	cout << "请选择操作："<<endl;
}

void contacts_add()	//联系人添加
{
	cout << "请输入第" << sum + 1 << "位联系人的姓名：" << endl;
	cin >> contacts[sum + 1 - 1].name;
	cout << "请输入第" << sum + 1 << "位联系人的性别：" << endl;
	cin >> contacts[sum + 1 - 1].sex;
	cout << "请输入第" << sum + 1 << "位联系人的年龄：" << endl;
	cin >> contacts[sum + 1 - 1].age;
	cout << "请输入第" << sum + 1 << "位联系人的联系电话：" << endl;
	cin >> contacts[sum + 1 - 1].Phone;
	cout << "请输入第" << sum + 1 << "位联系人的家庭住址：" << endl;
	cin >> contacts[sum + 1 - 1].home;
	MessageBox(NULL, TEXT("联系人添加完成!"), TEXT(""), MB_OK);
	sum++;
}

void contacts_show()	//联系人显示
{
	if (sum == 0)cout << "通讯录为空！" << endl;
	for (int i = 0; i < sum; i++)
	{
		cout << "联系人" << i + 1 << ":" << endl;
		cout << "\t姓名：" << contacts[i].name << endl;
		cout << "\t性别：" << contacts[i].sex << endl;
		cout << "\t年龄：" << contacts[i].age << endl;
		cout << "\t联系电话：" << contacts[i].Phone << endl;
		cout << "\t家庭住址：" << contacts[i].home << endl;
	}
	system("pause");
}

void contacts_delete()	//联系人删除
{
	int number_delete;
	string name_delete;
	cout << "请输入要删除联系人的姓名：" << endl;
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
			cout << "已删除联系人" << name_delete << endl;
			break;
		}
		cout << "查无此人" << endl;
		break;
	}
	system("pause");
}

void contacts_find()	//联系人查找
{
	string name_find;
	cout << "请输入要查找联系人的姓名：" << endl;
	cin >> name_find;
	for (int i = 0; i < sum; i++)
	{
		if (name_find.compare(contacts[i].name) == 0)
		{
			cout << "联系人" << i + 1 << ":" << endl;
			cout << "\t姓名：" << contacts[i].name << endl;
			cout << "\t性别：" << contacts[i].sex << endl;
			cout << "\t年龄：" << contacts[i].age << endl;
			cout << "\t联系电话：" << contacts[i].Phone << endl;
			cout << "\t家庭住址：" << contacts[i].home << endl;
			break;
		}
		cout << "查无此人" << endl;
		break;
	}
	system("pause");
}

void contacts_change()	//联系人修改
{
	string name_change;
	cout << "请输入要修改联系人的姓名：" << endl;
	cin >> name_change;
	for (int i = 0; i < sum; i++)
	{
		if (contacts[i].name.compare(name_change) == 0)
		{
			cout << "已找到，请重新输入该联系人信息" << endl;
			cout << "请输入该联系人的姓名：" << endl;
			cin >> contacts[i].name;
			cout << "请输入该联系人的性别：" << endl;
			cin >> contacts[i].sex;
			cout << "请输入该联系人的年龄：" << endl;
			cin >> contacts[i].age;
			cout << "请输入该联系人的联系电话：" << endl;
			cin >> contacts[i].Phone;
			cout << "请输入该联系人的家庭住址：" << endl;
			cin >> contacts[i].home;
			break;
		}
		cout << "查无此人" << endl;
	}
	system("pause");
}

void contacts_empty()	//联系人清空
{
	int yes_no = MessageBox(NULL, TEXT("确定要清空所有联系人？"), TEXT("提示"), MB_YESNO | MB_ICONQUESTION);
	if (yes_no == IDYES)
	{
		sum = 0;
		cout << "已清空所有联系人" << endl;
		system("pause");
	}
}




















