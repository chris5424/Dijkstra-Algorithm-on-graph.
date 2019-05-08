#pragma once

#include <iostream>

class trip
{
private:
	int value=0, size=0;
	trip* next;
	trip* root = NULL, * NEW = NULL, * end = NULL, * temp = NULL;
public:
	void add(int value);
	int remove();
	bool isEmpty();
};



