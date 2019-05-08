#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

// Definicja typu obiektowego queue_prior
//---------------------------------

struct qelement
{
	int weight, vertex;
};

class queue_prior
{
private:
	qelement* T;  // kopiec dynamiczny
	int size;         // trip elementów

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


