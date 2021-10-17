// 41_Permissions_usage.cpp: 目标的源文件。
//

#include "41_Permissions_usage.h"
using namespace std;

class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}

	//读取姓名
	string showName()
	{
		return m_Name;
	}

	//读取年龄	可读可写（若要修改，必须在0-150之间）
	int getAge()
	{
		//m_Age = 0;
		return m_Age;
	}
	//设置年龄
	void setAge(int age)
	{
		if (age < 0 || age > 150)
		{
			m_Age = 0;
			cout << "你这个妖精！" << endl;
			return;
		}
		m_Age = age;
	}
	// 设置情人
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	string m_Name;		//可读可写
	int m_Age;			//只读
	string m_Lover;		//只写
};

int main()
{
	Person YL;
	YL.setName("杨立");
	YL.setAge(1000);
	cout << "姓名为：" << YL.showName() << endl;

	cout << "年龄为：" << YL.getAge() << endl;

	YL.setLover("苍井女士！");


	system("pause");
	return 0;
}
