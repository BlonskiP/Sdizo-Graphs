#include "stdafx.h"
#include "KruskalSolver.h"


KruskalSolver::KruskalSolver(int V, int E, EdgeHeap *start)
{
	maxEdges = V-1;
	edges = E;
	startingHeap = start;
	endHeap = new EdgeHeap(maxEdges);
}
KruskalSolver::~KruskalSolver()
{
}

void KruskalSolver::solve()
{
}
