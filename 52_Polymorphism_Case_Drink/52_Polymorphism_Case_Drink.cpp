// 52_Polymorphism_Case_Drink.cpp: 目标的源文件。
//制作饮品大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料

//虚析构和纯虚析构
//多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方案：将父类的析构函数改为虚析构或者纯虚析构

//虚析构和纯虚析构共性：
//1.可以解决父类指针释放子类对象
//2.都需要有具体代码实现
//虚析构和纯虚析构区别：
//1.如果是春虚析构，该类属于抽象类，无法实例化对象

//虚析构语法：virtual ~类名(){}
//纯虚析构语法：virtual ~类名() = 0;		类名::~类名(){}

//总结：
//1.虚析构和纯虚析构就是用来解决通过父类指针释放子类对象
//2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
//3.拥有纯虚析构函数的类也属于抽象类


#include "52_Polymorphism_Case_Drink.h"

class AbstractDrink
{
public:
	
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//装杯
	virtual void PoolInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	//制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PoolInCup();
		PutSomething();
	}

};

//制作咖啡
class Coffee : public AbstractDrink
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮山泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲蓝山咖啡 " << endl;
	}
	//装杯
	virtual void PoolInCup()
	{
		cout << "装进咖啡杯" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入黑巧白奶方糖" << endl;
	}
};


//制作茶
//制作咖啡
class tea: public AbstractDrink
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮山泉水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "泡龙井茶 " << endl;
	}
	//装杯
	virtual void PoolInCup()
	{
		cout << "装进茶杯" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入黄冰糖" << endl;
	}
};
//制作过程
//void doWork(AbstractDrink& abs)
//{
//	abs.makeDrink();
//}
void doWork(AbstractDrink* abs)
{
	abs->makeDrink();
	delete abs;
}

void test01()
{
	//制作咖啡
	doWork(new Coffee);

	cout << "------------------------------------" << endl;

	//制作茶
	doWork(new tea);

}


//虚析构和纯虚析构
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数" << endl;
	}
	//利用虚析构可以解决父类指针释放子类对象时不干净的问题
	/*virtual ~Animal()
	{
		cout << "Animal的析构函数" << endl;
	}*/

	//纯虚析构	需要声明也需要实现	有了纯虚析构，此类也时抽象类，无法实例化对象
	virtual ~Animal() = 0;

	//纯虚函数
	virtual void speak() = 0;
};
Animal::~Animal()
{
	cout << "Animal的析构函数" << endl;
 }



class Cat : public Animal
{
public:
	Cat(string name)
	{
		cout << "cat的构造函数" << endl;
		m_Name = new string(name);
	}
	~Cat()
	{
		if (m_Name != NULL)
		{
			cout << "cat的析构函数" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}

	virtual void speak()
	{
		cout << *m_Name<< ":“喵喵喵”" << endl;
	}

	string* m_Name;
};

void test02()
{
	Animal* animal = new Cat("汤姆");
	animal->speak();
	//父类指针在析构的时候不会调用子类的析构，导致子类如果有堆区的数据，此时会出现内存泄漏情况
	//解决方案：父类析构函数改为虚析构
	delete animal;


}

int main()
{
	//test01();
	test02();

	return 0;
}
