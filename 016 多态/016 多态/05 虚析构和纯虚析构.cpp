/*
�������ʹ���������
	��̬ʹ��ʱ��������������Կ��ٵ���������ô�������ͷ�ʱ�޷����õ��������������
	�����ʽ���������е�����������Ϊ���������ߴ�������
	�������ʹ����������ԣ�
		���Խ������ָ���ͷ��������
		����Ҫ�о���ĺ���ʵ��
	�������ʹ�������������
		����Ǵ��������������ǳ����࣬�޷�ʵ��������
*/
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal���ù��캯��" << endl;
	}
	////������
	//virtual ~Animal()
	//{
	//	cout << "Animal������������" << endl;
	//}
	
	//��������,��Ҫ����ʵ��
	//���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
	virtual ~Animal() = 0;
	//���麯��
	virtual void func() = 0;
};
Animal::~Animal()
{
	cout << "Animal��������" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		Cat::name = new string(name);
		cout << "Cat���ù��캯��" << endl;
	}
	void func()
	{
		cout << *name << "�ڳ�ʺ" << endl;
	}
	~Cat()
	{
		cout << "Cat������������" << endl;
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
	}
	string* name;
};

int main()
{
	Animal* animal = new Cat("Tom");
	animal->func();
	delete animal;


	return 0;
}