#include "44_Initialization_and_cleanup_of_objects.h"

//深浅拷贝为面试经典巨坑
//浅拷贝：简单的赋值拷贝操作					带来的问题:堆区的内存重复释放
//深拷贝：在堆区重新申请空间，进行拷贝操作		解决浅拷贝带来的问题


class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age,int Height)
	{
		m_Age = age;
		m_Height = new int(Height);
		cout << "Person的有参构造函数调用" << endl;
	}
	
	//自己实现拷贝构造函数解决浅拷贝带来的问题
	Person(const Person& z)
	{
		cout << "Person的拷贝函数调用" << endl;
		m_Age = z.m_Age;
		//m_Height = p.m_Height;      编译器默认实现此行代码
		//深拷贝操作

		m_Height = new int(*z.m_Height);

	}

	~Person()
	{
		//析构代码，将堆区开辟的数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;		//防止野指针出现
		}
		cout << "Person的析构函数调用" << endl;
	}

	int m_Age;
	int* m_Height;
};

void test05()
{
	Person p1(18,180);

	cout << "p1的年龄：" << p1.m_Age << "身高为：" << *p1.m_Height << endl;

	Person p9 = Person (p1);

	cout << "p9的年龄：" << p9.m_Age << "身高为：" << *p9.m_Height << endl;
}
int main()
{
	test05();
}