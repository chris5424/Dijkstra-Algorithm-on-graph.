#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>

#include "graf.h"
#include "additional.h"
#include "dijkstra.h"
#include "test.h"

#define SIZE10 10
#define SIZE50 50
#define SIZE100 100
#define SIZE500 500
#define SIZE1000 1000

using namespace std;

int main()
{

	//kolorki
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
	//koniec kolorków

	std::chrono::duration<double> czas_calosci;
	
	InicjalizujPlik();

	auto st = std::chrono::system_clock::now();

	cout << "Gestosc 25% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100,SIZE10, 25);
	cout << "Rozmiar50 " << endl;
	Test(100, SIZE50, 25);
	cout << "Rozmiar100 " << endl;
	Test(100, SIZE100, 25); 
	cout << "Rozmiar500 " << endl;
	Test(100, SIZE500, 25); 
	cout << "Rozmiar1000 " << endl;
	Test(100, SIZE1000, 25);

	cout << "Gestosc 50% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100, SIZE10, 50);
	cout << "Rozmiar50 " << endl;
	Test(100, SIZE50, 50);
	cout << "Rozmiar100 " << endl;
	Test(100, SIZE100, 50);
	cout << "Rozmiar500 " << endl;
	Test(100, SIZE500, 50);
	cout << "Rozmiar1000 " << endl;
	Test(100, SIZE1000, 50);

	cout << "Gestosc 75% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100, SIZE10, 75);
	cout << "Rozmiar50 " << endl;
	Test(100, SIZE50, 75);
	cout << "Rozmiar100 " << endl;
	Test(100, SIZE100, 75);
	cout << "Rozmiar500 " << endl;
	Test(100, SIZE500, 75);
	cout << "Rozmiar1000 " << endl;
	Test(100, SIZE1000, 75);

	cout << "Gestosc 100% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100, SIZE10, 100);
	cout << "Rozmiar50 " << endl;
	Test(100, SIZE50, 100);
	cout << "Rozmiar100 " << endl;
	Test(100, SIZE100, 100);
	cout << "Rozmiar500 " << endl;
	Test(100, SIZE500, 100);
	cout << "Rozmiar1000 " << endl;
	Test(100, SIZE1000, 100);

	auto end = std::chrono::system_clock::now();
	czas_calosci = end - st;
	std::cout << czas_calosci.count() << " s" << std::endl;











	/*std::chrono::duration<double> czas_lista;
	std::chrono::duration<double> czas_macierz;

	int manyVertices = 0, edges=0, startVertex=0;
	int tempVertexStart = 0, tempVertexEnd = 0, tempWeight = 0;

	std::fstream graph_file;
	char file_name[20] = "graf.txt";
	graph_file.open(file_name, std::ios::in);
	if (graph_file.good() == 0)
	{
		return 0;
	}

	GenerateGraphRing(10, 100);
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

	std::cout << "\n";

	auto start = std::chrono::system_clock::now();
	dijkstra(graph,startVertex,manyVertices);
	auto stop = std::chrono::system_clock::now();
	czas_lista = stop - start;

	start = std::chrono::system_clock::now();
	dijkstra(graphm, startVertex, manyVertices);
	stop = std::chrono::system_clock::now();
	czas_macierz = stop - start;

	std::cout << "Czas Dijkstry na liscie: " << czas_lista.count() << std::endl << "Czas Dijkstry na macierzy: " << czas_macierz.count() << std::endl;*/
	
	system("pause");
	return 1;
}