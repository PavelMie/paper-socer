#include "Bot.h"

Bot::Bot() {
}

Bot::~Bot() {
}

Pilka Bot::dzialanie(Pilka lines,SprawdzenieBot spr) {
	
	spr.lines = lines;
	if ((lines.position_y == 660) && (lines.position_x >= 240 && lines.position_x <= 360)) {
		lines = wykonczenie(lines, spr);
	}
	else { lines = kierunek(lines, spr); }
	if (spr.czyKoniec(lines)) { return lines; }
	if (spr.czyDalej(lines)) { lines = dzialanie(lines, spr); }
	
	return lines;
}

Pilka Bot::wykonczenie(Pilka lines, SprawdzenieBot spr) {

	spr.lines = lines;
	int a=60, b = 60;
		switch (lines.position_x)
		{
		default:
			break;
		case 240:
			a = 0;
			break;
		case 300:
			if (spr.czySprTablice(lines.position_x + a, lines.position_y + b)) { a = -60; }
			else { a = 60; }
			break;
		case 360:
			a = 0;
			break;
		}
		if (!spr.czySprTablice(lines.position_x + a, position_y + b)) {
			lines.wyborF(lines.position_x + a, lines.position_y + b); return lines;
		}
		return lines;
}

Pilka Bot::kierunek(Pilka lines, SprawdzenieBot spr) {
	
	int a=60, b=60,p;
	spr.lines = lines;

	if (lines.position_x > 300) { a = -60; }
	else if (lines.position_x < 300) { a = 60; }
	else { a = 0; }
	
	if (!spr.czySprTablice(lines.position_x + a, lines.position_y + b)) {
		lines.wyborF(lines.position_x + a, lines.position_y + b); return lines;
	}
	
	if (a == 0) {
		p = (rand() % 2); if (p == 0) { a = -60; }else { a = 60; }
		if (!spr.czySprTablice(lines.position_x + a, lines.position_y + b)) {
			lines.wyborF(lines.position_x + a, lines.position_y + b); return lines;
		}
		a = -a;
		if (!spr.czySprTablice(lines.position_x + a, lines.position_y + b)) {
			lines.wyborF(lines.position_x + a, lines.position_y + b); return lines;
		}
	}

	a = -a;
	if (!spr.czySprTablice(lines.position_x + a, lines.position_y + b)) {
			lines.wyborF(lines.position_x + a, lines.position_y + b); return lines;
	}
		
	lines = losowo(lines, spr);
	return lines;
}

Pilka Bot::losowo(Pilka lines, SprawdzenieBot spr) {

	int a, b;
	spr.lines = lines;

	a = (rand() % 3 - 1) * 60; b = (rand() % 3 - 1) * 60;

	if (!spr.czySprTablice(lines.position_x + a, lines.position_y + b)) {
		lines.wyborF(lines.position_x + a, lines.position_y + b); return lines;
	}
	else {
		lines = losowo(lines, spr); return lines;
	}
}