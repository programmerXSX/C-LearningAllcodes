/*
二进制读文件：
	二进制读文件主要利用流对象调用成员函数read
	函数原型：istream& read(char* buffer,int len)
	参数解释：字符指针buffer指向内存中一段储存空间，len是读写的字节数
注：用什么方式写入就要用原方式读出，由于我重新创建文件，因此要重复写Person类
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
	//创建文件对象并打开
	fstream fs("Person.txt", ios::in | ios::binary);
	//判断是否成功打开
	if (!fs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return 0;
	}
	//读取数据
	Person p;
	while (fs.read((char*)&p, sizeof(p)))
	{
		//输出数据
		cout << "年龄：" << p.age << " 内容：" << p.ch << endl;
	}
	//关闭文件
	fs.close();
	
	return 0;
}