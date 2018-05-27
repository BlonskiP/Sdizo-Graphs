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
		int start, end, weight;
		int  temp;
		file.open("graf.txt");
		if (file.is_open())
		{
			file >> temp;
			V = temp;
			file >> temp;
			E = temp;
			graphArray = new int[2 + (3 * E)];
			graphArray[0] = V;
			graphArray[1] = E;
			
		}
		else {
			std::cout << "Nie moge wczytac pliku" << std::endl;
			return false;
		}
		int n = 2;
		for (int i = 0; i < E; i++)
		{

			file >> start;
			file >> end;
			file >> weight;
			graphArray[n] = start;
			graphArray[n+1] = end;
			graphArray[n+2] = weight;
			n = n + 3;
		}

		file.close();
		return true;
}

void Graph::createEdgeHeap()
{
	heap = new EdgeHeap(E);
}

void Graph::kruskalSolver()
{
	  //  changeToNotDirected();
		kruskal = new KruskalSolver(V, E, this);
	//	kruskal->startingHeap->printEdges();
		kruskal->solve();
		//kruskal->printTree();
	
}

void Graph::primSolver()
{
	//changeToNotDirected();
	prim = new PrimSolver(V, E, this);
	prim->solve();
	//prim->printTree();
}

void Graph::dijSolver()
{
	//changeToDirected();
	dij = new DijkstraSolver(V, E, this);
	dij->solve(0);
	dij->print();
}

void Graph::bellSolver()
{
	//changeToDirected();
	bellman = new Bellman(V, E, this);
	bellman->solve(0);
	bellman->print();
}

void Graph::generate(int W, int E)
{
	delete[] graphArray;
	graphArray = new int[2 + (3 * E)];
	graphArray[0] = W;
	graphArray[1] = E;
	int n = 2;
	int k = 2 + (3 * E);
	for (int i = 0; i < W; i++)
	{
		k = k - n;
		graphArray[n] = i;
		graphArray[n + 1] = rand() % W;
		graphArray[n + 2] = rand() % 10;
		while(graphArray[n] == graphArray[n + 1])graphArray[n+1]=rand() % W;
		graphArray[k+1] = rand() % 10; //Random koszt
		graphArray[k] = i;
		graphArray[k - 1] = rand() % W;
		while (graphArray[k] == graphArray[k-1])graphArray[k - 1] = rand() % W;
		n = n + 3;
	}
	n = 2;
	for (int i = 0; i < E; i++)
	{
		if (graphArray[n] < 0) { graphArray[n] = rand() % W;
		while (graphArray[n] == graphArray[n + 1])graphArray[n] = rand() % W;
		}

		if (graphArray[n + 1] < 0) { graphArray[n + 1] = rand() % W;
		while (graphArray[n] == graphArray[n + 1])graphArray[n+1] = rand() % W;
		}
		n = n + 3;
	}
}

