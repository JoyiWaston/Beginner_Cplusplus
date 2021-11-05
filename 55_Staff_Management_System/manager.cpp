#include "manager.h"

Manager::Manager(int id, string name, int depId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DepId = depId;
}

void Manager::showInfo()
{
	cout << "职工编号" << this->w_Id
		<< " \t职工姓名：" << this->w_Name
		<< "\t岗位：" << this->getDepInformation()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDepInformation()
{
	return string("经理");
}