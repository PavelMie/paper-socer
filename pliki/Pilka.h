#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Pilka
{
	int tablicaL;

	void update();

public:

	Pilka();
	~Pilka();

	sf::VertexArray lines;
	
	int numer;
	int position_x;
	int position_y;

	int tablicaZla[310][2][2];


	void zmianaP(int a, int b);

	void zmiana(int a);
	
	void ustaw(int x, int y, int xx, int yy);


	void wybor(sf::Vector2i mousePos);
	
	void wyborF(int a, int b);

	void kolor(int a);

	sf::VertexArray zwroc();


};



