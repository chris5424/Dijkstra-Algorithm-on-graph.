#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

void GenerateGraph(int manyVertices, int density)
{
	srand(time(NULL));
	int maxVertices = (((density / 100.0)*manyVertices*(manyVertices - 1))*0.5);
	int edges = 0;
	std::fstream graf;
	char file_name[20] = "graf.txt";
	graf.open(file_name, std::ios::trunc|std::ios::out);
	graf.close();

	graf.open(file_name, std::ios::app);

	if (graf.good() == false)
	{
		return;
	}
	graf << maxVertices << " " << manyVertices << " " << 0 << "\n";
	graf << 1 << " " << 0 << " " << (std::rand() % 9) + 1 << "\n";
	for (int i = 2; i < manyVertices; ++i)
	{
		int vertex = std::rand() % (i - 1);
		graf << i << " " << vertex << " " << (std::rand() % 9) + 1 << "\n";
		edges++;
	}
	graf.close();
	graf.open(file_name, std::ios::in | std::ios::app|std::ios::out);
	if (graf.good() == false)
	{
		return;
	}
	std::string first_line;
	getline(graf, first_line);

	int procent;
	for (edges; edges < maxVertices-1; ++edges)
	{
		int tempVertexStart = 0, tempVertexEnd = 0, tempWeight = 0, startVertex = 0, endVertex = 0;
		do
		{
			startVertex = std::rand() % manyVertices;
			endVertex = std::rand() % manyVertices;
		} while (startVertex == endVertex);
		graf.clear();
		graf.seekg(0,std::ios_base::beg);
		getline(graf, first_line);
		do
		{		
			graf >> tempVertexStart >> tempVertexEnd >> tempWeight;
			while (((startVertex == tempVertexStart) && (endVertex == tempVertexEnd)) ||
				((startVertex == tempVertexEnd) && (endVertex == tempVertexStart)) || (startVertex == endVertex))
			{
				startVertex = std::rand() % manyVertices;
				endVertex = std::rand() % manyVertices;
				graf.seekg(0,std::ios_base::beg);
				getline(graf, first_line);
			}
		} while (!graf.eof());
	
		std::cout << "dodajemy\n"<<edges+2<<"/"<<maxVertices;
		
		graf.clear();
		graf.seekp(0, std::ios_base::end);
		graf << startVertex << " " << endVertex << " " << (std::rand() % 9) + 1 << "\n";		
	}
	graf.close();
}

void GenerateGraphRing(int manyVertices, int density)
{
	srand(time(NULL));
	int maxVertices = (((density / 100.0)*manyVertices*(manyVertices - 1))*0.5);
	int IloscKrawedzi = 0;
	std::fstream graph;
	char file_name[20] = "graf.txt";
	graph.open(file_name, std::ios::trunc | std::ios::out);
	graph.close();

	graph.open(file_name, std::ios::app);

	if (graph.good() == 0)
	{
		return;
	}
	graph << maxVertices << " " << manyVertices << " " << 0 << "\n";
	int counter = 0;
	for (int j = 1; j < manyVertices; ++j)
	{
		for (int i = 0; i < manyVertices; ++i)
		{
			graph << i % manyVertices << " " << (i + j) % manyVertices << " " << (std::rand() % 9) + 1 << "\n";
			counter++;
			if (counter == maxVertices)
				break;
		}
		if (counter == maxVertices)
			break;
	}
	graph.close();
}

