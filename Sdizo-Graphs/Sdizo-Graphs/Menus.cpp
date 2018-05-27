#include "stdafx.h"
#include "MainMenu.h"

void MainMenu::start()
{
	clear();
	cout << "Menu g³owne \n" << std::endl;
	cout << "1. Wczytaj Graf z Pliku" << std::endl;
	cout << "2. Generuj Graf Algorytmem" << std::endl;
	cout << "3. Poka¿ strukture: " << std::endl;
	cout << "4. Wykonaj Algorytmy szukania minimalnego drzewa" << std::endl;
	cout << "5. Wykonaj Algorytmy szukania drogi" << std::endl;
	cout << "6. Wykonaj obliczenia" << std::endl;
	cout << "7. Zmieñ ilosc wierzcholkow i gestosc" << std::endl;
	cout << " W: " << graph->V << " E: " << graph->E << std::endl;
	cout << " Gestosc: " << (double)graph->V/(double)graph->E<< std::endl;
	GivenChoice = choice();
	switch (GivenChoice)
	{
	case 1: {
		graph->loadFromFile(); start();
		break;  }
	case 2: {
		graph->generate(W,E);  break; }
	case 3: {graph->print(); system("Pause");  break; }
	case 4: {tree(); system("Pause");  break; }
	case 5: {path(); system("Pause");  break; }
	case 6: {countAll(); system("Pause"); break; }
	case 7: {break; }
	default:
		break;
	}
	if(end==false)start();
}