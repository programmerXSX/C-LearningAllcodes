#include <iostream>
#include <conio.h>
using namespace std;

class Person
{
public:
	string name;
	int age;
private:

};
/*�ڳ�Ա������������ p.operator<<() �ĸ�ʽ �� ��Ϊ p<< , ������cout<< �ĸ�ʽ
�����Ҫ��ȫ�ֺ�������
*/
ostream& operator<<(ostream& cout, Person p)
{
	cout << p.name << "��������" << p.age << "��";
	return cout;
}



void test01()
{
	Person p1;
	p1.age = 18;
	p1.name = "��˳��";
	cout << p1 << endl;
}

int main() 
{
	test01();


	return 0;
}