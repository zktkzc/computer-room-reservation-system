#pragma once
#include<iostream>
#include "Identity.h"
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
	void showOrder();

	// ���ԤԼ
	void validOrder();

private:

	// ְ�����
	int m_EmpId;
};