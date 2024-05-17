#pragma once
#include "Pilka.h"
#include "Sprawdzenie.h"

class SprawdzenieBot :
	public Pilka
{
public:
	SprawdzenieBot(Pilka pilka);
	~SprawdzenieBot();
	Pilka lines;

	bool czyPole(int x, int y);
	bool czySprTablice(int x, int y);
	bool czyDalej(Pilka liness);
	bool czyKoniec(Pilka liness);
	
	//////
	bool czyBrak(Pilka lines);
};

