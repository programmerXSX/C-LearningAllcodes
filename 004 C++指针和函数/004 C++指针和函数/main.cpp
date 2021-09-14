#include <iostream>
using namespace std;
void swap1(int a, int b); 
void swap2(int* p1, int* p2);

int main()
{
	int a = 10, b = 20;
	cout << "未交换前a = 10,b = 20" << endl;
	swap1(a, b);
	cout << "swap1函数交换后a = " << a << " b = " << b << endl;


	swap2(&a, &b);
	cout << "swap2函数交换后a = " << a << " b = " << b << endl;


	system("pause");
	return 0;
}

void swap1(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int* p1, int* p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}