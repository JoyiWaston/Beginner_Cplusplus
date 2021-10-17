// 34_Memory.cpp: 目标的源文件。
//

#include "34_Memory.h"
using namespace std;
//全局变量
int g_a = 10;
int g_b = 10;
const int g_c_a = 10;
const int g_c_b = 10;

int main()
{
	//全局区

	//全局变量，静态变量，常量

	//创建普通局部变量
	int a = 10;
	int b = 10;

	cout << "a:\t" << (int)&a << endl;
	cout << "b:\t" << (int)&b << endl;
	cout << "g_a:\t" << (int)&g_a << endl;
	cout << "g_b:\t" << (int)&g_b << endl;

	//静态变量
	static int s_a = 10;
	static int s_b = 10;

	cout << "s_a:\t" << (int)&s_a << endl;
	cout << "s_b:\t" << (int)&s_b << endl;

	//常量
		//字符串常量
	cout << "hello world:\t" << (int)&"hello world" << endl;
	const int c_a = 10;
	const int c_b = 10;
	cout << "c_a:\t" << (int)&c_a << endl;
	cout << "c_b:\t" << (int)&c_b << endl;

	cout << "g_c_a:\t" << (int)&g_c_a << endl;
	cout << "g_c_b:\t" << (int)&g_c_b << endl;
	//const
	system("pause");
	return 0;
}
//局部变量别返回，会出事
//代码区
//全局区
//栈区		编译器决定
//堆区		程序员决定