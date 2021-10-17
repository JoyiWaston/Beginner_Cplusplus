// 26_Function_calls_and_usage.cpp: 目标的源文件。
//

#include "26_Function_calls_and_usage.h"
void simple();									//函数声明

int main()
{
	using namespace std;

	cout << "main() will call the simple() function:\n";
	simple();									//函数使用
	cout << "main() is finished with the simple() function.\n";
	//cin.get();

	return 0;
}
//function definition

void simple()
{
	using namespace std;

	cout << "I'm but a simple function.\n";
}

