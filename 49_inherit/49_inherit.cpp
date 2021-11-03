// 49_inherit.cpp: 目标的源文件。
//

#include "49_inherit.h"
class base
{
public:
	base()
	{
		b_a = 100;
		cout << "base构造" << endl;
	}
	~base()
	{
		cout << "base析构" << endl;
	}
	int b_a;
	static int b_d;
	static int func();
protected:
	int b_b;
private:
	int b_c;
};
int base::b_d = 100;

class son : public base					//利用开发人员命令提示工具查看对象模型
{										//跳到.cpp文件根目录		查看命令：cl /d1 reportSingleClassLayout类名 "所属文件名"
public:
	son()
	{
		b_a = 200;
		cout << "son构造" << endl;
	}
	~son()
	{
		cout << "son析构" << endl;
	}
	int b_a;
	static int b_d;
	static int func();
};
int son::b_d = 200;
void test01()
{
	son s1;
	cout << "父类b_a = " << s1.base::b_a << endl;		//同名调用无论函数还是变量都要加作用域
	cout << "子类b_a = " << s1.b_a << endl;
	cout << sizeof(son) << endl;		//父类中所有非静态成员属性都会被子类继承
}
//同名静态成员属性
void test02()
{
	//通过对象访问
	son s;
	cout << "b_d = " << s.b_d << endl;
	cout << "父类b_d = " << s.base::b_d << endl;

	//通过类名访问
	cout << "通过类名访问：" << endl;
	cout << son::b_d << endl;
	//第一个::代表通过类名方式访问；第二个::代表访问父类作用域下访问
	cout << son::base::b_d << endl;

}
//多继承,c++开发中不建议使用多继承技术
class grandson : public base, public son
{
public:
	grandson()
	{
		cout << grandson::base::b_d << endl;
	}
};




int main()
{
	//test01();
	test02();

	return 0;
}
