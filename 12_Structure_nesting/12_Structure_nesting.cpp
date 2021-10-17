// 12_Structure_nesting.cpp: 目标的源文件。
//

#include "12_Structure_nesting.h"
using namespace std;

//定义学生的结构体
struct student
{
	string name;		//学生姓名
	int age;			//学生年龄
	int score;			//学生成绩
};

//定义教师的结构体
struct teacher
{
	int id;				//教师编号
	string name;		//教师姓名
	int age;			//教师年龄
	struct student stu;	//辅导的学生
};

int main()
{

	//创建教师
	teacher t;
	t.id = 10000;
	t.name = "老王";
	t.age = 50;
	t.stu.name = "小王";
	t.stu.age = 20;
	t.stu.score = 60;

	cout << "老师姓名:" << t.name << " 老师编号:" << t.id
		<< " 老师年龄:" << t.age << " \n老师辅导学生的姓名:"
		<< t.stu.name << " 学生年龄: " << t.stu.age << " 学生成绩: "
		<< t.stu.score << endl;

	return 0;
}
