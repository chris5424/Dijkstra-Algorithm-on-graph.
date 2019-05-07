#include <iostream>
#include <assert.h>

#include "graf.h"


void Graph_Matrix::display()
{
	for (int i = 0; i < maxVertex; i++)
	{
		for (int j = 0; j < maxVertex; j++)
		{
			std::cout << adjacencyMatrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void Graph_Matrix::addVertex(int start, int end, int weight)
{
	if ((adjacencyMatrix[start][end] == 0) && (adjacencyMatrix[end][start] == 0))
	{
		adjacencyMatrix[start][end] = weight;
		adjacencyMatrix[end][start] = weight;
		edges++;
	}
}

void Graph_Matrix::removeVertex(int start, int end)
{
	if ((adjacencyMatrix[start][end] > 0) && (adjacencyMatrix[end][start] > 0))
	{
		adjacencyMatrix[start][end] = 0;
		adjacencyMatrix[end][start] = 0;
		edges--;
	}
}

bool Graph_Matrix::areAdjacent(int startVertex, int endVertex)
{
	if ((adjacencyMatrix[startVertex][endVertex] > 0) || (adjacencyMatrix[endVertex][startVertex] > 0))
	{
		return 1;
	}
	else
		return 0;
}

int Graph_Matrix::returnWeight(int startVertex, int endVertex)
{
	return adjacencyMatrix[startVertex][endVertex];
}

void Graph_List::addVertex(int start, int end, int weight)
{
	//if ((List[start].find(List->first, end) != end) && (List[start].find(List->first, start) != start))
	//if (List[start].find(List->first, end) == end)
	//{
	//if (!(List[start].areAdjacent(List->first, end)) && !(List[start].areAdjacent(List->first, end)))

	if (List[start].first == NULL)
	{
		List[start].addV(end, weight);
		List[end].addV(start, weight);
		std::cout <<"Dodajemy glowe\n";
	}

	else if ((List[start].areAdjacent(end) == 0)&& (List[end].areAdjacent(start) == 0))
	{
		List[start].addV(end, weight);
		List[end].addV(start, weight);
	}
	else
	{
		return;
	}
}

void Graph_List::display()
{
	for (int i = 0; i < maxvertex; i++)
	{
		std::cout << i << " ";
		List[i].disp();
		std::cout << "\n";
	}
}

void Graph_List::returnNeighbours(qelement tab[], int vertex, int size)
{
	List[vertex].neighbours(tab,size);
}

