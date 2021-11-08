// 58_STL_Standard_template_library.cpp: 目标的源文件。
//STL六大组件
//容器：各种数据结构，如vector，list，deque，set，map等，用来存放数据
//算法：各种常用的算法，如sort，find，copy，for_each等
//迭代器：扮演了容器和算法之间的胶合剂的角色
//仿函数：行为类似函数，可作为算法的某种策略
//适配器：一种用来修饰容器或者仿函数或迭代器接口的东西
//空间配置器：负责空间的配置和管理

//容器	
//序列式容器：强调值的排序，序列式容器中的每个元素均有固定的位置
//关联式容器：二叉树结构，各元素之间没有严格的物理上的顺序关系

//算法
//质变算法：指运算过程中会更改区间内的元素的内容，例如：拷贝，替换，删除等算法
//非质变算法：指运算过程中不会更改区间内的元素内容，例如：查找，计数，遍历，寻找极值等

//迭代器		算法只有通过迭代器才能访问容器中的元素
//提供一种方法，使之能够依序寻访某个容器所含的各个元素，而又无需暴露该容器的内部表示方式
//每个容器都有自己专属的迭代器
//迭代器使用非常类似于指针，刚开始学STL时，我们可以先理解迭代器为指针
//种类：(常用的容器中迭代器的种类为双向迭代器和随机访问迭代器)
//输入迭代器		对数据的只读访问											只读、支持++、==、！=
//输出迭代器		对数据的只写访问											只写、支持++
//前向迭代器		读写操作，并能向前推进迭代器								读写、支持++、==、！=
//双向迭代器		读写操作，并能向前和向后操作								读写、支持++、--
//随机访问迭代器	读写操作，可以以跳跃的方式访问任意数据，功能最强的迭代器	读写、支持++、--、[n]、-n、<、<=、>、>=


#include "58_STL_Standard_template_library.h"
//Vector存放数据

//1、vector存放内置数据类型
// 
//容器vector	算法for_each	迭代器vector<int>::iterator	

//第三种方法的回调函数myPrint
void myPrint(int val)
{
	cout << val << endl;
}
//--------------------------
void test01()
{
	//创建了一个vector的容器，数组
	vector<int> v;

	//向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//第一种遍历方式
	cout << "--------------------------" << endl;
	cout << "第一种遍历方式(while循环)：" << endl;
	cout << "--------------------------" << endl;
	//通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();	//起始迭代器	指向容器中第一个元素
	vector<int>::iterator itEnd = v.end();		//结束迭代器	指向容器中最后一个元素的下一个位置

	while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}
	
	//第二种遍历方式
	cout << "--------------------------" << endl;
	cout << "第二种遍历方式(for循环)：" << endl;
	cout << "--------------------------" << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	//第三种
	cout << "--------------------------" << endl;
	cout << "第三种遍历方式(for_each)：" << endl;
	cout << "--------------------------" << endl;

	for_each(v.begin(), v.end(), myPrint);		//myPrint回调函数
	
}

//2、vector容器中存放自定义数据类型
class Person
{
public:
	Person(string name,int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void myPrint2(Person& p)
{
	cout << "姓名：" << p.m_Name;
	cout << "\t年龄：" << p.m_Age << endl;
}
void test02()
{
	//创建了一个vector的容器，数组
	vector<Person> v;

	//创建八个自定义数据类型
	Person p1("赵一", 15);
	Person p2("钱二", 20);
	Person p3("孙三", 25);
	Person p4("李四", 30);
	Person p5("周五", 35);
	Person p6("吴六", 40);
	Person p7("郑七", 45);
	Person p8("王八", 50);

	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);
	v.push_back(p7);
	v.push_back(p8);

	//遍历容器中的数据
	//方式一：
	/*for_each(v.begin(), v.end(), myprint2);*/
	//方式二：
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name;			//知道*it是个Person
		cout << "\t年龄：" << it->m_Age << endl;	//知道it是个指针
	}
}

//3、vector存放自定义数据类型指针
void test03()
{
	//创建了一个vector的容器，数组
	vector<Person*> v;

	//创建八个自定义数据类型
	Person p1("赵一", 15);
	Person p2("钱二", 20);
	Person p3("孙三", 25);
	Person p4("李四", 30);
	Person p5("周五", 35);
	Person p6("吴六", 40);
	Person p7("郑七", 45);
	Person p8("王八", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	v.push_back(&p6);
	v.push_back(&p7);
	v.push_back(&p8);

	//遍历容器
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name;			//知道*it是个Person
		cout << "\t年龄：" << (*it)->m_Age << endl;	//知道it是个指针
	}
}

//4、vector容器嵌套容器
void test04()
{
	vector<vector<int>> v;

	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器插入到大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//通过大容器，把所有数据遍历一边
	for (vector<vector<int>>::iterator it1 = v.begin(); it1 != v.end(); it1++)
	{
		//（*it） ---- 容器vector<int>	遍历
		for (vector<int>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
		{
			cout << *it2 << " ";
		}
		cout << endl;
	}
}

int main()
{

	//test01();
	//test02();
	//test03();
	test04();

	return 0;
}
