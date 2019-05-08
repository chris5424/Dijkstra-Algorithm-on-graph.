#pragma once

#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
#include <chrono>
#include <fstream>

#include "graf.h"
#include "dijkstra.h"
#include "additional.h"

void writeResults(double czasG, double czasM, int rozmiar, int gestosc)
{
	std::fstream file;
	file.open("Wyniki.txt", std::ios::out | std::ios::app);
	if (file.good())
	{
		file << "GrafLista " << rozmiar << " " << gestosc << " " << std::setw(16) << czasG << std::endl;
		file << "GrafMacierz " << rozmiar << " " << gestosc << " " << std::setw(16) << czasM << std::endl;
	}
	file.close();
}

void Test(int manyTests, int size, int density)
{
	double *resultsL=new double[manyTests];
	double *resultsM=new double[manyTests];
	double suma_czasowG = 0;
	double suma_czasowM = 0;
	std::fstream graph_file;
	char file_name[20] = "graf.txt";
	std::chrono::duration<double> czas;
	int manyVertices = 0, edges = 0, startVertex = 0;
	int tempVertexStart = 0, tempVertexEnd = 0, tempWeight = 0;

	for (int i = 0; i < manyTests; ++i)
	{
		graph_file.open(file_name, std::ios::in);
		if (graph_file.good() == 0)
		{
			return;
		}

		GenerateGraphRing(size, density);
		graph_file >> edges >> manyVertices >> startVertex;

		Graph_Matrix* graph_matrix = new Graph_Matrix(manyVertices);
		Graph_List* graph_list = new Graph_List(manyVertices);

		graph_list->edges = edges;

		while (!graph_file.eof())
		{
			graph_file >> tempVertexStart >> tempVertexEnd >> tempWeight;
			graph_list->addVertex(tempVertexStart, tempVertexEnd, tempWeight);
			graph_matrix->addVertex(tempVertexStart, tempVertexEnd, tempWeight);
		}
		graph_file.close();


		auto start = std::chrono::system_clock::now();
		dijkstra(graph_list, startVertex, manyVertices);
		auto stop = std::chrono::system_clock::now();
		czas = stop - start;
		resultsL[i] = czas.count();
		suma_czasowG += resultsL[i];

		start = std::chrono::system_clock::now();
		dijkstra(graph_matrix, startVertex, manyVertices);
		stop = std::chrono::system_clock::now();
		czas = stop - start;
		resultsM[i] = czas.count();
		suma_czasowM += resultsM[i];

		std::cout << i<<"/"<<manyTests<<std::endl;
	}
	suma_czasowG /= manyTests;
	suma_czasowM /= manyTests;

	writeResults(suma_czasowG, suma_czasowM, size, density);
	//_endthread();
}

void InicjalizujPlik()
{
	std::fstream file;
	file.open("Wyniki.txt", std::ios::out);
	if (file.good())
	{
		file << "Reprezentacja_Grafu Rozmiar Gestosc Czas_Sredni" << std::endl;
	}
	file.close();
}

