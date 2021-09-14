/*
读文件步骤如下：
	1、包含头文件
		#include <fstream>
	2、创建流对象
		ifstream ifs;
	3、打开文件并判断文件是否打开成功
		ifs.open("文件路径",打开方式);
	4、读数据
		四种方式读取
	5、关闭文件
		ifs.open();

*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void readFile0(fstream& fs);
void readFile1(fstream& fs);
void readFile2(fstream& fs);
void readFile3(fstream& fs);


int main()
{
	//创建对象
	fstream fs;
	//打开文件
	fs.open("text.txt", ios::in);
	//判断文件是否打开
	if (!fs.is_open())
	{
		cout << "文件打开失败" << endl;
	}
	else
	{
		cout << "文件打开成功" << endl;
	}
//读取数据，共四种方式
   	//第一种：字符数组读数据
	readFile0(fs);
	//第二种：一次读一行数据
	readFile1(fs);
	//第三种：利用字符串读取
	readFile2(fs);
	//第四种：一次读一个字符
	readFile3(fs);

	//关闭文件
	fs.close();


	return 0;
}
void readFile0(fstream& fs)
{
	char buf[1024] = { 0 };
	while (fs >> buf)
	{
		cout << buf << endl;
	}
}
void readFile1(fstream& fs)
{
	char buf1[1024] = { 0 };
	while (fs.getline(buf1, sizeof(buf1)))
	{
		cout << buf1 << endl;
	}
}
void readFile2(fstream& fs)
{
	string buf;
	while (getline(fs,buf))
	{
		cout << buf << endl;
	}
}
void readFile3(fstream& fs)
{
	char buf;
	while ( (buf = fs.get()) != EOF)//EOF 是文件尾结束标志
	{
		cout << buf;//不要换行
	}
}