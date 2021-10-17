// 25_read_file.cpp: 目标的源文件。
//该程序打开用户指定文件，读取其中数据，然后指出文件包含多少个值以及他们的和与平均值。

#include "25_read_file.h"
const int SIZE = 60;
int main()
{
	using namespace std;
	char filename[SIZE];
	ifstream inFile;								//处理ostream对象
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);							//将inFile与文件关联
	if (!inFile.is_open())							//如果文件打开失败
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum = 0.0;
	int count = 0;									//被读取文件的值

	inFile >> value;								//获取第一个值
	while (inFile./*is_open()*/good())
	{
		++count;									//多个值读取
		sum += value;								//计算运行总数
		inFile >> value;							//获得下一个值
	}
	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}
	inFile.close();									//完成数据读取

	return 0;
}
