// 36_Reference.cpp: 目标的源文件。
//

#include "36_Reference.h"
//引用的本质在c++内部实现是一个指针常量,c++推荐使用

using namespace std;

//交换
//1 值传递
void swap01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}
//2 地址传递
void swap02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//3 引用传递
//发现是引用，自动转换为int* const a = &a;	int* const b = &b;
void swap03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int& test01()
{
	int a = 10;
	return a;
}
int& test02()
{
	static int a = 10;
	return a;
}

void show(const int& val)//const 开发过程中防止误操作
{
	cout << "val = " << val << endl;
}

int main()
{
	int a = 10, b = 20;
	swap01(a, b);
	cout << "1. a= " << a << "\n   b= " << b << endl;		//值传递，形参不会修饰实参
	swap02(&a, &b);
	cout << "2. a= " << a << "\n   b= " << b << endl;		//地址传递，形参会修饰实参
	swap03(a, b);
	cout << "3. a= " << a << "\n   b= " << b << endl;		//引用传递，形参会修饰实参

	//自动转换为 int* const ref = &a;指针常量是指针指向不可更改，也说明为什么引用不可更改
	int& ref1 = test01();
	//内部发现ref为引用，自动转换为*ref = 10；
	cout << "ref1 = " << ref1 << endl;
	cout << "ref1 = " << ref1 << endl;

	int& ref2 = test02();
	cout << "ref2 = " << ref2 << endl;
	test02() = 1000;//如果函数的返回值是引用，这个函数的调用可以作为左值
	cout << "ref2 = " << ref2 << endl;

	//加上const之后 编译器将代码修改 int temp = 10; const int& ref = temp;
	//const int& ref = 10;  //引用必须引一块合法内存空间
	int z = 100;
	show(z);
	cout << z << endl;


	return 0;
}
