/*
���ļ��������£�
	1������ͷ�ļ�
		#include <fstream>
	2������������
		ifstream ifs;
	3�����ļ����ж��ļ��Ƿ�򿪳ɹ�
		ifs.open("�ļ�·��",�򿪷�ʽ);
	4��������
		���ַ�ʽ��ȡ
	5���ر��ļ�
		ifs.open();

*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void readFile0(fstream& fs);
void readFile1(fstream& fs);
void readFile2(fstream& fs);
void readFile3(fstream& fs);


int main()
{
	//��������
	fstream fs;
	//���ļ�
	fs.open("text.txt", ios::in);
	//�ж��ļ��Ƿ��
	if (!fs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
	}
	else
	{
		cout << "�ļ��򿪳ɹ�" << endl;
	}
//��ȡ���ݣ������ַ�ʽ
   	//��һ�֣��ַ����������
	readFile0(fs);
	//�ڶ��֣�һ�ζ�һ������
	readFile1(fs);
	//�����֣������ַ�����ȡ
	readFile2(fs);
	//�����֣�һ�ζ�һ���ַ�
	readFile3(fs);

	//�ر��ļ�
	fs.close();


	return 0;
}
void readFile0(fstream& fs)
{
	char buf[1024] = { 0 };
	while (fs >> buf)
	{
		cout << buf << endl;
	}
}
void readFile1(fstream& fs)
{
	char buf1[1024] = { 0 };
	while (fs.getline(buf1, sizeof(buf1)))
	{
		cout << buf1 << endl;
	}
}
void readFile2(fstream& fs)
{
	string buf;
	while (getline(fs,buf))
	{
		cout << buf << endl;
	}
}
void readFile3(fstream& fs)
{
	char buf;
	while ( (buf = fs.get()) != EOF)//EOF ���ļ�β������־
	{
		cout << buf;//��Ҫ����
	}
}