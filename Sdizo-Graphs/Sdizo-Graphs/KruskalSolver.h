#pragma once
#include "EdgeHeap.h"
#include "Graph.h"
struct Node //element zbioru
{
	int up, rank;
};
struct NodeFamily
{	public:
	Node *nodePointer;
	NodeFamily(int x); // tworzy strukture ze zbiorami konstruktor
	void makeSet(int x); // tworzy  zbior
	int findSet(int x);
	void unionSet(Edge x);
};
class KruskalSolver
{
public:
	unsigned short int maxEdges;
	unsigned short int edges;
	EdgeHeap * startingHeap;
	EdgeHeap * endHeap;
	NodeFamily * nodes;
	Edge *tmp;
	KruskalSolver(int V, int E, Graph *start);
	~KruskalSolver();
	void solve();
	void printTree();
	
};

