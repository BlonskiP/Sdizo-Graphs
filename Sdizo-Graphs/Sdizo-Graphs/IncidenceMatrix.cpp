#include "stdafx.h"
#include "IncidenceMatrix.h"


IncidenceMatrix::IncidenceMatrix()
{
	int start, end, weight;
	loadFromFile();
	createEdgeHeap();
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
	list[end][number].cost = -cost;
	list[start][number].cost = cost;
	
}

void IncidenceMatrix::print()
{
	int temp;
	std::cout << " ";
	for (int i = 0 ; i < E; i++)
	{
		std::cout << std::setw(2);
		std::cout << i;
	}
	std::cout << std::endl << std::endl;
	for (int i = 0; i < V; i++)
	{
		std::cout << i;
		
		for (int k = 0; k < E; k++)
		{
			temp = list[i][k].cost;
			if (temp < 0)
				std::cout<<std::setw(1);
			else 
				std::cout << std::setw(2);
			std::cout << temp;
		}
		std::cout << std::endl;
	}
	
}

void IncidenceMatrix::changeRep()
{
}

void IncidenceMatrix::fillEdgeHeap()
{
}

void IncidenceMatrix::kruskalSolver()
{
}
