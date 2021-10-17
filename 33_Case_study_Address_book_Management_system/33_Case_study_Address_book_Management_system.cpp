// 33_Case_study_Address_book_Management_system.cpp: 目标的源文件。
/*
	系统中需要实现的功能如下：
		1.添加联系人：向通讯录中添加新人，信息包括（姓名，性别，年龄，联系电话，家庭住址）最多记录1000人
		2.显示联系人：显示通讯录中所以联系人的信息
		3.删除联系人：按照姓名删除指定联系人
		4.查找联系人：按照姓名查看指定联系人信息
		5.修改联系人：按照姓名重新修改指定联系人
		6.清空联系人：清空通讯录中所有信息
		7.退出通讯录：退出当前使用的通讯录
*/

#include "33_Case_study_Address_book_Management_system.h"

using namespace std;

const int MAX = 1000;			//通讯录最大可存入人数

//联系人结构体
struct Person
{
	string m_name;				//姓名
	int m_Sex;					//性别：     1：男 2：女
	int m_Age;					//年龄
	string m_Phone;				//电话号码
	string m_Addr;				//地址
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];							//通讯录中保存的联系人数组
	int m_Size;												//通讯录中人员个数
};

//菜单界面
void showMenu()
{
	cout << "*****************************" << endl;
	cout << "*****	1.添加联系人	*****" << endl;
	cout << "*****	2.显示联系人	*****" << endl;
	cout << "*****	3.删除联系人	*****" << endl;
	cout << "*****	4.查找联系人	*****" << endl;
	cout << "*****	5.修改联系人	*****" << endl;
	cout << "*****	6.清空联系人	*****" << endl;
	cout << "*****	0.退出通讯录	*****" << endl;
	cout << "*****************************" << endl;
}
void addPerson(Addressbooks* Abs);
void showPerson(Addressbooks* Abs);
void deletePerson(Addressbooks* Abs);
void findPerson(Addressbooks* Abs);
void changePerson(Addressbooks* Abs);

int main()
{
	//创建通讯录结构体变量
	Addressbooks Abs;

	//初始化通讯录当前人员个数
	Abs.m_Size = 0;

	int select = 0;											//创建用户选择输入的变量

	while (true)
	{
		showMenu();												//菜单调用

		cin >> select;

		switch (select)
		{
		case 1://1.添加联系人
			addPerson(&Abs);					//利用地址传递，可以修饰实参
			break;

		case 2://2.显示联系人
			showPerson(&Abs);
			break;

		case 3://3.删除联系人
			deletePerson(&Abs);
			break;

		case 4://4.查找联系人
			findPerson(&Abs);
			break;

		case 5://5.修改联系人
			changePerson(&Abs);
			break;

		case 6://6.清空联系人
			break;

		case 0://0.退出通讯录
			cout << "欢迎您下次使用！" << endl;
			system("pause");
			return 0;
			break;

		default://错误选项指导选正
			break;
		}
	}
	return 0;
}


//1.添加联系人
void addPerson(Addressbooks* Abs)
{
	//判断通讯录是否满员，若满员不再接受添加
	if (Abs->m_Size == MAX)
	{
		cout << "通讯录已满员，无法继续添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

			//姓名
		string name;
		cout << "请输入联系人姓名: " << endl;
		cin >> name;
		Abs->personArray[Abs->m_Size].m_name = name;

		//性别
		int Sex = 0;
		cout << "请输入该联系人性别: " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		while (true)
		{
			//如果输入为1或2可以退出循环，若输入错误则重新输入
			cin >> Sex;
			if (Sex == 1 || Sex == 2)
			{
				Abs->personArray[Abs->m_Size].m_Sex = Sex;
				break;
			}
			cout << "输入为非法性别，请重新输入！" << endl;
		}

		//年龄
		int Age = 0;
		cout << "请输入该联系人年龄: " << endl;
		while (true)
		{
			//输入输入0至150则可以退出循环，若输入错误则重新输入
			cin >> Age;
			if (Age >= 0 && Age <= 150)
			{
				Abs->personArray[Abs->m_Size].m_Age = Age;
				break;
			}
			cout << "输入非多见年龄，请重新输入!" << endl;
		}

		//电话
		cout << "请输入联系电话: " << endl;
		string phone;
		cin >> phone;
		Abs->personArray[Abs->m_Size].m_Phone = phone;
		//int Phone = 0;
		//int Phone_length = 0;
		//cout << "请输入该联系人电话号码: " << endl;
		//while (true)
		//{
		//	//输入七位或十一位电话号码可正常输入，若位数错误则重新输入

		//	cin >> Phone;
		//	if (Phone == 0)
		//		Phone_length = 1;
		//	while (Phone)
		//	{
		//		Phone_length++;
		//		Phone /= 10;
		//	}
		//	cout << Phone_length << endl;
		//	if (Phone_length == 7 || Phone_length == 11)
		//	{
		//		Abs->personArray[Abs->m_Size].m_Phone = Phone;
		//		Phone_length = 0;
		//		break;
		//	}
		//	Phone_length = 0;
		//	cout << "您输入的该联系人电话号码非七位及十一位正常电话号码，请您查证后重新输入！" << endl;
		//}

		//住址                                                                                                                                                                                                                                                                                                                                                                                                             
		string Address;
		cout << "请输入该联系人家庭住址: " << endl;
		cin >> Address;
		Abs->personArray[Abs->m_Size].m_Addr = Address;

		//更新通讯录人数
		Abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");//任意键退出
		system("cls");//清屏
	}
}

//显示联系人
void showPerson(Addressbooks* Abs)
{
	//判断通讯录中人数是否为零，如果为零，提示记录为空
	//如果不为零，显示记录的联系人信息
	if (Abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < Abs->m_Size; i++)
		{
			cout << "姓名：" << Abs->personArray[i].m_name << "\t";
			cout << "性别：" << (Abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << Abs->personArray[i].m_Age << "\t";
			cout << "地址：" << Abs->personArray[i].m_Addr << "\t";
			cout << "电话：" << Abs->personArray[i].m_Phone << endl;
		}
	}

	system("pause");//任意键退出
	system("cls");//清屏
}

//删除联系人实现步骤
	//封装监测联系人是否存在,如果存在，返回联系人数组具体位置，不存在返回-1
	//参数1 通讯录  参数2 姓名
int isExist(Addressbooks* Abs, string name)
{
	for (int i = 0; i < Abs->m_Size; i++)
	{
		//找到了
		if (Abs->personArray[i].m_name == name)
		{
			return i;//返回下标
		}
	}
	return -1;//没找到
}
//封装删除联系人函数
void deletePerson(Addressbooks* Abs)
{
	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	//ret == -1 未查到
	//ret =！找到了
	int ret = isExist(Abs, name);

	if (ret != -1)
	{
		//找到,删除操作
		for (int i = ret; i < Abs->m_Size; i++)
		{
			//数据迁移
			Abs->personArray[i] = Abs->personArray[i + 1];
		}
		Abs->m_Size--;//更新人数

		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");//任意键退出
	system("cls");//清屏
}

//查找联系人
void findPerson(Addressbooks* Abs)
{
	cout << "请输入您要查找的联系人: " << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在通讯录中
	int ret = isExist(Abs, name);

	if (ret != -1)//找到联系人
	{
		cout << "姓名：" << Abs->personArray[ret].m_name << "\t";
		cout << "性别：" << (Abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << Abs->personArray[ret].m_Age << "\t";
		cout << "地址：" << Abs->personArray[ret].m_Addr << "\t";
		cout << "电话：" << Abs->personArray[ret].m_Phone << endl;
	}
	else//未找到联系人
	{
		cout << "查无此人" << endl;
	}


	system("pause");//任意键退出
	system("cls");//清屏
}

//修改联系人
void changePerson(Addressbooks* Abs)
{
	cout << "请输入您要修改的联系人: " << endl;
	string name;
	cin >> name;

	int ret = isExist(Abs, name);
	if (ret != -1)//找到
	{
		//姓名
		string name;
		cout << "请输入修改后的姓名：" << endl;

		cin >> name;
		Abs->personArray[ret].m_name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				//输入正确，退出循环
				Abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		Abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入联系电话: " << endl;
		string phone;
		cin >> phone;
		Abs->personArray[ret].m_Phone = phone;
		//地址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		Abs->personArray[ret].m_Addr = address;

		cout << "修改成功！" << endl;
	}
	else//未找到
	{
		cout << "查无此人" << endl;
	}

	system("pause");//任意键退出
	system("cls");//清屏
}

//清空所以联系人
void cleanPerson(Addressbooks* Abs)
{
	Abs->m_Size = 0; //将当前记录联系人数量置为零，做逻辑清空
	cout << " 通讯录已清空" << endl;

	system("pause");//任意键退出
	system("cls");//清屏
}