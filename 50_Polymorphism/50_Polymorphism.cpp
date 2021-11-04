// 50_Polymorphism.cpp: 目标的源文件。
//多态 包括静态多态 动态多态
//静态多态：函数重载和运算符重载属于静态多态，复用函数名
//动态多态：派生类和虚函数实现运行时多态
//静态多态的函数地址早绑定 - 编译阶段确定函数地址
//动态多态的函数地址晚绑定 - 运行阶段确定函数地址

//动态多态满足条件
//1.有继承关系
//2.子类重写父类的虚函数
// 
//动态多态的使用
//父类的指针或者引用 指向子类对象


#include "50_Polymorphism.h"
//动物类
class Animal
{
public:
	//虚函数	虚函数表指针 ——> 虚函数表 ——> 表内记录虚函数地址 &Animal::speak	   
	//当子类继承后，子类的虚函数指针会找子类虚函数表中的虚函数，然后覆盖父类虚函数
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
};

//猫类
class Cat : public Animal
{
public:
	void speak()
	{
		cout << "喵喵喵" << endl;
	}
};

//狗类
class Dog : public Animal
{
public:
	void speak()
	{
		cout << "汪汪汪" << endl;
	}
};

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行喵喵喵，那么这个函数地址就不能提前绑定，需要在运行阶段绑定，即晚绑定
void dospeak(Animal& animal)		//Animal & animal = cat;
{
	animal.speak();
}

void test01()
{
	Cat cat;
	dospeak(cat);
	Dog dog;
	dospeak(dog);
}

void test02()
{
	cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
}

int main()
{
	//test01();
	test02();


	return 0;
}
