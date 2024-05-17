#include "Sprawdzenie.h"


Sprawdzenie::Sprawdzenie(Pilka pilka, sf::Vector2i mouse) {
	this->lines = pilka;
	this->mousePos = mouse;
	xp = ((mousePos.x + 30) / 60) * 60;
	yp = ((mousePos.y + 30) / 60) * 60;
}

Sprawdzenie::~Sprawdzenie() {

}

bool Sprawdzenie::czyPole() {
	if ((mousePos.x > 540) || (mousePos.x < 60)) { return false; }
	if (((mousePos.y > 720) || (mousePos.y < 120)) && ((mousePos.x < 240) || (mousePos.x > 360))) { return false; }
	else if ((mousePos.y > 780) || (mousePos.y < 60)) { return false; }
	return true;
}

bool Sprawdzenie::czyOdleglosc(){
	if (!(((mousePos.x > lines.position_x - 90) && (mousePos.x < lines.position_x + 90)) && ((mousePos.y > lines.position_y - 90) && (mousePos.y < lines.position_y + 90)))) { return false; }
	
	return true;
}

bool Sprawdzenie::czySprTablice(int x, int y) {
	for (int i = 0; i < (this->lines.numer / 2) +48; i++) {
		//jak zmienne w tablicy sa rowne biazacy i nowy albo nowy i bierzacy to odda false a tak to true (ze mozna dac dalej)
		if (((lines.tablicaZla[i][0][0] == x) && (lines.tablicaZla[i][0][1] == y)) && ((lines.tablicaZla[i][1][0] == lines.position_x) && (lines.tablicaZla[i][1][1] == lines.position_y))) { return true; }
		if (((lines.tablicaZla[i][1][0] == x) && (lines.tablicaZla[i][1][1] == y)) && ((lines.tablicaZla[i][0][0] == lines.position_x) && (lines.tablicaZla[i][0][1] == lines.position_y))) { return true; }

		if ((x == lines.position_x) && (y == lines.position_y)) { return true; }
	}
	return false;
}

bool Sprawdzenie::czyTabClick() {
	if (czySprTablice(xp, yp)) { return false; }
	return true;
}

bool Sprawdzenie::czyMozna() {
	if (!czyPole()) { return false; }
	if (!czyOdleglosc()) { return false; }
	if (!czyTabClick()) { return false; }
	return true;
}

bool Sprawdzenie::czyDalej(Pilka liness) {
	
	for (int i = 0; i <= ((lines.numer-1) / 2)-1 ; i++) {
		//jak dana pozycja jest w tablicy to oddaje true ze dalej mozna
		if (((liness.tablicaZla[i][0][0] == liness.position_x) && (liness.tablicaZla[i][0][1] == liness.position_y)) || ((liness.tablicaZla[i][1][0] == liness.position_x) && (liness.tablicaZla[i][1][1] == liness.position_y))) {
			return true;
		}
	}
	return false;
}

bool Sprawdzenie::czyKoniec(Pilka lines) {
	if ((lines.position_y == 60) || (lines.position_y == 780)) { return true; }
	return false;
}

