#pragma once
#include <fstream>
#include <iostream>
struct Edge
{ public:
	Edge(int f, int t, int c)
	{
		from = f;
		to = t;
		cost = c;
	}
	Edge() {};
	unsigned int number;
	int cost;
	int from;
	int to;
	Edge *next;
};

class Graph
{
public:
	std::fstream file;
	Edge * *list;
	Edge *p, *r; // Pointery pomocnicze
	int V = 0;
	int E = 0;
	Graph();
	virtual ~Graph();
	virtual void addEdge(int start, int end, int cost, int number) = 0;
	virtual void addVertex(int i) = 0;
	virtual void print() = 0; //prints
	virtual void changeRep() = 0; //changes representaion
	int GetV() {
		return V;
	};
	int GetE() {
		return E;
	}
	bool loadFromFile();
	void setSize(int size) {
		V = size;
	}
	void setEdges(int edge)
	{
		E = edge;
	}
};

