/*
二进制写文件：
	打开方式主要为 ios::binary;
	二进制写文件主要利用流对象调用成员函数write
	函数原型：ostream& write(const char* buffer, int len);
	参数解释：字符指针buffer指向内存中一段储存空间，len是读写的字节数

*/
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	int age;
	char ch[64];
};
int main()
{
	//创建Person对象并初始化
	Person p = { 18,"Hello World!" };
	//创建对象
	fstream fs("Person.txt", ios::binary | ios::out);
	//写数据
	fs.write((const char*)&p, sizeof(p));
	//&p是p的指针地址，参数是（const char*）型，所以强转类型
	
	//关闭文件
	fs.close();

	return 0;
}