#include "Manager.h"

// 默认构造
Manager::Manager()
{
}

// 有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}

// 菜单界面
void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型：" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加教师" << endl;

	// 操作的文件名
	string fileName;
	// 提示id号
	string tip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// 添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
	}
	else
	{
		// 添加老师
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
	}

	ofs.open(fileName, ios::out | ios::app); // 利用追加的方式写文件

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	cin >> id;
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 开始向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	ofs.close();
	system("pause");
	system("cls");
}

// 查看账号
void Manager::showPerson()
{
}

// 查看机房信息
void Manager::showComputer()
{
}

// 清空所有预约记录
void Manager::cleanFile()
{
}
