#include "stdafx.h"
#include "MainMenu.h"


MainMenu::MainMenu()
{
	structure = AdjList;
	W = 10;
	G = 25; // %
	graph = new AdjacencyList(W,G);
}


MainMenu::~MainMenu()
{
}



int MainMenu::choice()
{
	int choice;
#undef max
	while (!(std::cin >> choice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	return choice;
}
