#include <iostream>
#include <windows.h>

#include "graf.h"
#include "additional.h"
#include "dijkstra.h"
#include "heap.h"

int main()
{

	//kolorki
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
	//koniec kolorków

	int manyVertices = 0;
	int edges;
	int startVertex;

	std::fstream graph;
	char file_name[20] = "graf.txt";

	graph.open(file_name, std::ios::in);

	if (graph.good() == 0)
	{
		return 0;
	}

	graph >> edges >> manyVertices;
	
	Graph_Matrix *graf = new Graph_Matrix(manyVertices);
	
	graf->edges = edges;
	graph >> startVertex;
	//GenerateGraph(50, 100);
	GenerateGraphRing(50, 10);

	
	int tempVertexStart = 0, tempVertexEnd = 0, tempWeight = 0;
	
	while (!graph.eof())
	{
		graph >> tempVertexStart >> tempVertexEnd >> tempWeight;
		graf->addVertex(tempVertexStart, tempVertexEnd, tempWeight);
	}
	//graf->display();
	graph.close();

	dijkstra(graf,startVertex,manyVertices);


	system("pause");
	return 1;
}