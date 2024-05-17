#include "SprawdzenieBot.h"

SprawdzenieBot::SprawdzenieBot(Pilka pilka) {
	this->lines = pilka;

}

SprawdzenieBot::~SprawdzenieBot() {

}

bool SprawdzenieBot::czyPole(int x, int y) {
	if ((x > 540) || (x < 60)) { return false; }
	if (((y > 720) || (y < 120)) && ((x < 240) || (x > 360))) { return false; }
	else if ((y > 780) || (y < 60)) { return false; }
	return true;
}

bool SprawdzenieBot::czySprTablice(int x, int y) {
	if (!czyPole(x, y)) {return true;};
	for (int i = 0; i < (this->lines.numer / 2) + 39; i++) {
		//jak zmienne w tablicy sa rowne biazacy i nowy albo nowy i bierzacy to odda false a tak to true (ze mozna dac dalej)
		if (((lines.tablicaZla[i][0][0] == x) && (lines.tablicaZla[i][0][1] == y)) && ((lines.tablicaZla[i][1][0] == lines.position_x) && (lines.tablicaZla[i][1][1] == lines.position_y))) { return true; }
		if (((lines.tablicaZla[i][1][0] == x) && (lines.tablicaZla[i][1][1] == y)) && ((lines.tablicaZla[i][0][0] == lines.position_x) && (lines.tablicaZla[i][0][1] == lines.position_y))) { return true; }

		if ((x == lines.position_x) && (y == lines.position_y)) { return true; }
	}
	return false;
}

bool SprawdzenieBot::czyDalej(Pilka liness) {

	for (int i = 0; i <= ((lines.numer - 1) / 2) - 1; i++) {
		//jak dana pozycja jest w tablicy to oddaje true ze dalej mozna
		if (((liness.tablicaZla[i][0][0] == liness.position_x) && (liness.tablicaZla[i][0][1] == liness.position_y)) || ((liness.tablicaZla[i][1][0] == liness.position_x) && (liness.tablicaZla[i][1][1] == liness.position_y))) {
			return true;
		}
	}
	return false;
}

bool SprawdzenieBot::czyBrak(Pilka lines) {
	int licznik = 0;
	if (czySprTablice(lines.position_x + 60, lines.position_y)) { licznik++; }
	if (czySprTablice(lines.position_x+60, lines.position_y+60)) { licznik++; }
	if (czySprTablice(lines.position_x, lines.position_y+60)) { licznik++; }
	if (czySprTablice(lines.position_x-60, lines.position_y+60)) { licznik++; }
	if (czySprTablice(lines.position_x-60, lines.position_y)) { licznik++; }
	if (czySprTablice(lines.position_x-60, lines.position_y-60)) { licznik++; }
	if (czySprTablice(lines.position_x, lines.position_y-60)) { licznik++; }
	if (czySprTablice(lines.position_x+60, lines.position_y-60)) { licznik++; }
	if (licznik == 8) { return true; }
	return false;
}

bool SprawdzenieBot::czyKoniec(Pilka lines) {
	if (czyBrak(lines)) { return true; }
	if ((lines.position_y == 60) || (lines.position_y == 780)) { return true; }
	return false;
}


