#include "Rysunek.h"

Rysunek::Rysunek(){
	prostokat.setPrimitiveType(sf::Points);
	prostokat.resize(100);
}

Rysunek::~Rysunek() {
}

void Rysunek::poczatek() {
	punkt.setSize(sf::Vector2f(3, 3));
	punkt.setPosition(sf::Vector2f(300, 420));
}

void Rysunek::rysunek() {
	punkt.setSize(sf::Vector2f(3, 3));
	punkt.setPosition(sf::Vector2f(298, 418));

	prostokat[0].position.x = 120;
	prostokat[0].position.y = 180;
	int z=1;
	int x= 60, y= 0;
		for (int i = 0; i < 9;i++) {
			for (int j = 0; j < 7; j++) {
				prostokat[z].position.x = prostokat[z-1].position.x + x;
				prostokat[z].position.y = prostokat[z-1].position.y + y;
				z++;
			}
			prostokat[z].position.x = 120;
			prostokat[z].position.y = prostokat[z - 1].position.y + 60;
			z++;
		}

		
	prostokat[92].position.x = 300;
	prostokat[92].position.y = 120;

	prostokat[91].position.x = 300;
	prostokat[91].position.y = 720;

	prostokat[90].position.x = 300;
	prostokat[90].position.y = 420;
	
}

sf::VertexArray Rysunek::zwroc() {
	return prostokat;
}

sf::RectangleShape Rysunek::zwrocPkt() {
	return punkt;
}