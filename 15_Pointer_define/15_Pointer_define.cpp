// 15_Pointer_define.cpp: 目标的源文件。
//

#include "15_Pointer_define.h"
using namespace std;
int main()
{
	//取地址

	/*int donuts = 6;
	double cups = 4.5;

	cout << "donuts value: " << donuts;
	cout << " and donuts address: " << &donuts << endl;

	cout << "cups value: " << cups;
	cout << " and cups address: " << &cups << endl;*/

	//指针的定义使用

	/*int updates = 6;
	int* p_updates;
	p_updates = &updates;

	cout << "Value: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;

	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;*/

	//将指针初始化成一个地址

	/*int higgens = 5;
	int* pt = &higgens;
	cout << "Value of higgens = " << higgens << "; Address of higgens = " << &higgens << endl;
	cout << "Value of *pt = " << *pt << "; Value of pt = " << pt << endl;*/

	//new 方法

	/*int nights = 1001;
	int* pt = new int;
	*pt = 1001;

	cout << "nights Value = ";
	cout << nights << ": location = " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;

	double* pd = new double;
	*pd = 10000001.0;
	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;

	cout << "size of pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size of pd = " << sizeof(pd);
	cout << ": size of *pd = " << sizeof(*pd) << endl;

	delete pt;
	delete pd;*/

	//创建动态数组

	//double* p3 = new double[3];
	//p3[0] = 0.2;
	//p3[1] = 0.5;
	//p3[2] = 0.8;
	//cout << "p3[1] is " << p3[1] << ".\n";
	//p3 = p3 + 1;
	//cout << "Now p3[0] is " << p3[0] << " and ";
	//cout << "p3[1] is " << p3[1] << ".\n";
	//p3 = p3 - 1;
	//delete[] p3;

	//指针在字符串中

	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;						//未定义，错误典型

	cout << animal << " and ";
	cout << bird << "\n";
	// cout << ps << "\n"

	cout << "Enter a kind of animal: ";
	cin >> animal;
	// cin >> ps;

	ps = animal;
	cout << ps << "!\n";
	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int*)ps << endl;
	cout << ps << " at " << (int*)ps << endl;

	ps = new char[strlen(animal) + 1];

# pragma warning(suppress : 4996)					// 为解决编译器对于strcpy安全报错问题，对4996警告进行warning忽略
	strcpy(ps, animal);

	cout << "After using strcpy():\n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;

	delete[] ps;

	return 0;
}
