// 37_Default_functions_and_parameter_placeholders.cpp: 目标的源文件。
//

#include "37_Default_functions_and_parameter_placeholders.h"
using namespace std;

int sum(int a, int b, int c = 30)//自己传用自己的，没传用默认的
{
	return a + b + c;
}
//注意事项：
//1.如果某位置有默认参数，从这个位置往后，从左到右都得有默认值
//2.如果函数声明有默认参数，函数实现就不能有默认参数

void func(int a, int)//占位
{
	cout << "yes" << endl;
}
int main()
{
	cout << sum(10, 20, 40) << endl;
	func(10, 20);
	return 0;
}
