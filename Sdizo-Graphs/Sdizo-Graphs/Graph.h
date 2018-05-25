#pragma once

#ifndef GRAPH_H
#define GRAPH_H
#include "KruskalSolver.h"
#include "EdgeHeap.h"
#include <fstream>
#include <iostream>
#include <iomanip>


class KruskalSolver;
class Graph
{
public:
	std::fstream file;
	Edge * *list;
	EdgeHeap * heap;
	Edge *p, *r; // Pointery pomocnicze
	KruskalSolver *kruskal;
	int V = 0;
	int E = 0;
	Graph();
	virtual ~Graph();
	virtual void addEdge(int start, int end, int cost, int number) = 0;
	virtual void addVertex(int i) = 0;
	virtual void print() = 0; //prints
	virtual void changeRep() = 0; //changes representaion
	bool loadFromFile();
	void setSize(int size) {
		V = size;
	}
	void setEdges(int edge)
	{
		E = edge;
	}
	void createEdgeHeap();
	virtual void fillEdgeHeap() = 0;
	void kruskalSolver();
	virtual EdgeHeap* getVerticeEdges(int verticle) = 0;
};
#endif
