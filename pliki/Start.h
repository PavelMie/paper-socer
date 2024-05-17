#pragma once
#include "Boisko.h"
#include "Pilka.h"
#include "Sprawdzenie.h"
#include "Bot.h"
class Start
{
	public:
		Start(Pilka pilka);
		~Start();
		Pilka pilka;
		Boisko boisko;
		Pilka wynik();
		Pilka click(sf::Vector2i mouse,Sprawdzenie spr,Bot bot,Pilka pilka);
};

