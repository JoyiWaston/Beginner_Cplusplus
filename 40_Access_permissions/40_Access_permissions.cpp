// 40_Access_permissions.cpp: 目标的源文件。
//

#include "40_Access_permissions.h"
using namespace std;

//三种访问权限 
//1.公共权限public			成员 类内可以访问	类外也可以访问
//2.保护权限protected		成员 类内可以访问	类外不可以访问	 父类保护权限子类可访问
//3.私有权限privated		成员 类内可以访问	类外不可以访问   父类私有权限子类不可访问

class Person
{
public:
	string m_Name;

protected:
	string m_car;

private:
	int m_password;

public:
	void func()
	{
		m_Name = "张三";
		m_car = "拖拉机";
		m_password = 123456;
	}
};

int main()
{
	Person p1;
	p1.m_Name = "李四";
	//p1.m_car = "奔驰";		//保护内容类外不能访问
	//p1.m_password = 123;	//私有内容类外不能访问

	return 0;
}
