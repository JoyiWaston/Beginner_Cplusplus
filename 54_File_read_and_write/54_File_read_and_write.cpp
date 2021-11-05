// 54_File_read_and_write.cpp: 目标的源文件。
//文件操作

//文件类型分为两种：
//1.文本文件：文件以文本的ASCLL码形式存储在计算机中
//2.二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂

//文件操作三大类：
//1. ofstream：写操作
//2. ifstream：读操作
//3. fstream：读写操作

//文件打开方式（列举）			可以配合使用，用 | 操作符		例如：用二进制方式写文件 ios::binary | ios::out
//ios::in		为读文件而打开文件
//ios::out		为写文件而打开文件
//ios::ate		初始位置：文件尾
//ios::app		追加方式写文件
//ios::trunc	如果文件存在，先删除再创建
//ios::binary	二进制方式

#include "54_File_read_and_write.h"

//写文件
void test01()
{
	//创建流对象
	ofstream ofs;

	//指定打开方式
	ofs.open("test.txt", ios::out);

	//写内容
	ofs << "姓名：杨立" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;

	//关闭
	ofs.close();

}

//读文件
void test02()
{
	ifstream ifs;
	ifs.open("W:\\C++_Workspace\\Beginner_C++\\out\\build\\x64-Debug\\54_File_read_and_write\\test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//读取数据四种方法
	//1.
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}
	
	ifs.close();*/

	//2.
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	//3.
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/

	//4.
	char c;
	while ((c = ifs.get()) != EOF)		//EOF  end of file
	{
		cout << c;
	}
	ifs.close();
}

//二进制写
class Person
{
public:
	char m_name[64];//姓名
	int m_age;//年龄
};

void test03()
{
	//创建流对象
	ofstream ofs("Person.txt", ios::out | ios::binary);
	//打开文件
	//ofs.open("Person.txt", ios::out | ios::binary);
	//写文件
	Person P1 = { "杨立",18 };
	ofs.write((const char*)&P1, sizeof(Person));
	//关闭
	ofs.close();
}
//二进制读
void test04()
{
	//创建流对象
	ifstream ifs;
	//打开文件 判断是否打开成功
	ifs.open("W:\\C++_Workspace\\Beginner_C++\\out\\build\\x64-Debug\\54_File_read_and_write\\Person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	//读文件
	Person P2;

	ifs.read((char*)&P2, sizeof(Person));

	cout << "姓名：" << P2.m_name << "\n年龄：" << P2.m_age << endl;
	//关闭
	ifs.close();
}

int main()
{
	//est01();
	//test02();
	//test03();
	test04();

	return 0;
}
