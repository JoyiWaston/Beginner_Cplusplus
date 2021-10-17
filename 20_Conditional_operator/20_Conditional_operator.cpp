// 20_Conditional_operator.cpp: 目标的源文件。
//

#include "20_Conditional_operator.h"

using namespace std;

int main()
{
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "The larger of " << a << " and " << b;
	int c = a > b ? a : b;								// c = a if a > b, else c = b
	cout << " is " << c << endl;

	return 0;
}
