// 47_class_friend.cpp: 目标的源文件。
//友元的目的就是让一个函数或类 访问另一个类中的私有成员
//友元三种实现

#include "47_class_friend.h"

//1.全局函数做友元
//建筑物类

class Building
{
	//goodGuy全局函数是Building的友元，可以访问私有成员
	friend void goodGuy(Building* building);

	//GoodGuy是本类的友元，可以访问私有成员
	friend class GoodGuy;

public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_Bedroom = "卧室";
	}

public:
	string m_SittingRoom;//客厅

private:
	string m_Bedroom;//卧室
};

//全局函数
void goodGuy(Building *building)
{
	cout << "杨立全局函数  正在访问我的:" << building->m_SittingRoom << endl;
	cout << "杨立全局函数  正在访问我的:" << building->m_Bedroom << endl;

}


//2.类做友元
class GoodGuy
{
public:
	GoodGuy();

	void visit();//参观函数 访问Building中的属性

	Building* building;
};

GoodGuy::GoodGuy()
{
	//创建一个建筑物对象
	building = new Building;
}

void GoodGuy::visit()
{
	cout << "杨立又在访问我的:" << building->m_SittingRoom << endl;
	cout << "杨立又在访问我的:" << building->m_Bedroom << endl;

}


//3.成员函数做友元
class Building_demo;
class GoodGirl
{
public:
	GoodGirl();

	void visit1();//让visit1函数可以访问Building中私有成员
	void visit2();//让visit2函数不可以访问~

	Building_demo* building;
};
class Building_demo     //为了解决前向声明问题，重新定义一个和Building一样的类
{
	//GoodGirl类下的visit1函数是本类友元，可以访问私有成员
	friend void GoodGirl::visit1();

public:
	Building_demo()
	{
		m_SittingRoom = "客厅";
		m_Bedroom = "卧室";
	}

public:
	string m_SittingRoom;//客厅

private:
	string m_Bedroom;//卧室
};

GoodGirl::GoodGirl()
{
	building = new Building_demo;
}

void GoodGirl::visit1()
{
	cout << "杨立第一次在访问我的:" << building->m_SittingRoom << endl;
	cout << "杨立第一次居然在访问我的:" << building->m_Bedroom << endl;

}

void GoodGirl::visit2()
{
	cout << "杨立第二次在访问我的:" << building->m_SittingRoom << endl;
	//cout << "杨立第二次居然在访问我的:" << building->m_Bedroom << endl;

}

//测试
void test01()
{
	Building building;
	goodGuy(&building);
}

void test02()
{
	GoodGuy YL;
	YL.visit();
}

void test03()
{
	GoodGirl YL;
	YL.visit1();
	YL.visit2();
}

int main()
{
	test01();
	test02();
	test03();

	system("pause");
	return 0;
}
