#include <iostream>
#include <conio.h>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();


	Building* building;

};
class Building
{
	
	friend GoodGay;
public:
	Building();
public:
	string SittingRoom;
private:
	string BedRoom;
};
Building::Building()
{
	SittingRoom = "客厅";
	BedRoom = "卧室";

}
GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::visit()
{
	cout << "好基友类正在访问：" << building->SittingRoom << endl;
	cout << "好基友正在访问：" << building->BedRoom << endl; 
}

void test01()
{
	GoodGay gg;
	gg.visit();
	
}

int main()
{
	test01();




	system("pause");
	return 0;
}