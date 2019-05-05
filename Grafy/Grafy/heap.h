#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAXINT = -2147483647;

// Definicja typu obiektowego queue
//---------------------------------

struct qelement
{
	int weight, vertex;
};

class queue
{
private:
	qelement * T;  // kopiec dynamiczny
	int size;         // liczba elementów

public:
	queue(int max_n);
	~queue();
	bool empty();
	int  front();
	int  frontprio();
	void push(int weight, int vertex);
	void pop();
};

// Konstruktor - rezerwuje pamiêæ na kopiec
//-----------------------------------------
queue::queue(int max_n)
{
	T = new qelement[max_n];  // tworzymy tablicê dynamiczn¹
	size = 0;                 // kopiec jest pusty
}

// Destruktor - usuwa tablicê z pamiêci
//-------------------------------------
queue::~queue()
{
	delete[] T;
}

// Sprawdza, czy kolejka jest pusta
//---------------------------------
bool queue::empty()
{
	return !size;
}

// Zwraca pocz¹tek kolejki.
// Wartoœæ specjalna to -MAXINT
//-----------------------------
int queue::front()
{
	return size ? T[0].vertex : -MAXINT;
}

// Zwraca priorytet pierwszego elementu
//-------------------------------------
int queue::frontprio()
{
	return size ? T[0].weight : -MAXINT;
}

// Zapisuje do kolejki wg priorytetu
//----------------------------------
void queue::push(int v, int prio)
{
	int i, j;

	i = size++;
	j = (i - 1) / 2;

	while (i > 0 && T[j].weight < prio)
	{
		T[i] = T[j];
		i = j;
		j = (i - 1) / 2;
	}

	T[i].weight = prio;
	T[i].vertex = v;
}

// Usuwa z kolejki
//----------------
void queue::pop()
{
	int i, j, v, p;

	if (size--)
	{
		p = T[size].weight;
		v = T[size].vertex;

		i = 0;
		j = 1;

		while (j < size)
		{
			if (j + 1 < size && T[j + 1].weight > T[j].weight) j++;
			if (p >= T[j].weight) break;
			T[i] = T[j];
			i = j;
			j = 2 * j + 1;
		}

		T[i].weight = p;
		T[i].vertex = v;
	}
}

//---------------
// Program g³ówny
//---------------

int main()
{
	queue Q(10);   // kolejka 10-cio elementowa
	int i, p, v;

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		v = rand() % 100;
		p = rand() % 10;
		cout << setw(2) << v << ":" << p << endl;
		Q.push(p, v);
	}

	cout << "----\n";

	while (!Q.empty())
	{
		cout << setw(2) << Q.front() << ":" << Q.frontprio() << endl;
		Q.pop();
	}
}