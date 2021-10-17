// 13_Structure_as_function_parameters.cpp: 目标的源文件。
//

#include "13_Structure_as_function_parameters.h"
using namespace std;
void printStudent1(struct student s);			//值传递
void printStudent2(struct student* p);			//地址传递

struct student
{
	string name;				//姓名
	int age;					//年龄
	int score;					//分数
};

int main()
{
	//创建结构体变量
	struct student s = { "张三",20,85 };

	printStudent1(s);			//值传递
	printStudent2(&s);			//地址传递

	/*cout << "main函数中打印 姓名: " << s.name << " 年龄: "
		<< s.age << " 分数: " << s.score << endl;*/

	return 0;
}

void printStudent1(struct student s)
{
	//s.age = 100;
	cout << "以值传递的方式在子函数中打印 姓名: " << s.name << " 年龄: "
		<< s.age << " 分数: " << s.score << endl;
}

void printStudent2(struct student* p)
{
	//p->age = 200;
	cout << "以地址传递的方式在子函数中打印 姓名: " << p->name << " 年龄: "
		<< p->age << " 分数: " << p->score << endl;
}