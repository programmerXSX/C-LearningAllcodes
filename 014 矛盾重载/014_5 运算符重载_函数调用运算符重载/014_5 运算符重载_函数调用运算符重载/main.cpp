/*
函数调用运算符()也可以重载
由于重载后的使用方式非常像函数的调用，因此被称为仿函数
仿函数没有固定写法，非常灵活
*/

#include<iostream>
using namespace std;

class MyPrint
{
public:
	void operator()(string line)
	{
		cout << line << endl;
	}

private:

};

int main()
{
	MyPrint mp;
	mp("妈妈非常吵闹");
	//匿名函数对象 函数名+() 
	MyPrint()("匿名函数对象");
	return 0;
}