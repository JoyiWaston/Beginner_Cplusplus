#include"employee.h"

Employee::Employee(int id, string name, int depId)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_DepId = depId;
}

void Employee::showInfo()
{
	cout << "职工编号" << this->w_Id
		<< "\t职工姓名：" << this->w_Name
		<< "\t岗位：" << this->getDepInformation()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDepInformation()
{
	return string("员工");
}