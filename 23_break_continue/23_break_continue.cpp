// 23_break_continue.cpp: 目标的源文件。
//

#include "23_break_continue.h"
const int ArSize = 80;

int main()
{
	using namespace std;
	char line[ArSize];
	int spaces = 0;

	cout << "Enter a line of text:\n";
	cin.get(line, ArSize);
	cout << "Complete line:\n" << line << endl;
	cout << "Line through first period:\n";
	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];							//显示字符
		if (line[i] == '.')							//如果有'.'就退出循环
			break;
		if (line[i] != ' ')							//如果有' '就跳过剩余循环
			continue;
		spaces++;
	}
	cout << "\n" << spaces << " spaces\n";
	cout << "Done.\n";

	return 0;
}
