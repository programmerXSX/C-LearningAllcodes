#include <iostream>
using namespace std;

int main()
{
	//利用指针访问数组中的元素
	int arr[10] = { 1,3,5,7,9,11,7,8,9,10 };

	cout << "第一个元素为 ：" << arr[0] << endl;

	int* p = arr;//arr就是数组首地址

	cout << "利用指针访问第一个元素 ： " << *p << endl;
	p++;
	cout << "利用指针访问第二个元素 ：" << *p << endl;
	
	cout << "(错误）利用指针访问第三个元素 ：" << *p+1 << endl;

	cout << "利用指针访问第三个元素 ：" << *(p + 1) << endl;




	return 0;
}
