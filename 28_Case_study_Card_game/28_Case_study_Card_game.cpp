// 28_Case_study_Card_game.cpp: 目标的源文件。
//从total张牌中选择choices张牌，然后随机从total张牌中抽取choices张牌，求中奖概率

#include "28_Case_study_Card_game.h"
//注意！有些实现方法需要double而不是long double
long  double probability(unsigned numbers, unsigned picks);


int main()
{
	using namespace std;
	double total, choices;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices);
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit): ";
	}
	cout << "bye\n";
	return 0;
}
//以下函数计算选择的概率
//正确选择数字

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;								//这里有局部变量
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
	{
		result = result * n / p;
	}

	return result;
}

