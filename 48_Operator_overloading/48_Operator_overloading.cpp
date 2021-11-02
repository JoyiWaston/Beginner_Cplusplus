// 48_Operator_overloading.cpp: 目标的源文件。
//加号运算符重载
//左移运算符重载
//递增运算符重载
//赋值运算符重载
//关系运算符重载
//函数调用运算符重载

#include "48_Operator_overloading.h"

class Person
{
public:
	//1.成员函数重载+号
	/*Person operator+(Person& p)
	{
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/

	//2.成员函数重载<<号		p.operator<<(cout)  简化版本 p << cout;
	//通常不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	/*void operator<<(cout)
	{

	}*/


	int m_A;
	int m_B;
};
//加号运算符重载
//2.全局函数重载+号
Person operator+(Person& p1, Person& p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//函数重载版本
Person operator+(Person& p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}
void test01()
{
	Person p1;
	p1.m_A = 10;
	p1.m_B = 20;
	Person p2;
	p2.m_A = 20;
	p2.m_B = 10;

	//成员函数重载本质调用
	//Person p3 = p1.operator+(p2);

	//全局函数重载本质调用
	//Person p3 = operator+(p1, p2);
	
	Person p3 = p1 + p2;
	//运算符重载，也可以发生函数重载
	Person p4 = p1 + 100;

	cout << p3.m_A << "\n" << p3.m_B << endl;
	cout << p4.m_A << "\n" << p4.m_B << endl;
}

//左移运算符重载
//只能利用全局函数重载<<运算符
ostream &operator<<(ostream &cout, Person &p)
{
	cout << "m_A = " << p.m_A << "\nm_B = " << p.m_B << endl;
	return cout;
}

void test02()
{
	Person p3;
	p3.m_A = 10;
	p3.m_B = 10;

	cout << p3 << endl;
}
//递增运算符++重载
class myInteger
{
	friend ostream& operator<<(ostream& cout, myInteger& myint);

public:
	myInteger()
	{
		m_Num = 0;
	}
	//重载前置++运算符，前置递增返回引用
	myInteger& operator++()
	{
		//先进行++操作
		m_Num++;
		//再将自身返回		为了只对一直只对一个数据进行递增操作
		return *this;
	}
	//重载后置++运算符,后置递增返回值
	//int代表占位参数，可以用于区分前置和后置递增
	myInteger operator++(int)
	{
		//先 记录当时结果
		myInteger temp = *this;

		//后 递增
		m_Num++;

		//最后将记录结果返回
		return temp;

	}
private:
	int m_Num;
};

void test03()
{
	myInteger myint;
	cout << myint << endl;
}
void test04()
{
	myInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}
ostream &operator<<(ostream& cout, myInteger& myint)
{
	cout << myint.m_Num;
	return cout;
}

//赋值运算符重载
class Man
{
public:
	Man(int age)
	{
		m_Age = new int(age);
		
	}
	~Man()
	{
		if (m_Age != NULL)				//堆区内存重复释放  浅拷贝带来的问题，深拷贝解决
		{								//
			delete m_Age;
			m_Age = NULL;
		}
	}
	//重载 赋值运算符
	Man& operator=(Man &m)
	{
		//编译器提供浅拷贝			m_Age = p.m_Age;


		//应该先判断是否有属性在堆区，如果有先释放干净再深拷贝
		if (m_Age != NULL)
		{
			delete m_Age;
			m_Age = NULL;
		}

		//深拷贝
		m_Age = new int(*m.m_Age);

		return *this;
	}


	int* m_Age;
};
void test05()
{
	Man p1(18);
	Man p2(20);
	Man p3(30);

	p3 = p2 = p1; //赋值操作

	cout << "P1的年龄为：" << *p1.m_Age << endl;
	cout << "P2的年龄为：" << *p2.m_Age << endl;
	cout << "P3的年龄为：" << *p3.m_Age << endl;
}

//关系运算符重载
class Guy
{
public:
	Guy(string name, int age)
	{
		g_name = name;
		g_age = age;
	}
	//重载==号
	bool operator==(Guy &g)
	{
		if (this->g_name == g.g_name && this->g_age == g.g_age)
		{
			return true;
		}
		return false;
	}
	//重载!=号
	bool operator!=(Guy& g)
	{
		if (this->g_name != g.g_name || this->g_age != g.g_age)
		{
			return true;
		}
		return false;
	}



	string g_name;
	int g_age;
};
void test06()
{
	Guy g1("TOM", 18);
	Guy g2("TOM", 19);
	if (g1 == g2)
	{
		cout << "g1与g2相等" << endl;
	}
	else
	{
		cout << "g1和g2不等" << endl;
	}

	if (g1 != g2)
	{
		cout << "g1与g2不相等" << endl;
	}
	else
	{
		cout << "g1和g2相等" << endl;
	}
}

//函数调用运算符重载()
//打印输出类
class myprint
{
public:
	//重载函数调用运算符

	void operator()(string test)
	{
		cout << test << endl;
	}
};

//仿函数非常灵活没有固定写法
class myplus
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};
void test07()
{
	myprint myprint;
	myprint("hello world");		//由于使用起来非常像函数调用，所以被称为    仿函数

	myplus mylpus;
	int temp = mylpus(1, 2);
	cout << temp << endl;

	//匿名函数对象
	cout << myplus()(200, 200) << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();

	system("pause");
	return 0;
}
