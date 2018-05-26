#include "stdafx.h"
#include "Bellman.h"




Bellman::Bellman(int V, int E, Graph * graf)
{
	G = graf;
	verticlesCost = new int[V];
	preVerticle = new int[V];
	for (int i = 0; i < V; i++) {
		verticlesCost[i] = MAXINT;
		preVerticle[i] = -1;
	}

}

Bellman::~Bellman()
{
}

void Bellman::solve(int startVerticle)
{
	int v = startVerticle;
	verticlesCost[v] = 0;
	int heapSize = 0;
	bool changes = true;
	Edge *tmp;
	EdgeHeap *tmpHeap;
	tmpHeap = new EdgeHeap(1);
	while (changes)
	{
		changes = false;
		tmpHeap->pushHeap(G->getVerticeEdges(v));
		heapSize = tmpHeap->heapSize;
		for (int k = 0; k < heapSize; k++)
		{
			tmp = &tmpHeap->pop();
			if (verticlesCost[tmp->to] >(tmp->cost + verticlesCost[tmp->from]))
			{
				verticlesCost[tmp->to] = tmp->cost + verticlesCost[tmp->from];
				preVerticle[tmp->to] = tmp->from;
				changes = true;
			};
		}
		
		for (int i = 1; i < G->V; i++)
		{
		tmpHeap->pushHeap(G->getVerticeEdges(i));
		heapSize = tmpHeap->heapSize;
		for (int k = 0; k < heapSize; k++)
		{
			tmp = &tmpHeap->pop();
			if(verticlesCost[tmp->from]!=MAXINT)
			if (verticlesCost[tmp->to] > (tmp->cost + verticlesCost[tmp->from])) 
			{
				verticlesCost[tmp->to] = tmp->cost + verticlesCost[tmp->from];
				preVerticle[tmp->to] = tmp->from;
				changes = true;
			};
		}


		}

	}
	for (int x = 0; x <G-> V; x++)
	{
		tmpHeap->pushHeap(G->getVerticeEdges(x));
		heapSize = tmpHeap->heapSize;
		for (int k = 0; k < heapSize; k++)
		{
			tmp = &tmpHeap->pop();
			if (verticlesCost[tmp->to] > verticlesCost[tmp->from] + tmp->cost)
			{
				std::cout << "Negatywny cykl" << std::endl;
			}
		}


	}
}

void Bellman::print()
{
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