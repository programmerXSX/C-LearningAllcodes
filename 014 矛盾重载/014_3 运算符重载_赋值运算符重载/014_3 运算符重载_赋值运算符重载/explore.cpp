#include <iostream>
using namespace std;
class Person
{
public:
	int age;
	char name[64];
	const char* ID;
};
int main()
{
	Person p1;
	Person p2;
	p1.ID = "ָ�ӹٵ������ֻ�Ŷ�ǿ���˹��Ŷÿ������";
	p2.ID = p1.ID;
	cout << "p1.ID = " << p1.ID << endl;
	cout << "sizeof(p1.ID) = " << sizeof(p1.ID) << endl;
	cout << "p2.ID = " << p2.ID << endl;
	cout << "sizeof(p2.ID) = " << sizeof(p2.ID) << endl;
	string s = "�ַ���";
	Person p3 = { 12," ","ubsbefiufe" };
	p3.ID = s.data();
	cout << "p3.ID = " << p3.ID << endl;


	return 0;
 }