// 05_boolean.cpp: 目标的源文件。
//

#include "05_boolean.h"
using namespace std;
int main()
{

	//创建bool数据类型
	//查内存空间
	bool flag = true;

	cout << flag << endl;

	flag = false;

	cout << flag << endl;

	cout << sizeof(flag) << endl;

	system("pause");

	return 0;
}
