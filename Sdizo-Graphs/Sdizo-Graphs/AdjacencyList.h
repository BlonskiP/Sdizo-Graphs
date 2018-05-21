#pragma once
#include "Graph.h"
#include <iostream>

class AdjacencyList :
	public Graph
{
public:
	std::fstream file;
	AdjacencyList();
	AdjacencyList(int size, int edge);
	~AdjacencyList();
	Edge **list;
	Edge *p, *r; // Pointery pomocnicze
	void addEdge(int start, int end, int cost);
	void addVertex(int i);
	void print(); //prints
	void changeRep(); //changes representaion
	void setSize(int size) {
		V = size;
	}
	void setEdges(int edge)
	{E = edge; }
	bool loadFromFile();
};


