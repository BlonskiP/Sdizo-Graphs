#include "stdafx.h"
#include "Graph.h"


Graph::Graph()
{
	V = 0;
	E = 0;
}


Graph::~Graph()
{
}

bool Graph::loadFromFile()
{

		int  temp;
		file.open("graf.txt");
		if (file.is_open())
		{
			file >> temp;
			V = temp;
			file >> temp;
			E = temp;
			return true;
		}
		else {
			std::cout << "Nie moge wczytac pliku" << std::endl;
			return false;
		}
	
}

void Graph::createEdgeHeap()
{
	heap = new EdgeHeap(E);
}

void Graph::kruskalSolver()
{
	
		kruskal = new KruskalSolver(V, E, this);
		kruskal->startingHeap->printEdges();
		kruskal->solve();
		kruskal->printTree();
	
}

void Graph::primSolver()
{
	prim = new PrimSolver(V, E, this);
	prim->solve();
	prim->printTree();
}

