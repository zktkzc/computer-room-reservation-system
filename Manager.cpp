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

	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		// ���ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
	}
	else
	{
		// �����ʦ
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
	}

	ofs.open(fileName, ios::out | ios::app); // ����׷�ӵķ�ʽд�ļ�

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	cin >> id;
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	// ��ʼ���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	ofs.close();
	system("pause");
	system("cls");
}

// �鿴�˺�
void Manager::showPerson()
{
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
