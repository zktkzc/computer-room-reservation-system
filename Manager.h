#pragma once
#include<iostream>
#include "Identity.h"
using namespace std;

// ����Ա��
class Manager :public Identity
{
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
	void clearFile();

};

