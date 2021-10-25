// 46_this_pointer.cpp: 目标的源文件。
//this指针指向被调用的成员函数所属对象
// 空指针访问成员函数
// const修饰成员函数
// 
//用途
//1.当形参和成员变量同名可用this区分
//2.在类的非静态成员函数中返回对象本身可用return *this


#include "46_this_pointer.h"

//this指针指向被调用的成员函数所属对象
class Person
{
public:
	Person(int age)
	{
		//this指针指向被调用的成员函数所属对象
		this->age = age;
	}
	//值返回方式会创建新的对象
	Person& addAddAge(Person &p)
	{
		this->age += p.age;
		return *this;
	}


	int age;
};

//解决名称冲突
void test01()
{
	Person p1(18);
	cout << "p1的年龄：" << p1.age << endl;
}

//返回对象本身用*this
void test02()
{
	Person p2(10);

	Person p3(10); 


	//链式编程思想
	p3.addAddAge(p2).addAddAge(p2).addAddAge(p2);

	cout << "p3的年龄：" << p3.age << endl;
}

// 空指针访问成员函数
class Man
{
public:
	void showClassName()
	{
		cout << "MAN" << endl;
	}

	void showManAge()
	{
		//解决方案:提供健壮性
		if (this == NULL)
		{
			return;
		}
		//报错原因时因为传入指针为NULL
		cout << "年龄：" << this->age << endl;
	}

	int age;
};

void test03()
{
	Man* p = NULL;
	p->showClassName();
	p->showManAge();
}

// const修饰成员函数
//常函数
class Guy
{
public :
	//this指针的本质 是一个指针常量 指针的指向是不可以修改的
	//在成员函数后面加const,修饰的是this指向，让指针指向的值也不可以修改
	void showGuyName() const
	{
		//this->m_A = 100;      //报错
		//this = NULL;			//报错
		this->m_B = 100;
		cout << m_A << endl;
	}
	void showClassName()
	{
		cout << "Guy" << endl;
	}

	int m_A;
	mutable int m_B;	//特殊变量，即使在常函数中也可以修改这个值，加关键字mutable
};
void test04()
{
	Guy p4;
	p4.showGuyName();
}

//常对象
void test05()
{
	const Guy p5;//在对象前面加const,变为常对象
	//p5.m_A = 100;
	p5.m_B = 100;//特殊变量，即使在常对象中也可以修改这个值
	
	//常对象只能调用常函数
	p5.showGuyName();
	//p5.showClassName();		//常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性

}	

int main()
{
	//test01();
	//test02();
	//test03();
	system("pause");

	return 0;
}
