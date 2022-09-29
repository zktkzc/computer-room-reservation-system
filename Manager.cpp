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

	// 初始化容器，并获取到所有学生、老师的信息
	this->initVector();
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
	// 重复错误提示
	string errorTip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// 添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入！";
	}
	else
	{
		// 添加老师
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工编号重复，请重新输入！";
	}

	ofs.open(fileName, ios::out | ios::app); // 利用追加的方式写文件

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool res = this->checkRepeat(id, select);
		if (res)
		{
			// 有重复
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	// 开始向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	ofs.close();

	// 初始化就容器
	this->initVector();

	system("pause");
	system("cls");
}

void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << " 用户名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工编号：" << t.m_EmpId << " 用户名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

// 查看账号
void Manager::showPerson()
{
	cout << "请选择要查看的内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有教师" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有教师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::showComputer()
{
}

// 清空所有预约记录
void Manager::cleanFile()
{
}

// 初始化容器
void Manager::initVector()
{
	// 清空容器
	this->vStu.clear();
	this->vTea.clear();

	// 读取学生信息
	ifstream ifs(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	cout << "当前的学生数量为：" << this->vStu.size() << endl;
	ifs.close();

	// 读取教师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	cout << "当前的教师数量为：" << this->vTea.size() << endl;
	ifs.close();
}

// 检测重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		// 检测学生
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		// 检测教师
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
