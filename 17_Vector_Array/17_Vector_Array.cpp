// 17_Vector_Array.cpp: 目标的源文件。
//

#include "17_Vector_Array.h"

using namespace std;
int main()
{
	// vector 定义方式

	/* vector<int> vi(5);

	int n;
	cin >> n;
	vector<double> vd(n); */

	// array 定义方式

	/* array<int, 5> ai;

	array<double, 4> ad = { 1.2,2.1,3.43,4.3 }; */

	// C, original C++
	double a1[4] = { 1.2,2.4,3.6,4.8 };

	// C++98 STL,初始化方式不简便
	vector<double> a2(4);

	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[3] = 1.0 / 7.0;
	a2[4] = 1.0 / 9.0;

	// C++11 创造和初始化array样式
	array<double, 4> a3 = { 3.14,2.72,1.62,1.41 };
	array<double, 4> a4;
	a4 = a3;

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	//misdeed
	//以下两行请看VS2019报错内容
	a1[-2] = 20.2;
	cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	return 0;
}
