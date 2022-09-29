#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include "Identity.h"
#include"GlobalFile.h"
#include"Student.h"
#include"Teacher.h"
using namespace std;

// ����Ա��
class Manager :public Identity
{
public:
	// Ĭ�Ϲ���
	Manager();

	// �вι���
	Manager(string name, string pwd);

	// �˵�����
	virtual void openMenu();

	// ����˺�
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// �������ԤԼ��¼
	void cleanFile();

	// ��ʼ������
	void initVector();

	// ����ظ�
	bool checkRepeat(int id, int tupe);

	// ѧ������
	vector <Student> vStu;

	// ��ʦ����
	vector<Teacher> vTea;
};

