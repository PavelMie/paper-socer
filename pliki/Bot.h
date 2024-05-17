#pragma once
#include "Pilka.h"
#include "SprawdzenieBot.h"
#include <iostream>

class Bot :
	public Pilka
{
	Pilka losowo(Pilka lines, SprawdzenieBot spr);

	Pilka kierunek(Pilka lines, SprawdzenieBot spr);

	Pilka wykonczenie(Pilka lines, SprawdzenieBot spr);

public:

	Bot();
	~Bot();

	Pilka dzialanie( Pilka lines, SprawdzenieBot spr);

};

