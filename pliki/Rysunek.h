#pragma once
#include <SFML/Graphics.hpp>

class Rysunek
{
public:
	Rysunek();
	~Rysunek();

	sf::VertexArray prostokat;
	sf::RectangleShape punkt;
	sf::RectangleShape zwrocPkt();
	void poczatek();
	sf::VertexArray zwroc();
	void rysunek();
};

