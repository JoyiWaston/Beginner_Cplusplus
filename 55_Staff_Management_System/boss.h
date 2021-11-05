#pragma once
#include"worker.h"

//老板类
class Boss : public Worker
{
public:
	Boss(int id, string name, int depId);

	//显示个人信息
	virtual void showInfo();

	//获取职工岗位名称
	virtual string getDepInformation();
};