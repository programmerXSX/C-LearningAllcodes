#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int number = 1;

//���ڼ���
class CPU
{
public:
	virtual void calculate() = 0;
};
//������ʾ
class Card
{
public:
	virtual void show() = 0;
};
//���ڴ���
class Memory
{
public:
	virtual void reserve() = 0;
};
/*
������˼��
	������ö�̳еķ�ʽ������һ��Lenovo���һ��Intel��̳��������
	��������ͳ����ˣ�
		��Computer��������������ͷ������������Դ��ʱ���������⣬���˼��鷢��
		ԭ���ڴ�����������Ķ����ʱ��new����ͬһ��������͵����ͷ��ڴ�ʱ����ظ��ͷ�
		�Ӷ��������
	����ڿ����У���̳кܶ�ʱ�򲢲�����
*/
//Intel����
//class Intel:public Memory,public CPU, public Card
//{
//public:
//	void calculate()
//	{
//		cout << "\tIntel������CPU" << endl;
//	}
//	void show()
//	{
//		cout << "\tIntel�������Կ�" << endl;
//	}
//	void reserve()
//	{
//		cout << "\tIntel�������ڴ���" << endl;
//	}
//};
////Lenovo����
//class Lenovo :public CPU, public Card, public Memory
//{
//public:
//	void calculate()
//	{
//		cout << "\tLenovo������CPU" << endl;
//	}
//	void show()
//	{
//		cout << "\tLenovo�������Կ�" << endl;
//	}
//	void reserve()
//	{
//		cout << "\tLenovo�������ڴ���" << endl;
//	}
//};
//Lenovo��CPU
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "\tLenovo������CPU" << endl;
	}
};
//Lenovo���Կ�
class LenovoCard :public Card
{
public:
	void show()
	{
		cout << "\tLenovo�������Կ�" << endl;
	}
};
//Lenovo���ڴ���
class LenovoMemory :public Memory 
{
public:
	void reserve()
	{
		cout << "\tLenovo�������ڴ���" << endl;
	}
};
//Intel��CPU
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "\tIntel������CPU" << endl;
	}
};
//Intel���Կ�
class IntelCard :public Card
{
public:
	void show()
	{
		cout << "\tIntel�������Կ�" << endl;
	}
};
//Intel���ڴ���
class IntelMemory :public Memory
{
public:
	void reserve()
	{
		cout << "\tIntel�������ڴ���" << endl;
	}
};
//���Ի���
class Computer
{
public:
	Computer(CPU* cpu, Card* card, Memory* memory)
	{
		m_card = card;
		m_cpu = cpu;
		m_memory = memory;
		productNumber = "computerMakeByXSX" + to_string(number / 1000) + to_string(number / 100) + to_string(number / 10) + to_string(number++);
	}
	//���Կ�ʼ����
	void work()
	{
		m_cpu->calculate();
		m_card->show();
		m_memory->reserve();
	}
	//��ȡ��Ʒ��
	void getProductNumber()
	{
		cout << "\t��Ʒ����:" << productNumber << endl;
	}
	//�ͷ�����ڴ�
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_card != NULL)
		{
			delete m_card;
			m_card = NULL;
		}
		if (m_memory != NULL)
		{
			delete m_memory;
			m_memory = NULL;
		}
	}
private:
	string productNumber;//��Ʒ��
	CPU* m_cpu;
	Card* m_card;
	Memory* m_memory;
};
void assembleComputer1()
{
	cout << "��һ̨������װ��ɣ�" << endl;
	//�������
	CPU* cpu = new LenovoCPU();
	Card* card = new LenovoCard();
	Memory* memory = new LenovoMemory();
	//��װ����
	Computer* computer = new Computer(cpu, card, memory);
	computer->getProductNumber();//��ȡ��Ʒ��
	computer->work();//��ʼ����
	//�ͷ��ڴ�
	delete computer;
}
void assembleComputer2()
{
	cout << "�ڶ�̨������װ��ɣ�" << endl;
	//ֱ���ڴ�������ʱ�½�����
	Computer* computer = new Computer(new LenovoCPU, new IntelCard, new LenovoMemory);
	computer->getProductNumber();//��ȡ��Ʒ��
	computer->work();//��ʼ����
	//�ͷ��ڴ�
	delete computer;
}
void assembleComputer3()
{
	cout << "����̨������װ��ɣ�" << endl;
	//�������
	CPU* cpu = new IntelCPU();
	Card* card = new IntelCard();
	Memory* memory = new IntelMemory();
	//��װ����
	Computer* computer = new Computer(cpu, card, memory);
	computer->getProductNumber();//��ȡ��Ʒ��
	computer->work();//��ʼ����
	//�ͷ��ڴ�
	delete computer;
}
int main()
{
	cout << "n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	assembleComputer1();//����1
	assembleComputer2();//����2
	assembleComputer3();//����3

	return 0;
}