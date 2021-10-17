// 03_constant.cpp: 目标的源文件。
//
#define day 7
#include "03_constant.h"
using namespace std;

int main()
{
	const int month = 12;
	//day = 14; 表达式必须是可修改的左值
	cout << "一周共有：" << day << "天" << endl;

	cout << "一年共有：" << month << "个月份" << endl;

	cout << sizeof(month) << endl;
	system("pause");

	return 0;
}
