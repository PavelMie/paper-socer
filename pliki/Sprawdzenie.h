#pragma once
#include "Pilka.h"


class Sprawdzenie :
	public Pilka
{

	bool czyPole();

	bool czyOdleglosc();

	bool czySprTablice(int x, int y);
	
	bool czyTabClick();

	public:
		Sprawdzenie(Pilka pilka, sf::Vector2i mouse);
		~Sprawdzenie();

		sf::Vector2i mousePos;
		Pilka lines;
		int xp;
		int yp;

		bool czyMozna();
		
		bool czyDalej(Pilka liness);
		bool czyKoniec(Pilka liness);

};

