#pragma once

#include <iostream>


class Graph_Matrix
{
private:
	int maxVertex;
	int countVertex = 0;
	int **adjacencyMatrix;


public:
	int edges=0;
	void addVertex(int start, int end, int weight);
	void removeVertex(int start, int end);
	void display();
	bool areAdjacent(int startVertex, int endVertex);
	int returnWeight(int startVertex, int endVertex);
	Graph_Matrix(int maxvertex)
	{
		{
			this->maxVertex = maxvertex;
			adjacencyMatrix = new int *[maxvertex];
			for (int i = 0; i < maxvertex; i++)
			{
				adjacencyMatrix[i] = new int[maxvertex];
			}
			for (int i = 0; i < maxvertex; i++)
			{
				for (int j = 0; j < maxvertex; j++)
				{
					adjacencyMatrix[i][j] = 0;
				}
			}
		}
	}
	~Graph_Matrix()
	{
		for (int i(0); i < maxVertex; ++i)
		{
			delete[] adjacencyMatrix[i];
		}
		delete[] adjacencyMatrix;
		adjacencyMatrix = NULL;
	}
};



class Graph_List
{
private:
	struct V
	{
		V *next;
		int vertex=0;
		int weight=0;
		V()
		{
			next = NULL;
		}
	};

	struct listVertex
	{
		V *first;
		listVertex()
		{
			first = 0;
		}
		void addV(int vertex, int weight)
		{
			V *NEW = new V;
			NEW->vertex = vertex;
			NEW->weight = weight;

			if (first == NULL)
			{
				first = NEW;
			}
			else
			{
				// w przeciwnym wypadku wêdrujemy na koniec listy
				V *temp = first;

				while (temp->next)
				{
					// znajdujemy wskaŸnik na ostatni element
					temp = temp->next;
				}

				temp->next = NEW;  // ostatni element wskazuje na nasz nowy
				NEW->next = 0;     // ostatni nie wskazuje na nic
			}
		}
		void remove_headV()
		{
			V *temp=first;
			if (temp)
			{
				first = temp->next;
				delete temp;
			}
		}
		void removeV(int v)
		{
			V *temp, *rem;
			if (first->vertex == v)
			{
				remove_headV();
			}
			else
			{
				temp = first;
				while (first->vertex != v)
				{
					temp = temp->next;
				}
				rem = temp->next;
				temp->next = temp->next->next;
				delete rem;
			}
		}
		bool areAdjacent(int v)
		{
			V  *finder = first;
			while (finder)
			{
				if (finder->vertex == v)
				{
					std::cout << "juz jest!\n";
					return 1;
				}
				finder = finder->next;
			}
			std::cout << "nie ma, dodajemy\n";
			return 0;
		}
		void disp()
		{
			V *temp = first;
			while (temp)
			{
				std::cout <<" "<< temp->vertex << "#" << temp->weight;
				temp = temp->next;
			}
		}
	};
	int maxvertex;
	listVertex *List;
	

public:
	int edges = 0;
	Graph_List(int maxvertex)
	{
		this->maxvertex = maxvertex;
		List = new listVertex[maxvertex];
	}
	~Graph_List()
	{
		delete[] List;
		List = NULL;
	}
	void addVertex(int start, int end, int weight);
	void display();

};