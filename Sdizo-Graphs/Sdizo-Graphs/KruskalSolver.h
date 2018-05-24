#pragma once
#include "EdgeHeap.h"

class KruskalSolver
{
public:
	unsigned short int maxEdges;
	unsigned short int edges;
	EdgeHeap * startingHeap;
	EdgeHeap * endHeap;
	Edge *tmp;
	KruskalSolver(int V, int E, EdgeHeap *start);
	~KruskalSolver();
	void solve();
	
};

