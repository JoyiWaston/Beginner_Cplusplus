// 38_Function_overloading.cpp: 目标的源文件。
//

#include "38_Function_overloading.h"
//函数重载,提高复用性
using namespace std;
//函数重载需要函数都在同一个作用域下

void func()
{
	cout << " func 调用! " << endl;
}
void func(int a)
{
	cout << " func 调用!!" << endl;
}
void func(float a)
{
	cout << " func 调用!!!" << endl;
}
//1.引用作为重载条件
void func(const double& a)
{
	cout << " func(int& a)" << endl;
}

//函数的返回值不可以作为函数重载的条件
int main()
{
	func();
	func(1);
	func(1.5);
	int a;
	func(10);
	return 0;
}
