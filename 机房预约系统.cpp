#include<iostream>
#include<fstream>
#include"Identity.h"
#include"GlobalFile.h"
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

	}
	else if (type == 2)
	{
		// ��ʦ�����֤

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