#include "dijkstra.h"



constexpr auto infinity = 2147483647;

void dijkstra(Graph_Matrix* graph, int startVertex, int size)
{
	int* distance = new int[size];
	bool* visited = new bool[size];
	for (int i = 0; i <= size; i++)
	{
		visited[i] = 0;
		distance[i] = infinity;
	}
	distance[startVertex] = 0;


	for (int j = 0; j < graph->edges; j++)
	{
		visited[startVertex] = 1;
		for (int i = 0; i < size; i++)
		{
			if ((visited[i] == 0) && graph->areAdjacent(startVertex, i))
			{
				if ((distance[startVertex] + graph->returnWeight(startVertex, i) < distance[i]) || (distance[i] == infinity))
				{
					distance[i] = distance[startVertex] + graph->returnWeight(startVertex, i);
				}
			}
		}
		int smaller = -1;
		int sw = infinity;
		for (int i = 0; i < size; i++)
		{
			if ((visited[i] == 0) && (distance[i] >= 0) && ((sw > distance[i])))
			{
				sw = distance[i];
				smaller = i;
			}
		}
		if (smaller != -1)
		{
			startVertex = smaller;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " " << distance[i] << std::endl;
	}
	std::cout << std::endl;
}

void dijkstra(Graph_List *graph, int startVertex, int size)
{
	int* distance = new int[size];
	bool* visited = new bool[size];
	queue* Q = new queue(size);
	qelement* tab = new qelement[size];


	for (int i = 0; i < size; i++)
	{
		if (startVertex != i)
		{
			distance[i] = infinity;
		}
		distance[startVertex] = 0;
		visited[i] = 0;
		Q->push(i, distance[i]);
	}
	while (!(Q->empty()))
	{
		for (int i = 0; i < size-1; i++)
		{
			tab[i].vertex = -1;
			tab[i].weight = 0;
		}
		qelement u = Q->pop();
		visited[u.vertex] = 1;
		graph->returnNeighbours(tab, u.vertex);
		for(int i=0;i<size-1;i++)
		{
			if ((visited[tab[i].vertex] == 0)&& (tab[i].vertex != -1))
			{
				if ((distance[u.vertex] + tab[i].weight) < distance[tab[i].weight])
				{
					distance[tab[i].weight] = distance[u.vertex] + tab[i].weight;
					Q->replace(tab[i].vertex, distance[tab[i].weight]);
					//Q->heapify();
				}
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " " << distance[i] << std::endl;
	}
	std::cout << std::endl;

}