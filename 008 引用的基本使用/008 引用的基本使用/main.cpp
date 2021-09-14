#include <iostream>
using namespace std;

//int& 的本质是指针常量——（int& = int* const）
void swap(int& a, int& b);
int& test();
void test2(const int& a);

int main()
{
	int a1 = 10;
	const int& ref = a1;//加上const后不可修改，防止作形参误操作
	a1 = 20;
	cout << ref;

	int a = 10,c= 20;
	int& b = a;
	b = 1000;
	cout << "a = " <<a<< endl;;
	swap(a, c);
	cout << "a = " << a << "  c = " << c << endl;


	int& d = test();
	cout << d;
}

void swap( int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int& test()
{

	//int a = 10;	这个时候不可以做返回值，此时a存放在栈区
	static int a = 10;//static表示静态变量，存放在全局区，全局区上的数据在程序结束后系统释放
	return a;
}


void test2(const int& a)
{
	//a = 10    错误，防止误操作



}