#include"Circle.h"

//设置半径
void Circle::setR(int R)
{
	m_R = R;
}
//获取半径
int Circle::getR()
{
	return m_R;
}
//设置圆心
void Circle::setCenterPoint(Point center)
{
	m_Centerl = center;
}
//获取圆心
Point Circle::getCenterPoint()
{
	return m_Centerl;
}