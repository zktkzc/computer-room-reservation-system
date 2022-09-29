#include<iostream>
#include<fstream>
#include"Identity.h"
#include"GlobalFile.h"
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"
using namespace std;

//教师菜单
void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		//教师菜单
		teacher->openMenu();

		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			//查看所有预约
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}

	}
}

//学生菜单
void studentMenu(Identity*& student)
{
	while (true)
	{
		//学生菜单
		student->openMenu();

		Student* stu = (Student*)student;
		int select = 0;

		cin >> select;

		if (select == 1) //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "注销成功!" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

// 进入管理员的子菜单页面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		// 调用管理员子菜单
		manager->openMenu();

		// 将父类指针转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// 添加账号
			man->addPerson();
		}
		else if (select == 2)
		{
			// 查看账号
			man->showPerson();
		}
		else if (select == 3)
		{
			// 查看机房信息
			man->showComputer();
		}
		else if (select == 4)
		{
			// 清空预约
			man->cleanFile();
		}
		else
		{
			// 销毁堆区对象
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void login(string fileName, int type)
{
	// 父类指针，用于指向子类对象
	Identity* person = NULL;

	// 读文件
	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	// 准备接收信息
	int id = 0;
	string name;
	string pwd;

	// 判断身份
	if (type == 1)
	{
		// 学生
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		// 老师
		cout << "请输入您的职工编号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		// 学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			// 与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// 教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			// 与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3)
	{
		// 管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			// 与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				// 进入管理员子菜单界面
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// 接收用户的选择
	int select = 0;

	while (true)
	{

		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:  //学生身份
			login(STUDENT_FILE, select);
			break;
		case 2:  //老师身份
			login(TEACHER_FILE, select);
			break;
		case 3:  //管理员身份
			login(ADMIN_FILE, select);
			break;
		case 0:  //退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}