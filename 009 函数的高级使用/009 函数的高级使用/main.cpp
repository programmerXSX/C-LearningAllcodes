#include <iostream>
using namespace std;

void fun3(int a, int b = 10);
void fun3(int a);//���������������������һ���ᵼ�±����������������û����

void cons(int& a);//const������Ϊ�������ص���������
void cons(const int& a);//��������޸ı�����������ĺ����������޸Ľ�����ĺ���

void func(int a, char b);//�������أ�1��ͬһ��������2������������ͬ
void func(char b, int a);//3�������������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
void fun1(int a, int);//ռλ����
void fun(int a, int b);//������ʵ�ֺ�����ֻ����һ��ʹ��Ĭ�ϲ���
//void fun(int a, int b = 10);

int main()
{
	const int aa = 10;
	cons(aa);

	//fun1(10);���봫����������
	fun1(10, 20);

	func(10, 'a');
	func('a', 10);

	system("pause");
	return 0;
}


void fun3(int a, int b = 10)
{
	cout << "yes" << endl;
}
void fun3(int a)
{
	cout << "no" << endl;
}

void cons(int& a)
{
	cout << "cons(int& a)����" << endl;

}
void cons(const int& a)
{
	cout << "cons(const int& a)����" << endl;
}

void func(int a, char b)
{
	cout << "��������" << endl;
}

void func(char b, int a)
{
	cout << "�ĺ�Ȼ����" << endl;
}


void fun(int a, int b = 10)
{
	cout << a + b << endl;
}

void fun1(int a, int)
{
	cout << "a = " << a << endl;
}