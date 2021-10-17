// 31_Pointer_Function.cpp: 目标的源文件。
//

#include "31_Pointer_Function.h"

using namespace std;

void swap(int* p1, int* p2);
int main()
{
	int a = 10;
	int b = 20;

	swap(&a, &b);

	cout << "swap a = " << a << endl;
	cout << "swap b = " << b << endl;

	return 0;
}
void swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}