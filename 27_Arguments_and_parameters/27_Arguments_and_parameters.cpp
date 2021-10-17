// 27_Arguments_and_parameters.cpp: 目标的源文件。
//

#include "27_Arguments_and_parameters.h"

void cheers(int);									//无返回值

double cube(double x);								//返回值为一个double类型

int main()
{
	using namespace std;
	cheers(5);
	cout << "Give me a number: ";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "A " << side << "-foot cube has a volume of ";
	cout << volume << " cubic feet.\n";
	cheers(cube(2));

	return 0;
}
void cheers(int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Cheers! ";
	}
	cout << endl;
}

double cube(double x)
{
	return x * x * x;
}