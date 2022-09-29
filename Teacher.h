#pragma once
#include "Identity.h"

// 教师类
class Teacher :public Identity
{
public:
	// 默认构造
	Teacher();

	// 有参构造
	Teacher(int empId, string name, string pwd);

	// 菜单界面
	virtual void openMenu();

	// 查看所有预约
	void showOrder();

	// 审核预约
	void validOrder();

private:

	// 职工编号
	int m_EmpId;
};