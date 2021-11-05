#include "boss.h"

Boss::Boss(int id, string name, int depId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DepId = depId;
}

void Boss::showInfo()
{
	cout << "职工编号" << this->w_Id
		<< " \t职工姓名：" << this->w_Name
		<< "\t岗位：" << this->getDepInformation()
		<< "\t岗位职责：管理公司所有业务" << endl;
}

string Boss::getDepInformation()
{
	return string("老板");
}