#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Identity.h"
#include"ComputerRoom.h"
#include"GlobalFile.h"

using namespace std;

// ѧ����
class Student :public Identity
{
public:
	// Ĭ�Ϲ���
	Student();

	// �вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴����ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

	// ѧ��ѧ��
	int m_Id;

	// ��������
	vector<ComputerRoom> vCom;
};

