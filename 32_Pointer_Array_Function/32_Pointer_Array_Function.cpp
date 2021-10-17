// 32_Pointer_Array_Function.cpp: 目标的源文件。
//

#include "32_Pointer_Array_Function.h"
using namespace std;

void bubbleSort(int* arr, int length);
void printArray(int* arr, int length);

int main()
{
	//创建数组
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	//数组长度
	int length = sizeof(arr) / sizeof(arr[0]);

	//创建函数，实现冒泡排序
	bubbleSort(arr, length);

	//打印排序后的数组
	printArray(arr, length);

	return 0;
}
//冒泡排序 参数1 数组首地址 参数2 数组长度

void bubbleSort(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			//如果j>j+1的值 交换数值
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//打印数组
void printArray(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << arr[i] << endl;
	}
}