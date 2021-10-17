// 16_Array_Deconstruction_Pointer.cpp: 目标的源文件。
//

#include "16_Array_Deconstruction_Pointer.h"
// using namespace std;

struct antarctica_years_end
{
	int year;
	/* some really interesting data, etc. */
};

int main()
{
	antarctica_years_end s01, s02, s03;
	s01.year = 1998;

	antarctica_years_end* pa = &s02;
	pa->year = 1999;

	antarctica_years_end trio[3];
	trio[0].year = 2003;
	std::cout << trio->year << std::endl;

	const antarctica_years_end* arp[3] = { &s01,&s02,&s03 };
	std::cout << arp[1]->year << std::endl;

	const antarctica_years_end** ppa = arp;
	auto ppb = arp;						//c++11特性auto，或者替换为const antarctica_years_end ** ppb = arp;

	std::cout << (*ppa)->year << std::endl;
	std::cout << (*(ppb + 1))->year << std::endl;

	return 0;
}