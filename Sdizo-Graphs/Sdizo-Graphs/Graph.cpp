#include "stdafx.h"
#include "Graph.h"


Graph::Graph()
{
	V = 0;
	E = 0;
	graphArray = new int[1];
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
	 
	   
		kruskal = new KruskalSolver(V, E, this);
		kruskal->solve();
		
	
}

void Graph::primSolver()
{
	
	prim = new PrimSolver(V, E, this);
	prim->solve();
	

}

void Graph::dijSolver()
{
	
	
	dij = new DijkstraSolver(V, E, this);
	dij->solve(0);
	
}

void Graph::bellSolver()
{
	
	
	bellman = new Bellman(V, E, this);
	bellman->solve(0);
	
}

void Graph::generate(int W, int E)
{
	for (int i = 0; i < V; i++) delete[] list[i];
	delete[] list;
	
	this->E = E;
	this->V = W;
	list = new Edge *[V];
	for (int i = 0; i < V; i++)
		addVertex(i);
	delete[] graphArray;
	int k = 2 + (3 * E);
	graphArray = new int[2 + (3 * E)];
	graphArray[0] = W;
	graphArray[1] = E;
	int n = 2;
	bool *array = new bool[W];
	for (int i = 0; i < V; i++)
	{
		array[i] = false;
		
	}
	int x = 0;
	int y = rand() % W;
	

	int i = 0;
	array[x] = true;
	while (checkBools(array)) 
	{   if(!array[y])
		if (x != y)
		{
			array[y] = true;
			graphArray[n] = x;
			graphArray[n + 1] = y;
			graphArray[n + 2] = rand() % W;
			n = n + 3;
			i++;
			x = y;
			
		}
	y = rand() % W;
	}

	
	for (;i<E; )
	{
		x = rand() % W;
		y = rand() % W;
		if (x != y)
		{
			graphArray[n] = x;
			graphArray[n + 1] = y;
			graphArray[n + 2] = rand() % (W-1);
			n = n + 3;
			i++;
		}
	}
	
	
	
	
	
	
	
	
	for (int i = 2; i <k; i++)
	{
		//std::cout << graphArray[i] << std::endl;
		if (graphArray[i] > W - 1)graphArray[i] = rand() % 5;
		
	}
	
	changeDir();
}
bool Graph::checkBools(bool * ar)
{
	for (int i = 0; i < V; i++)
	{
		if (ar[i] == false)
			return true;
	}
	return false;
}

void Graph::changeDir()
{
	if (directed == true)changeToDirected();
	else changeToNotDirected();

}

void Graph::printArray()
{
	int k = 2 + (3 * E);
	std::cout << graphArray[0] << " " << graphArray[1] << std::endl;
	for (int i = 2; i <k; i=i+3)
	{
		std::cout << graphArray[i] << " ";
		std::cout << graphArray[i + 1]<< " ";
		std::cout << graphArray[i + 2] << " "<< std::endl;

	}
}



