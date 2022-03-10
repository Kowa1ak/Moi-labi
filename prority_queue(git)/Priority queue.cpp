#include <iostream>
#include "Queue.h"
#include "QueueItem.h"

using namespace std;

int Menu(); //меню
Queue CreateExample(); //создаёт очередь для примера

int main()
{
	while (true)
	{
		switch (Menu())
		{
		case 1:
		{
			cout << "\n The constructor with no parameters creates an empty queue q0.\n";
			Queue q0;
			cout << "Let's create queue q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Copy constructor: create queue q2(q1):\n";
			Queue q2(q1);
			cout << q2;
			cout << "Move constructor: create queue q3:\n";
			Queue q3 = CreateExample();
			cout << q3;
			break;
		}
		case 2:
		{
			cout << "\nLet's create queue q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Copy assignment operator: create a queue q2=q1:\n";
			Queue q2 = q1;
			cout << q2;
			cout << "Move assignment operator: create queue q3:\n";
			Queue q3;
			q3 = CreateExample();
			cout << q3;
			break;
		}
		case 3:
		{
			cout << "\nLet's create queue q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Total number of items in the queue:" << q1.getSize() << "\n";
			break;
		}
		case 4:
		{
			cout << "\nLet's create queue q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Number of queue elements\n"
				<< "with high (3) priority:" << q1.getCount(3) << "\n"
				<< "with medium (2) priority:" << q1.getCount(2) << "\n"
				<< "with low (1) priority:" << q1.getCount(1) << "\n";
			break;
		}
		case 5:
		{
			cout << "\nUsing the constructor without parameters, we create the queue q0, as well as the queue q1:\n";
			Queue q0, q1 = CreateExample();
			cout << q1;
			if (q0.isEmpty())
				cout << "Queue q0 is empty.\n";
			else
				cout << "Queue q0 is not empty.\n";
			if (q1.isEmpty())
				cout << "Queue q1 is empty.\n";
			else
				cout << "Queue q1 is not empty.\n";
			break;
		}
		case 6:
		{
			cout << "\nLet's create queue q1:\n";
			Queue q1 = CreateExample();
			cout << q1;
			cout << "Add elements to it with the following values ​​and priorities:\n"
				<< "77 medium (2)\n"
				<< "55 tall (3)\n"
				<< "66 low (1)\n";
			q1.push(77, 2);
			q1.push(55, 3);
			q1.push(66, 1);
			cout << "Now the queue looks like this:\n";
			cout << q1;
			break;
		}
		case 7:
		{
			try
			{
				cout << "\nLet's create queue q1:\n";
				Queue q1 = CreateExample();
				cout << q1;
				cout << "Let's remove 2 elements from the queue.\n";
				q1.pop();
				q1.pop();
				cout << "Now the queue looks like this:\n";
				cout << q1;
				cout << "When trying to remove an element from an empty queue q0, an exception is thrown:\n";
				Queue q0;
				q0.pop();
			}
			catch (const exception& exception)
			{
				cout << exception.what();
			}
			break;
		}
		case 8:
		{
			try
			{
				cout << "\nLet's create queue q1:\n";
				Queue q1 = CreateExample();
				cout << q1;
				cout << "Information about the element at the head of the queue:\n" << q1.getHeadInfo();
				cout << "\nIf the queue is empty, then an exception is thrown:\n";
				Queue q0;
				q0.getHeadInfo();
			}
			catch (const exception& exception)
			{
				cout << exception.what();
			}
			break;
		}
		case 0:
			return 0;
		}
		cout << endl;
	}
}

int Menu()
{
	int choose;

	do
	{
		cout << "Select an operation:\n";
		cout << "1 - an example of the work of constructors without parameters, copying and moving\n";
		cout << "2 - an example of the copy and move assignment operators\n";
		cout << "3 - determining the total number of elements in the queue\n";
		cout << "4 - determining the number of elements in the queue that have a specific priority\n";
		cout << "5 - check for empty queue\n";
		cout << "6 - insert element with value and priority\n";
		cout << "7 - remove an element from the queue\n";
		cout << "8 - output information about the priority and value of the element at the head of the queue\n";
		cout << "0 - exit\n";
		cin >> choose;
	} while (choose > 8 || choose < 0);

	return choose;
}

Queue CreateExample()
{
	Queue queue;
	queue.push(11, 2);
	queue.push(22, 1);
	queue.push(33, 3);
	queue.push(44, 1);

	return queue;
}
