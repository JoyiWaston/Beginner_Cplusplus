// 30_Pointer_Array.cpp: 目标的源文件。
//

#include "30_Pointer_Array.h"

using namespace std;

int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "第一个元素为： " << arr[0] << endl;

	int* p = arr;

	cout << "利用指针访问第一个元素： " << *p << endl;

	p++;

	cout << "利用指针访问第二个元素： " << *p << endl;

	return 0;
}
