#include <iostream>
using namespace std;

//int& �ı�����ָ�볣��������int& = int* const��
void swap(int& a, int& b);
int& test();
void test2(const int& a);

int main()
{
	int a1 = 10;
	const int& ref = a1;//����const�󲻿��޸ģ���ֹ���β������
	a1 = 20;
	cout << ref;

	int a = 10,c= 20;
	int& b = a;
	b = 1000;
	cout << "a = " <<a<< endl;;
	swap(a, c);
	cout << "a = " << a << "  c = " << c << endl;


	int& d = test();
	cout << d;
}

void swap( int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int& test()
{

	//int a = 10;	���ʱ�򲻿���������ֵ����ʱa�����ջ��
	static int a = 10;//static��ʾ��̬�����������ȫ������ȫ�����ϵ������ڳ��������ϵͳ�ͷ�
	return a;
}


void test2(const int& a)
{
	//a = 10    ���󣬷�ֹ�����



}