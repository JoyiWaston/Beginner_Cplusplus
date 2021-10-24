#pragma once
#include"Point.h"

//圆类
class Circle
{
public:
	//设置半径
	void setR(int R);
	//获取半径
	int getR();
	//设置圆心
	void setCenterPoint(Point center);
	//获取圆心
	Point getCenterPoint();
private:
	int m_R;//半径

	//在类中可以让另一个类作为本类的数据成员
	Point m_Centerl;//圆心
};
