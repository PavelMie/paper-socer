#include "Boisko.h"
#include <iostream>

Boisko::Boisko() {
}

Boisko::~Boisko() {
}

Pilka Boisko::standard(Pilka lines) {

	for (int i = 0; i < 10; i++) {
		lines.zmiana(-1);
	}
	for (int i = 0; i < 3; i++) {
		lines.zmiana(3);
	}
	lines.zmiana(-1);
	for (int i = 0; i < 2; i++) {
		lines.zmiana(3);
	}
	lines.zmiana(1);
	for (int i = 0; i < 3; i++) {
		lines.zmiana(3);
	}
	for (int i = 0; i < 10; i++) {
		lines.zmiana(1);
	}
	for (int i = 0; i < 3; i++) {
		lines.zmiana(-3);
	}
	lines.zmiana(1);
	for (int i = 0; i < 2; i++) {
		lines.zmiana(-3);
	}
	lines.zmiana(-1);
	for (int i = 0; i < 3; i++) {
		lines.zmiana(-3);
	}

	lines.ustaw(360, 780, 420, 720);
	lines.ustaw(180, 720, 240, 780);
	lines.ustaw(360, 60, 420, 120);
	lines.ustaw(180, 120, 240, 60);

	lines.ustaw(300, 420, 300, 420);
	return lines;
}

