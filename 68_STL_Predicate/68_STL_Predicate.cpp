// 68_STL_Predicate.cpp: 目标的源文件。
//谓词
//返回bool类型的仿函数称为谓词
//如果operator()接受一个参数，那么叫做一元谓词
//如果operator()接受两个参数，那么叫做二元谓词

#include "68_STL_Predicate.h"
//1、一元谓词
class GreaterFive
{
public:
	bool operator()(int val) const
	{
		return val > 5;
	}
};
void test01()
{
	vector<int> v;
	for (int i = 1; i <= 10; i++)
	{
		v.push_back(i);
	}

	//查找容器中 是否有大于5的数字
	vector<int>::iterator it = find_if(v.begin(), v.end(),GreaterFive());
	auto it1 = find_if(v.begin(), v.end(), [](int x) {return x > 5; });
	if (it == v.end())
	{
		cout << "未找到比5大的！" << endl;
	}
	else
	{
		cout <<"找到的数字为：" << * it << endl;
	}
	if (it1 == v.end())
	{
		cout << "未找到比5大的！" << endl;
	}
	else
	{
		cout << "找到的数字为：" << *it1 << endl;
	}
}

//2、二元谓词
class MyCompare
{
public:
	bool operator ()(int v1,int v2)
	{
		return v1 > v2;
	}

};
void test02()
{
	vector<int> v;
	srand((unsigned int)time(NULL));
	v.push_back(rand()%100+100);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);
	v.push_back(rand() % 100 + 10);

	for_each(v.begin(), v.end(), [](int x) {cout << x << " ";});
	cout << endl;

	cout << "--------排序后--------" << endl;
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int x) {cout << x << " ";});
	cout << endl;

	//使用函数对象 改变算法策略，变为排序规则为从大到小
	sort(v.begin(), v.end(),MyCompare());
	for_each(v.begin(), v.end(), [](int x) {cout << x << " "; });
	cout << endl;
	sort(v.begin(), v.end(), [](int v1, int v2) {return v1 > v2; });
	for_each(v.begin(), v.end(), [](int x) {cout << x << " "; });
	cout << endl;
}





int main()
{
	//test01();
	test02();

	return 0;
}
