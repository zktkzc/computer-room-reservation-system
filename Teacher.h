#pragma once
#include<iostream>
#include<vector>
#include "Identity.h"
#include"OrderFile.h"
using namespace std;

// ��ʦ��
class Teacher :public Identity
{
public:
	// Ĭ�Ϲ���
	Teacher();

	// �вι���
	Teacher(int empId, string name, string pwd);

	// �˵�����
	virtual void openMenu();

	// �鿴����ԤԼ
	void showAllOrder();

	// ���ԤԼ
	void validOrder();

	// ְ�����
	int m_EmpId;
};