#include "Manager.h"

// Ĭ�Ϲ���
Manager::Manager()
{
}

// �вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	// ��ʼ������������ȡ������ѧ������ʦ����Ϣ
	this->initVector();
}

// �˵�����
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

// ����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2����ӽ�ʦ" << endl;

	// �������ļ���
	string fileName;
	// ��ʾid��
	string tip;
	// �ظ�������ʾ
	string errorTip;

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else
	{
		// �����ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ������ظ������������룡";
	}

	ofs.open(fileName, ios::out | ios::app); // ����׷�ӵķ�ʽд�ļ�

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
			// ���ظ�
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	// ��ʼ���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	ofs.close();

	// ��ʼ��������
	this->initVector();

	system("pause");
	system("cls");
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " �û�����" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ����ţ�" << t.m_EmpId << " �û�����" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}

// �鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��Ҫ�鿴�����ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;

	int select;
	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}

// �鿴������Ϣ
void Manager::showComputer()
{
}

// �������ԤԼ��¼
void Manager::cleanFile()
{
}

// ��ʼ������
void Manager::initVector()
{
	// �������
	this->vStu.clear();
	this->vTea.clear();

	// ��ȡѧ����Ϣ
	ifstream ifs(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	cout << "��ǰ��ѧ������Ϊ��" << this->vStu.size() << endl;
	ifs.close();

	// ��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	cout << "��ǰ�Ľ�ʦ����Ϊ��" << this->vTea.size() << endl;
	ifs.close();
}

// ����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		// ���ѧ��
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
		// ����ʦ
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
