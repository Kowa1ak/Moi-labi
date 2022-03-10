#pragma once

#include <iostream>
#include "QueueItem.h"

using namespace std;

class Queue
{
private:
	QueueItem* HEAD = NULL;
	QueueItem* last_low_priority_pointer = NULL;
	QueueItem* last_medium_priority_pointer = NULL;
	QueueItem* last_high_priority_pointer = NULL;
	int size = 0;

	QueueItem* CreateNode(int, int);
	void clearQueue();
	Queue& Copy(const Queue&);
	Queue& Move(Queue&&);

public:
	//������������
	Queue(); //��� ����������
	Queue(const Queue&); //�����������
	Queue(Queue&&); //�����������

	//��������� ������������
	Queue& operator = (const Queue&); //����������
	Queue& operator = (Queue&&); //������������

	//����� ��������� � �������
	int getSize(); //����� ����������
	int getCount(int); //������� ���������

	//�������� �� ������� �������
	bool isEmpty();

	//������� �������� �� ��������� � �����������
	void push(int, int);

	//�������� �������� �� �������
	QueueItem* pop();

	//��������� ���������� � ���������� � �������� ��������, �������� � ������ �������
	string getHeadInfo();

	//����� �������
	friend ostream& operator << (ostream&, const Queue&);

	//����������
	~Queue();
};
