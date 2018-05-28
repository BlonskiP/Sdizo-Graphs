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
	tmpHeap = new EdgeHeap(1);
}

Bellman::~Bellman()
{
	//std::cout << " DIE BELLMAN";
	delete[] verticlesCost;
	delete[] preVerticle;
	delete tmpHeap;
}

void Bellman::solve(int startVerticle)
{
	int v = startVerticle;
	verticlesCost[v] = 0; //zerowanie kosztu 0
	int heapSize = 0;
	bool changes = true;
	Edge *tmp;
	
	
	while (changes)
	{
		changes = false; //flaga zmian na fa³sz
		tmpHeap->pushHeap(G->getVerticeEdges(v)); // pobierz krawedzie aktualnego	
		heapSize = tmpHeap->heapSize;
		for (int k = 0; k < heapSize; k++) //sprawdz sasiadow	
		{
			tmp = &tmpHeap->pop();
			if (verticlesCost[tmp->to] >(tmp->cost + verticlesCost[tmp->from])) //jezeli koszt do sasiada jest wyzszy to aktualizuj
			{
				verticlesCost[tmp->to] = tmp->cost + verticlesCost[tmp->from];
				preVerticle[tmp->to] = tmp->from;
				changes = true; // jezeli aktualizowales to flaga do gory
			};
		}
		
		for (int i = 1; i < G->V; i++) //pentla po wierzcholkach 
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
	std::cout << "ALGORYTM BELLMANA-FORDA \n";
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
