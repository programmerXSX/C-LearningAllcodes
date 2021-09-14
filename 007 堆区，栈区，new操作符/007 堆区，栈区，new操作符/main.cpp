#include <iostream>
using namespace std;

int* func1();
int* func2();

int main()
{
	int* p = func1();
	cout << *p << endl;
	//delete p;	//ÊÍ·ÅpµÄÄÚ´æ
	cout << *p << endl;
	int* arr = func2();
	cout << *arr << endl;
	//delete[] arr;
	cout << *(arr + 1) << endl;
	system("pause");
	return 0;
}

int* func1()
{
	int a = 10;
	int* p = new int(a);
	return p;

}

int* func2()
{
	int* arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}
	return arr;

}