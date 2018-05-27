#include "stdafx.h"
#include "MainMenu.h"

//TIME COUNT

MainMenu::MainMenu()
{
	structure = AdjList;
	W = 5;
	E = 5; // %
	graph = new AdjacencyList(true);
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

void MainMenu::tree() {
	graph->changeToNotDirected();
	graph->kruskalSolver();
	graph->kruskal->printTree();
	graph->primSolver();
	graph->prim->printTree();
}
void MainMenu::path()
{
	graph->changeToDirected();
	graph->dijSolver();
	graph->bellSolver();
}
void MainMenu::clearAndPause() {
	graph->kruskalSolver();
	graph->primSolver();

}
void MainMenu::clear() {
	system("cls");

}

void MainMenu::countAll()
{
	
	W = 100; E = 25; // 25%
	count(AdjList, W, E);
	W = 1000; E = 250;
	count(AdjList, W, E);
}

void MainMenu::count(structureGraph type, int verticles, int edges)
{
	W = verticles;
	E = edges;
	if (type == AdjList)cout << "Lista sasiedzctwa" << endl;
	else cout << "Macierz incydencji" << endl;
	cout << "Gest " << " W "<<   setw(5) << "KRUSKAL" << setw(10) << "PRIM" << setw(10) << "DIJ" << setw(10) << "BELL" << endl;
	cout << (double)verticles / (double)edges << "||" << W << "||" << setw(5);
	measure(&MainMenu::kruskal);
	cout << measurement << "[us] ||" << setw(10);
	measure(&MainMenu::prim);
	cout << measurement << "[us] ||" << setw(10);
	measure(&MainMenu::dij);
	cout << measurement << "[us] ||" << setw(10);
	measure(&MainMenu::bell);
	cout<< measurement << "[us] ||" << endl;
}

void MainMenu::countMeasure()
{
	measurement = 0;
	for (int i = 0; i < 100; i++) {
		measurement += measureTab[i];
	}
	measurement = measurement / 100;
}

void MainMenu::measure(void(MainMenu::* function)(void))
{
	for (int i = 0; i < 100; i++)
	{
		graph->generate(W,E);
		measureTab[i] = timeCount(function);
		
		
	}
	countMeasure();
}
//Time counting
long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return((long long int)count.QuadPart);
}

double MainMenu::timeCount(void(MainMenu::* function)(void))
{
	double measure = 0;
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = read_QPC();
	function;
	elapsed = read_QPC() - start;
	//	std::cout << "Time [s] = " << std::fixed << std::setprecision(3) << (float)elapsed / frequency << std::endl;
	//	std::cout << "Time [ms] = " << std::setprecision(0) << (1000.0 * elapsed) / frequency << std::endl;
	//	std::cout << "Time [us] = " << std::setprecision(0) << (1000000.0 * elapsed) / frequency << std::endl << std::endl;
	measure = (1000000.0 * elapsed) / frequency;
	return measure;
}

void MainMenu::kruskal()
{
	graph->kruskalSolver();
}

void MainMenu::prim()
{
	graph->primSolver();
}

void MainMenu::dij()
{
	graph->dijSolver();
}

void MainMenu::bell()
{
	graph->bellSolver();
}
