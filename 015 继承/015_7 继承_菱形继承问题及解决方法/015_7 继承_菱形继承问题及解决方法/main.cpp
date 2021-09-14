/*
菱形继承——例：
	🐏与🐫继承了动物类，
	羊驼又同时继承了二者，
	如果动物类中有一个属性m_Age,则🐏和🐫也有这个属性，这样的话羊驼就会继承两份m_Age属性
	导致数据不明确
*/
#include <iostream>
using namespace std;
//动物类
class Animal
{
public:
	int m_Age;
};
//🐏类
class sheep :virtual public Animal
{
};
//🐫类
class camel:virtual public Animal
{
};
//羊驼类
class sheep_camel :public sheep, public camel{};

int main()
{
	sheep_camel sc;
	sc.sheep::m_Age = 12;
	sc.camel::m_Age = 15;
	//sc.m_age = 10;//不明确
	//解决方法:注明作用域
	cout << "🐏类m_Age = " << sc.sheep::m_Age << endl;
	cout << "🐫类m_Age = " << sc.camel::m_Age << endl;
	/*
	我们都知道只要有一份数据就可以，菱形继承导致数据浪费
	因此采取virtual，利用虚继承解决菱形继承问题
	Animal类称为虚基类
	此时也不会出现不明确的问题了
	数据是最后一次修改的值
	*/
	cout << "子类m_Age = " << sc.m_Age << endl;
	return 0;
}