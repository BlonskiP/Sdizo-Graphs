#include "stdafx.h"
#include "MainMenu.h"

void MainMenu::start()
{
	cout << "Menu g³owne \n" << std::endl;
	cout << "1. Wczytaj Graf z Pliku" << std::endl;
	cout << "2. Generuj Graf Algorytmem" << std::endl;
	cout << "3. Poka¿ strukture: " << std::endl;
	cout << "4. Wykonaj Algorytmy szukania minimalnego drzewa" << std::endl;
	cout << "5. Wykonaj Algorytmy szukania drogi" << std::endl;
	cout << "6. Wykonaj obliczenia" << std::endl;
	cout << "7. Zmieñ ilosc wierzcholkow i gestosc" << std::endl;
	cout << " W: " << W << " G: " << G << std::endl;
	GivenChoice = choice();
	switch (GivenChoice)
	{
	case 1: {
		graph->loadFromFile();
		break; }
	case 2: {
		graph->generate();  break; }
	case 3: {graph->print(); break; }
	case 4: {break; }
	case 5: {break; }
	case 6: {break; }
	case 7: {break; }
	default:
		start();
		break;
	}
}