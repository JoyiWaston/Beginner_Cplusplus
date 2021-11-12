// 61_STL_Deque.cpp: 目标的源文件。
// deque容器：双端数组，可以对头端进行插入删除操作
// deque容器的迭代器也是支持随机访问的

//deque与vector区别：
//vector对于头部的插入删除效率低，数据量越大，效率越低
//deque相对而言，对头部的插入删除速度回比vector快
//vector访问元素时的速度会比deque快, 这和两者内部实现有关

//deque内部工作原理:
//deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
//中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间


#include "61_STL_Deque.h"

//遍历输出接口
void printdeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//*it = 100;				//容器中的数据不可以修改了
		cout << *it << " ";
	}
	cout << endl;
}

//deque构造函数
//deque<T> deqT; //默认构造形式
//deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
//deque(n, elem); //构造函数将n个elem拷贝给本身。
//deque(const deque& deq); //拷贝构造函数
void test01()
{
	//默认构造
	deque<int> d1;
	for (int i = 1; i <= 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	//区间构造
	deque<int> d2(d1.begin(), d1.end());
	printdeque(d2);

	//n个elem构造
	deque<int> d3(10, 100);
	printdeque(d3);

	//拷贝构造
	deque<int> d4(d1);
	printdeque(d4);

}

//deque赋值操作
//deque& operator=(const deque& deq); //重载等号操作符
//assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem); //将n个elem拷贝赋值给本身。
void test02()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	deque<int>d2;
	d2 = d1;
	printdeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printdeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printdeque(d4);

}

//deque大小操作
//deque.empty();					//判断容器是否为空
//deque.size();						//返回容器中元素的个数
//deque.resize(num);				//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
//deque.resize(num, elem);			//重新指定容器的长度为num,若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

//deque没有容量的概念
//判断是否为空-- - empty
//返回元素个数-- - size
//重新指定个数-- - resize
void test03()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printdeque(d1);

	//判断容器是否为空
	if (d1.empty()) {
		cout << "d1为空!" << endl;
	}
	else {
		cout << "d1不为空!" << endl;
		//统计大小
		cout << "d1的大小为：" << d1.size() << endl;
	}

	//重新指定大小
	d1.resize(15, 1);
	printdeque(d1);
	d1.resize(5);
	printdeque(d1);
}

//deque插入与删除
//两端插入操作：
//push_back(elem);						//在容器尾部添加一个数据
//push_front(elem);						//在容器头部插入一个数据
//pop_back();							//删除容器最后一个数据
//pop_front();							//删除容器第一个数据

//指定位置操作：
//insert(pos, elem);					//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
//insert(pos, n, elem);					//在pos位置插入n个elem数据，无返回值。
//insert(pos, beg, end);				//在pos位置插入[beg,end)区间的数据，无返回值。
//clear();								//清空容器的所有数据
//erase(beg, end);						//删除[beg,end)区间的数据，返回下一个数据的位置。
//erase(pos);							//删除pos位置的数据，返回下一个数据的位置。

//插入和删除提供的位置是迭代器！
//尾插-- - push_back
//尾删-- - pop_back
//头插-- - push_front
//头删-- - pop_front

void test04()
{
	//-------------两端操作-------------

	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);

	printdeque(d);

	//尾删
	d.pop_back();
	//头删
	d.pop_front();

	printdeque(d);


	//------------------插入---------------
	deque<int> d1;

	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printdeque(d1);

	d1.insert(d1.begin(), 1000);
	printdeque(d1);
	d1.insert(d1.begin(), 2, 10000);
	printdeque(d1);

	deque<int>d2;

	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d1.insert(d1.begin(), d2.begin(), d2.end());
	printdeque(d1);

	//--------------------删除------------------
	deque<int> d4;

	d4.push_back(10);
	d4.push_back(20);
	d4.push_front(100);
	d4.push_front(200);
	printdeque(d4);

	d4.erase(d4.begin());
	printdeque(d4);

	d4.erase(d4.begin(), d4.end());

	d4.clear();

	printdeque(d4);

}

//deque数据存取
//at(int idx);	 //返回索引idx所指的数据
//operator[];	 //返回索引idx所指的数据
//front();		 //返回容器中第一个数据元素
//back();		 //返回容器中最后一个数据元素

//除了用迭代器获取deque容器中元素，[ ]和at也可以
//front返回容器第一个元素
//back返回容器最后一个元素

void test05()
{
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "front:" << d.front() << endl;
	cout << "back:" << d.back() << endl;
}

//deque排序操作
//sort(iterator beg, iterator end)		//对beg和end区间内元素进行排序
void test06()
{
	deque<int> d;

	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printdeque(d);

	sort(d.begin(), d.end());
	printdeque(d);
}



//学完的容器综合做		评委打分案例
//需求：有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

//实现步骤：
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，去除最高和最低分
//4. deque容器遍历一遍，累加总分
//5. 获取平均分k

//选手类
class Person
{
public:
	Person(string name,int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
	string m_Name;		//姓名
	int m_Score;		//平均分
};
//选手创建
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		//将创建的Person对象放入容器中
		v.push_back(p);
	}
}
//打分
void setScore(vector<Person>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		//将评委所打的分数 放入deque容器中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;					//60到100随机数
			d.push_back(score);
		}
		/*cout << "选手" << it->m_Name << "的得分：" ;
		for_each(d.begin(), d.end(), [](int x) {cout << x << " "; });
		cout << endl;*/

		//先排序
		sort(d.begin(), d.end());

		//去除最高最低分
		d.pop_back();
		d.pop_front();

		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;	//累加每个评委的分数
		}
		int avg = sum / d.size();

		//平均分赋值给选手
		it->m_Score = avg;
	}
}

//打印分数
void showScore(vector<Person>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "\t平均分：" << it->m_Score << endl;
	}
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();

	//随机数种子
	srand((unsigned int)time(NULL));

	//1、创建五名选手
	vector<Person> v;	//存放选手的容器
	createPerson(v);

	//for_each(v.begin(), v.end(), [](Person& p) {cout << p.m_Name << "现有分数为 = " << p.m_Score << endl; });

	//2、给五名选手打分
	setScore(v);

	//3、显示最后得分
	showScore(v);

	return 0;
}
