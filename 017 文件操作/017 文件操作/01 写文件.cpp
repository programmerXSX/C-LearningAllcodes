/*
д�ļ��������£�
	1������ͷ�ļ�
		#include <fstream>
	2������������
		ofstream ofs;
	3�����ļ�
		ofs.open("�ļ�·��",�򿪷�ʽ);
	4��д����
		ofs << "д�������";
	5���ر��ļ�
		ofs.close();
�򿪷�ʽ��
	ios::in			Ϊ���ļ������ļ�
	ios::out		Ϊд�ļ������ļ�
	ios::ate		��ʼλ�ã��ļ�β
	ios::app		׷�ӷ�ʽд�ļ�
	ios::trunc		����ļ����ڣ���ɾ��
	ios::binary		�����Ʒ�ʽ
ע�⣺�ļ��򿪷�ʽ�������ʹ�ã�����|������
���磺�ö����Ʒ�ʽд�ļ�,ios::binary|ios::out
	

*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//����������
	fstream fs;
	ofstream ofs("text.txt", ios::out |ios::trunc);
	//��λ�á���ʽ
	//ofs.open("text.txt", ios::out|ios::app);
	//д����
	ofs << "�ҵĵ�һ���ļ������ڻ���" << endl;

	//�ر�
	ofs.close();


	return 0;
}