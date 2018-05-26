// Sdizo-Graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include <stdlib.h>

int main()
{
	Graph * pointer;
	//pointer = new IncidenceMatrix();
	pointer = new AdjacencyList(true);
	pointer->print();
	std::cout << " E: " << pointer->E << " V: " << pointer->V << std::endl;
	//pointer->print();
	//pointer->kruskalSolver();
	//pointer->primSolver();
	//pointer->dijSolver();
	pointer->bellSolver();
	system("PAUSE");
    return 0;
}

