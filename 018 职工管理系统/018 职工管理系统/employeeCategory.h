#include <iostream>
#pragma once
//����ְ����
class Allstaff
{
public:
	const char* number = "NUMBER";//ְ�����
	const char* name = "NAME";//ְ������
};
//��ְͨ����
class Staff :public Allstaff
{
public:
	Staff& operator=(Staff staff);
	const char* station = "��ְͨ��";//ְ����λ
	const char* responsibility= "���";//ְ��ְ��	��ɾ�����������
};
//����
class Manager :public Allstaff
{
public:
	
	const char* station = "����";//ְ����λ
	const char* responsibility = "����·�";//ְ��ְ��		����ϰ彻�������񣬲��·������Ա��
};
//�ϰ�
class Boss :public Allstaff
{
public:
	const char* station = "�ϰ�";//ְ����λ
	const char* responsibility = "����";//ְ��ְ��		����˾��������
};
