// 42_Package_case_point_cercle.cpp: 目标的源文件。
//判断点与圆间位置关系的测试代码

#include "42_Package_case_point_cercle.h"
#include"isInCircle.h"
int main()
{
	//创建一个圆
	Circle c;
	Point p;
	p.setX(0);
	p.setY(0);
	c.setR(10);
	c.setCenterPoint(p);

	//创建一个点
	Point z;
	z.setX(0);
	z.setY(11);

	//判断点与圆的位置关系
	isInCircle(c, z);

	system("pause");
	return 0;
}

////点类
//class Point
//{
//public:
//	//设置X
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	//获取X
//	int getX()
//	{
//		return m_X;
//	}
//	//设置Y
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//获取Y
//	int getY()
//	{
//		return m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};

////圆类
//class Circle
//{
//public:
//	//设置半径
//	void setR(int R)
//	{
//		m_R = R;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//	//设置圆心
//	void setCenterPoint(Point center)
//	{
//		m_Centerl = center;
//	}
//	//获取圆心
//	Point getCenterPoint()
//	{
//		return m_Centerl;
//	}
//private:
//	int m_R;//半径
//
//	//在类中可以让另一个类作为本类的数据成员
//	Point m_Centerl;//圆心
//};

////判断点和圆之间的关系
//void isInCircle(Circle& c, Point& p)
//{
//	//计算两点之间距离平方
//	int Distance =
//		(c.getCenterPoint().getX() - p.getX()) * (c.getCenterPoint().getY() - p.getY()) +
//		(c.getCenterPoint().getY() - p.getY()) * (c.getCenterPoint().getY() - p.getY());
//
//	//计算半径的平方
//	int RDistance = c.getR() * c.getR();
//
//	//判断关系
//	if (Distance == RDistance)
//	{
//		cout << "点在圆上" << endl;
//	}
//	else if (Distance > RDistance)
//	{
//		cout << "点在圆外" << endl;
//	}
//	else
//	{
//		cout << "点在圆内" << endl;
//	}
//}
