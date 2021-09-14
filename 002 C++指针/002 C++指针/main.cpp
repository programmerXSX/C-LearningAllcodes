#include <iostream>
using namespace std;

int main()
{
	int a = 10, b = 20;


	/*const修饰指针——常量指针
	特点：指针的指向可以修改，但是指针指向的值不可以修改*/
	const int* p = &a;
	*p = 20;		//错误！！！不可执行
	cout << "*p = " << *p << endl;
	p = &b;
	cout << "*p = " << *p << endl;


	/*const修饰常量——指针常量
	特点：指针的指向不可以改，指针指向的值可以改*/
	int* const p = &a;
	*p = 20;
	p = &b;		//错误！！指针指向不可以改


	/*const既修饰指针，又修饰常量
	特点：指针的指向和指针指向的值都不可以改*/
	const int* const p = &a;
	*p = 20;		//错误
	p = &b;			//错误


	return 0;
}