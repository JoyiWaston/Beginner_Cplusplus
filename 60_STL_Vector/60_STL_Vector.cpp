// 60_STL_Vector.cpp: 目标的源文件。
//Vector

#include "60_STL_Vector.h"
//vector数据结构和数组非常相似，也称为单端数组
//vector与普通数组的区别：数组是静态空间，而vector可以动态扩展
//动态扩展：并不是在原空间之后续接新空间，而是找更大的内存空间，将原数据拷贝到新空间，释放原空间
//vector的迭代器是支持随机访问的迭代器

//vector容器构造
//vector<T> v; //采用模板实现类实现，默认构造函数
//vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
//vector(n, elem); //构造函数将n个elem拷贝给本身。
//vector(const vector& vec); //拷贝构造函数。
void myPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int> v1;	//默认构造，无参构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	////遍历方法一
	for_each(v1.begin(),v1.end(),myPrint);
	
	//遍历方法二
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}
	//c++11新特性
	for (auto it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}

	//通过区间方式构造
	vector<int> v2(v1.begin(), v1.end());
	for_each(v2.begin(), v2.end(), myPrint);


	//n个elem方式构造
	vector<int> v3(10, 100);
	for_each(v3.begin(), v3.end(), myPrint);

	//拷贝构造
	vector<int> v4(v3);
	for_each(v4.begin(), v4.end(), [](int x) {cout << x << endl; });
}


//vector容器赋值操作
//vector& operator=(const vector &vec);			//重载等号操作符
//assign(beg, end);								//将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem);								//将n个elem拷贝赋值给本身。
void vectorprint(vector<int>& v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test02()
{
	vector<int>v1;
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	//赋值	operator=
	vector<int> v2 = v1;
	vectorprint(v2);

	//assign
	vector<int> v3;
	v3.assign(v2.begin(), v2.end());
	vectorprint(v3);

	//n个elem方式赋值
	vector<int> v4;
	v4.assign(10, 'a');
	vectorprint(v4);
}
//vector容量和大小

//函数原型：	
//empty();					//判断容器是否为空
//capacity();				//容器的容量
//size();					//返回容器中元素的个数
//resize(int num);			//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
//resize(int num, elem);	//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除
void test03()
{
	vector<int> v1;
	for (int i = 1; i <= 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);
	if (v1.empty())		//true 代表容器为空
	{
		cout << "vector v1为空！" << endl;
	}
	else 
	{
		cout << "vector v1不为空！" << endl;
		cout << "v1容量为：" << v1.capacity() << endl;
		cout << "v1大小为：" << v1.size() << endl;
	}

	//重新指定大小
	//v1.resize(15);
	//v1.resize(5);
	//v1.resize(15, 6);
	
	vectorprint(v1);
	cout << "v1容量为：" << v1.capacity() << endl;
	cout << "v1大小为：" << v1.size() << endl;

}

// vector插入和删除
//push_back(ele);										//尾部插入元素ele
//pop_back();											//删除最后一个元素
//insert(const_iterator pos, ele);						//迭代器指向位置pos插入元素ele
//insert(const_iterator pos, int count, ele);			//迭代器指向位置pos插入count个元素ele
//erase(const_iterator pos);							//删除迭代器指向的元素
//erase(const_iterator start, const_iterator end);		//删除迭代器从start到end之间的元素
//clear();												//删除容器中所有元素
void test04()
{
	vector<int> v1;
	//尾插
	for (int i = 0; i <= 100; i=i+10)
	{
		v1.push_back(i);
	}
	vectorprint(v1);
	
	//尾删
	v1.pop_back();
	vectorprint(v1);

	//插入
	v1.insert(v1.begin(),100);
	vectorprint(v1);
	v1.insert(v1.begin(),5, 100);
	vectorprint(v1);

	//删除		参数也是迭代器
	v1.erase(v1.begin());
	vectorprint(v1);

	//清空
	v1.clear();
	vectorprint(v1);
	v1.erase(v1.begin(),v1.end());
	vectorprint(v1);
}

//vector数据存取
//at(int idx); //返回索引idx所指的数据
//operator[]; //返回索引idx所指的数据
//front(); //返回容器中第一个数据元素
//back(); //返回容器中最后一个数据元素
void test05()
{
	vector<int> v1;
	//尾插
	for (int i = 0; i <= 100; i = i + 10)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	cout << v1.at(3) << endl;
	cout << v1[4] << endl;
	cout << v1.front() << endl;
	cout << v1.back() << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
}

//vector容器互换
void test06()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vectorprint(v1);

	vector<int>v2;

	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	vectorprint(v2);

	//互换容器
	cout << "互换后" << endl;
	v1.swap(v2);
	vectorprint(v1);
	vectorprint(v2);

	cout << "----------------实际用途----------------" << endl;
	//实际应用
	vector<int> v;

	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//巧用swap，收缩内存
	vector<int>(v).swap(v); //匿名对象执行完 编译器立即回收内存
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

//vector预留空间
//减少vector在动态扩展容量时的扩展次数
//reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。
void test07()
{
	vector<int> v;
	//预留空间
	v.reserve(100000);

	int num = 0;			//统计开辟次数
	int* p = nullptr;		//

	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << "num:" << num << endl;
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}
