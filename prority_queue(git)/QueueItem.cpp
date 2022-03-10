#pragma once

#include <iostream>
#include "QueueItem.h"

using namespace std;

QueueItem::QueueItem(int value, int priority)
{
	this->value = value;
	this->priority = priority;
}

int QueueItem::getValue()
{
	return this->value;
}

int QueueItem::getPriority()
{
	return this->priority;
}

QueueItem* QueueItem::getNextItem()
{
	return this->next;
}

void QueueItem::setValue(int value)
{
	this->value = value;
}

void QueueItem::setPriority(int priority)
{
	this->priority = priority;
}

void QueueItem::setNextItem(QueueItem* item)
{
	this->next = item;
}
