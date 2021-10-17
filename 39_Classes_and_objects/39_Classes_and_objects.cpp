// 39_Classes_and_objects.cpp: 目标的源文件。
//

#include "39_Classes_and_objects.h"
using namespace std;
//设计一个学生类
const double PI = 3.14;

class student
{
	//属性和行为统一叫成员

	//访问权限
public:

	//属性：成员属性
	string Name;
	int s_Number;

	//行为：成员行为
	void changeName(string name)
	{

		Name = name;
	}
	void changeNum(int number)
	{

		s_Number = number;
	}
	void showStu()
	{
		cout << "学生的姓名为：" << Name << "\n学生的学号为：" << s_Number << endl;
	}
};

int main()
{
	student YL;

	cout << "请输入学生名称：" << endl;
	string name;
	cin >> name;
	YL.changeName(name);

	cout << "请输入学生学号：" << endl;
	int number;
	cin >> number;
	YL.changeNum(number);

	YL.showStu();

	system("pause");
	return 0;
}
