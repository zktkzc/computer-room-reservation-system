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
