/*计算器*/
#include <iostream>
using namespace std;
//计算基类
class abstractCalculator
{
public:
	int num1;
	int num2;
	virtual int getResult() = 0;
};
//加法
class addCalculator : public abstractCalculator
{
public:
	int getResult()
	{
		return num1 + num2;
	}
};
//减法
class subCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return num1 - num2;
	}
};
//乘法
class mulCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return num1 * num2;
	}
};
//除法
class divCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return num1*1.000 / num2;
	}
};
int main()
{
//加法运算
	//使用多态创建对象
	abstractCalculator* ac = new addCalculator;
	ac->num1 = 18;
	ac->num2 = 90;
	cout << ac->num1 << "+" << ac->num2 << " = " << ac->getResult() << endl;
	//用完记得销毁
	delete ac;

	return 0;
}