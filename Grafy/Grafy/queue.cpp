#include "queue.h"


void trip::add(int value)
{
	NEW = new trip;
	NEW->value = value;
	if (root == NULL) //dodaj pierwszy element do kolejki
	{
		root = NEW;
		end = NEW;
		NEW->next = NULL;
	}
	size++;
	
}
int trip::remove()
{
	int ret;
	if (end && end == root) //zabierz ostatni element z kolejki
	{
		ret = end->value;
		delete end;
		end = root = NULL;
		size--;
		return ret;
	}
	else if (end) //zabierz element z kolejki
	{
		temp = root;
		while (temp->next != end)
		{
			temp = temp->next;
		}
		ret = end->value;
		delete end;
		end = temp;
		size--;
		return ret;
	}
}

bool trip::isEmpty()
{
	return !size;
}

trip::trip()
{
}

trip::~trip()
{
}
