/*
�����ƶ��ļ���
	�����ƶ��ļ���Ҫ������������ó�Ա����read
	����ԭ�ͣ�istream& read(char* buffer,int len)
	�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ���ռ䣬len�Ƕ�д���ֽ���
ע����ʲô��ʽд���Ҫ��ԭ��ʽ���������������´����ļ������Ҫ�ظ�дPerson��
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
	//�����ļ����󲢴�
	fstream fs("Person.txt", ios::in | ios::binary);
	//�ж��Ƿ�ɹ���
	if (!fs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return 0;
	}
	//��ȡ����
	Person p;
	while (fs.read((char*)&p, sizeof(p)))
	{
		//�������
		cout << "���䣺" << p.age << " ���ݣ�" << p.ch << endl;
	}
	//�ر��ļ�
	fs.close();
	
	return 0;
}