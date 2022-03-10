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
	//Конструкторы
	Queue(); //без параметров
	Queue(const Queue&); //копирования
	Queue(Queue&&); //перемещения

	//Операторы присваивания
	Queue& operator = (const Queue&); //копирующий
	Queue& operator = (Queue&&); //перемещающий

	//Число элементов в очереди
	int getSize(); //общее количество
	int getCount(int); //имеющие приоритет

	//Проверка на пустоту очереди
	bool isEmpty();

	//Вставка элемента со значением и приоритетом
	void push(int, int);

	//Удаление элемента из очереди
	QueueItem* pop();

	//Получение информации о приоритете и значении элемента, стоящего в голове очереди
	string getHeadInfo();

	//Вывод очереди
	friend ostream& operator << (ostream&, const Queue&);

	//Деструктор
	~Queue();
};
