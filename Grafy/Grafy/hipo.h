#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

struct qelement
{
	int weight, vertex;
};

class queue_prior
{
private:
	qelement* T;
	int size;       

public:
	queue_prior(int max_n);
	~queue_prior();
	bool isEmpty();
	void push(int vertex, int weight);
	qelement pop();
	void replace(int vertex, int newWeight);
	void display();
	void heapify();
};


