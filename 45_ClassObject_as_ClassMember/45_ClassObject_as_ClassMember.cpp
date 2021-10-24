// 45_ClassObject_as_ClassMember.cpp: 目标的源文件。
//类对象作为类成员,静态成员变量static，静态成员函数

#include "45_ClassObject_as_ClassMember.h"

//类对象作为类成员
class Phone
{
public:
	Phone(string Band)
	{
		band = Band;
		cout << "Phone构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "Phone析构函数调用" << endl;
	}
	
	string band;//品牌
};

class Person
{
public:
	Person(string Name, string band):name(Name),myPhone(band)	//等同于Phone myPhone = band;隐式转换法
	{
		cout << "Person构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person析构函数调用" << endl;
	}
	string name;//姓名
	Phone myPhone;
};

//静态成员变量
class Man
{
public:
	//1.所有对象都共享同一份数据
	//2.编译阶段就分配内存
	//3.类内声明，类外初始化操作

	static int m_A;

	//静态成员变量也是有访问权限的
private:
	static int m_B;
};
int Man::m_A = 100;
//当其他类对象作为本类成员，先构造类对象，再构造自身
void test01()
{
	Person p("张三", "华为P50");

	cout << p.name << "拿着:" << p.myPhone.band << endl;
}
void test02()
{
	Man p;
	cout << p.m_A << endl;

	Man p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}
void test03()
{
	//静态成员变量 不属于某个对象 所有对象共享数据
	//静态成员变量的两种访问

	//1.通过对象访问
	Man p;
	cout << p.m_A << endl;
	//2.通过类名进行访问
	cout << Man::m_A << endl;
	//cout << Man::m_B << endl;
}


//静态成员函数
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量
class Guy
{
public:
	//静态成员函数
	static void func()
	{
		m_A = 100;//静态成员函数	可以访问	静态成员变量
		//m_B = 200;//静态成员函数	不可以访问	静态成员变量 无法区分到底是哪个对象所有的

		cout << "static void func调用" << endl;
	}
	static int m_A;
	int m_B;

	//静态成员函数也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2调用" << endl;
	}

};

int Guy::m_A = 0;
void test04()
{
	//1.通过对象访问
	Guy p;
	p.func();

	//2.通过类名进行访问
	Guy::func();
	//Guy::func2();   //类外不可以访问私有静态成员函数

}


int main()
{
	//test01();
	//test02();
	//test03();
	test04();

	return 0;
}
