/*������*/
#include <iostream>
using namespace std;
//�������
class abstractCalculator
{
public:
	int num1;
	int num2;
	virtual int getResult() = 0;
};
//�ӷ�
class addCalculator : public abstractCalculator
{
public:
	int getResult()
	{
		return num1 + num2;
	}
};
//����
class subCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return num1 - num2;
	}
};
//�˷�
class mulCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return num1 * num2;
	}
};
//����
class divCalculator :public abstractCalculator
{
public:
	int getResult()
	{
		return num1*1.000 / num2;
	}
};
int main()
{
//�ӷ�����
	//ʹ�ö�̬��������
	abstractCalculator* ac = new addCalculator;
	ac->num1 = 18;
	ac->num2 = 90;
	cout << ac->num1 << "+" << ac->num2 << " = " << ac->getResult() << endl;
	//����ǵ�����
	delete ac;

	return 0;
}