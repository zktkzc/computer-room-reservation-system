#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;

// ѧ����
class Student :public Identity
{
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
	void cancleOrder();

private:
	// ѧ��ѧ��
	int m_Id;
};

