#pragma once
#include "Graph.h"
class IncidenceMatrix :
	public Graph
{
public:
	IncidenceMatrix();
	~IncidenceMatrix();
	void addVertex(int i);
	void addEdge(int start, int end, int cost, int number);
	void print(); //prints
	void changeRep(); //changes representaion
	void fillEdgeHeap();
//	void kruskalSolver();
};

