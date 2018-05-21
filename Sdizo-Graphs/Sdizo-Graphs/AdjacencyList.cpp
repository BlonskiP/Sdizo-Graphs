#include "stdafx.h"
#include "AdjacencyList.h"




AdjacencyList::AdjacencyList()
{
	int start, end, weight;
	loadFromFile();
	list = new Edge *[V];
	for (int i = 0; i < V; i++) addVertex(i);
	for (int i = 0; i < E; i++)
	{
		
			file >> start;
			file >> end;
			file >> weight;
			addEdge(start, end, weight);
		
	}
	file.close();
}

AdjacencyList::AdjacencyList(int size, int edge)
{	
	setSize(size);
	setEdges(edge);
	list = new Edge *[V];
	for (int i = 0; i < V; i++) addVertex(i);
	
}

AdjacencyList::~AdjacencyList()
{

	for (int i = 0; i < V; i++)
	{
		p = list[i];
		while (p)
		{
			r = p;
			p = p->next;
			delete r;
		}
	}
	delete[] list;



}


void AdjacencyList::addEdge(int start, int end, int cost)
{
	p = new Edge(start,end,cost);
	p->next = list[start];
	list[start] = p;
	
}

void AdjacencyList::addVertex(int i)
{
	list[i] = nullptr;
}

void AdjacencyList::print()
{
	for (int i = 0; i < V; i++)
	{
		std::cout << "Wierzcholek: " << i << " :" << std::endl;
		p = list[i];
		while (p)
		{
			std::cout << " Waga: " << p->cost << " do " << p->to << std::endl;
			p = p->next;
		}
		std::cout << std::endl;
	}
}

void AdjacencyList::changeRep()
{
}
bool AdjacencyList::loadFromFile()
{
	
	int t1, a;
	file.open("graf.txt");
	if (file.is_open())
	{
		file >> a;
		V = a;
		file >> a;
		E = a;
		return true;
	}
	else {
		std::cout << "Nie moge wczytac pliku" << std::endl;
		return false;
	}
}