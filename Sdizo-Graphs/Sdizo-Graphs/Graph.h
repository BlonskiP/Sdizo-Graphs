#pragma once
#include <fstream>
struct Edge
{ public:
	Edge(int f, int t, int c)
	{
		from = f;
		to = t;
		cost = c;
	}
	unsigned int number;
	int cost;
	int from;
	int to;
	Edge *next;
};

class Graph
{
public:

	
	int V = 0;
	int E = 0;
	Graph();
	virtual ~Graph();
	virtual void addEdge(int start, int end, int cost) = 0;
	virtual void addVertex(int i) = 0;
	virtual void print() = 0; //prints
	virtual void changeRep() = 0; //changes representaion
	virtual void setSize(int size) = 0;
	virtual void setEdges(int edge) = 0;
	int GetV() {
		return V;
	};
	int GetE() {
		return E;
	}
	virtual bool loadFromFile()=0;
};

