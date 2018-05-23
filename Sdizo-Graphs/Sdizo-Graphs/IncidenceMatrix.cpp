#include "stdafx.h"
#include "IncidenceMatrix.h"


IncidenceMatrix::IncidenceMatrix()
{
	int start, end, weight;
	loadFromFile();
	list = new Edge *[V];
	for (int i = 0; i < V; i++)
		addVertex(i);
	for (int i = 0; i < E; i++)
	{

		file >> start;
		file >> end;
		file >> weight;
		addEdge(start, end, weight,i);

	}
}


IncidenceMatrix::~IncidenceMatrix()
{
	for (int i = 0; i < V; i++) delete[] list[i];
	delete[] list;
}

void IncidenceMatrix::addVertex(int i)
{
	list[i] = new Edge[E];
	
}

void IncidenceMatrix::addEdge(int start, int end, int cost, int number) {
	list[start][number].cost = 5;
}

void IncidenceMatrix::print()
{
}

void IncidenceMatrix::changeRep()
{
}
