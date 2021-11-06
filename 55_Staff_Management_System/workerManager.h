#pragma once			//防止头文件重复包含
#include "55_Staff_Management_System.h"
#include "worker.h"

#define FILENAME "W:\\C++_Workspace\\Beginner_C++\\out\\build\\x64-Debug\\55_Staff_Management_System\\empFile.txt"

class WorkManager
{
public:
	//构造函数
	WorkManager();

	//展示菜单
	void ShowMenu();

	//退出系统
	void ExitSystem();

	//添加职工
	void Add_Emp();
	//记录文件中人数的个数
	int w_EmpNum;
	//员工数组的指针
	Worker** w_EmpArray;
	//文件写入并保存
	void Save();
	//标志文件是否为空
	bool w_FileIsEmpty;
	
	
	//统计人数
	int Get_EmpNum();

	//初始化员工
	void Init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();
	//员工是否存在函数
	int IsExist(int id);

	
	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();
	//示例表
	void showHeader();


	//排序职工(选择排序)
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkManager();
};