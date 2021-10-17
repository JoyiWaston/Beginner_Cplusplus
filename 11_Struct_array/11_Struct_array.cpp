// 11_Struct_array.cpp: 目标的源文件。
//

#include "11_Struct_array.h"
using namespace std;

struct inflatable
{
	string name;
	float volume;
	double price;
};

int main()
{
	inflatable guests[2] =
	{
		{"Bambi apple",0.5,21.99},
		{"Godzilla bananer",2000,565.99}
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name << endl
		<< "have a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet." << endl;

	return 0;
}
