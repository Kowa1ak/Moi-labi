#pragma once

#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

Queue::Queue()
{
	HEAD = NULL;
	size = 0;
	last_high_priority_pointer = NULL;
	last_medium_priority_pointer = NULL;
	last_low_priority_pointer = NULL;
}

Queue::Queue(const Queue& queue)
{
	this->Copy(queue);
}

Queue::Queue(Queue&& queue)
{
	this->Move(move(queue));
}

QueueItem* Queue::CreateNode(int value, int priority)
{
	QueueItem* newItem = new QueueItem(value, priority);
	size++;
	newItem->setNextItem(NULL);
	return newItem;
}

void Queue::clearQueue()
{
	QueueItem* cursor = HEAD;
	QueueItem* temp;
	while (cursor != NULL)
	{
		temp = cursor;
		cursor = cursor->getNextItem();
		delete temp;
	}
	HEAD = NULL;
	last_high_priority_pointer = NULL;
	last_medium_priority_pointer = NULL;
	last_low_priority_pointer = NULL;
	size = 0;
}

Queue& Queue::Copy(const Queue& queue)
{
	clearQueue();
	QueueItem* rightCursor = queue.HEAD;
	QueueItem* leftCursor = NULL;
	while (rightCursor != NULL)
	{
		if (HEAD == NULL)
		{
			leftCursor = CreateNode(rightCursor->getValue(), rightCursor->getPriority());
			last_low_priority_pointer = last_medium_priority_pointer = last_high_priority_pointer = HEAD = leftCursor;
		}
		else
		{
			leftCursor->setNextItem(CreateNode(rightCursor->getValue(), rightCursor->getPriority()));
			leftCursor = leftCursor->getNextItem();
		}
		if (rightCursor == queue.last_high_priority_pointer)
			last_high_priority_pointer = leftCursor;
		if (rightCursor == queue.last_medium_priority_pointer)
			last_medium_priority_pointer = leftCursor;
		if (rightCursor == queue.last_low_priority_pointer)
			last_low_priority_pointer = leftCursor;

		rightCursor = rightCursor->getNextItem();
	}

	return *this;
}

Queue& Queue::Move(Queue&& queue)
{
	clearQueue();

	this->HEAD = queue.HEAD;
	queue.HEAD = NULL;

	this->last_high_priority_pointer = queue.last_high_priority_pointer;
	queue.last_high_priority_pointer = NULL;

	this->last_low_priority_pointer = queue.last_low_priority_pointer;
	queue.last_low_priority_pointer = NULL;

	this->last_medium_priority_pointer = queue.last_medium_priority_pointer;
	queue.last_medium_priority_pointer = NULL;

	this->size = queue.size;
	queue.size = 0;

	return *this;
}

Queue& Queue::operator = (const Queue& queue)
{
	if (this == &queue)
		return *this;

	return this->Copy(queue);
}

Queue& Queue::operator = (Queue&& queue)
{
	if (this == &queue)
		return *this;

	return this->Move(move(queue));
}

int Queue::getSize()
{
	return size;
}

int Queue::getCount(int priority)
{
	QueueItem* cursor = NULL;
	int counter = 1;
	if (priority == 1)
	{
		if (last_low_priority_pointer == NULL)
			return 0;
		if (last_medium_priority_pointer != NULL)
		{
			cursor = last_medium_priority_pointer;
			counter--;
		}
		else if (last_medium_priority_pointer == NULL && last_high_priority_pointer != NULL)
		{
			cursor = last_high_priority_pointer;
			counter--;
		}
		else if (last_medium_priority_pointer == NULL && last_high_priority_pointer == NULL)
			cursor = HEAD;

		while (cursor != NULL && cursor != last_low_priority_pointer)
		{
			counter++;
			cursor = cursor->getNextItem();
		}
	}
	else if (priority == 2)
	{
		if (last_medium_priority_pointer == NULL)
			return 0;
		if (last_high_priority_pointer != NULL)
		{
			cursor = last_high_priority_pointer;
			counter--;
		}
		else
			cursor = HEAD;

		while (cursor != NULL && cursor != last_medium_priority_pointer)
		{
			counter++;
			cursor = cursor->getNextItem();
		}
	}
	else if (priority == 3)
	{
		if (last_high_priority_pointer == NULL)
			return 0;
		cursor = HEAD;

		while (cursor != NULL && cursor != last_high_priority_pointer)
		{
			counter++;
			cursor = cursor->getNextItem();
		}
	}

	return counter;
}

bool Queue::isEmpty()
{
	return size == 0;
}

void Queue::push(int value, int priority)
{
	QueueItem* item = CreateNode(value, priority);
	if (HEAD == NULL)
	{
		HEAD = item;
		switch (priority)
		{
		case 1:
			last_low_priority_pointer = item;
			break;
		case 2:
			last_medium_priority_pointer = item;
			break;
		case 3:
			last_high_priority_pointer = item;
			break;
		}
		return;
	}
	if (priority == 1)
	{
		if (last_low_priority_pointer != NULL)
		{
			last_low_priority_pointer->setNextItem(item);
			last_low_priority_pointer = item;
			return;
		}
		if (last_low_priority_pointer == NULL && last_medium_priority_pointer != NULL)
		{
			last_medium_priority_pointer->setNextItem(item);
			last_low_priority_pointer = item;
			return;
		}
		if (last_low_priority_pointer == NULL && last_high_priority_pointer != NULL)
		{
			last_high_priority_pointer->setNextItem(item);
			last_low_priority_pointer = item;
			return;
		}
	}
	if (priority == 2)
	{
		if (last_high_priority_pointer == NULL && last_medium_priority_pointer == NULL)
		{
			item->setNextItem(HEAD);
			last_medium_priority_pointer = HEAD = item;
			return;
		}
		if (last_medium_priority_pointer != NULL)
		{
			QueueItem* tempItem = last_medium_priority_pointer->getNextItem();
			last_medium_priority_pointer->setNextItem(item);
			item->setNextItem(tempItem);
			last_medium_priority_pointer = item;
			return;
		}
	}
	if (priority == 3)
	{
		if (last_high_priority_pointer == NULL && last_medium_priority_pointer == NULL && last_low_priority_pointer == NULL)
		{
			last_high_priority_pointer = HEAD = item;
			return;
		}
		if (last_high_priority_pointer == NULL)
		{
			item->setNextItem(HEAD);
			last_high_priority_pointer = HEAD = item;
			return;
		}
		if (last_high_priority_pointer != NULL)
		{
			QueueItem* tempItem = last_high_priority_pointer->getNextItem();
			last_high_priority_pointer->setNextItem(item);
			item->setNextItem(tempItem);
			last_high_priority_pointer = item;
			return;
		}
	}
}

QueueItem* Queue::pop()
{
	if (HEAD == NULL)
		throw exception("\nDeleting the element is not possible, the queue is empty!\n");

	QueueItem* tempItem = HEAD;
	HEAD = HEAD->getNextItem();

	if (tempItem == last_high_priority_pointer)
		last_high_priority_pointer = NULL;
	if (tempItem == last_medium_priority_pointer)
		last_medium_priority_pointer = NULL;
	if (tempItem == last_low_priority_pointer)
		last_low_priority_pointer = NULL;
	size--;

	return tempItem;
}

string Queue::getHeadInfo()
{
	if (HEAD == NULL)
		throw exception("\nThe queue is empty!\n");

	return "Element value: " + to_string(HEAD->getValue()) + "   Priority: " + to_string(HEAD->getPriority());
}

ostream& operator << (ostream& out, const Queue& queue)
{
	out << "Queue:\n";
	QueueItem* cursor = queue.HEAD;
	while (cursor != NULL)
	{
		out << "Meaning:" << cursor->getValue() << "     Priority: " << cursor->getPriority() << "\n";
		cursor = cursor->getNextItem();
	}
	return out;
}

Queue::~Queue()
{
	clearQueue();
}