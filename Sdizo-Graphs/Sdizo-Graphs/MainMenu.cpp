#include "stdafx.h"
#include "MainMenu.h"

//TIME COUNT

MainMenu::MainMenu()
{
	structure = InciMatrix;
	W = 20;
	E = E = (int)(0.25 * (W*(W - 1)));// %
	if (structure == AdjList)
		graph = new AdjacencyList(true);
	else
		graph = new IncidenceMatrix(true);
	measureType = treeM;
	
	graph->changeDir();
}


MainMenu::~MainMenu()
{
	delete graph;

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
	graph->kruskal=new KruskalSolver(graph->V,graph->E,graph);
	graph->prim = new PrimSolver(graph->V, graph->E, graph);
	graph->directed = false;
	graph->changeDir();
	graph->kruskalSolver();
	graph->kruskal->printTree();
	delete graph->kruskal;
	graph->primSolver();
	graph->prim->printTree();
	delete graph->prim;
}
void MainMenu::path()
{
	
	graph->dij = new DijkstraSolver(graph->V, graph->E, graph);
	graph->bellman = new Bellman(graph->V, graph->E, graph);
	graph->directed =true;
	graph->changeDir();
	graph->dijSolver();
	graph->dij->print();
	graph->bellSolver();
	graph->bellman->print();
	
	delete graph->dij;
	delete graph->bellman;
}
void MainMenu::clearAndPause() {
	

}
void MainMenu::clear() {
	system("cls");

}

void MainMenu::countAll()
{
	
	W = 10;  E = (int)(0.25 * (W*(W - 1))); // 25%
	count(AdjList, W, E);
	W = 100; E = (int)(0.25 * (W*(W - 1))); // 25%
	count(AdjList, W, E);
	W = 150; E = (int)(0.25 * (W*(W - 1))); // 25%
	count(AdjList, W, E);
	W = 200; E = (int)(0.25 * (W*(W - 1))); // 25%
	count(AdjList, W, E);
	W = 250; E = (int)(0.25 * (W*(W - 1))); // 25%
	count(AdjList, W, E);
}

void MainMenu::count(structureGraph type, int verticles, int edges)
{
	W = verticles;
	E = edges;
	reloadStructure();
	if (type == AdjList) cout << "Lista sasiedzctwa" << endl; 
	else cout << "Macierz incydencji" << endl;

	cout << "Gest " << " W "<<   setw(5) << "KRUSKAL" << setw(10) << "PRIM" << setw(10) << "DIJ" << setw(10) << "BELL" << endl;
	cout << (double)verticles / (double)edges << "||" << W << "||" << setw(5);
	measureType = treeM;
	measure(&MainMenu::kruskal);
	cout << measurement << "[us] ||" << setw(10);
	measure(&MainMenu::prim);
	cout << measurement << "[us] ||" << setw(10);
	measureType = pathM;
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
	measureTab = new int[100];
	for (int i = 0; i < 100; i++)
	{
		
		graph = new AdjacencyList(false);
		
		if (measureType = treeM)graph->directed = false;
		else graph->directed = true;
		graph->generate(W,E);
		measureTab[i] = timeCount(function);
		
		
	}
	countMeasure();
	delete[] measureTab;
	
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
	(this->*function)();
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

void MainMenu::reloadStructure()
{	delete graph;
	if (structure == AdjList)
		graph = new AdjacencyList(true);
	else
		graph = new IncidenceMatrix(true);
}
