#pragma once

#include <iostream>

using namespace std;

class QueueItem
{
private:
	int value = 0;
	QueueItem* next = NULL;
	int priority = 0;

public:
	QueueItem(int, int);
	int getValue();
	int getPriority();
	QueueItem* getNextItem();
	void setValue(int);
	void setPriority(int);
	void setNextItem(QueueItem*);
};
