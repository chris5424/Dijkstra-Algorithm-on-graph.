#pragma once

#include <iostream>
#include <iomanip>
#include <memory>
#include <ctime>
#include <chrono>
#include <fstream>
//#include <process.h>

#include "graf.h"
#include "dijkstra.h"
#include "additional.h"

void ZapiszWyniki(double czasG, double czasM, int rozmiar, int gestosc)
{
	std::fstream plik;
	plik.open("Wyniki.txt", std::ios::out | std::ios::app);
	if (plik.good())
	{
		plik << "GrafLista " << rozmiar << " " << gestosc << " " << std::setw(16) << czasG << std::endl;
		plik << "GrafMacierz " << rozmiar << " " << gestosc << " " << std::setw(16) << czasM << std::endl;
	}
	plik.close();
}

void Test(int iloscTestow, int rozmiar, int gestosc)
{
	double *wynikiG=new double[iloscTestow];//tablica na wyniki sortowan pojedynczych tablic
	double *wynikiM=new double[iloscTestow];//tablica na wyniki sortowan pojedynczych tablic
	double suma_czasowG = 0;
	double suma_czasowM = 0;
	std::fstream graph_file;
	char file_name[20] = "graf.txt";
	std::chrono::duration<double> czas;
	int manyVertices = 0, edges = 0, startVertex = 0;
	int tempVertexStart = 0, tempVertexEnd = 0, tempWeight = 0;

	for (int i = 0; i < iloscTestow; ++i)
	{
		graph_file.open(file_name, std::ios::in);
		if (graph_file.good() == 0)
		{
			return;
		}

		GenerateGraphRing(rozmiar, gestosc);
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
		wynikiG[i] = czas.count();
		suma_czasowG += wynikiG[i];

		start = std::chrono::system_clock::now();
		dijkstra(graph_matrix, startVertex, manyVertices);
		stop = std::chrono::system_clock::now();
		czas = stop - start;
		wynikiM[i] = czas.count();
		suma_czasowM += wynikiM[i];

		std::cout << i<<"/"<<iloscTestow<<std::endl;
	}
	suma_czasowG /= iloscTestow;
	suma_czasowM /= iloscTestow;

	ZapiszWyniki(suma_czasowG, suma_czasowM, rozmiar, gestosc);
	//_endthread();
}

void InicjalizujPlik()
{
	std::fstream plik;
	plik.open("Wyniki.txt", std::ios::out);
	if (plik.good())
	{
		plik << "Reprezentacja_Grafu Rozmiar Gestosc Czas_Sredni" << std::endl;
	}
	plik.close();
}

