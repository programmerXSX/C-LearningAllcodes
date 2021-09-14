/*
虚析构和纯虚析构：
	多态使用时，如果子类有属性开辟到堆区，那么父类在释放时无法调用到子类的析构代码
	解决方式：将父类中的析构函数改为虚析构或者纯虚析构
	虚析构和纯虚析构共性：
		可以解决父类指针释放子类对象
		都需要有具体的函数实现
	虚析构和纯虚析构的区别：
		如果是纯虚析构，该类是抽象类，无法实例化对象
*/
#include <iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		cout << "Animal调用构造函数" << endl;
	}
	////虚析构
	//virtual ~Animal()
	//{
	//	cout << "Animal调用析构函数" << endl;
	//}
	
	//纯虚析构,需要类外实现
	//有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
	virtual ~Animal() = 0;
	//纯虚函数
	virtual void func() = 0;
};
Animal::~Animal()
{
	cout << "Animal纯虚析构" << endl;
}
class Cat :public Animal
{
public:
	Cat(string name)
	{
		Cat::name = new string(name);
		cout << "Cat调用构造函数" << endl;
	}
	void func()
	{
		cout << *name << "在吃屎" << endl;
	}
	~Cat()
	{
		cout << "Cat调用析构函数" << endl;
		if (name != NULL)
		{
			delete name;
			name = NULL;
		}
	}
	string* name;
};

int main()
{
	Animal* animal = new Cat("Tom");
	animal->func();
	delete animal;


	return 0;
}