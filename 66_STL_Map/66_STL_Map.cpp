// 66_STL_Map.cpp: 目标的源文件。
//map中所有元素都是pair
//pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
//所有元素都会根据元素的键值自动排序
//map/multimap属于关联式容器，底层结构是用二叉树实现。
//可以根据key值快速找到value值
//map和multimap区别：
//map不允许容器中有重复key值元素
//multimap允许容器中有重复key值元素

#define CEHUA 0
#define MEISHU 1
#define YANFA 2


#include "66_STL_Map.h"

void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << (*it).first << " value = " << it->second << endl;
	}
	cout << endl;
}

//map容器构造与赋值

//构造：
//map<T1, T2> mp;						//map默认构造函数:
//map(const map& mp);					//拷贝构造函数

//赋值：
//map& operator=(const map& mp);		//重载等号操作符
void test01()
{
	map<int, int>m; //默认构造
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	printMap(m);

	map<int, int>m2(m); //拷贝构造
	printMap(m2);

	map<int, int>m3;
	m3 = m2; //赋值
	printMap(m3);
}

//map容器大小和交换
//size();					//返回容器中元素的数目
//empty();					//判断容器是否为空
//swap(st);					//交换两个集合容器
void test02()
{
	//大小
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为： " << m.size() << endl;
	}

	//交换
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	cout << "交换前" << endl;
	printMap(m1);
	printMap(m2);

	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);

}

//map容器插入和删除
//insert(elem);									//在容器中插入元素。
//clear();										//清除所有元素
//erase(pos);									//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end);								//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
//erase(key);									//删除容器中值为key的元素。
void test03()
{
	//插入
	map<int, int> m;

	//第一种插入方式
	m.insert(pair<int, int>(1, 10));

	//第二种插入方式
	m.insert(make_pair(2, 20));

	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));

	//第四种插入方式
	m[4] = 40;

	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);
	m.erase(3);
	printMap(m);

	//清空
	m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}

//map容器查找和统计
//find(key);					//查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key);					//统计key的元素个数
void test04()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	//查找
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	//统计
	int num = m.count(3);
	cout << "num = " << num << endl;
}

//map容器排序
//map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
//利用仿函数，可以改变排序规则
class MyCompare {
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};

void test05()
{
	//默认从小到大排序
	//利用仿函数实现从大到小排序
	map<int, int, MyCompare> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) 
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}

}

//综合案例：员工分组
/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入 key(部门编号) value(员工)
- 分部门显示员工信息
*/

//实现步骤
//1. 创建10名员工，放到vector中
//2. 遍历vector容器，取出每个员工，进行随机分组
//3. 分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
//4. 分部门显示员工信息

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10000 + 10000; // 10000 ~ 19999
		//将员工放入到容器中
		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int deptId = rand() % 3; // 0 1 2
		//将员工插入到分组中
		//key部门编号，value具体员工
		m.insert(make_pair(deptId, *it));
	}
}
void showWorkerByGourp(multimap<int, Worker>& m)
{
	// 0 A B C 1 D E 2 F G ...
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);

	int count = m.count(CEHUA); // 统计具体人数
	int index = 0;

	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;

	cout << "美术部门： " << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU); // 统计具体人数
	index = 0;

	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;

	cout << "研发部门： " << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA); // 统计具体人数
	index = 0;

	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Salary << endl;
	}
}

void test06()
{
	srand((unsigned int)time(NULL));
	//1、创建员工
	vector<Worker>vWorker;
	createWorker(vWorker);
	//2、员工分组
	multimap<int, Worker>mWorker;
	setGroup(vWorker, mWorker);
	//3、分组显示员工
	showWorkerByGourp(mWorker);
	////测试
	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	//{
	// cout << "姓名： " << it->m_Name << " 工资： " << it->m_Salary << endl;
}
int main()
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();

	return 0;
}
