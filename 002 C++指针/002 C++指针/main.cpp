#include <iostream>
using namespace std;

int main()
{
	int a = 10, b = 20;


	/*const����ָ�롪������ָ��
	�ص㣺ָ���ָ������޸ģ�����ָ��ָ���ֵ�������޸�*/
	const int* p = &a;
	*p = 20;		//���󣡣�������ִ��
	cout << "*p = " << *p << endl;
	p = &b;
	cout << "*p = " << *p << endl;


	/*const���γ�������ָ�볣��
	�ص㣺ָ���ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը�*/
	int* const p = &a;
	*p = 20;
	p = &b;		//���󣡣�ָ��ָ�򲻿��Ը�


	/*const������ָ�룬�����γ���
	�ص㣺ָ���ָ���ָ��ָ���ֵ�������Ը�*/
	const int* const p = &a;
	*p = 20;		//����
	p = &b;			//����


	return 0;
}