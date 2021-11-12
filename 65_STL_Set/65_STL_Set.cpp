// 65_STL_Set.cpp: 目标的源文件。
//set和multiset 容器	（关联式容器）
//set基本概念
//所有元素都会在插入时自动被排序
//set/multiset属于关联式容器，底层结构是用二叉树实现。

//set和multiset区别：
//set不允许容器中有重复的元素
//multiset允许容器中有重复的元素

#include "65_STL_Set.h"

void printSet(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//set容器构造与赋值

//构造：
//set<T> st;						//默认构造函数：
//set(const set& st);				//拷贝构造函数

//赋值：
//set& operator=(const set& st);	//重载等号操作符
void test01()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//拷贝构造
	set<int>s2(s1);
	printSet(s2);

	//赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

//set容器大小和交换
//size();							//返回容器中元素的数目
//empty();							//判断容器是否为空
//swap(st);							//交换两个集合容器

//统计大小-- - size
//判断是否为空-- - empty
//交换容器-- - swap
void test02()
{
	//大小
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s1.size() << endl;
	}
	
	//交换
	set<int> s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(20);
	s2.insert(40);

	set<int> s3;
	s3.insert(100);
	s3.insert(300);
	s3.insert(200);
	s3.insert(400);

	cout << "交换前" << endl;
	printSet(s2);
	printSet(s3);
	cout << endl;

	cout << "交换后" << endl;
	s2.swap(s3);
	printSet(s2);
	printSet(s3);
}

//set容器插入和删除
//insert(elem);						//在容器中插入元素。
//clear();							//清除所有元素
//erase(pos);						//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end);					//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
//erase(elem);						//删除容器中值为elem的元素。

//插入-- - insert
//删除-- - erase
//清空-- - clear

void test03()
{
	set<int> s1;

	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);

	//删除
	s1.erase(s1.begin());
	printSet(s1);
	s1.erase(30);
	printSet(s1);

	//清空
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);

}

//set容器查找和排序
//find(key);						//查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key);						//统计key的元素个数
void test04()
{
	set<int> s1;

	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//查找
	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end())
	{
		cout << "找到了元素 ： " << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	int num = s1.count(30);
	cout << "num = " << num << endl;

}

//set容器set和multiset区别
//set不可以插入重复数据，而multiset可以
//set插入数据的同时会返回插入结果，表示插入是否成功
//multiset不会检测数据，因此可以插入重复数据
//如果不允许插入重复数据可以利用set
//如果需要插入重复数据利用multiset


void test05()
{
	set<int> s;

	pair<set<int>::iterator, bool> ret = s.insert(10);

	if (ret.second) {
		cout << "第一次插入成功!" << endl;
	}
	else {
		cout << "第一次插入失败!" << endl;
	}

	ret = s.insert(10);

	if (ret.second) {
		cout << "第二次插入成功!" << endl;
	}
	else {
		cout << "第二次插入失败!" << endl;
	}

	//multiset
	multiset<int> ms;

	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//pari使用与对组创建
//成对出现的数据，利用对组可以返回两个数据
//pair<type, type> p(value1, value2);
//pair<type, type> p = make_pair(value1, value2);
void test06()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " << p.first << " 年龄： " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

//set容器内置类型指定排序规则
//利用仿函数，可以改变排序规则
class MyCompare 
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void test07()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);

	//默认从小到大
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则
	set<int, MyCompare> s2;

	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);

	for (set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//set容器自定义数据类型存放
//对于自定义数据类型，set必须指定排序规则才可以插入数据
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//自定义数据类型必须指定排序规则
class comparePerson
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		//按照年龄进行排序 降序
		return p1.m_Age > p2.m_Age;
	}
};

void test08()
{
	set<Person, comparePerson> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}

}



int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();

	return 0;
}
