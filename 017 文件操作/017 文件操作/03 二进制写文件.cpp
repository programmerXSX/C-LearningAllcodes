/*
������д�ļ���
	�򿪷�ʽ��ҪΪ ios::binary;
	������д�ļ���Ҫ������������ó�Ա����write
	����ԭ�ͣ�ostream& write(const char* buffer, int len);
	�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ���ռ䣬len�Ƕ�д���ֽ���

*/
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	int age;
	char ch[64];
};
int main()
{
	//����Person���󲢳�ʼ��
	Person p = { 18,"Hello World!" };
	//��������
	fstream fs("Person.txt", ios::binary | ios::out);
	//д����
	fs.write((const char*)&p, sizeof(p));
	//&p��p��ָ���ַ�������ǣ�const char*���ͣ�����ǿת����
	
	//�ر��ļ�
	fs.close();

	return 0;
}