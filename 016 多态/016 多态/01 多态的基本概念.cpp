/*
��̬��C++���������������֮һ
	��̬��Ϊ���ࣺ
		��̬��̬���������غ���������ض����ھ�̬��̬�����ú�����
		��̬��̬����������麯��ʵ������ʱ��̬
	��̬��̬�Ͷ�̬��̬������
		��̬��̬�ĺ�����ַ��� - ����׶�ȷ��������ַ
		��̬��̬�ĺ�����ַ��� - ���н׶�ȷ��������ַ
*//*
	��̬��̬����������
		1���м̳й�ϵ
		2��������д�����麯�����о��е���Java����abstract��������
	��̬��̬ʹ�ã�
		�����ָ�������ָ���������
	��д����������ֵ���ͣ��������������б���ȫһ�³�Ϊ��д
*/

#include <iostream>
using namespace std;
class Animal
{
public:
	virtual void speak()//�麯��
	{
		cout << "������˵��" << endl;
	}
};
class Cat :public Animal
{
public :
	void speak()
	{
		cout << "Сè��˵��" << endl;
	}
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "������˵��" << endl;
	}
};
//ִ��˵���ĺ���
void doSpeak(Animal& aniaml)
{
	aniaml.speak();
}
int main()
{
	Cat cat;
	doSpeak(cat);//Aniaml& animal = cat

	Dog dog;
	doSpeak(dog);//Animal& animal = dog

	return 0;
}