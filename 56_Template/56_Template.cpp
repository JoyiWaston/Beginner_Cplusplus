// 56_Template.cpp: 目标的源文件。
//C++另一种编程思想称为 泛型编程，主要利用的技术就是模板		学习模板并不是为了写模板，而是为了在STL中能够运用系统提供的模板
//关键字template		typename可以用class替换
//自动类型推导、显示指定类型
//模板的目的是为了提高代码复用性，将类型参数化

//注意：
//自动类型推导 必须推导出一致的数据类型T才能使用！
//模板必须要确定出T的数据类型，才可以使用！

//普通函数和函数模板的区别
//1、普通函数调用可以发生隐式类型转换
//2、函数模板 自动类型推导 不可以发生隐式类型转换
//3、函数模板 显式指定类型 可以发生隐式类型转换

//普通函数与函数模板调用规则
//1、如果函数模板和普通函数都可以调用，编译器优先调用普通函数
//2、可以通过空模板参数列表 强制调用 函数模板
//3、函数模板可以发生函数重载
//4、如果函数模板可以产生更好的匹配，优先调用函数模板

//模板有局限性：特定数据类型需要具体化方式做特殊实现


//类模板
//作用：建立一个通用类，类中的成员 数据类型 可以不具体指定 而是用一个 虚拟的类型 来代表

//类模板和函数模板的区别
//1、类模板没有自动类型推导的使用方式
//2、类模板在模板参数列表中可以有默认参数

//类模板中成员函数创建时机
//1、普通类中的成员函数一开始就可以创建
//2、类模板中的成员函数在调用时才创建

//类模板对象做函数参数
//1、指定传入类型
//2、参数模板化
//3、整个类模板化

//类模板与继承
//1、当子类继承的父类是一个类模板时，子类在声明的时候，要指定父类中T的类型
//2、如果不指定，编译器无法给子类分配内存
//3、如果想灵活指定出父类中T的类型，子类也需要变为类模板

//类模板分文件编写报错：链接时报错
//解决方案：
//1、直接包含.cpp源文件
//2、将.h和.cpp文件写在一起，将后缀名写成.hpp

//类模板与友元
//全局函数类内实现 - 直接在类内声明友元
//全局函数类外实现 - 需要提前让编译器知道全局函数的存在		先做函数模板声明，下方再做函数模板定义，再做友元

#include "56_Template.h"
//函数模板
template<typename T>	//声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
template<typename T>
void func()
{
	cout << "func()调用" << endl;
}

//函数模板测试
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	cout << "目前：a = " << a << endl;
	cout << "目前：b = " << b << endl;

	//利用函数模板完成交换
	//两种方式使用函数模板
	//1、自动类型推导
	mySwap(a, b);

	cout << "自动推导交换后：a = " << a << endl;
	cout << "自动推导交换后：b = " << b << endl;
	//2、显示指定类型
	mySwap<int>(a, b);

	cout << "指定类型交换后：a = " << a << endl;
	cout << "指定类型交换后：b = " << b << endl;

	//错误示范
	//mySwap(a, c);	//推导不出一致的数据类型T						错误！！！
	//func();	//模板不能确定T的数据类型	在前加个数据类型定义	错误！！！
}

//实现一个通用的 对数组进行 从大到小 （选择）排序的函数  测试：char，int数组
template<typename T>
void SortArr(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;	//认定最大值下表
		for (int j = i + 1; j < len; j++)
		{
			//认定的最大值 比 遍历出的最大值 要小，说明j下标的元素才是真正的最大值
			if (arr[max] < arr[j])
			{
				max = j;//更新最大值下标
			}
		}
		if (max != i)
		{
			//交换max和i下标元素
			mySwap(arr[max], arr[i]);
		}
	}
}
//数组打印模板
template<typename T>
void myprint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test02()
{
	//测试char数组
	char charArr[] = "We come! We see! We conquer!";
	int num = sizeof(charArr) / sizeof(char);
	SortArr(charArr, num);
	myprint(charArr, num);
	//测试int数组
	int intArr[] = { 1,2,3,4,51,243,14,5,5,1,4,123,1,412,5,6,245,235,23 };
	int Num = sizeof(intArr) / sizeof(int);
	SortArr(intArr, Num);
	myprint(intArr, Num);
}

//局限性
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	int m_Age;
	string m_Name;
};


template<typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//利用具体化的Person版本实现代码，具体化优先调用
template<> bool myCompare(Person& a, Person& b)
{
	if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test03()
{
	int a = 10;
	int b = 20;
	bool ret = myCompare(a, b);

	if (ret)
	{
		cout << "a == b" << endl;
	}
	else
	{
		cout << "a != b" << endl;
	}

	Person o1("杨立", 10);
	Person o2("段金城", 20);

	bool ret1 = myCompare(o1, o2);
	if (ret1)
	{
		cout << "o1 == o2" << endl;
	}
	else
	{
		cout << "o1 != o2" << endl;
	}
}




//类模板
template<class NameType, class AgeType = int>
class Guy
{
public:
	Guy(NameType name, AgeType age);
	/*{
		this->m_Name = name;
		this->m_Age = age;
	}*/
	void showPerson();
	/*{
		cout << "名字叫：" << this->m_Name << "\t年龄为：" << this->m_Age << endl;
	}*/

	NameType m_Name;
	AgeType m_Age;
};
//类模板构造函数和成员函数的类外实现
template<class NameType,class AgeType>
Guy<NameType, AgeType>::Guy(NameType name, AgeType age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class NameType, class AgeType>
void Guy<NameType, AgeType>::showPerson()
{
	cout << "名字叫：" << this->m_Name << "\t年龄为：" << this->m_Age << endl;
}
//class child : public Guy<int>			//无法判断继承的参数T数据类型，必须指定父类T类型才能继承
//{
//
//};
//
//template<class T1,class T2>
//class child2 : public Guy<T2>				//如果想灵活指定父类中T类型，子类也需要变成类模板
//{
//public:
//	child2()
//	{
//		cout << "T1类型：" << typeid(T1).name() << "\nT2类型：" << typeid(T2).name() << endl;
//	}
//	T1 obj;
//};

void test04()
{
	Guy<string, int> p1("杨立", 999);
	Guy<string> p2("院枚潮", 999);
	p1.showPerson();
	p2.showPerson();
}
//类模板做函数参数
//1、指定传入类型
void printGuy1(Guy<string, int>& p)
{
	p.showPerson();
}

void test05()
{
	Guy<string, int> p("杨立", 100);
	printGuy1(p);
}
//2、参数模板化
template<class T1,class T2>
void printGuy2(Guy<T1,T2>&p)
{
	p.showPerson();
	cout << "T1 的类型为：" << typeid(T1).name() << "\nT2 的类型为：" << typeid(T2).name() << endl;
}
void test06()
{
	Guy<string, int> p("杨立", 200);
	printGuy2(p);
}
//3、将整个类模板化
template<class T>
void printGuy3(T &p)
{
	p.showPerson();
	cout << "T 的类型为：" << typeid(T).name() << endl;
}

void test07()
{
	Guy<string, int> p("杨立", 300);
	printGuy3(p);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	//child2<int,char> p2;
	system("pause");

	return 0;
}
