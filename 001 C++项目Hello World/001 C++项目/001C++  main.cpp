#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
#define week 7	//define定义的宏常量
int stop;

int main()
{
	int array[10] = { 8,2,4,5,7,3,13,9,28,15 },t;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				t = array[j];
				array[j] = array[j + 1];
				array[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < 10; i++) { cout << array[i] <<" "; }
	cout << endl;

	int arr[10] = { 1,2,3,4,5 };
	cout << sizeof(arr) << endl;
	stop = _getch();

	for (int i = 0; i <= 100; i++)
	{
		if (i % 2 == 0)continue;
		cout << i + 1 << endl;
	}

	bool a_0 = true, b_0 = false;
	cout << (a_0 && b_0)<< endl;

	int cin_0;
	cout << "输入整数：" << endl;
	cin >> cin_0;
	cout << "结果为" << cin_0 << endl;

	bool love = true;
	if (love)printf("xsx love jzt");
	cout << endl;

	char str1[] = "hello World";
	cout << str1<< endl ;

	string str2 = "minwa";
	cout << str2 << endl;
	cout << "\a" << endl;//警报
	char ch0 = '0', ch1 = 'a', ch2 = 'A';

	cout << "0的ACSLL码是"<<(int)ch0<< "	a的ACSLL码是" << (int)ch1 << "	A的ACSLL码是"<<(int)ch2 << endl;

	int a = 10;

	float b = 3.141592657f;
	double c = 3.141592657;

	cout << "b = " << b << "c = " << c << endl;

	const int weekend = 2;		//const修饰的变量，不可修改

	cout << sizeof(a) << endl;

	cout << "周末有" << weekend << "天" << endl;

	cout << "一周有" << week  <<"天"<< endl;

	if (true)goto xxx;
	cout << "Hello World" << endl;
	
xxx:

	system("pause");

	return 0;
}