#include "hipo.h"

// Konstruktor - rezerwuje pami�� na kopiec
//-----------------------------------------
queue::queue(int max_n)
{
	T = new qelement[max_n];  // tworzymy tablic� dynamiczn�
	size = 0;                 // kopiec jest pusty
}

// Destruktor - usuwa tablic� z pami�ci
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

void queue::display()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << T[i].vertex <<":"<<T[i].weight<<std::endl;
	}
}

void queue::heapify()
{
	for (int parentInd = 0; parentInd < size; parentInd++)
	{
		int min = parentInd;
		int leftChild = parentInd * 2 + 1;
		int rightChild = parentInd * 2 + 2;

		if (leftChild < size && T[leftChild].weight < T[min].weight) {
			min = leftChild;
		}
		if (rightChild < size && T[rightChild].weight < T[min].weight) {
			min = rightChild;
		}
		if (min != parentInd)
		{
			qelement temp;
			temp = T[min];
			T[min] = T[parentInd];
			T[parentInd] = temp;
		}
	}
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
