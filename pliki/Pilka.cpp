#include "Pilka.h"
#include "Warunki.h"
#include <iostream>


//#include <SFML/Graphics.hpp>

Pilka::Pilka() {
	lines.setPrimitiveType(sf::Lines);
	lines.resize(3010);

	lines[0].position = sf::Vector2f(60, 120);
	lines[1].position = sf::Vector2f(60, 120);
	this->position_x = lines[1].position.x;
	this->position_y = lines[1].position.y;
	tablicaL = 0;
	numer = 1;
}

Pilka::~Pilka()
{
}


//boisko
void Pilka::zmianaP(int a, int b) {
		numer++;
		lines[numer].position.x = lines[numer - 1].position.x;
		lines[numer].position.y = lines[numer - 1].position.y;
		numer++;
		lines[numer].position.x = lines[numer - 1].position.x + a;
		lines[numer].position.y = lines[numer - 1].position.y + b;
		update();
	
}

void Pilka::zmiana(int a) {

	if (a == 1) {
		zmianaP(0, -60);
	}
	if (a == 2) { zmianaP(60, -60); }
	if (a == 3) { zmianaP(60, 0); }
	if (a == 4) { zmianaP(60, 60); }
	if (a == -1) { zmianaP(0, 60); }
	if (a == -2) { zmianaP(-60, 60); }
	if (a == -3) { zmianaP(-60, 0); }
	if (a == -4) { zmianaP(-60, -60); }
}

void Pilka::ustaw(int x, int y, int xx, int yy) {

	numer++;
	lines[numer].position.x = x;
	lines[numer].position.y = y;

	numer++;
	lines[numer].position.x = xx;
	lines[numer].position.y = yy;
	update();
}


//bot
void Pilka::wyborF(int a, int b) {
	numer++;
	lines[numer].position.x = lines[numer - 1].position.x;
	lines[numer].position.y = lines[numer - 1].position.y;
	numer++;
	lines[numer].position.x = a;
	lines[numer].position.y = b;

	kolor(1);
	update();
}

//main
void Pilka::wybor(sf::Vector2i mousePos) {

	numer++;
	lines[numer].position.x = lines[numer - 1].position.x;
	lines[numer].position.y = lines[numer - 1].position.y;
	numer++;
	lines[numer].position.x = ((mousePos.x + 30) / 60) * 60;
	lines[numer].position.y = ((mousePos.y + 30) / 60) * 60;
	kolor(0);
	update();

}

void Pilka::kolor(int a) {

	if (a == 2) {
		for (int i = 0; i < numer+1; i++) {
			lines[i].color = sf::Color::White;
		}
	}
	if (a == 1) {
		lines[numer].color = sf::Color::Blue;
		lines[numer - 1].color = sf::Color::Blue;
	}
	if (a == 0) {
		lines[numer].color = sf::Color::Green;
		lines[numer - 1].color = sf::Color::Green;
	}
}

void Pilka::update() {

	tablicaL++;
	this->position_x = lines[numer].position.x;
	this->position_y = lines[numer].position.y;

	tablicaZla[tablicaL][0][0] = lines[numer - 1].position.x;
	tablicaZla[tablicaL][0][1] = lines[numer - 1].position.y;
	tablicaZla[tablicaL][1][0] = lines[numer].position.x;
	tablicaZla[tablicaL][1][1] = lines[numer].position.y;

}

sf::VertexArray Pilka::zwroc() {
	return lines;
}
