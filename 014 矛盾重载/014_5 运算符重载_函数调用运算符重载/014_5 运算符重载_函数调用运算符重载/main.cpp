/*
�������������()Ҳ��������
�������غ��ʹ�÷�ʽ�ǳ������ĵ��ã���˱���Ϊ�º���
�º���û�й̶�д�����ǳ����
*/

#include<iostream>
using namespace std;

class MyPrint
{
public:
	void operator()(string line)
	{
		cout << line << endl;
	}

private:

};

int main()
{
	MyPrint mp;
	mp("����ǳ�����");
	//������������ ������+() 
	MyPrint()("������������");
	return 0;
}