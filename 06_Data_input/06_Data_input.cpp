// 06_Data_input.cpp: 目标的源文件。
//

#include "06_Data_input.h"
using namespace std;

int main()
{
	//整型输入
	int a = 0;
	cout << "请输入整型变量：" << endl;
	cin >> a;
	cout << a << endl;

	//浮点型输入
	double d = 3.14f;
	cout << "请输入浮点型变量：" << endl;
	cin >> d;
	cout << d << endl;

	//字符型输入
	char ch = 'a';
	cout << "请输入字符型变量：" << endl;
	cin >> ch;
	cout << ch << endl;

	//字符串
	string str = "Hello C++";
	cout << "请给字符串变量赋值:" << endl;
	cin >> str;
	cout << str << endl;

	//布尔型
	bool flag = false;
	cout << "请给布尔型变量赋值：" << endl;
	cin >> flag;
	cout << flag << endl;

	system("pause");

	return EXIT_SUCCESS;
}
