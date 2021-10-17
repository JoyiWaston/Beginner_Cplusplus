// 10_Case_study_Three_little_pigs_weigh_themselves.cpp: 目标的源文件。
//

#include "10_Case_study_Three_little_pigs_weigh_themselves.h"
using namespace std;

int main()
{
	//A,B,C三只小猪称体重
	int A = 0, B = 0, C = 0;

	//输入ABC重量
	cout << "请输入小猪A的体重：" << endl;
	cin >> A;

	cout << "请输入小猪B的体重：" << endl;
	cin >> B;

	cout << "请输入小猪C的体重：" << endl;
	cin >> C;

	cout << "小猪A的体重为：" << A << endl;
	cout << "小猪B的体重为：" << B << endl;
	cout << "小猪C的体重为：" << C << endl;
	//我真的太棒了,困扰我真正三天啊啊啊啊
	//判断哪只小猪最重
	if (A > B)			//A比B重
	{
		if (A > C)
		{
			cout << "小猪A最重 " << endl;
		}
		else            //C比A重
		{
			cout << "小猪C最重" << endl;
		}
	}
	else                //B比A重
	{
		if (B > C)
		{
			cout << "小猪B最重" << endl;
		}
		else
		{
			cout << "小猪C最重" << endl;
		}
	}
	system("pause");

	return 0;
}
