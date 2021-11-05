#pragma once
#include "55_Staff_Management_System.h"

//职工抽象基类
class Worker
{
public:
	//显示个人信息
	virtual void showInfo() = 0;
	//获取岗位信息
	virtual string getDepInformation() = 0;

	int w_Id;
	string w_Name;
	int w_DepId;
};