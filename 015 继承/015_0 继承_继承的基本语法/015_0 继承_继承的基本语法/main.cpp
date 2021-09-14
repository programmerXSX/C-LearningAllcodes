//语法	class 子类 ： 继承方式 父类
#include<iostream>
using namespace std;

class People
{
public:
	long ID_number;
	string name;
	void work(string workName)
	{
		cout << "姓名：" << name << "\n身份证号码：" << ID_number << "\n工作：" << workName << endl;
	}
};

class WYF :public People
{
public:
	void crime()
	{
		cout << "进去了" << endl;
	}
};

int main()
{
	WYF wyf;
	wyf.name = "wu";
	wyf.ID_number = 15456484;
	wyf.work("明星、歌手");
	wyf.crime();

	


	return 0;
}