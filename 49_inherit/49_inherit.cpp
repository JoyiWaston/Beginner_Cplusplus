// 49_inherit.cpp: 目标的源文件。
//

#include "49_inherit.h"
class base
{
public:
	base()
	{
		b_a = 100;
		cout << "base构造" << endl;
	}
	~base()
	{
		cout << "base析构" << endl;
	}
	int b_a;
	static int b_d;
	static int func();
protected:
	int b_b;
private:
	int b_c;
};
int base::b_d = 100;

class son : public base					//利用开发人员命令提示工具查看对象模型
{										//跳到.cpp文件根目录		查看命令：cl /d1 reportSingleClassLayout类名 "所属文件名"
public:
	son()
	{
		b_a = 200;
		cout << "son构造" << endl;
	}
	~son()
	{
		cout << "son析构" << endl;
	}
	int b_a;
	static int b_d;
	static int func();
};
int son::b_d = 200;
void test01()
{
	son s1;
	cout << "父类b_a = " << s1.base::b_a << endl;		//同名调用无论函数还是变量都要加作用域
	cout << "子类b_a = " << s1.b_a << endl;
	cout << sizeof(son) << endl;		//父类中所有非静态成员属性都会被子类继承
}
//同名静态成员属性
void test02()
{
	//通过对象访问
	son s;
	cout << "b_d = " << s.b_d << endl;
	cout << "父类b_d = " << s.base::b_d << endl;

	//通过类名访问
	cout << "通过类名访问：" << endl;
	cout << son::b_d << endl;
	//第一个::代表通过类名方式访问；第二个::代表访问父类作用域下访问
	cout << son::base::b_d << endl;

}
//多继承,c++开发中不建议使用多继承技术
class grandson : public base, public son
{
public:
	grandson()
	{
		cout << grandson::base::b_d << endl;
	}
};

//菱形继承
//动物类
class Animal
{
public:
	Animal();
	~Animal();
	int m_Age;

private:

};

Animal::Animal()
{
}

Animal::~Animal()
{
}
//羊类
//利用虚继承virtual解决菱形继承问题
//animal称为虚基类	
class sheep : virtual public Animal
{
public:
	sheep();
	~sheep();

private:

};

sheep::sheep()
{
}

sheep::~sheep()
{
}
//驼类
class camel : virtual public Animal
{
public:
	camel();
	~camel();

private:

};

camel::camel()
{
}

camel::~camel()
{
}
//羊驼类
class Alpaca : public sheep, public camel
{
public:
	Alpaca();
	~Alpaca();

private:

};

Alpaca::Alpaca()
{
}

Alpaca::~Alpaca()
{
}

void test03()
{
	Alpaca cnm;

	//虚基类继承得到的共同数据类似静态成员变量，只有一份
	cnm.sheep::m_Age = 18;
	cnm.camel::m_Age = 28;
	//当菱形继承，两个父类拥有相同的数据，需要加作用域用以区分
	cout << "cnm.sheep::m_Age = " << cnm.sheep::m_Age << endl;
	cout << "cnm.camel::m_Age = " << cnm.camel::m_Age << endl;
	//vbptr 虚基类指针指向同一块内存
	cout << "cnm.m_Age = " << cnm.m_Age << endl;

	//m_Age只需一份数据即可，菱形继承导致数据有两份，资源浪费
}

int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}
