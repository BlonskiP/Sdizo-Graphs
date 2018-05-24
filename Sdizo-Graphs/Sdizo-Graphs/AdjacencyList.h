#pragma once
#include "Graph.h"
#include <iostream>

class AdjacencyList :
	public Graph
{
public:
	
	AdjacencyList();
	AdjacencyList(int size, int edge);
	~AdjacencyList();
	void addEdge(int start, int end, int cost, int number);
	void addVertex(int i);
	void print(); //prints
	void changeRep(); //changes representaion
	void fillEdgeHeap();
	void kruskalSolver();
	
};


