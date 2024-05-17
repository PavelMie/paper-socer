#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bot.h"
#include "Pilka.h"
#include "Start.h"
#include "Sprawdzenie.h"
#include "Rysunek.h"
#include <cstdio>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 840), "Pilka");
	
	Pilka lines;
	Start start(lines);
	Bot bot;
	Rysunek rysunek;

	lines = start.wynik();
	rysunek.rysunek();
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}



		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		Sprawdzenie spr(lines, mousePos);


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			
			lines = start.click(mousePos, spr, bot,lines);
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
	
		}


		
		window.clear();
		window.draw(lines.zwroc());
		window.draw(rysunek.zwroc());
		window.draw(rysunek.zwrocPkt());
		window.display();
		
		if (spr.czyKoniec(lines)) {
			window.draw(lines.zwroc());
			window.display();
			while (!sf::Mouse::isButtonPressed(sf::Mouse::Left)); break; 
		}
	}
	return 0;
}

