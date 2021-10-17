// 42_Packaging_case.cpp: 目标的源文件。
//

#include "42_Packaging_case.h"

using namespace std;

//立方体类设计创建
//1.设计属性
//2.设计行为，获取体积和面积
//3，分别用全局函数和成员函数 判断两个立方体是否相等
class cube
{
public:
	//行为接口
		//设置获取长宽高
	void setL(int l)
	{
		m_L = l;
	}
	int getL()
	{
		return m_L;
	}
	void setW(int w)
	{
		m_W = w;
	}
	int getW()
	{
		return m_W;
	}
	void setH(int h)
	{
		m_H = h;
	}
	int getH()
	{
		return m_H;
	}
	//获取体积
	int calculateV()
	{
		return m_H * m_L * m_W;
	}
	//获取面积
	int calculateS()
	{
		return (2 * m_H * m_L) + (2 * m_H * m_W) + (2 * m_L * m_W);
	}
	//利用成员函数判断
	bool isSameByclass(cube& c)
	{
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
		{
			return true;
		}
		else
		{
			return false;
		}
	}


private:
	//长宽高
	int m_L;
	int m_W;
	int m_H;
};
//利用全局函数判断是否相等
bool isSame(cube& c1, cube& c2)
{
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	//创建第一个立方体
	cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1的面积：" << c1.calculateS() << endl;//600
	cout << "c1的体积：" << c1.calculateV() << endl;//1000

	//创建第二个立方体
	cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	cout << "c2的面积：" << c2.calculateS() << endl;//600
	cout << "c2的体积：" << c2.calculateV() << endl;//1000

	//全局函数判断
	bool ret1 = isSame(c1, c2);
	if (ret1)
	{
		cout << "c1 = c2；" << endl;
	}
	else
	{
		cout << "c1 != c2；" << endl;
	}

	//成员函数判断
	bool ret2;
	ret2 = c1.isSameByclass(c2);
	if (ret2)
	{
		cout << "c1 = c2；" << endl;
	}
	else
	{
		cout << "c1 != c2；" << endl;
	}

	system("pause");
	return 0;
}
