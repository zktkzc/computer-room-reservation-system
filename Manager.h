#pragma once
#include<iostream>
#include<string>
#include "Identity.h"
using namespace std;

// 管理员类
class Manager :public Identity
{
public:
	// 默认构造
	Manager();

	// 有参构造
	Manager(string name, string pwd);

	// 菜单界面
	virtual void openMenu();

	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputer();

	// 清空所有预约记录
	void cleanFile();

};

