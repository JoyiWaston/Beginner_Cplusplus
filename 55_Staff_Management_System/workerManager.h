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
	void showMenu();

	
	//退出系统
	void exitSystem();

	
	//添加职工
	void Add_Emp();
	//记录文件中人数的个数
	int w_EmpNum;
	//员工数组的指针
	Worker** w_EmpArray;
	//文件写入并保存
	void save();
	//标志文件是否为空
	bool w_FileIsEmpty;
	
	
	//统计人数
	int get_EmpNum();


	//初始化员工
	void init_Emp();


	//析构函数
	~WorkManager();
};