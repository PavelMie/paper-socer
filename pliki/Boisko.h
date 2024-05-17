#pragma once
#include "Pilka.h"
class Boisko :
	public Pilka
{
		
	public:
		Boisko();
		~Boisko();

		Pilka standard(Pilka lines);

};
