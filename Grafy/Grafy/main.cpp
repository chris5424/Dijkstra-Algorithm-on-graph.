#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>


#include "graf.h"
#include "additional.h"
#include "dijkstra.h"
#include "test.h"

#define ROZMIAR10 10
#define ROZMIAR30 30
#define ROZMIAR50 50
#define ROZMIAR70 70
#define ROZMIAR100 100
#define ROZMIAR200 200
#define ROZMIAR500 500
#define ROZMIAR1000 1000



int main()
{

	//kolorki
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
	//koniec kolorków

	std::chrono::duration<double> czas_ca³oœci;
	
	InicjalizujPlik();

	auto st = std::chrono::system_clock::now();

	cout << "Gestosc 25% " << endl;
	cout << "Rozmiar10 " << endl;
	//std::thread thd1(Test,100, std::ref(ROZMIAR10), 25);
	Test(100,ROZMIAR10, 25);
	cout << "Rozmiar50 " << endl;
	Test(100, ROZMIAR50, 25);
	cout << "Rozmiar100 " << endl;
	Test(100, ROZMIAR100, 25); 
	cout << "Rozmiar500 " << endl;
	Test(100, ROZMIAR500, 25); 
	cout << "Rozmiar1000 " << endl;
	Test(100, ROZMIAR1000, 25);

	cout << "Gestosc 50% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100, ROZMIAR10, 50);
	cout << "Rozmiar50 " << endl;
	Test(100, ROZMIAR50, 50);
	cout << "Rozmiar100 " << endl;
	Test(100, ROZMIAR100, 50);
	cout << "Rozmiar500 " << endl;
	Test(100, ROZMIAR500, 50);
	cout << "Rozmiar1000 " << endl;
	Test(100, ROZMIAR1000, 50);

	cout << "Gestosc 75% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100, ROZMIAR10, 75);
	cout << "Rozmiar50 " << endl;
	Test(100, ROZMIAR50, 75);
	cout << "Rozmiar100 " << endl;
	Test(100, ROZMIAR100, 75);
	cout << "Rozmiar500 " << endl;
	Test(100, ROZMIAR500, 75);
	cout << "Rozmiar1000 " << endl;
	Test(100, ROZMIAR1000, 75);

	cout << "Gestosc 100% " << endl;
	cout << "Rozmiar10 " << endl;
	Test(100, ROZMIAR10, 100);
	cout << "Rozmiar50 " << endl;
	Test(100, ROZMIAR50, 100);
	cout << "Rozmiar100 " << endl;
	Test(100, ROZMIAR100, 100);
	cout << "Rozmiar500 " << endl;
	Test(100, ROZMIAR500, 100);
	cout << "Rozmiar1000 " << endl;
	Test(100, ROZMIAR1000, 100);

	auto end = std::chrono::system_clock::now();
	czas_ca³oœci = end - st;
	std::cout << czas_ca³oœci.count() << " s" << std::endl;











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