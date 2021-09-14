#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int number = 1;

//用于计算
class CPU
{
public:
	virtual void calculate() = 0;
};
//用于显示
class Card
{
public:
	virtual void show() = 0;
};
//用于储存
class Memory
{
public:
	virtual void reserve() = 0;
};
/*
若有所思：
	起初我用多继承的方式，创建一个Lenovo类和一个Intel类继承三个零件
	但是问题就出现了：
		在Computer类的析构函数中释放三个零件的资源的时候会出现问题，看了几遍发现
		原来在创建电脑零件的对象的时候，new的是同一个对象，这就导致释放内存时多次重复释放
		从而代码崩溃
	因此在开发中，多继承很多时候并不适用
*/
//Intel厂商
//class Intel:public Memory,public CPU, public Card
//{
//public:
//	void calculate()
//	{
//		cout << "\tIntel出产的CPU" << endl;
//	}
//	void show()
//	{
//		cout << "\tIntel出产的显卡" << endl;
//	}
//	void reserve()
//	{
//		cout << "\tIntel出产的内存条" << endl;
//	}
//};
////Lenovo厂商
//class Lenovo :public CPU, public Card, public Memory
//{
//public:
//	void calculate()
//	{
//		cout << "\tLenovo出产的CPU" << endl;
//	}
//	void show()
//	{
//		cout << "\tLenovo出产的显卡" << endl;
//	}
//	void reserve()
//	{
//		cout << "\tLenovo出产的内存条" << endl;
//	}
//};
//Lenovo的CPU
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "\tLenovo出产的CPU" << endl;
	}
};
//Lenovo的显卡
class LenovoCard :public Card
{
public:
	void show()
	{
		cout << "\tLenovo出产的显卡" << endl;
	}
};
//Lenovo的内存条
class LenovoMemory :public Memory 
{
public:
	void reserve()
	{
		cout << "\tLenovo出产的内存条" << endl;
	}
};
//Intel的CPU
class IntelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "\tIntel出产的CPU" << endl;
	}
};
//Intel的显卡
class IntelCard :public Card
{
public:
	void show()
	{
		cout << "\tIntel出产的显卡" << endl;
	}
};
//Intel的内存条
class IntelMemory :public Memory
{
public:
	void reserve()
	{
		cout << "\tIntel出产的内存条" << endl;
	}
};
//电脑基类
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
	//电脑开始工作
	void work()
	{
		m_cpu->calculate();
		m_card->show();
		m_memory->reserve();
	}
	//获取产品号
	void getProductNumber()
	{
		cout << "\t产品号是:" << productNumber << endl;
	}
	//释放零件内存
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
	string productNumber;//产品号
	CPU* m_cpu;
	Card* m_card;
	Memory* m_memory;
};
void assembleComputer1()
{
	cout << "第一台电脑组装完成！" << endl;
	//制造零件
	CPU* cpu = new LenovoCPU();
	Card* card = new LenovoCard();
	Memory* memory = new LenovoMemory();
	//组装电脑
	Computer* computer = new Computer(cpu, card, memory);
	computer->getProductNumber();//获取产品号
	computer->work();//开始工作
	//释放内存
	delete computer;
}
void assembleComputer2()
{
	cout << "第二台电脑组装完成！" << endl;
	//直接在创建电脑时新建对象
	Computer* computer = new Computer(new LenovoCPU, new IntelCard, new LenovoMemory);
	computer->getProductNumber();//获取产品号
	computer->work();//开始工作
	//释放内存
	delete computer;
}
void assembleComputer3()
{
	cout << "第三台电脑组装完成！" << endl;
	//制造零件
	CPU* cpu = new IntelCPU();
	Card* card = new IntelCard();
	Memory* memory = new IntelMemory();
	//组装电脑
	Computer* computer = new Computer(cpu, card, memory);
	computer->getProductNumber();//获取产品号
	computer->work();//开始工作
	//释放内存
	delete computer;
}
int main()
{
	cout << "n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	assembleComputer1();//电脑1
	assembleComputer2();//电脑2
	assembleComputer3();//电脑3

	return 0;
}