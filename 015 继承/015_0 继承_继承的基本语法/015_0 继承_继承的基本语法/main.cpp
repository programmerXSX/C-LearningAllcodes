//�﷨	class ���� �� �̳з�ʽ ����
#include<iostream>
using namespace std;

class People
{
public:
	long ID_number;
	string name;
	void work(string workName)
	{
		cout << "������" << name << "\n���֤���룺" << ID_number << "\n������" << workName << endl;
	}
};

class WYF :public People
{
public:
	void crime()
	{
		cout << "��ȥ��" << endl;
	}
};

int main()
{
	WYF wyf;
	wyf.name = "wu";
	wyf.ID_number = 15456484;
	wyf.work("���ǡ�����");
	wyf.crime();

	


	return 0;
}