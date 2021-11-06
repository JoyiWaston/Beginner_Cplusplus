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
	this->w_FileIsEmpty = false;
	
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
	int num = this->Get_EmpNum();
	//cout << "现有职工人数为：" << num << endl; //测试代码
	this->w_EmpNum = num;	//更新成员属性

	//根据职工数创建数组
	this->w_EmpArray = new Worker * [this->w_EmpNum];
	//初始化职工			将文件中的数据存入到数组中
	this->Init_Emp();

	////测试代码
	//for (int i = 0; i < w_EmpNum; i++)
	//{
	//	cout << "职工号" << this->w_EmpArray[i]->w_Id
	//		<< "职工姓名" << this->w_EmpArray[i]->w_Name
	//		<< "部门编号" << this->w_EmpArray[i]->w_DepId << endl;
	//}
}

//展示菜单
void WorkManager::ShowMenu()
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
void WorkManager::ExitSystem()
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
					worker = new Employee(id, name, depSelect);
					break;
				case 2:
					worker = new Manager(id, name, depSelect);
					break;
				case 3:
					worker = new Boss(id, name, depSelect);
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
		this->Save();
	}
	else
	{
		cout << " 输入有误！ " << endl;
	}

	system("pause");
	system("cls");
}

//写入文件并保存
void WorkManager::Save()
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
int WorkManager::Get_EmpNum()
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
void WorkManager::Init_Emp()
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

//显示职工
void WorkManager::Show_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < w_EmpNum; i++)
		{
			//利用多态调用接口
			this->w_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

//删除职工		数组中的删除 本质就是数据前移
// 
void WorkManager::Del_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按照职工编号删除
		cout << "请输入想要删除员工的编号：" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);

		if (index != -1)	//说明职工存在，并且要删除index位置上的职工
		{
			//数据前移
			for (int i = index; i < this->w_EmpNum - 1; i++)
			{
				this->w_EmpArray[i] = this->w_EmpArray[i + 1];
			}
			this->w_EmpNum--;//更新数组中记录人员的个数
			this->Save();//数据同步更新到文件中

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工！" << endl;
		}
	}

	system("pause");
	system("cls");
}
//职工是否存在		存在返回职工所在数组中的位置	不存在返回-1
int WorkManager::IsExist(int id)
{
	int index = -1;

	for (int i = 0; i < this->w_EmpNum; i++)
	{
		if (this->w_EmpArray[i]->w_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}


//修改职工
void WorkManager::Mod_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "文件不存在或数据为空！" << endl;
	}
	else
	{
		cout << "请输入想要修改员工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)		//该员工存在
		{
			delete this->w_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int depSelect = 0;

			cout << "查询到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;

			cout << "请输入该职工新姓名：" << endl;
			cin >> newName;

			cout << "请输入该职工新岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> depSelect;

			Worker* worker = NULL;
			switch (depSelect)
			{
			case 1:
				worker = new Employee(id, newName, depSelect);
				break;
			case 2:
				worker = new Manager(id, newName, depSelect);
				break;
			case 3:
				worker = new Boss(id, newName, depSelect);
				break;
			default:
				break;
			}
			//更改数据 到数组中
			this->w_EmpArray[ret] = worker;

			cout << "修改成功" << endl;

			//保存到文件
			this->Save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}

	system("pause");
	system("cls");
}

//查找职工
void WorkManager::Find_Emp() {
	int type;
	cout << "请输入查找信息的方式" << endl;
	cout << "1、职员编号" << endl;
	cout << "2、职员姓名" << endl;
	cin >> type;

	switch (type) {
	case 1:
	{
		int id;
		cout << "请输入员工的职员编号：" << endl;
		cin >> id;

		int result = this->IsExist(id);
		if (result == -1) {
			cout << "职工不存在！" << endl;
		}
		else {
			cout << "查询到员工的信息为：" << endl;
			this->showHeader();
			int deptTemp = this->w_EmpArray[result]->w_DepId;
			string deptName = deptTemp == 1 ? "普通员工" : deptTemp == 2 ? "经理" : "老板";
			cout << this->w_EmpArray[result]->w_Id << "\t\t" << this->w_EmpArray[result]->w_Name<< "\t\t" << deptName << endl;
		}
	}
	break;
	case 2:
	{
		string name;
		cout << "请输入员工的姓名：" << endl;
		cin >> name;

		bool flag = false;
		for (int i = 0; i < this->w_EmpNum; i++) {
			if (this->w_EmpArray[i]->w_Name == name) {
				flag = true;
				this->showHeader();
				int deptTemp = this->w_EmpArray[i]->w_DepId;
				string deptName = deptTemp == 1 ? "普通员工" : deptTemp == 2 ? "经理" : "老板";
				cout << this->w_EmpArray[i]->w_Id << "\t\t" << this->w_EmpArray[i]->w_Name << "\t\t" << deptName << endl;
				break;
			}
		}

		if (!flag) {
			cout << "没有查询该员工！" << endl;
		}
	}
	break;
	default:
		break;
	}
	system("pause");
	system("cls");
}

void WorkManager::showHeader() {
	cout << "职工编号" << "\t" << "职工姓名" << "\t" << "职员部门" << endl;
}

//职工编号排序（选择排序）
void WorkManager:: Sort_Emp()
{
	if (this->w_FileIsEmpty)
	{
		cout << "文件不存在或数据为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工编号升序排列：" << endl;
		cout << "2、按职工编号降序排列：" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < w_EmpNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < w_EmpNum; j++)
			{
				if (select == 1)
				{
					//升序
					if (w_EmpArray[minORmax]->w_Id > w_EmpArray[j]->w_Id)
					{
						minORmax = j;
					}
				}
				else
				{
					//降序
					if (w_EmpArray[minORmax]->w_Id < w_EmpArray[j]->w_Id)
					{
						minORmax = j;
					}
				}
			}

			if (i != minORmax)
			{
				Worker* temp = w_EmpArray[i];
				w_EmpArray[i] = w_EmpArray[minORmax];
				w_EmpArray[minORmax] = temp;
			}
		}
		cout << "排序成功，排序后的结果为：" << endl;
		this->Save();
		this->Show_Emp();
	}
}


//清空文件
void WorkManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、取消" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在文件，删除并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->w_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0; i < this->w_EmpNum; i++)
			{
				delete this->w_EmpArray[i];
				this->w_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->w_EmpArray;
			this->w_EmpArray = NULL;
			this->w_EmpNum = 0;
			this->w_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

//析构
WorkManager::~WorkManager()
{
	if (this->w_EmpArray != NULL)
	{
		for (int i = 0; i < this->w_EmpNum; i++)
		{
			if (this->w_EmpArray[i] != NULL)
			{
				delete this->w_EmpArray[i];
			}
		}

		delete[] this->w_EmpArray;
		this->w_EmpArray = NULL;
	}
}