#include<iostream>
using namespace std;
class Base
{
public:
	int m;
	void func()
	{
		cout << "����func��������" << endl;
	}void func(int a)
	{
		cout << "����func��������" << endl;
	}
};
class Son :public Base
{
public:
	int m;
	void func()
	{
		cout << "����func��������" << endl;
	}
};
int main()
{
	Son s;
	s.m = 100;
	cout << "�����е�m = " << s.m << endl;
	s.Base::m = 200;
	cout << "�����е�m = " << s.Base::m << endl;

	s.func();
	s.Base::func();
	//��������г����˺͸����ͬ����Ա�����������е�����ͬ����Ա������������
	//s.func(90);
	s.Base::func(90);

	return 0;
}