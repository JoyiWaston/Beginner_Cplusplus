// 14_Union.cpp: 目标的源文件。
//

#include "14_Union.h"
using namespace std;

union id
{
	long id_num;
	char id_char[20];
} id_val;

struct inflatable
{
	char brand[20];
	int type = 1;
	union id id_val;
};

int main()
{
	struct inflatable prize;

	if (prize.type == 1)
	{
		cin >> prize.id_val.id_num;
	}
	else
	{
		cin >> prize.id_val.id_char;
	}

	return 0;
}
