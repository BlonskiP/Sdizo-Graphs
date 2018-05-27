#pragma once
#include "Graph.h"
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"
#include <iostream>
using namespace std;
class MainMenu
{
public:
	int W; //wierzcholki
	int G; //gestosc
	enum structureGraph {
		AdjList, InciMatrix
	}structure;
	Graph *graph;
	int GivenChoice;
	MainMenu();
	~MainMenu();
	//Menus
	void start();
	int choice();
};

