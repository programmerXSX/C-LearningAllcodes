#include <iostream>
using namespace std;
class makeDrinks
{
public:
	void boilWater()
	{
		cout << "\t1、煮水" << endl;
	}
	virtual void brew() = 0;//冲泡
	void pourIntoCup()
	{
		cout << "\t3、倒入杯中" << endl;
	}
	virtual void addSeason() = 0;

};
class coffee :public makeDrinks
{
public:
	void addSeason()
	{
		cout << "\t4、加糖和牛奶" << endl;
	}
	void brew()
	{
		cout << "\t2、冲泡咖啡" << endl;
	}
};
class tea :public makeDrinks
{
public:
	void brew()
	{
		cout << "\t1、冲泡茶叶" << endl;
	}
	void addSeason()
	{
		cout << "\t4、加柠檬" << endl;
	}
};
void makeDrink(makeDrinks* md)
{
	md->boilWater();
	md->brew();
	md->pourIntoCup();
	md->addSeason();
	//释放内存
	delete md;
}
int main()
{
	//制作coffee
	makeDrinks* md = new coffee;
	cout << "制作coffee步骤：" << endl;
	makeDrink(md);
	//制作tea
	cout << "制作tea步骤：" << endl;
	md = new tea;
	makeDrink(md);
	//释放内存
	delete md;

	return 0;
}