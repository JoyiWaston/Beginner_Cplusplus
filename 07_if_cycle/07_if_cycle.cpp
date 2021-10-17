// 07_if_cycle.cpp: 目标的源文件。
//

#include "07_if_cycle.h"
using namespace std;

int main()
{
	int score = 0;
	cout << "请输入您的分数：" << endl;
	cin >> score;

	cout << "您输入的分数为：" << score << endl;

	if (score > 600)
	{
		cout << "您考上了一本！" << endl;
	}
	else
	{
		cout << "很抱歉，您没有考上一本。" << endl;
	}

	system("pause");
	return 0;
}
