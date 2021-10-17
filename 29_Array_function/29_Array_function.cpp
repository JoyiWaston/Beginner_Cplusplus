// 29_Array_function.cpp: 目标的源文件。
//

#include "29_Array_function.h"
const int ArSize = 8;

int sum_arr(int arr[], int n);

//使用std::代替使用using编译

int main()
{
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	//某些系统要求int前要使用static让数组能初始化

	std::cout << cookies << " = array address. ";
	//有些系统需要强制类型转换unsigned(cookies)

	std::cout << sizeof(cookies) << " = sizeof cookies\n";
	int sum = sum_arr(cookies, ArSize);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	sum = sum_arr(cookies, 3);//告诉函数cookies有3个元素，计算前3个元素的总和																	
	std::cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, 4);//提供给函数假数组起始位，然后计算从该位起4个元素的总和
	std::cout << "Last four eaters ate " << sum << " cookies.\n";

	return 0;
}
//返回整数数组的和

int sum_arr(int arr[], int n)
{
	int total = 0;
	std::cout << arr << " = arr. ";

	//有些系统需要强制类型转换unsigned(arr)

	std::cout << sizeof(arr) << " = sizeof arr\n";
	for (int i = 0; i < n; i++)
		total = total + arr[i];

	return total;
}