#include "customize.h"
#include <iostream>

void set_coordinate(Circle& C, Point& P)		//��������
{
	cout << "������Բ������" << endl;
	cin >> C.c_X >> C.c_Y;
	cout << "������Բ�İ뾶" << endl;
	cin >> C.R;
	cout << "������������" << endl;
	cin >> P.p_X >> P.p_Y;

}

void relation_C_P(Circle C, Point P)			//Բ����ϵ
{
	double distance = pow(pow(C.c_X - P.p_X, 2) + pow(C.c_Y - P.p_Y, 2), 0.5);
	cout << "�㵽Բ�ľ���Ϊ��" << distance << endl;
	cout << "����Բ�Ĺ�ϵΪ��";
	if (distance - C.R > 0)cout << "����Բ��" << endl;
	else if (distance - C.R < 0)cout << "����԰��" << endl;
	else cout << "����Բ��" << endl;
}
