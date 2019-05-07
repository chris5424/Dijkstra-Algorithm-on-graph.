#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#include "heapsort.hpp"

using namespace std;

// Definicja typu obiektowego queue
//---------------------------------

struct qelement
{
	int weight, vertex;
};

class queue
{
private:
	qelement* T;  // kopiec dynamiczny
	int size;         // liczba elementów

public:
	queue(int max_n);
	~queue();
	bool empty();
	void push(int vertex, int weight);
	qelement pop();
	void replace(int vertex, int newWeight);
	void display();
	void heapify();
};


