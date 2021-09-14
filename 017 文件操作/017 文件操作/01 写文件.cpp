/*
写文件步骤如下：
	1、包含头文件
		#include <fstream>
	2、创建流对象
		ofstream ofs;
	3、打开文件
		ofs.open("文件路径",打开方式);
	4、写数据
		ofs << "写入的数据";
	5、关闭文件
		ofs.close();
打开方式：
	ios::in			为读文件而打开文件
	ios::out		为写文件而打开文件
	ios::ate		初始位置：文件尾
	ios::app		追加方式写文件
	ios::trunc		如果文件存在，先删除
	ios::binary		二进制方式
注意：文件打开方式可以配合使用，利用|操作符
例如：用二进制方式写文件,ios::binary|ios::out
	

*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	//创建流对象
	fstream fs;
	ofstream ofs("text.txt", ios::out |ios::trunc);
	//打开位置、方式
	//ofs.open("text.txt", ios::out|ios::app);
	//写数据
	ofs << "我的第一个文件，终于会了" << endl;

	//关闭
	ofs.close();


	return 0;
}