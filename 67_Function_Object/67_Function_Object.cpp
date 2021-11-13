// 67_Function_Object.cpp: 目标的源文件。
//重载函数调用操作符的类，其对象常称为函数对象
//函数对象使用重载的()时，行为类似函数调用，也叫仿函数
//本质：函数对象(仿函数)是一个类，不是一个函数

#include "67_Function_Object.h"

//函数对象的使用
//函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
//函数对象超出普通函数的概念，函数对象可以有自己的状态
//函数对象可以作为参数传递


//1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};
void test01()
{
	MyAdd add;

	cout << add(10, 100) << endl;
}
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}
	void operator ()(string test)
	{
		cout << test << endl;
		this->count++;
	}

	int count;//内部自身状态
};
void test02()
{
	MyPrint myprint;
	myprint("helloworld");
	myprint("helloworld");
	myprint("helloworld");
	myprint("helloworld");
	myprint("helloworld");
	cout << myprint.count << endl;	//myprint调用次数
}
//3.函数对象可以作为参数传递
void doPrint(MyPrint& Mp, string test)
{
	Mp(test);
}
void test03()
{
	MyPrint myprint;
	doPrint(myprint, "Hello C++");
}

int main()
{
	//函数对象的使用
	test01();
	test02();
	test03();
	
	return 0;
}
