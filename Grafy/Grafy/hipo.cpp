#include "hipo.h"

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

void queue::replace(int vertex, int newWeight)
{
	int i = 0;
	while (T[i].vertex != vertex)
	{
		i++;
		if (i == size)
		{
			return;
		}
	}
	T[i].weight = newWeight;
}

// Zapisuje do kolejki wg priorytetu
//----------------------------------
void queue::push(int vertex, int weight)
{
	int i, j;

	i = size++;
	j = (i - 1) / 2;

	while (i > 0 && T[j].weight > weight)
	{
		T[i] = T[j];
		i = j;
		j = (i - 1) / 2;
	}

	T[i].weight = weight;
	T[i].vertex = vertex;
}

// Usuwa z kolejki
//----------------
qelement queue::pop()
{
	qelement pom;
	pom.vertex = T[0].vertex;
	pom.weight = T[0].weight;
	int i, j, vertex, weight;

	if (size--)
	{
		weight = T[size].weight;
		vertex = T[size].vertex;

		i = 0;
		j = 1;

		while (j < size)
		{
			if (j + 1 < size && T[j + 1].weight < T[j].weight) j++;
			if (weight <= T[j].weight) break;
			T[i] = T[j];
			i = j;
			j = 2 * j + 1;
		}

		T[i].weight = weight;
		T[i].vertex = vertex;
	}
	return pom;
}