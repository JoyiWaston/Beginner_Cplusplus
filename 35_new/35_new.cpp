// 35_new.cpp: 目标的源文件。
//

#include "35_new.h"

using namespace std;

//1.new的基本用法
int* func()
{
	//堆区创建整型数据
	//new返回是该数据类型的指针
	int* p = new int(10);
	return p;
}
void test01()
{
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	delete p;
	//cout << *p << endl; //内存已被释放，再次访问属于非法操作
	//堆区由程序员开辟释放（delete）
}

//2.堆区利用new开辟数组
void test02()
{
	//创建是个整型数据数组
	int* arr = new int[10];//数组有十个元素

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;//给是个元素赋值，100——109
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区数组
	delete[] arr;
}
int main()
{
	test01();
	test02();
	return 0;
}
