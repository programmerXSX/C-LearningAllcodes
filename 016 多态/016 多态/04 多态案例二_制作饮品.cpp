#include <iostream>
using namespace std;
class makeDrinks
{
public:
	void boilWater()
	{
		cout << "\t1����ˮ" << endl;
	}
	virtual void brew() = 0;//����
	void pourIntoCup()
	{
		cout << "\t3�����뱭��" << endl;
	}
	virtual void addSeason() = 0;

};
class coffee :public makeDrinks
{
public:
	void addSeason()
	{
		cout << "\t4�����Ǻ�ţ��" << endl;
	}
	void brew()
	{
		cout << "\t2�����ݿ���" << endl;
	}
};
class tea :public makeDrinks
{
public:
	void brew()
	{
		cout << "\t1�����ݲ�Ҷ" << endl;
	}
	void addSeason()
	{
		cout << "\t4��������" << endl;
	}
};
void makeDrink(makeDrinks* md)
{
	md->boilWater();
	md->brew();
	md->pourIntoCup();
	md->addSeason();
	//�ͷ��ڴ�
	delete md;
}
int main()
{
	//����coffee
	makeDrinks* md = new coffee;
	cout << "����coffee���裺" << endl;
	makeDrink(md);
	//����tea
	cout << "����tea���裺" << endl;
	md = new tea;
	makeDrink(md);
	//�ͷ��ڴ�
	delete md;

	return 0;
}