#include "stdafx.h"
#include "EdgeHeap.h"


EdgeHeap::EdgeHeap(int edges)
{
	heap = new Edge[edges];
	maxSize = edges;
	heapSize = 0;
}


EdgeHeap::~EdgeHeap()
{
}

void EdgeHeap::push(Edge edge)
{
	if (heapSize == maxSize)
	{
		std::cout << "ERROR TO MANY EDGES\n";
		return;
	}
	else
	{
		heapSize++;
		int i = heapSize - 1;
		heap[i] = edge;


		while (i != 0 && heap[parent(i)].cost > heap[i].cost)
		{
			Edge temp = heap[parent(i)];
			heap[parent(i)] = heap[i];
			heap[i] = temp;
			i = parent(i);
		}
	}
}

Edge EdgeHeap::pop()
{
	if (heapSize <= 0)
		return heap[0];
		if (heapSize == 1)
		{
			heapSize--;
			return heap[0];
		}

		// Store the minimum value, and remove it from heap
		Edge root = heap[0];
		heap[0] = heap[heapSize - 1];
		heapSize--;
		heapify(0);

		return root;
}


void EdgeHeap::swap(Edge x, Edge y)
{
	Edge temp = x;
	x = y;
	y = temp;
}

void EdgeHeap::heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heapSize && heap[l].cost < heap[i].cost)
		smallest = l;
	if (r < heapSize && heap[r].cost < heap[smallest].cost)
		smallest = r;
	if (smallest != i)
	{
		swap(heap[i], heap[smallest]);
		heapify(smallest);
	}
}

void EdgeHeap::printHeap()
{
	std::cout << "n :";
	for (int i = 0; i < heapSize; i++)
		std::cout << heap[i].number << " ";
	std::cout << "\nk :";
	for (int i = 0; i < heapSize; i++)
		std::cout << heap[i].cost << " ";
	std::cout << std::endl;
}

bool EdgeHeap::heapCheck()
{
	int pCost = 0;
	int i = 0;
	while (i < heapSize) {
		pCost = heap[parent(i)].cost;
		if (heap[i].cost >= pCost)
			i++;
		else return false;
	}
		return true;
}
