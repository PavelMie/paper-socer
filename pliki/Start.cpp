#include "Start.h"

Start::Start(Pilka lines) {
	pilka = boisko.standard(lines);
	}

Start::~Start() {

}

Pilka Start::wynik() {
	return this->pilka;
}

Pilka Start::click(sf::Vector2i mousePos,Sprawdzenie spr,Bot bot,Pilka pilka) {
	spr.lines = pilka;

	if (spr.czyMozna()) {
		pilka.wybor(mousePos);
		spr.lines = pilka;
		if (!spr.czyDalej(pilka)) { pilka.kolor(2); pilka = bot.dzialanie(pilka, spr); }
	}
	return pilka;
}