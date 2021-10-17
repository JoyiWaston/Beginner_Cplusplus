// 09_Switch.cpp: 目标的源文件。
//

#include "09_Switch.h"

using namespace std;
int main()
{
	// switch分支语句
	//eg:给电影打分

	// 10-9 经典
	// 8-7  非常好
	// 6-5 一般
	// >=5 烂

	//01：提示用户给电影评分
	cout << "请给电影打分" << endl;
	//02：用户开始打分
	int score = 0;
	cin >> score;
	cout << "您打的分数为：" << score << endl;
	//03：根据用户输入的分数提示最终评价结果
	switch (score)
	{
	case 10:
		cout << "您认为本片为经典电影" << endl;
		break;

	case 9:
		cout << "您认为本片为经典电影" << endl;
		break;
	default:
		cout << "凑合" << endl;
		break;
	}


	system("pause");

	return 0;
}
