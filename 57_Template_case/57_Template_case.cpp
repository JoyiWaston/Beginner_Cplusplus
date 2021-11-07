// 57_Template_case.cpp: 目标的源文件。
//实现一个通用的数组类：
//1、可以对内置数据类型以及自定义数据类型的数据进行存储
//2、将数组中的数据存储到堆区
//3、构造函数中可以传入数组的容量
//4、提供对应的拷贝构造函数以及operator = 防止浅拷贝问题
//5、提供尾插法和尾删法对数组中的数据进行增加和删除
//6、可以通过下标的方式访问数组中的元素
//7、可以获取数组中当前元素个数和数组的容量

#include "myArray.hpp"

void printIntArray(MyArray<int>& arr) 
{
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test01()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1打印输出：" << endl;
	printIntArray(array1);
	cout << "array1的大小：" << array1.getSize() << endl;
	cout << "array1的容量：" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_back();
	cout << "array2尾删后打印输出：" << endl;
	printIntArray(array2);
	cout << "array2的大小：" << array2.getSize() << endl;
	cout << "array2的容量：" << array2.getCapacity() << endl;
}

//测试自定义数据类型
class Person {
public:
	Person() {};
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}

}

void test02()
{
	//创建数组
	MyArray<Person> pArray(10);
	Person p1("孙悟空\t", 30);
	Person p2("韩信\t", 20);
	Person p3("妲己\t", 18);
	Person p4("王昭君\t", 15);
	Person p5("赵云\t", 24);

	//插入数据
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;

}

int main() {

	test01();
	cout << "--------------------------" << endl;
	test02();

	system("pause");

	return 0;
}
