#include "stdafx.h"
#include "DijkstraSolver.h"

DijkstraSolver::DijkstraSolver(int V, int E, Graph *graf)
{
	G = graf;
	verticlesCost = new int[V];
	verticles = new bool[V];
	preVerticle = new int[V];
	for (int i = 0; i < V; i++) {
		verticlesCost[i] = MAXINT;
		preVerticle[i] = -1;
		verticles[i] = false;
	}

	
}

DijkstraSolver::~DijkstraSolver()
{
}

void DijkstraSolver::solve(int startVerticle)
{
	int v = startVerticle;
	verticles[v] = true; //odwiedzilismy pierwszy wierzcho³ek
	verticlesCost[v] = 0;
	int heapSize = 0;

	Edge *tmp;
	EdgeHeap *tmpHeap;
	tmpHeap = new EdgeHeap(3);

	for (int i = 0; i < G->V-1; i++)
	{
		tmpHeap->pushHeap(G->getVerticeEdges(v));
		heapSize = tmpHeap->heapSize;
		for (int k = 0; k < heapSize; k++)
		{
			tmp = &tmpHeap->heap[k];
			if (verticlesCost[tmp->to] > (tmp->cost + verticlesCost[tmp->from])) {
				if (!verticles[tmp->to]){
					verticlesCost[tmp->to] = tmp->cost + verticlesCost[tmp->from];
					preVerticle[tmp->to] = tmp->from;
				}
			}

		}
		tmp = &tmpHeap->pop();
		v = tmp->to;
		verticles[v] = true;
	}
}

void DijkstraSolver::print()
{
	std::cout << "ALGORYTM DIJKSTRY \n";
	std::cout << "W: ";
	for (int i = 0; i < G->V; i++)
		std::cout << std::setw(3) << i;
	std::cout << std::endl;
	std::cout << "K: ";
	for (int i = 0; i < G->V; i++)
		std::cout << std::setw(3) << verticlesCost[i];
	std::cout << std::endl;
	std::cout << "P: ";
	for (int i = 0; i < G->V; i++)
		std::cout << std::setw(3) << preVerticle[i];
	std::cout << std::endl;
	
}
