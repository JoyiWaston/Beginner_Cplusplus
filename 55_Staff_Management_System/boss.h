#pragma once
#include"worker.h"

//�ϰ���
class Boss : public Worker
{
public:
	Boss(int id, string name, int depId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDepInformation();
};