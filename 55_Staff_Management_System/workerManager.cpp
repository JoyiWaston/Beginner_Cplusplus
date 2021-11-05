# include"workerManager.h"
# include"employee.h"
# include"manager.h"
# include"boss.h"
//创建管理类
//1.与用户的沟通菜单界面
//2.对职工增删改查的操作
//3.与文件读写交互

//构造
WorkManager::WorkManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//1.文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在,即将创建！" << endl;

		//初始化人数
		this->w_EmpNum = 0;

		//初始化文件为空标志
		this->w_FileIsEmpty = true;

		//初始化数组指针
		this->w_EmpArray = NULL;

		//关闭文件
		ifs.close();
		return;
	}
	//2.文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件存在,但数据为空，即将写入数据！" << endl;

		//初始化人数
		this->w_EmpNum = 0;

		//初始化文件为空标志
		this->w_FileIsEmpty = true;

		//初始化数组指针
		this->w_EmpArray = NULL;

		//关闭文件
		ifs.close();
		return;
	}

	//3.文件存在，并且有记录数据
	int num = this->get_EmpNum();
	//cout << "现有职工人数为：" << num << endl; //测试代码
	this->w_EmpNum = num;	//更新成员属性

	//根据职工数创建数组
	this->w_EmpArray = new Worker * [this->w_EmpNum];
	//初始化职工			将文件中的数据存入到数组中
	this->init_Emp();

	////测试代码
	//for (int i = 0; i < w_EmpNum; i++)
	//{
	//	cout << "职工号" << this->w_EmpArray[i]->w_Id
	//		<< "职工姓名" << this->w_EmpArray[i]->w_Name
	//		<< "部门编号" << this->w_EmpArray[i]->w_DepId << endl;
	//}
}

//展示菜单
void WorkManager::showMenu()
{
	cout << "***********************************" << endl;
	cout << "*****  欢迎使用职工管理系统   *****" << endl;
	cout << "*****     0.退出管理系统      *****" << endl;
	cout << "***** 	  1.增加职工信息      *****" << endl;
	cout << "*****	  2.显示职工信息      *****" << endl;
	cout << "*****	  3.删除离职员工      *****" << endl;
	cout << "*****	  4.修改职工信息      *****" << endl;
	cout << "*****	  5.查找职工信息      *****" << endl;
	cout << "*****	  6.按照编号排序      *****" << endl;
	cout << "*****	  7.清空所有文档      *****" << endl;
	cout << "***********************************" << endl;
	cout << endl;
}

//退出系统
void WorkManager::exitSystem()
{
	cout << "欢迎您下次使用！" << endl;
	system("pause");
	exit(0);//退出系统
}

//添加员工
void WorkManager::Add_Emp()
{
	cout << "请输入添加员工数量：" << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->w_EmpNum + addNum;		//新空间人数 = 原纪录人数 + 新添加人数

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->w_EmpArray != NULL)
		{
			for (int i = 0; i < this->w_EmpNum; i++)
			{
				newSpace[i] = this->w_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int depSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> depSelect;

			Worker* worker = NULL;
			switch (depSelect)
			{
				case 1:
					worker = new Employee(id, name, 1);
					break;
				case 2:
					worker = new Manager(id, name, 2);
					break;
				case 3:
					worker = new Boss(id, name, 3);
					break;
				default:
					break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->w_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->w_EmpArray;

		//更新新空间指向
		this->w_EmpArray = newSpace;

		//更新新的个数
		this->w_EmpNum = newSize;

		//更新职工不为空标志
		this->w_FileIsEmpty = false;

		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;

		//保存数据写入文件
		this->save();
	}
	else
	{
		cout << " 输入有误！ " << endl;
	}

	system("pause");
	system("cls");
}

//写入文件并保存
void WorkManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->w_EmpNum; i++)
	{
		ofs << this->w_EmpArray[i]->w_Id << " "
			<< this->w_EmpArray[i]->w_Name << " "
			<< this->w_EmpArray[i]->w_DepId << endl;
	}

	ofs.close();
}

//职工人数统计
int WorkManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int depId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		//记录人数
		num++;
	}
	ifs.close();

	return num;
}

//初始化员工
void WorkManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int depId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> depId)
	{
		Worker* worker = NULL;
		//根据不同的部门id创建不同对象
		if (depId == 1)	//普通员工
		{
			worker = new Employee(id, name, depId);
		}
		else if (depId == 2)	//经理
		{
			worker = new Manager(id, name, depId);
		}
		else                    //老板
		{
			worker = new Boss(id, name, depId);
		}
		//存放在数组中
		this->w_EmpArray[index] = worker;
		index++;
	}
	//关闭文件
	ifs.close();
}

//析构
WorkManager::~WorkManager()
{
	if (this->w_EmpArray != NULL)
	{
		delete[] this->w_EmpArray;
		this->w_EmpArray = NULL;
	}
}