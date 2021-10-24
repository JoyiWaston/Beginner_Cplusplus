#include"isInCircle.h"
//判断点和圆之间的关系
void isInCircle(Circle& c, Point& p)
{
	//计算两点之间距离平方
	int Distance =
		(c.getCenterPoint().getX() - p.getX()) * (c.getCenterPoint().getY() - p.getY()) +
		(c.getCenterPoint().getY() - p.getY()) * (c.getCenterPoint().getY() - p.getY());

	//计算半径的平方
	int RDistance = c.getR() * c.getR();

	//判断关系
	if (Distance == RDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (Distance > RDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}