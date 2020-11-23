#pragma once
#include <vector>
#include "Cible.h"


class Capteur
{
private:
	int cout;
	int id;
	std::vector<Cible> cibles;

public:
	Capteur(void);
	Capteur(int id, int cout);
	void addCible(Cible cible);
	std::vector<Cible> getCibles(void);
};

