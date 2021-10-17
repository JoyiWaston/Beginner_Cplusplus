// 19_cctype.cpp: 目标的源文件。
//

#include "19_cctype.h"

using namespace std;

int main()
{
	cout << "Enter text for analysis, and type @"
		" to terminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);						//键入第一个字符
	while (ch != '@')
	{
		if (isalpha(ch))				//是否字母型？
			chars++;
		else if (isspace(ch))			//是否空白型？
			whitespace++;
		else if (isdigit(ch))			//是否数字型？
			digits++;
		else if (ispunct(ch))			//是否符号型？
			punct++;
		else
			others++;
		cin.get(ch);					//键入下一个字符
	}
	cout << chars << " letters, "
		<< whitespace << " whitesoace, "
		<< digits << " digits, "
		<< punct << " punctuations, "
		<< others << " others.\n";

	return 0;
}
