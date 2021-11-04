// 51_Polymorphism_Case_Calculator.cpp: 目标的源文件。
//纯虚函数和抽象类
//语法：virtual 返回值类型 函数名 (参数列表) = 0;
//当类中有了纯虚函数，这个类也称为抽象类
//抽象类特点：
//1.无法实例化对象
//2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类

#include "51_Polymorphism_Case_Calculator.h"
class Calculator
{
public:
	double getResult(string oper)
	{
		if (oper == "+")
		{
			return m_NUM1 + m_NUM2;
		}
		if (oper == "-")
		{
			return m_NUM1 - m_NUM2;
		}
		if (oper == "*")
		{
			return m_NUM1 * m_NUM2;
		}
		if (oper == "/")
		{
			return m_NUM1 / m_NUM2;
		}
		//想加取模运算新功能，需要修改源码
		//在真实开发中 提倡 开闭原则
		//开闭原则：对扩展进行开发，对修改进行关闭
	}


	double m_NUM1;//操作数1
	double m_NUM2;//操作数2
};
void test01()
{
	//创建计算器对象
	Calculator c;
	cin >> c.m_NUM1;
	cin >> c.m_NUM2;

	cout << c.m_NUM1 << " + " << c.m_NUM2 << " = " << c.getResult("+") << endl;
	cout << c.m_NUM1 << " - " << c.m_NUM2 << " = " << c.getResult("-") << endl;
	cout << c.m_NUM1 << " * " << c.m_NUM2 << " = " << c.getResult("*") << endl;
	cout << c.m_NUM1 << " / " << c.m_NUM2 << " = " << c.getResult("/") << endl;
}


//利用多态实现计算器
//多态的好处：
// 1.组织结构清晰
// 2.可读性强
// 3.对于前期和后期扩展维护性高

//实现计算器抽象类
class AbstractCalculatir
{
public:
	/*virtual double getResult()
	{
		return 0;
	}*/

	//纯虚函数
	virtual double getResult() = 0;

	double m_Num1;
	double m_Num2;
};
//加法计算器类
class AddCalculator : public AbstractCalculatir
{
public:
	virtual double getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//减法计算器类
class SubCalculator : public AbstractCalculatir
{
public:
	virtual double getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class MulCalculator : public AbstractCalculatir
{
public:
	virtual double getResult()
	{
		return m_Num1 * m_Num2;
	}
};
//除法计算器类
class DivCalculator : public AbstractCalculatir
{
public:
	virtual double getResult()
	{
		return m_Num1 / m_Num2;
	}
};

void test02()
{
	//多态使用条件
	//父类指针或者引用指向子类对象

	//加法
	AbstractCalculatir* abc = new AddCalculator;
	cin >> abc->m_Num1;
	cin >> abc->m_Num2;

	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//减法
	abc = new SubCalculator;
	cin >> abc->m_Num1;
	cin >> abc->m_Num2;

	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//乘法
	abc = new MulCalculator;
	cin >> abc->m_Num1;
	cin >> abc->m_Num2;

	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;

	//除法
	abc = new DivCalculator;
	cin >> abc->m_Num1;
	cin >> abc->m_Num2;

	cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}


int main()
{
	//test01();
	test02();

	return 0;
}
