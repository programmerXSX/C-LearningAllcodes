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
	SittingRoom = "����";
	BedRoom = "����";

}
GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::visit()
{
	cout << "�û��������ڷ��ʣ�" << building->SittingRoom << endl;
	cout << "�û������ڷ��ʣ�" << building->BedRoom << endl; 
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