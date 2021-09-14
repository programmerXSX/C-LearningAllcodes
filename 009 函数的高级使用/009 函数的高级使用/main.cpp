#include <iostream>
using namespace std;

void fun3(int a, int b = 10);
void fun3(int a);//这两个函数传入参数可以一样会导致保错，如果传入两个就没问题

void cons(int& a);//const可以作为函数重载的区分条件
void cons(const int& a);//当传入可修改变量，进上面的函数，不可修改进下面的函数

void func(int a, char b);//函数重载：1、同一作用域下2、函数名称相同
void func(char b, int a);//3、函数参数类型不同，或者个数不同，或者顺序不同
void fun1(int a, int);//占位参数
void fun(int a, int b);//函数的实现和声明只能有一个使用默认参数
//void fun(int a, int b = 10);

int main()
{
	const int aa = 10;
	cons(aa);

	//fun1(10);必须传入两个参数
	fun1(10, 20);

	func(10, 'a');
	func('a', 10);

	system("pause");
	return 0;
}


void fun3(int a, int b = 10)
{
	cout << "yes" << endl;
}
void fun3(int a)
{
	cout << "no" << endl;
}

void cons(int& a)
{
	cout << "cons(int& a)调用" << endl;

}
void cons(const int& a)
{
	cout << "cons(const int& a)调用" << endl;
}

void func(int a, char b)
{
	cout << "夏敏大笨猪" << endl;
}

void func(char b, int a)
{
	cout << "夏浩然大笨猪" << endl;
}


void fun(int a, int b = 10)
{
	cout << a + b << endl;
}

void fun1(int a, int)
{
	cout << "a = " << a << endl;
}