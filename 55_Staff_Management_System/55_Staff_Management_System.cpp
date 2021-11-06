// 55_Staff_Management_System.cpp: 目标的源文件。
//利用C++实现一个基于多态的职工管理系统

//公司职工分为三类：普通员工（完成经理交代的任务），经理（完成老板交代的任务及命令下发），老板（管理所有事务）	
// 显示职工编号，职工姓名，职工岗位，职责
//主要实现功能如下：
//1. 退出管理系统：退出当前管理系统
//2. 增加职工信息：实现批量添加员工功能，信息录入文件，职工信息为：职工编号，姓名，部门编号
//3. 显示职工信息：显示公司内部所有职工信息
//4. 删除离职职工：按照编号删除指定员工
//5. 修改职工信息：按照编号修改职工个人信息
//6. 查找职工信息：按照职工编号或者姓名进行查找相关人员信息
//7. 按照编号排序：按照职工编号，进行排序，排序规则由用户指定
//8. 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）

#include "workerManager.h"


int main()
{
	//实例化管理者对象
	WorkManager root;

	int command = 0;
	while (true)
	{
		//调用展示菜单的成员函数
		root.ShowMenu();
		cout << "请您输入管理员选项：" << endl;
		cin >> command;

		switch (command)
		{
			case 0://退出系统
				root.ExitSystem();
				break;
			case 1://添加职工
				root.Add_Emp();
				break;
			case 2://显示职工
				root.Show_Emp();
				break;
			case 3://删除职工
				root.Del_Emp();
				break;
			case 4://修改职工
				root.Mod_Emp();
				break;
			case 5://查找职工
				root.Find_Emp();
				break;
			case 6://排序职工
				root.Sort_Emp();
				break;
			case 7://清空文件
				root.Clean_File();
				break;
		
			default:
				system("cls");
				break;
		}
	}
	system("pause");
	return 0;
}
