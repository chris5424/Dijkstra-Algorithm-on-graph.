#include <iostream>
#include <windows.h>

#include "graf.h"
#include "additional.h"
#include "dijkstra.h"


int main()
{

	//kolorki
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
	//koniec kolorków

	int manyVertices = 0, edges=0, startVertex=0;
	int tempVertexStart = 0, tempVertexEnd = 0, tempWeight = 0;

	std::fstream graph_file;
	char file_name[20] = "graf.txt";
	graph_file.open(file_name, std::ios::in);
	if (graph_file.good() == 0)
	{
		return 0;
	}

	GenerateGraphRing(10, 50);
	graph_file >> edges >> manyVertices >> startVertex;
	Graph_Matrix *graphm = new Graph_Matrix(manyVertices);
	Graph_List* graph = new Graph_List(manyVertices);
	graph->edges = edges;
		
	while (!graph_file.eof())
	{
		graph_file >> tempVertexStart >> tempVertexEnd >> tempWeight;
		graph->addVertex(tempVertexStart, tempVertexEnd, tempWeight);
		graphm->addVertex(tempVertexStart, tempVertexEnd, tempWeight);
	}
	graph_file.close();
	//graph->display();

	std::cout << "\n";

	/*trip t;
	t.add(1);
	t.add(2);
	t.add(3);
	while(!(t.isEmpty()))
	{ 
		std::cout << t.remove();
	}*/
	
	//qelement* tab = new qelement[manyVertices];
	//graph->returnNeighbours(tab,2);
	/*for (int i = 0; i < manyVertices-1; i++)
	{
		std::cout << tab[i].vertex<<"#"<< tab[i].weight<<" ";
	}*/
	dijkstra(graph,startVertex,manyVertices);
	//dijkstra(graphm, startVertex, manyVertices);

	//queue_prior Q(10);   // kolejka 10-cio elementowa
	//int i, p, v;

	//srand(time(NULL));

	//for (i = 0; i < 10; i++)
	//{
	//	v = rand() % 10;
	//	p = rand() % 10;
	//	std::cout << v << ":" << p << endl;
	//	Q.push(v, p);
	//}

	//cout << "----\n";
	//Q.replace(1, 2308);

	/*while (!Q.isEmpty())
	{
		qelement t = Q.pop();
		cout << t.vertex << ":" << t.weight << endl;
	}*/
	/*Q.display();
	Q.heapify();
	std::cout << std::endl;*/
	//Q.display();
	/*std::cout << std::endl;
	while (!Q.isEmpty())
	{
		qelement t = Q.pop();
		cout << t.vertex << ":" << t.weight << endl;
	}
*/
	system("pause");
	return 1;
}