#include<iostream>
#include<fstream>
#include"Identity.h"
#include"GlobalFile.h"
#include"Manager.h"
#include"Student.h"
#include"Teacher.h"
using namespace std;

void login(string fileName, int type)
{
	// ����ָ�룬����ָ���������
	Identity* person = NULL;

	// ���ļ�
	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	// ׼��������Ϣ
	int id = 0;
	string name;
	string pwd;

	// �ж����
	if (type == 1)
	{
		// ѧ��
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		// ��ʦ
		cout << "����������ְ����ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		// ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			// ���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 2)
	{
		// ��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			// ���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				return;
			}
		}
	}
	else if (type == 3)
	{
		// ����Ա�����֤

	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}

int main()
{
	// �����û���ѡ��
	int select = 0;

	while (true)
	{

		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select; //�����û�ѡ��

		switch (select)
		{
		case 1:  //ѧ�����
			login(STUDENT_FILE, select);
			break;
		case 2:  //��ʦ���
			login(TEACHER_FILE, select);
			break;
		case 3:  //����Ա���
			login(ADMIN_FILE, select);
			break;
		case 0:  //�˳�ϵͳ
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}